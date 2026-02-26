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
	
};
