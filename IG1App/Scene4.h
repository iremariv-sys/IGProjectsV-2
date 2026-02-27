#ifndef _H_Scene4_H_
#define _H_Scene4_H_

#include "Scene.h"
#include "Texture.h"

class Scene4 : public Scene
{
public:

	void init() override;
	void update() override;
	~Scene4();

	Texture* groundTex;
	Texture* boxTex;
	Texture* starTex;
	Texture* boxTexInterior;
	Texture* glassTex;
	
};

#endif //_H_Scene4_H_
