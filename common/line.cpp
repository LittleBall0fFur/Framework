#include "line.h"
#include <iostream>

Line::Line()
{
	guid = nextGuid;
	nextGuid++;

	dynamic = false;
	closed = false;
	char buf[12]; // should be big enough: "Line99999"
	sprintf(buf, "line%d", guid);
	std::string linename(buf);
	filename = linename;
}

Line::Line(const std::string& _filename)
{
	filename = _filename;
	loadLineFile(_filename);
}

void Line::addPoint(float x, float y)
{
	glm::vec3 pnt(x, y, 0.0f);
	points.push_back(pnt);
}

void Line::editPoint(unsigned int _id, float _x, float _y)
{
	if (_id < points.size()) {
		points[_id].x = _x;
		points[_id].y = _y;
	}
}

bool Line::loadLineFile(const std::string& _filename)
{
	FILE * file = fopen(_filename.c_str(), "r");
	if( file == NULL ){
		printf("Can't open %s\n", _filename.c_str());
		return false;
	}

	while(1) {
		char lineHeader[128];
		// read the first word of the line
		int res = fscanf(file, "%s", lineHeader);
		if (res == EOF) {
			break; // EOF = End Of File. Quit the loop.
		}
		// else : parse lineHeader
		if (strcmp( lineHeader, "v") == 0) {
			glm::vec3 vertex;
			int matches = fscanf(file, "%f %f %f\n", &vertex.x, &vertex.y, &vertex.z );
			if (matches != 3) {
				printf("File can't be read by the parser. Not 3 vertices per point.\n");
				return false;
			}
			points.push_back(vertex);
		} else {
			// Probably a comment, eat up the rest of the line
			char tmpBuffer[1000];
			char * returned = fgets(tmpBuffer, 1000, file);
			if (returned[0] == '#') {
				// yes, a comment
			}
		}
	}

	fclose (file);

	// close the line
	points.push_back(points[0]);

	return true;
}

Line::~Line(){
  points.clear();
}
