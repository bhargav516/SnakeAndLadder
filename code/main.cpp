#include "texture.h"

TEXTURE texture1;

int main( void )
{
    ...
    GLuint Texture = texture1.loadFromFile("3t223-kpzbs.dds", DDS);

    ...

    do{
            ...
    }
    while( glfwGetKey( GLFW_KEY_ESC ) != GLFW_PRESS && 
        glfwGetWindowParam( GLFW_OPENED ) );

    glfwTerminate();

    glDeleteBuffers(1, &vertexbuffer);
    glDeleteBuffers(1, &uvbuffer);
    glDeleteProgram(programID);
    glDeleteTextures(1, &TextureID);
    glDeleteVertexArrays(1, &VertexArrayID);

    return 0;
}
