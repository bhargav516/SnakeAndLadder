    #ifndef _TEXTURELOADER
    #define TEXTURELOADER

    #include <GL/glew.h>
#include <GL/gl.h>
#include <GL/glu.h>

#include <GLFW/glfw3.h>
    
    #include <fstream>

    enum imagetype {BMP, TGA, DDS};

    #define FOURCC_DXT1 0x31545844 // Equivalent to "DXT1" in ASCII
    #define FOURCC_DXT3 0x33545844 // Equivalent to "DXT3" in ASCII
    #define FOURCC_DXT5 0x35545844 // Equivalent to "DXT5" in ASCII

    class TEXTURE
    {

    public:

        float posX;
        float posY;

        GLuint loadFromFile(const char* filename, imagetype extension); // Returns a texture ID; Accepted extensions: BMP, JPG, TGA, PNG, DDS

        GLuint rotate(float degrees); // Positive for clockwise, negative for counterclockwise
        GLuint scale(float multiplier); // Positve for growth, negative for shrinkage
        GLuint move(float x, float y); // Moves the texure x, y

        GLuint setCenter(float x, float y); // Sets centerpoint of texture, used for rotating

        float getPosX();
        float getPosY();

        imagetype getExtension();
        float* getCenter();
    };
