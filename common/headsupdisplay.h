#ifndef HEADSUPDISPLAY_H
#define HEADSUPDISPLAY_H

#include <common/entity.h>

class HeadsUpDisplay: public Entity
{
public:
	HeadsUpDisplay();
	virtual ~HeadsUpDisplay();

	void update(float _deltaTime);

	void setScreenOverlay(bool _overlay);

	bool getOverlay(){return overlay;}

private:
	bool overlay;

	glm::vec3 position;
};

#endif
