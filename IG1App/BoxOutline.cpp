#include "BoxOutline.h"
#include "Entity.h"
#include "Shader.h"


//BoxOutline::BoxOutline(GLdouble length) : SingleColorEntity(glm::vec4())
//{
//    
//    mMesh = Mesh::generateBoxOutline(length);
//    
//}


BoxOutline::BoxOutline(Texture* tex, GLdouble length) : EntityWithTexture(tex)
{
	mMesh = Mesh::generateBoxOutlineTexCor(length);
}

//void
//BoxOutline::render(glm::mat4 const& modelViewMat) const
//{
//	//if (mMesh != nullptr) {
//	//	glm::mat4 aMat = modelViewMat * mModelMat; // glm matrix multiplication
//	//	mShader->use();
//	//	upload(aMat);
//	//	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
//	//	mMesh->render();
//	//	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
//	//}
//	if (mMesh != nullptr && mShader != nullptr) {
//		glm::mat4 aMat = modelViewMat * mModelMat;
//		mShader->use();
//		upload(aMat);
//		glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
//		mMesh->render();
//		// si quieres el contorno encima:
//		glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
//		mMesh->render();
//		glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
//	}
//}
void BoxOutline::render(glm::mat4 const& modelViewMat) const {
    // primero renderiza con textura (relleno)
    EntityWithTexture::render(modelViewMat);

    // luego dibuja el contorno encima
    if (mMesh != nullptr && mShader != nullptr) {
        glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
        mMesh->render();
        glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
    }
}