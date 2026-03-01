#include "Scene4.h"
#include "Ground.h"
#include "BoxOutline.h"
#include "Star3D.h"
#include "Shader.h"
#include "Box.h"
#include <glm/ext/matrix_transform.hpp>
#include <GLFW/glfw3.h>
#include "GlassParapet.h"
#include "Photo.h"
#include "IG1App.h"
#include "Grass.h"

void Scene4::init() {
	Scene::init();

	gObjects.push_back(new RGBAxes(300.0));

	groundTex = new Texture();
	groundTex->load("../assets/images/baldosaC.png", 1);
	Ground* ground = new Ground(500.0, 500.0, groundTex);

	// Texturas de la caja (BoxOutline - paredes)
	boxTex = new Texture();
	boxTex->load("../assets/images/container.jpg", 1);
	boxTexInterior = new Texture();
	boxTexInterior->load("../assets/images/papelE.png", 1);

	// Texturas de la tapa y fondo (Box)
	boxLidTex = new Texture();
	boxLidTex->load("../assets/images/papelE.png", 1);   
	boxLidTexInterior = new Texture();
	boxLidTexInterior->load("../assets/images/container.jpg", 1); 

	// Posición compartida por BoxOutline y Box
	glm::mat4 M = glm::translate(glm::mat4(1.0f), glm::vec3(130, 51, -60));

	// BoxOutline: las 4 paredes laterales
	BoxOutline* outline = new BoxOutline(boxTex, boxTexInterior, 100.0);
	outline->setModelMat(M);

	// Box: tapa animada (abre/cierra 180°) + fondo estático
	Box* cube = new Box(boxLidTex, boxLidTexInterior, 100.0);
	cube->setModelMat(M);

	starTex = new Texture();
	starTex->load("../assets/images/rueda.png", 1);
	Star3D* star = new Star3D(20.0, 8, 30.0, starTex);
	star->setPosition(glm::vec3(130.0f, 60.0f, -60.0f));

	Photo* photo = new Photo(800, 600, 100.0, 100.0);
	glm::mat4 Mp = glm::translate(glm::mat4(1.0f), glm::vec3(0.0f, 1.0f, 0.0f));
	photo->setModelMat(Mp);

	glassTex = new Texture();
	glassTex->load("../assets/images/windowC.png", 180);
	GlassParapet* glass = new GlassParapet(125.0, glassTex);
	glm::mat4 Mg = glm::scale(glm::mat4(1.0f), glm::vec3(4.0f, 1.0f, 4.0f));
	glass->setModelMat(Mg);


	// Textura hierba (con fondo transparente)
	grassTex = new Texture();
	grassTex->load("../assets/images/grass.png", 255);

	Grass* grass = new Grass(80.0, 120.0, grassTex);
	glm::mat4 Mgrass = glm::translate(glm::mat4(1.0f), glm::vec3(-91.0f, 0.0f, 60.0f)); // solo posición XZ en el mundo
	grass->setModelMat(Mgrass);


	


	// Añadir al vector de entidades
	gObjects.push_back(star);
	gObjects.push_back(outline); // 4 paredes
	gObjects.push_back(cube);    // tapa animada + fondo
	gObjects.push_back(ground);
	gObjects.push_back(grass);
	gObjects.push_back(glass);
	gObjects.push_back(photo);
}

Scene4::~Scene4()
{
	delete groundTex;         
	groundTex = nullptr;
	delete boxTex;             
	boxTex    = nullptr;
	delete boxTexInterior;     
	boxTexInterior  = nullptr;
	delete boxLidTex;         
	boxLidTex = nullptr;
	delete boxLidTexInterior;  
	boxLidTexInterior  = nullptr;
	delete starTex;            
	starTex            = nullptr;
	delete glassTex;           
	glassTex           = nullptr;
	delete grassTex;           
	grassTex           = nullptr;
}

void Scene4::update()
{
	Scene::update(); 
}
