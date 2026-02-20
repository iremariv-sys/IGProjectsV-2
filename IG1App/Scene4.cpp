#include "Scene4.h"
#include "Ground.h"
#include "BoxOutline.h"
#include <glm/ext/matrix_transform.hpp>


void Scene4::init() {
	Scene::init();

	gObjects.push_back(new RGBAxes(300.0));
	groundTex = new Texture();
	groundTex->load("../assets/images/baldosaC.png",1);

	Ground* ground = new Ground(400.0, 400.0, groundTex);


	BoxOutline* cube = new BoxOutline(100.0);

	glm::mat4 M = glm::translate(glm::mat4(1.0f), glm::vec3(0, 50, 0));
	cube->setModelMat(M);

	
	gObjects.push_back(cube);
	
	//gObjects.push_back(new BoxCubeOpen(100.0));
	
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

