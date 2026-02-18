#include "Mesh.h"

using namespace std;
using namespace glm;

// Placeholder for the pending index of a GPU object
constexpr GLuint NONE = numeric_limits<GLuint>::max();

Mesh::Mesh()
	: mVAO(NONE)
	, mVBO(NONE)
	, mCBO(NONE)
{
}

Mesh::~Mesh()
{
	unload();
}

void
Mesh::draw() const
{
	glDrawArrays(
		mPrimitive,
		0,
		size()); // primitive graphic, first index and number of elements to be rendered
}

void
Mesh::load()
{
	assert(mVBO == NONE); // not already loaded
	if (vVertices.size() > 0) { // transfer data
		glGenBuffers(1, &mVBO);
		glGenVertexArrays(1, &mVAO);

		glBindVertexArray(mVAO);
		glBindBuffer(GL_ARRAY_BUFFER, mVBO);
		glBufferData(GL_ARRAY_BUFFER, vVertices.size() * sizeof(vec3), vVertices.data(), GL_STATIC_DRAW);
		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(vec3), nullptr);
		glEnableVertexAttribArray(0);

		if (vColors.size() > 0) {             // upload colors
			glGenBuffers(1, &mCBO);

			glBindBuffer(GL_ARRAY_BUFFER, mCBO);
			glBufferData(GL_ARRAY_BUFFER, vColors.size() * sizeof(vec4), vColors.data(), GL_STATIC_DRAW);
			glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, sizeof(vec4), nullptr);
			glEnableVertexAttribArray(1);
		}
	}
}

void
Mesh::unload()
{
	if (mVAO != NONE) {
		glDeleteVertexArrays(1, &mVAO);
		glDeleteBuffers(1, &mVBO);
		mVAO = NONE;
		mVBO = NONE;

		if (mCBO != NONE) {
			glDeleteBuffers(1, &mCBO);
			mCBO = NONE;
		}
	}
}

void
Mesh::render() const
{
	assert(mVAO != NONE);

	glBindVertexArray(mVAO);
	draw();
}

Mesh*
Mesh::createRGBAxes(GLdouble l)
{
	Mesh* mesh = new Mesh();

	mesh->mPrimitive = GL_LINES;

	mesh->mNumVertices = 6;
	mesh->vVertices.reserve(mesh->mNumVertices);

	// X axis vertices
	mesh->vVertices.emplace_back(0.0, 0.0, 0.0);
	mesh->vVertices.emplace_back(l, 0.0, 0.0);
	// Y axis vertices
	mesh->vVertices.emplace_back(0, 0.0, 0.0);
	mesh->vVertices.emplace_back(0.0, l, 0.0);
	// Z axis vertices
	mesh->vVertices.emplace_back(0.0, 0.0, 0.0);
	mesh->vVertices.emplace_back(0.0, 0.0, l);

	mesh->vColors.reserve(mesh->mNumVertices);
	// X axis color: red  (Alpha = 1 : fully opaque)
	mesh->vColors.emplace_back(1.0, 0.0, 0.0, 1.0);
	mesh->vColors.emplace_back(1.0, 0.0, 0.0, 1.0);
	// Y axis color: green
	mesh->vColors.emplace_back(0.0, 1.0, 0.0, 1.0);
	mesh->vColors.emplace_back(0.0, 1.0, 0.0, 1.0);
	// Z axis color: blue
	mesh->vColors.emplace_back(0.0, 0.0, 1.0, 1.0);
	mesh->vColors.emplace_back(0.0, 0.0, 1.0, 1.0);

	return mesh;
}

Mesh* Mesh::generateRegularPolygon(GLuint num, GLdouble r)
{
	Mesh* mesh = new Mesh();
	mesh->mPrimitive = GL_LINE_LOOP;
	mesh->mNumVertices = num;

	mesh->vVertices.reserve(num);

	double angulo = 90.0;              // grados
	double incremento = 360.0 / num;   // grados

	for (GLuint i = 0; i < num; ++i)
	{
		double rad = glm::radians(angulo);

		double x = r * cos(rad);
		double y = r * sin(rad);

		mesh->vVertices.emplace_back(x, y, 0.0);

		angulo += incremento;
	}


	return mesh;
}


//APARTADO 7, 8  - QUEREMOS PONERLE COLOR Y HACER LA FORMA DEL TRIANGULO 
Mesh* Mesh::generateRGBTriangle(GLdouble r) { // generaos el triangulo pero tambien le damos colors 
	Mesh* m = new Mesh();
	m->mPrimitive = GL_TRIANGLES;
	m->mNumVertices = 3;


	m->vVertices.push_back(glm::vec3(0, r, 0));        // Superior
	m->vVertices.push_back(glm::vec3(-r, -r, 0));      // Inferior Izquierda
	m->vVertices.push_back(glm::vec3(r, -r, 0));       // Inferior Derecha

	m->vColors.push_back(glm::vec4(1, 0, 0, 1));       // Rojo
	m->vColors.push_back(glm::vec4(0, 1, 0, 1));       // Verde
	m->vColors.push_back(glm::vec4(0, 0, 1, 1));       // Azul

	return m;
}

Mesh* Mesh::generateRGBRectangle(GLdouble w, GLdouble h) {
	Mesh* mesh = new Mesh();
	mesh->mPrimitive = GL_TRIANGLE_STRIP; // strip para optimizar ( 4 vértices para 2 triángulos)
	mesh->mNumVertices = 4;

	GLdouble x = w / 2.0;
	GLdouble y = h / 2.0;

	// Vértices (Posiciones)
	mesh->vVertices.push_back(glm::vec3(-x, y, 0.0)); // Superior Izquierda
	mesh->vVertices.push_back(glm::vec3(-x, -y, 0.0)); // Inferior Izquierda
	mesh->vVertices.push_back(glm::vec3(x, y, 0.0)); // Superior Derecha
	mesh->vVertices.push_back(glm::vec3(x, -y, 0.0)); // Inferior Derecha


	mesh->vColors.emplace_back(0.0, 1.0, 0.0, 1.0); // V0: 
	mesh->vColors.emplace_back(1.0, 0.0, 0.0, 1.0); // V1: 
	mesh->vColors.emplace_back(0.0, 0.0, 1.0, 1.0); // V2: 
	mesh->vColors.emplace_back(0.0, 1.0, 0.0, 1.0);//V3 



	return mesh;
}


Mesh* Mesh::generateRGBCubeTriangles(GLdouble length)
{
	GLfloat l = GLfloat(length / 2.0f);

	glm::vec4 rojo = { 1, 0, 0, 1 };
	glm::vec4 verde = { 0, 1, 0, 1 };
	glm::vec4 azul = { 0, 0, 1, 1 };

	std::vector<glm::vec3> vertices = {
		{-l,-l, l}, { l,-l, l}, { l, l, l},
		{-l,-l, l}, { l, l, l}, {-l, l, l},

		{ l,-l,-l}, {-l,-l,-l}, {-l, l,-l},
		{ l,-l,-l}, {-l, l,-l}, { l, l,-l},

		{-l,-l,-l}, {-l,-l, l}, {-l, l, l},
		{-l,-l,-l}, {-l, l, l}, {-l, l,-l},

		{ l,-l, l}, { l,-l,-l}, { l, l,-l},
		{ l,-l, l}, { l, l,-l}, { l, l, l},

		{-l, l, l}, { l, l, l}, { l, l,-l},
		{-l, l, l}, { l, l,-l}, {-l, l,-l},

		{-l,-l,-l}, { l,-l,-l}, { l,-l, l},
		{-l,-l,-l}, { l,-l, l}, {-l,-l, l}
	};

	std::vector<glm::vec4> colors = {
		rojo, rojo, rojo, rojo, rojo, rojo,
		rojo, rojo, rojo, rojo, rojo, rojo,
		verde, verde, verde, verde, verde, verde,
		verde, verde, verde, verde, verde, verde,
		azul, azul, azul, azul, azul, azul,
		azul, azul, azul, azul, azul, azul
	};

	Mesh* mesh = new Mesh();
	mesh->mPrimitive = GL_TRIANGLES;
	mesh->mNumVertices = GLuint(vertices.size());
	mesh->vVertices = vertices;
	mesh->vColors = colors;

	return mesh;
}
