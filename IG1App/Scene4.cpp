#include "Scene4.h"
#include "Ground.h"
#include "BoxOutline.h"
#include "Star3D.h"
#include "Shader.h"
#include <glm/ext/matrix_transform.hpp>
#include <GLFW/glfw3.h>
#include "GlassParapet.h"
#include "Photo.h"
#include "IG1App.h"



void Scene4::init() {
	Scene::init();

	gObjects.push_back(new RGBAxes(300.0));
	groundTex = new Texture();
	groundTex->load("../assets/images/baldosaC.png",1);
	Ground* ground = new Ground(500.0, 500.0, groundTex);

	//Interior de la Caja 
	boxTex = new Texture();
	boxTex->load("../assets/images/container.jpg", 1);
	//Exterior de la caja
	boxTexInterior = new Texture();
	boxTexInterior->load("../assets/images/papelE.png", 1);

	BoxOutline* cube = new BoxOutline(boxTex, boxTexInterior, 100.0);
	// Posicionarla en la escena
	glm::mat4 M = glm::translate(glm::mat4(1.0f), glm::vec3(130, 51, -60));
	cube->setModelMat(M);


	starTex = new Texture();
	starTex->load("../assets/images/rueda.png", 1);
	Star3D* star = new Star3D(20.0, 8, 30.0, starTex);	
	// Posicionarla en la escena
	star->setPosition(glm::vec3(130.0f, 60.0f, -60.0f));


	Photo* photo = new Photo(800, 600, 100.0, 100.0);
	glm::mat4 Mp = glm::translate(glm::mat4(1.0f), glm::vec3(0.0f, 1.0f, 0.0f));
	photo->setModelMat(Mp);

	//cubo translúcido
	glassTex = new Texture();
	glassTex->load("../assets/images/windowC.png", 180);

	GlassParapet* glass = new GlassParapet(125.0, glassTex);
	glm::mat4 Mg = glm::translate(glm::mat4(1.0f), glm::vec3(0.0f, 0.0f, 0.0f));
	Mg = glm::scale(Mg, glm::vec3(4.0f, 1.0f, 4.0f));
	glass->setModelMat(Mg);


	

	// Añadirla al vector de entidades
	
	gObjects.push_back(star);
	gObjects.push_back(cube);
	gObjects.push_back(ground);
	gObjects.push_back(glass);
	gObjects.push_back(photo);
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

	delete glassTex;
	glassTex = nullptr;

}

void Scene4::update()
{
	Scene::update();
	for (Abs_Entity* obj : gObjects)
		obj->update();
}
