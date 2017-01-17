#ifndef RESOURCEMANAGER_H
#define RESOURCEMANAGER_H

#include <iostream>
#include <string>
#include <map>

#include <common/shader.h>

class ResourceManager
{
public:
	ResourceManager();
	virtual ~ResourceManager();

	Shader* getShader(const std::string& _vs, const std::string& _fs);

private:
	std::map<std::string, Shader*> shaders;
};

#endif
