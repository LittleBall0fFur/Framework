#include "resourcemanager.h"

ResourceManager::ResourceManager(){

}

Shader* ResourceManager::getShader(const std::string& _vs, const std::string& _fs)
{
	std::string filename;
	filename = _vs;
	std::string tmp("_");
	filename.append(tmp);
	filename.append(_fs);
	if (shaders[filename] != NULL) {
		//std::cout << "return existing resource: " << filename << " (shader)" << std::endl;
		return shaders[filename];
	} else {
		Shader* s = new Shader();
		std::string fss = "";
		fss.append(_fs);
		std::string vss = "";
		vss.append(_vs);
		s->loadShaders(vss.c_str(), fss.c_str());
		shaders[filename] = s;

		std::cout << "return new resource: " << filename << " (shader)" << std::endl;
		return s;
	}

	return NULL;
}

/*Mesh* ResourceManager::getLineMesh(Line* _line)
{
	std::string meshname = _line->getFileName();

	if (meshes[meshname] != NULL) {
		//std::cout << "return existing resource: " << meshname << " (mesh)" << std::endl;
		return meshes[meshname];
	} else {
		Mesh* m = new Mesh();
		m->generateLineMesh(_line);
		meshes[meshname] = m;

		std::cout << "return new resource: " << meshname << " (mesh)" << std::endl;
		return m;
	}
	std::cout<<"no mesh returned"<<std::endl;
	return NULL;
}*/

ResourceManager::~ResourceManager(){

}
