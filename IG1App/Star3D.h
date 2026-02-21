#include "SingleColorEntity.h"
#include "Mesh.h"


class Star3D : public SingleColorEntity {
public:
    // Constructor: recibe radio exterior, nº de puntas, altura y color
    //Star3D(GLdouble re, GLuint np, GLdouble h, glm::vec4 const& color);

    //Star3D(GLdouble re, GLuint np, GLdouble h, glm::dvec4 const& color);

    Star3D(GLdouble re, GLuint np, GLdouble h, glm::dvec4 const& color);

    // Sobrescribe el render para dibujar dos estrellas unidas por el origen
    void render(glm::mat4 const& modelViewMat) const override;

private:
    GLdouble mRe;   // radio exterior
    GLuint   mNp;   // número de puntas
    GLdouble mH;    // altura (z = +h y z = -h)
};