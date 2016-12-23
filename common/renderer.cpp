#include "renderer.h"

Renderer::Renderer(){
  window_width = 1920;
  window_height = 1080;

  window = NULL;

  fragment_shader	= "shaders/sprite.frag";
  vertex_shader	= "shaders/sprite.vert";
  projectionMatrix = glm::ortho(0.0f, (float)window_width, (float)window_height, 0.0f, 0.1f, 100.0f);

  init();
}

Renderer::~Renderer(){
  glDeleteProgram(programID);
	glDeleteTextures(1, &textureID);
	// Close OpenGL window and terminate GLFW
	glfwTerminate();
}

void Renderer::renderScene(Scene* _scene)
{
  // Clear the screen
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

  // Compute the ViewMatrix from keyboard and mouse input (see: camera.h/cpp)
  _scene->getCamera()->computeMatricesFromInputs(window);

  glm::mat4 modelMatrix = this->getModelMatrix(_scene->position,_scene->scale, _scene->rotation);

  this->renderEntity(modelMatrix, _scene, _scene->getCamera());
  // Swap buffers
  glfwSwapBuffers(window);
  glfwPollEvents();
}

void Renderer::renderEntity(glm::mat4 &modelmatrix, Entity* _entity, Camera* _camera)
{
  modelmatrix *= this->getModelMatrix(_entity->getPosition(), _entity->getScale(), _entity->getRotation());
  if(_entity->getSprite() != NULL){
    texture = _entity->getSprite()->getTexture();
  	mesh = new Mesh(texture->getWidth() , texture->getHeight(), _entity->getSprite()->getTexture()->getTextureBuffer());
  	glm::mat4 MVP = projectionMatrix * _camera->getViewMatrix() * modelmatrix;

  	_entity->getSprite()->setTextureSize(Vector2(texture->getWidth(), texture->getHeight()));
  	if (_entity->getSprite()->getSpriteScale().x == 0 && _entity->getSprite()->getSpriteScale().y == 0)
  	{
  		_entity->getSprite()->setSpriteScale(Vector2(texture->getWidth(), texture->getHeight()));
  		_entity->setScale(_entity->getScale());
  	}

	  renderMesh(mesh, MVP);
    delete mesh;
  }
	std::vector<Entity*>children = _entity->getChildren();
	std::vector<Entity*>::iterator it = children.begin();

	while (it != children.end())
	{
		renderEntity(modelmatrix, (*it), _camera);
		it++;
	}
  if(_entity->getParent() != NULL) {
    modelmatrix = this->getModelMatrix(_entity->getParent()->getPosition(), _entity->getParent()->getScale(), _entity->getParent()->getRotation());
  }
}


void Renderer::renderMesh(Mesh* _mesh, glm::mat4 _MVP)
{
  glUseProgram(programID);

  // Send our transformation to the currently bound shader,
  // in the "MVP" uniform
  glUniformMatrix4fv(matrixID, 1, GL_FALSE, &_MVP[0][0]);

  // Bind our texture in Texture Unit 0
  glActiveTexture(GL_TEXTURE0);
  glBindTexture(GL_TEXTURE_2D, _mesh->getTexture());
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
  // Set our "myTextureSampler" sampler to user Texture Unit 0
  glUniform1i(textureID, 0);

  // 1st attribute buffer : vertices
  glEnableVertexAttribArray(vertexPosition_modelspaceID);
  glBindBuffer(GL_ARRAY_BUFFER, _mesh->getVertexbuffer());
  glVertexAttribPointer(
    vertexPosition_modelspaceID,  // The attribute we want to configure
    3,                            // size : x+y+z => 3
    GL_FLOAT,                     // type
    GL_FALSE,                     // normalized?
    0,                            // stride
    (void*)0                      // array buffer offset
  );

  // 2nd attribute buffer : UVs
  glEnableVertexAttribArray(vertexUVID);
  glBindBuffer(GL_ARRAY_BUFFER, _mesh->getUvbuffer());
  glVertexAttribPointer(
    vertexUVID,                   // The attribute we want to configure
    2,                            // size : U+V => 2
    GL_FLOAT,                     // type
    GL_FALSE,                     // normalized?
    0,                            // stride
    (void*)0                      // array buffer offset
  );

  // Draw the triangles !
  glDrawArrays(GL_TRIANGLES, 0, 2*3); // 2*3 indices starting at 0 -> 2 triangles

  glDisableVertexAttribArray(vertexPosition_modelspaceID);
  glDisableVertexAttribArray(vertexUVID);
}

glm::mat4 Renderer::getModelMatrix(Vector2 _position, Vector2 _scale, float _rotation)
{
  // Build the Model matrix
  glm::mat4 translationMatrix	= glm::translate(glm::mat4(1.0f), glm::vec3(_position.x, _position.y, 0.0f));
  glm::mat4 rotationMatrix	= glm::eulerAngleYXZ(0.0f, 0.0f, _rotation);
  glm::mat4 scalingMatrix		= glm::scale(glm::mat4(1.0f), glm::vec3(_scale.x, _scale.y, 1.0f));

  glm::mat4 modelMatrix = translationMatrix * rotationMatrix * scalingMatrix;

  return modelMatrix;
}

void Renderer::init()
{
  // Initialise GLFW
  if( !glfwInit() )
  {
    fprintf( stderr, "Failed to initialize GLFW\n" );
    return;
  }

  glfwWindowHint(GLFW_SAMPLES, 4);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 2);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 1);

  // Open a window and create its OpenGL context
  window = glfwCreateWindow( window_width, window_height, "Demo", NULL, NULL);
  if( window == NULL ){
    fprintf( stderr, "Failed to open GLFW window.\n" );
    glfwTerminate();
    return;
  }
  glfwMakeContextCurrent(window);

  // Initialize GLEW
  if (glewInit() != GLEW_OK) {
    fprintf(stderr, "Failed to initialize GLEW\n");
    return;
  }

  // Ensure we can capture the escape key being pressed below
  glfwSetInputMode(window, GLFW_STICKY_KEYS, GL_TRUE);

  // Dark blue background
  glClearColor(0.0f, 0.0f, 0.4f, 0.5f);

  glfwSwapInterval(0);

  // Enable depth test
  //glEnable(GL_DEPTH_TEST);
  // Accept fragment if it closer to the camera than the former one
  //glDepthFunc(GL_LESS);

  // Cull triangles which normal is not towards the camera
  //glEnable(GL_CULL_FACE);

  // Create and compile our GLSL program from the shaders
  // see: shader.h/cpp
  programID = loadShaders(vertex_shader.c_str(), fragment_shader.c_str());

  // Get a handle for our buffers
  vertexPosition_modelspaceID = glGetAttribLocation(programID, "vertexPosition_modelspace");
  vertexUVID = glGetAttribLocation(programID, "vertexUV");

  // Get a handle for our "MVP" uniform
  matrixID = glGetUniformLocation(programID, "MVP");
  // Get a handle for our "myTextureSampler" uniform
  textureID  = glGetUniformLocation(programID, "myTextureSampler");
}

bool Renderer::quit()
{
  return (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS || glfwWindowShouldClose(window));
}
