
#include "Photo.h"

Photo::Photo(GLsizei winW, GLsizei winH, GLdouble w, GLdouble h)
    : EntityWithTexture(new Texture(), false)
    , mWinW(winW)
    , mWinH(winH)
{
    //sobre el suelo, textura 1×1
    mMesh = Mesh::generaRectangleTexCor(w, h, 1, 1);
}

Photo::~Photo()
{
    delete mTexture;
    mTexture = nullptr;
}

void Photo::render(glm::mat4 const& modelViewMat) const
{
    
    if (mTexture != nullptr)
        mTexture->loadColorBuffer(mWinW, mWinH, GL_BACK);

    // Usar la implementación de la clase base para bind + draw
    EntityWithTexture::render(modelViewMat);
}