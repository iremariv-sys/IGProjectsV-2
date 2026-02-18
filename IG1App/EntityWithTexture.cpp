#include "EntityWithTexture.h"


EntityWithTexture::EntityWithTexture(Texture* tex, bool modulate)
    : EntityWithColors()
{
    mTexture = tex;
    mModulate = modulate;

    mShader = Shader::get("texture");
}

void EntityWithTexture::render(glm::mat4 const& modelViewMat) const
{
    if (mMesh == nullptr || mShader == nullptr)
        return;

    glm::mat4 aMat = modelViewMat * mModelMat;

    mShader->use();
    mShader->setUniform("modelView", aMat);
    mShader->setUniform("modulate", mModulate);

    if (mTexture != nullptr)
    {
        glActiveTexture(GL_TEXTURE0);
        mTexture->bind();
        //mShader->setUniform("tex", 0);  // 
        mShader->setUniform("tex", 0);

    }

    mMesh->render();

    if (mTexture != nullptr)
        mTexture->unbind();
}



