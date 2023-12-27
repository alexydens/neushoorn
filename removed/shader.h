/* Include guard */
#if !defined(NH_SHADER_H)
#define NH_SHADER_H

#if defined(DEBUG)
#   include "logging.h"
#endif

/* Base library */
#include "base.h"
#include "arena_alloc.h"
#include "file_io.h"

/* OpenGL */
#include <GLES3/gl3.h>

/* ShaderHandle type is just a GLuint */
typedef u32 ShaderHandle;

/* Create shader */
NHAPI ShaderHandle createShader(const char* vertPath, const char* fragPath);
/* Destroy shader */
NHAPI void destroyShader(ShaderHandle handle);

/* Bind shader */
NHAPI void bindShader(ShaderHandle handle);

#endif /* NH_SHADER_H */
