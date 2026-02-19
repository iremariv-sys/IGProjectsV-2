#include "Scene4.h"
#include "Ground.h"


void Scene4::init() {
	Scene::init();

	gObjects.push_back(new RGBAxes(300.0));
	groundTex = new Texture();
	groundTex->load("../assets/images/baldosaC.png",1);

	Ground* ground = new Ground(400.0, 400.0, groundTex);
	
	//gObjects.push_back(new Ground(300.0, 300.0, nullptr));

	gObjects.push_back(ground);

}

Scene4::~Scene4()
{
	delete groundTex;
	groundTex = nullptr;
}

void Scene4::update()
{
	Scene::update();   
}

