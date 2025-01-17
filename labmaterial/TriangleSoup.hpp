#include <GLFW/glfw3.h>   // To use OpenGL datatypes

#include "Utilities.hpp"  // To be able to use OpenGL extensions

/* A struct to hold geometry data and send it off for rendering */
class TriangleSoup {

private:

    // All data members are private. They are accessed only by methods in the class.
    GLuint vao;          // Vertex array object, the main handle for geometry
    int nverts; // Number of vertices in the vertex array
    int ntris;  // Number of triangles in the index array (may be zero)
    GLuint vertexbuffer; // Buffer ID to bind to GL_ARRAY_BUFFER
    GLuint indexbuffer;  // Buffer ID to bind to GL_ELEMENT_ARRAY_BUFFER
    GLfloat *vertexarray; // Vertex array on interleaved format: x y z nx ny nz s t
    GLuint *indexarray;   // Element index array

public:

/* Constructor: initialize a triangleSoup object to all zeros */
TriangleSoup();

/* Destructor: clean up allocated data in a triangleSoup object */
~TriangleSoup();

/* Clean up allocated data in a triangleSoup object */
void clean();

/* Create a very simple demo mesh with a single triangle */
void createTriangle();

/* Create a simple box geometry */
void createBox(float xsize, float ysize, float zsize);

/* Create a sphere (approximated by polygon segments) */
void createSphere(float radius, int segments);

/* Load geometry from an OBJ file */
void readOBJ(const char* filename);

/* Print data from a triangleSoup object, for debugging purposes */
void print();

/* Print information about a triangleSoup object (stats and extents) */
void printInfo();

/* Render the geometry in a triangleSoup object */
void render();

private:

void printError(const char *errtype, const char *errmsg);

};
