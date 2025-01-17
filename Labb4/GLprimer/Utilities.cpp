/*
 * Useful helper functions for the course TNM046
 * Author: Stefan Gustavson 2013-2014 (stefan.gustavson@liu.se)
 * This code is in the public domain.
 *
 * The function pointer loading for all OpenGL extensions,
 * the code in loadExtensions(), is forced upon us by
 * Microsoft Windows. MacOS and Linux don't need that.
 * A more general project would use GLEW, but we choose to
 * stay clear of that dependence. GLEW is a large library
 * that hides a lot of details from the programmer, and it
 * is instructive to see what it hides - if nothing else to
 * better appreciate GLEW as a tool for OpenGL programming
 * under Windows.
 *
 */

#include <cstdio>  // For console messages
#include <cmath>

#include "Utilities.hpp"

#ifdef __WIN32__
/* Global function pointers for everything we need beyond OpenGL 1.1 */
PFNGLCREATEPROGRAMPROC            glCreateProgram      = NULL;
PFNGLDELETEPROGRAMPROC            glDeleteProgram      = NULL;
PFNGLUSEPROGRAMPROC               glUseProgram         = NULL;
PFNGLCREATESHADERPROC             glCreateShader       = NULL;
PFNGLDELETESHADERPROC             glDeleteShader       = NULL;
PFNGLSHADERSOURCEPROC             glShaderSource       = NULL;
PFNGLCOMPILESHADERPROC            glCompileShader      = NULL;
PFNGLGETSHADERIVPROC              glGetShaderiv        = NULL;
PFNGLGETPROGRAMIVPROC             glGetProgramiv       = NULL;
PFNGLATTACHSHADERPROC             glAttachShader       = NULL;
PFNGLGETSHADERINFOLOGPROC         glGetShaderInfoLog   = NULL;
PFNGLGETPROGRAMINFOLOGPROC        glGetProgramInfoLog  = NULL;
PFNGLLINKPROGRAMPROC              glLinkProgram        = NULL;
PFNGLGETUNIFORMLOCATIONPROC       glGetUniformLocation = NULL;
PFNGLUNIFORM1FPROC                glUniform1f          = NULL;
PFNGLUNIFORM1FVPROC               glUniform1fv         = NULL;
PFNGLUNIFORM1IPROC                glUniform1i          = NULL;
PFNGLUNIFORMMATRIX4FVPROC         glUniformMatrix4fv   = NULL;
PFNGLGENBUFFERSPROC               glGenBuffers         = NULL;
PFNGLISBUFFERPROC                 glIsBuffer           = NULL;
PFNGLBINDBUFFERPROC               glBindBuffer         = NULL;
PFNGLBUFFERDATAPROC               glBufferData         = NULL;
PFNGLDELETEBUFFERSPROC            glDeleteBuffers      = NULL;
PFNGLGENVERTEXARRAYSPROC          glGenVertexArrays    = NULL;
PFNGLISVERTEXARRAYPROC            glIsVertexArray      = NULL;
PFNGLBINDVERTEXARRAYPROC          glBindVertexArray    = NULL;
PFNGLDELETEVERTEXARRAYSPROC       glDeleteVertexArrays = NULL;
PFNGLENABLEVERTEXATTRIBARRAYPROC  glEnableVertexAttribArray  = NULL;
PFNGLVERTEXATTRIBPOINTERPROC      glVertexAttribPointer      = NULL;
PFNGLDISABLEVERTEXATTRIBARRAYPROC glDisableVertexAttribArray = NULL;
PFNGLGENERATEMIPMAPPROC           glGenerateMipmap           = NULL;
#endif


/*
 * printError() - Signal an error.
 * Simple printf() to console for portability.
 */
void Utilities::printError(const char *errtype, const char *errmsg) {
  fprintf(stderr, "%s: %s\n", errtype, errmsg);
}


/*
 * loadExtensions() - Load OpenGL extensions for anything above OpenGL
 * version 1.1. (This is a requirement only on Windows, so on other
 * platforms, this function does nothing.)
 */
void Utilities::loadExtensions() {
    //These extension strings indicate that the OpenGL Shading Language
    // and GLSL shader objects are supported.
#ifdef __WIN32__
    glCreateProgram      = (PFNGLCREATEPROGRAMPROC)glfwGetProcAddress("glCreateProgram");
    glDeleteProgram      = (PFNGLDELETEPROGRAMPROC)glfwGetProcAddress("glDeleteProgram");
    glUseProgram         = (PFNGLUSEPROGRAMPROC)glfwGetProcAddress("glUseProgram");
    glCreateShader       = (PFNGLCREATESHADERPROC)glfwGetProcAddress("glCreateShader");
    glDeleteShader       = (PFNGLDELETESHADERPROC)glfwGetProcAddress("glDeleteShader");
    glShaderSource       = (PFNGLSHADERSOURCEPROC)glfwGetProcAddress("glShaderSource");
    glCompileShader      = (PFNGLCOMPILESHADERPROC)glfwGetProcAddress("glCompileShader");
    glGetShaderiv        = (PFNGLGETSHADERIVPROC)glfwGetProcAddress("glGetShaderiv");
    glGetShaderInfoLog   = (PFNGLGETSHADERINFOLOGPROC)glfwGetProcAddress("glGetShaderInfoLog");
    glAttachShader       = (PFNGLATTACHSHADERPROC)glfwGetProcAddress("glAttachShader");
    glLinkProgram        = (PFNGLLINKPROGRAMPROC)glfwGetProcAddress("glLinkProgram");
    glGetProgramiv       = (PFNGLGETPROGRAMIVPROC)glfwGetProcAddress("glGetProgramiv");
    glGetProgramInfoLog  = (PFNGLGETPROGRAMINFOLOGPROC)glfwGetProcAddress("glGetProgramInfoLog");
    glGetUniformLocation = (PFNGLGETUNIFORMLOCATIONPROC)glfwGetProcAddress("glGetUniformLocation");
    glUniform1f          = (PFNGLUNIFORM1FPROC)glfwGetProcAddress("glUniform1f");
    glUniform1fv         = (PFNGLUNIFORM1FVPROC)glfwGetProcAddress("glUniform1fv");
    glUniform1i          = (PFNGLUNIFORM1IPROC)glfwGetProcAddress("glUniform1i");
	glUniformMatrix4fv   = (PFNGLUNIFORMMATRIX4FVPROC)glfwGetProcAddress("glUniformMatrix4fv");

    if( !glCreateProgram || !glDeleteProgram || !glUseProgram ||
        !glCreateShader || !glDeleteShader || !glShaderSource || !glCompileShader ||
        !glGetShaderiv || !glGetShaderInfoLog || !glAttachShader || !glLinkProgram ||
        !glGetProgramiv || !glGetProgramInfoLog || !glGetUniformLocation ||
        !glUniform1fv || !glUniform1f || !glUniform1i || !glUniformMatrix4fv )
    {
        printError("GL init error", "One or more required OpenGL shader-related functions were not found");
        return;
    }

	glGenBuffers               = (PFNGLGENBUFFERSPROC)glfwGetProcAddress("glGenBuffers");
	glIsBuffer                 = (PFNGLISBUFFERPROC)glfwGetProcAddress("glIsBuffer");
	glBindBuffer               = (PFNGLBINDBUFFERPROC)glfwGetProcAddress("glBindBuffer");
	glBufferData               = (PFNGLBUFFERDATAPROC)glfwGetProcAddress("glBufferData");
	glDeleteBuffers            = (PFNGLDELETEBUFFERSPROC)glfwGetProcAddress("glDeleteBuffers");
	glGenVertexArrays          = (PFNGLGENVERTEXARRAYSPROC)glfwGetProcAddress("glGenVertexArrays");
	glIsVertexArray            = (PFNGLISVERTEXARRAYPROC)glfwGetProcAddress("glIsVertexArray");
	glBindVertexArray          = (PFNGLBINDVERTEXARRAYPROC)glfwGetProcAddress("glBindVertexArray");
	glDeleteVertexArrays       = (PFNGLDELETEVERTEXARRAYSPROC)glfwGetProcAddress("glDeleteVertexArrays");
	glEnableVertexAttribArray  = (PFNGLENABLEVERTEXATTRIBARRAYPROC)glfwGetProcAddress("glEnableVertexAttribArray");
	glVertexAttribPointer      = (PFNGLVERTEXATTRIBPOINTERPROC)glfwGetProcAddress("glVertexAttribPointer");
	glDisableVertexAttribArray = (PFNGLDISABLEVERTEXATTRIBARRAYPROC)glfwGetProcAddress("glDisableVertexAttribArray");

	if( !glGenBuffers || !glIsBuffer || !glBindBuffer || !glBufferData || !glDeleteBuffers ||
	    !glGenVertexArrays || !glIsVertexArray || !glBindVertexArray || !glDeleteVertexArrays ||
		!glEnableVertexAttribArray || !glVertexAttribPointer ||
		!glDisableVertexAttribArray )
    	{
	   		printError("GL init error", "One or more required OpenGL vertex array functions were not found");
            return;
        }

	glGenerateMipmap = (PFNGLGENERATEMIPMAPPROC)glfwGetProcAddress("glGenerateMipmap");
	if( !glGenerateMipmap)
    	{
	   		printError("GL init error", "The required OpenGL function glGenerateMipmap() was not found");
            return;
        }
#endif
}


/*
 * displayFPS() - Calculate, display and return frame rate statistics.
 * Called every frame, but statistics are updated only once per second.
 * The time per frame is a better measure of performance than the
 * number of frames per second, so both are displayed.
 *
 * NOTE: This function doesn't work properly if you call it for multiple
 * windows. Call it only for one window, and only once for each frame.
 */
double Utilities::displayFPS(GLFWwindow *window) {

    static double t0 = 0.0;
    static int frames = 0;
    double fps = 0.0;
    double frametime = 0.0;
    static char titlestring[200];

    double t;

    // Get current time
    t = glfwGetTime();  // Gets number of seconds since glfwInit()
    // If one second has passed, or if this is the very first frame
    if( (t-t0) > 1.0 || frames == 0 )
    {
        fps = (double)frames / (t-t0);
        if(frames > 0) frametime = 1000.0 * (t-t0) / frames;
        sprintf(titlestring, "TNM046, %.2f ms/frame (%.1f FPS)", frametime, fps);
        glfwSetWindowTitle(window, titlestring);
        // printf("Speed: %.1f FPS\n", fps);
        t0 = t;
        frames = 0;
    }
    frames ++;
    return fps;
}

void Utilities::mat4mult(float M2[], float M1[], float Mout[]) {

    float Mtemp[16];

    Mtemp[0] = M1[0]*M2[0]+M1[1]*M2[4]+M1[2]*M2[8]+M1[3]*M2[12];
    Mtemp[1] = M1[0]*M2[1]+M1[1]*M2[5]+M1[2]*M2[9]+M1[3]*M2[13];
    Mtemp[2] = M1[0]*M2[2]+M1[1]*M2[6]+M1[2]*M2[10]+M1[3]*M2[14];
    Mtemp[3] = M1[0]*M2[3]+M1[1]*M2[7]+M1[2]*M2[11]+M1[3]*M2[15];

    Mtemp[4] = M1[4]*M2[0]+M1[5]*M2[4]+M1[6]*M2[8]+M1[7]*M2[12];
    Mtemp[5] = M1[4]*M2[1]+M1[5]*M2[5]+M1[6]*M2[9]+M1[7]*M2[13];
    Mtemp[6] = M1[4]*M2[2]+M1[5]*M2[6]+M1[6]*M2[10]+M1[7]*M2[14];
    Mtemp[7] = M1[4]*M2[3]+M1[5]*M2[7]+M1[6]*M2[11]+M1[7]*M2[15];

    Mtemp[8] = M1[8]*M2[0]+M1[9]*M2[4]+M1[10]*M2[8]+M1[11]*M2[12];
    Mtemp[9] = M1[8]*M2[1]+M1[9]*M2[5]+M1[10]*M2[9]+M1[11]*M2[13];
    Mtemp[10] = M1[8]*M2[2]+M1[9]*M2[6]+M1[10]*M2[10]+M1[11]*M2[14];
    Mtemp[11] = M1[8]*M2[3]+M1[9]*M2[7]+M1[10]*M2[11]+M1[11]*M2[15];

    Mtemp[12] = M1[12]*M2[0]+M1[13]*M2[4]+M1[14]*M2[8]+M1[15]*M2[12];
    Mtemp[13] = M1[12]*M2[1]+M1[13]*M2[5]+M1[14]*M2[9]+M1[15]*M2[13];
    Mtemp[14] = M1[12]*M2[2]+M1[13]*M2[6]+M1[14]*M2[10]+M1[15]*M2[14];
    Mtemp[15] = M1[12]*M2[3]+M1[13]*M2[7]+M1[14]*M2[11]+M1[15]*M2[15];

    for(int i = 0; i < 16; i++){
        Mout[i] = Mtemp[i];
    }
}

void Utilities::mat4identity(float M[]) {

    for(int i = 0; i < 16; i++){
        M[i] = 0;
        if( i % 5 == 0 ){
            M[i] = 1;
        }
    }
}

void Utilities::mat4rotx(float M[], float angle) {

    mat4identity(M);

    M[5] = cos(angle);
    M[6] = sin(angle);
    M[9] = -sin(angle);
    M[10] = cos(angle);
}
void Utilities::mat4roty(float M[], float angle) {

    mat4identity(M);

    M[0] = cos(angle);
    M[2] = -sin(angle);
    M[8] = sin(angle);
    M[10] = cos(angle);
}

void Utilities::mat4rotz(float M[], float angle) {

    mat4identity(M);

    M[0] = cos(angle);
    M[1] = sin(angle);
    M[4] = -sin(angle);
    M[5] = cos(angle);
}

void Utilities::mat4scale(float M[], float scale) {

    mat4identity(M);

    M[0] = scale;
    M[5] = scale;
    M[10] = scale;
}

void Utilities::mat4translate(float M[], float x, float y, float z) {

    mat4identity(M);

    M[12] = x;
    M[13] = y;
    M[14] = z;
}

void Utilities::mat4perspective(float M[], float vfov, float aspect, float znear, float zfar) {

    mat4identity(M);

    float f = 1/tan(vfov/2);

    M[0] = f/aspect;

    M[5] = f;

    M[10] = -(zfar+znear)/(zfar-znear);

    M[11] = -1;

    M[14] = -(2*zfar*znear)/(zfar-znear);

}



