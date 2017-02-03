#ifndef LINE_H
#define LINE_H

#include <vector>
#include <string>
#include <cstring>
#include <stdio.h>

#include <glm/glm.hpp>

class Line
{
public:
	Line();
	Line(const std::string& _filename);
	virtual ~Line();

	bool loadLineFile(const std::string& filename);
	void addPoint(float x, float y);
	void editPoint(unsigned int _id, float _x, float _y);

	std::vector<glm::vec3> getPoints(){return points;}
	bool getClosed(){return closed;}
	std::string getFileName(){return filename;}

private:
	std::vector<glm::vec3> points;

	std::string filename; ///< @brief _filename filename of the Line

	// identity for unique filename
	int guid; ///< @brief The _guid property of this Line
	int nextGuid; ///< @brief The _nextGuid property of this Line

	bool dynamic; ///< @brief The _dynamic property of this Line
	bool closed;
};

#endif
