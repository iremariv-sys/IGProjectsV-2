#include "Star3D.h"

#include "Mesh.h"


Star3D::Star3D(GLdouble re, GLuint np, GLdouble h, glm::dvec4 const& color)
    : SingleColorEntity(color), mRe(re), mNp(np), mH(h)
{
    // Generamos la estrella superior en z = +h
    mMesh = Mesh::generateStar3D(re, np, h);
}
void Star3D::render(glm::mat4 const& modelViewMat) const {
    if (mMesh == nullptr || mShader == nullptr) return;

    glm::mat4 aMat = modelViewMat * mModelMat;
    mShader->use();
    upload(aMat);

    glPolygonMode(GL_FRONT_AND_BACK, GL_LINE); // contorno

    mMesh->render();
    //mMeshLower->render();

    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL); // restaurar
}