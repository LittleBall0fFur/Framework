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

ResourceManager::~ResourceManager(){

}
