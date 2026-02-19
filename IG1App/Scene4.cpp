#include "Scene4.h"
#include "Ground.h"


void Scene4::init() {
	Scene::init();

	//glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	//glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);

	gObjects.push_back(new RGBAxes(300.0));
	
	//PROBLEMA
	groundTex = new Texture();
	groundTex->load("../assets/images/baldosaC.png",1);

	Ground* ground = new Ground(300.0, 300.0, groundTex);
	
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

