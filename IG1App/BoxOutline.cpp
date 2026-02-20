#include "BoxOutline.h"
#include "Entity.h"


BoxOutline::BoxOutline(GLdouble length) : SingleColorEntity(glm::vec4())
{
    
    mMesh = Mesh::generateBoxOutline(length);
    
}