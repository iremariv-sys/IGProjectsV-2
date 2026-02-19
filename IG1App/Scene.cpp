#include "Scene.h"

#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include "Texture.h"
#include "Ground.h"
#include <iostream>

using namespace glm;

void
Scene::init()
{
	setGL(); // OpenGL settings

	// allocate memory and load resources
	// Lights
	// Textures

	// Graphics objects (entities) of the scene
	// --- TEXTURA DEL SUELO ---
	//Texture* groundTex = new Texture();
	//groundTex->load("./../assets/images/baldosaC.png");

	//Ground* ground = new Ground(20.0, 20.0, groundTex);
	gObjects.push_back(new RGBAxes(400.0));
}

Scene::~Scene()
{
	destroy();
	resetGL();
}

void
Scene::destroy()
{ // release memory and resources

	for (Abs_Entity* el : gObjects)
		delete el;

	gObjects.clear();
}

void
Scene::load()
{
	for (Abs_Entity* obj : gObjects)
		obj->load();
}

void
Scene::unload()
{
	for (Abs_Entity* obj : gObjects)
		obj->unload();
}

void
Scene::setGL()
{
	// OpenGL basic setting
	//glClearColor(1.0, 1.0, 1.0, 1.0); // background color (alpha=1 -> opaque)
	glClearColor(0.6f, 0.7f, 0.8f, 1.0f);
	glEnable(GL_DEPTH_TEST);          // enable Depth test
}
void
Scene::resetGL()
{
	glClearColor(.0, .0, .0, .0); // background color (alpha=1 -> opaque)
	glDisable(GL_DEPTH_TEST);     // disable Depth test
}

void
Scene::render(Camera const& cam) const
{
	cam.upload();
	std::cout << "Rendering objects..." << std::endl;
	int i = 0;
	for (Abs_Entity* el : gObjects) {
		std::cout << "Object " << i << " ptr = " << el << std::endl;
		el->render(cam.viewMat());
		i++;
	}

	//for (Abs_Entity* el : gObjects)
	//	el->render(cam.viewMat());
}

void Scene::update() {
	for (Abs_Entity* obj : gObjects)
		obj->update();
}
