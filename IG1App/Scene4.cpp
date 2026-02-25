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


	boxTex = new Texture();
	boxTex->load("../assets/images/papelE.png", 1);
	BoxOutline* cube = new BoxOutline(boxTex,100.0);
	glm::mat4 M = glm::translate(glm::mat4(1.0f), glm::vec3(0, 50, 0));
	cube->setModelMat(M);

	// Textura interior
	Texture* texInterior = new Texture();
	texInterior->load("../assets/images/container.jpg", 1);

	// Caja con dos texturas
	//BoxOutline* cube = new BoxOutline(100.0, texExterior);
	//cube->setInnerTexture(texInterior);
	//

	Star3D* star = new Star3D(100.0, 8, 50.0, glm::dvec4(1, 1, 0, 1));
	
	// Posicionarla en la escena
	star->setModelMat(glm::translate(glm::dmat4(1.0), glm::dvec3(0.0, 200.0, 0.0)));

	// Añadirla al vector de entidades
	gObjects.push_back(star);



	//gObjects.push_back(cube);
	//gObjects.push_back(ground);

}

Scene4::~Scene4()
{
	delete groundTex;
	groundTex = nullptr;

	delete boxTex;
	boxTex = nullptr;

	//delete texInterior
	//	texInterior = nullptr;


}

//void Scene4::update()
//{
//	Scene::update();   
//}

void Scene4::update()
{
	Scene::update();
	for (auto obj : gObjects)
		obj->update();

}
//gObjects.push_back(new BoxCubeOpen(100.0));

	//gObjects.push_back(new Ground(300.0, 300.0, nullptr));