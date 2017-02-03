#ifndef RESOURCEMANAGER_H
#define RESOURCEMANAGER_H

#include <iostream>
#include <string>
#include <map>

#include <common/shader.h>
#include <common/mesh.h>
#include <common/line.h>

class ResourceManager
{
public:
	ResourceManager();
	virtual ~ResourceManager();

	Shader* getShader(const std::string& _vs, const std::string& _fs);
	Mesh* getLineMesh(Line* line);

private:
	std::map<std::string, Shader*> shaders;
	std::map<std::string, Mesh*> meshes;
};

#endif
