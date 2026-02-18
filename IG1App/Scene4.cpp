#include "Scene4.h"
#include "Ground.h"

void Scene4::init() {
	Scene::init();

	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

	gObjects.push_back(new RGBAxes(300.0));
	gObjects.push_back(new Ground(600.0, 600.0, nullptr));

}

void Scene4::update()
{
	Scene::update();   // opcional si no haces nada especial
}
