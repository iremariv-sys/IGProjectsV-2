//#include "Star3D.h"
//
//#include "Mesh.h"
//
//
//Star3D::Star3D(GLdouble re, GLuint np, GLdouble h, glm::dvec4 const& color)
//    : SingleColorEntity(color), mRe(re), mNp(np), mH(h)
//{
//    // Generamos la estrella superior en z = +h
//    mMesh = Mesh::generateStar3D(re, np, h);
//}
//void Star3D::render(glm::mat4 const& modelViewMat) const {
//    if (mMesh == nullptr || mShader == nullptr) return;
//
//    glm::mat4 aMat = modelViewMat * mModelMat;
//    mShader->use();
//    upload(aMat);
//
//    glPolygonMode(GL_FRONT_AND_BACK, GL_LINE); // contorno
//
//    mMesh->render();
//    //mMeshLower->render();
//
//    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL); // restaurar
//}
#include "Star3D.h"
#include <glm/gtc/matrix_transform.hpp> 
#include "Mesh.h"


//Star3D::Star3D(GLdouble re, GLuint np, GLdouble h, glm::dvec4 const& color)
//    : SingleColorEntity(color), mRe(re), mNp(np), mH(h)
//{
//    // Generamos la estrella superior en z = +h
//    mMesh = Mesh::generateStar3D(re, np, h);
//}
Star3D::Star3D(GLdouble re, GLuint np, GLdouble h, glm::dvec4 const& color)
    : SingleColorEntity(color), mRe(re), mNp(np), mH(h), mPos(0.0f, 200.0f, 0.0f)
{
    mMesh = Mesh::generateStar3D(re, np, h);
}
//void Star3D::render(glm::mat4 const& modelViewMat) const
//{
//    if (mMesh == nullptr || mShader == nullptr) return;
//
//    mShader->use();
//    mShader->setUniform("color", mColor);
//
//    glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
//
//    // Estrella superior (z = +h)
//    glm::mat4 aMat = modelViewMat * mModelMat;
//    upload(aMat);
//    mMesh->render();
//
//    // Estrella inferior (reflejada respecto al origen)
//    glm::mat4 mirrorMat = glm::scale(glm::dmat4(1.0), glm::dvec3(1.0, 1.0, -1.0));
//    glm::mat4 bMat = modelViewMat * mModelMat * glm::mat4(mirrorMat);
//    upload(bMat);
//    mMesh->render();
//
//    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
//}
void Star3D::render(glm::mat4 const& modelViewMat) const
{
    if (mMesh == nullptr || mShader == nullptr) return;

    mShader->use();
    mShader->setUniform("color", mColor);

    glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

    // Estrella superior
    glm::mat4 aMat = mModelMat;   // usar solo la matriz del objeto
    upload(aMat);
    mMesh->render();

    // Estrella inferior
    glm::mat4 mirrorMat = glm::scale(glm::mat4(1.0f), glm::vec3(1.0f, 1.0f, -1.0f));
    glm::mat4 bMat = mModelMat * mirrorMat;
    upload(bMat);
    mMesh->render();

    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
}

void Star3D::update()
{
    static float angY = 0.0f;
    static float angZ = 0.0f;

    angY += 2.0f;
    angZ += 5.0f;

    mModelMat = glm::mat4(1.0f);
   mModelMat = glm::translate(mModelMat, mPos);  // usa la posición guardada
    mModelMat = glm::rotate(mModelMat, glm::radians(angY), glm::vec3(0, 1, 0));
    mModelMat = glm::rotate(mModelMat, glm::radians(angZ), glm::vec3(0, 0, 1));
}