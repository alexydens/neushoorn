/* Include guard */
#if !defined(NH_TEXTURE_H)
#define NH_TEXTURE_H

/* Base library */
#include "base.h"
/* Shaders */
#include "shader.h"

/* OpenGL */
#include <GLES3/gl3.h>

/* SDL2 image */
#include <SDL2/SDL_image.h>

/* Texture structure */
typedef struct {
  u32* textures;
  u32 numTextures;
} Texture;

/* Create a texture */
Texture createTexture(
    const char** fileNames,
    const char** shaderNames,
    u32 numTextures,
    ShaderHandle shader);

/* Destroy a texture */
void destroyTexture(Texture* texture);

/* Bind texture */
void bindTexture(Texture* texture);

#endif /* NH_TEXTURE_H */
