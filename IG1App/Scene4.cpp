#include "Scene4.h"
#include "Ground.h"
#include "BoxOutline.h"
#include "Star3D.h"
#include "Shader.h"
#include <glm/ext/matrix_transform.hpp>
#include <GLFW/glfw3.h>


void Scene4::init() {
	Scene::init();

	gObjects.push_back(new RGBAxes(300.0));
	groundTex = new Texture();
	groundTex->load("../assets/images/baldosaC.png",1);
	Ground* ground = new Ground(400.0, 400.0, groundTex);


	//boxTex = new Texture();
	//boxTex->load("../assets/images/papelE.png", 1);
	//BoxOutline* cube = new BoxOutline(boxTex,100.0);
	//glm::mat4 M = glm::translate(glm::mat4(1.0f), glm::vec3(0, 50, 0));
	//cube->setModelMat(M);
	// 
	//Interior de la Caja 
	boxTex = new Texture();
	boxTex->load("../assets/images/container.jpg", 1);
	//Exterior de la caja
	boxTexInterior = new Texture();
	boxTexInterior->load("../assets/images/papelE.png", 1);

	BoxOutline* cube = new BoxOutline(boxTex, boxTexInterior, 100.0);
	glm::mat4 M = glm::translate(glm::mat4(1.0f), glm::vec3(0, 50, 0));
	cube->setModelMat(M);


	starTex = new Texture();
	starTex->load("../assets/images/rueda.png", 1);
	Star3D* star = new Star3D(100.0, 8, 100.0, starTex);

	//Star3D* star = new Star3D(100.0, 8, 100.0, glm::dvec4(0.0, 0.0, 0.0, 1.0));
	
	// Posicionarla en la escena
	star->setModelMat(glm::translate(glm::dmat4(1.0), glm::dvec3(0.0, 200.0, 0.0)));

	// Añadirla al vector de entidades
	gObjects.push_back(star);
	gObjects.push_back(cube);
	gObjects.push_back(ground);

}

Scene4::~Scene4()
{
	delete groundTex;
	groundTex = nullptr;

	delete boxTex;
	boxTex = nullptr;

	delete boxTexInterior;
		boxTexInterior = nullptr;

	delete starTex;
	starTex = nullptr;

}

//void Scene4::update()
//{
//	Scene::update();   
//}

void Scene4::update()
{
	Scene::update();
	for (Abs_Entity* obj : gObjects)
		obj->update();
}
//gObjects.push_back(new BoxCubeOpen(100.0));

	//gObjects.push_back(new Ground(300.0, 300.0, nullptr));