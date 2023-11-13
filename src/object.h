/* Include guard */
#if !defined(NH_OBJECT_H)
#define NH_OBJECT_H

/* Base library */
#include "base.h"
#include "shader.h"
#include "texture.h"
#include "mesh.h"
#include "obj_parser.h"

typedef struct {
  /* Vertex data - OBJ model */
  char* obj_path;
  /* Texture data - Images */
  char** texture_paths;
  char** texture_names;
  u32 numTextures;

  /* Shaders - paths */
  char* frag_path;
  char* vert_path;
} ObjectCreateInfo;

typedef struct {
  f32 ambient;
  f32 diffuse;
  f32 specular;
  f32 specularPow;
} Material;

typedef struct {
  /* Mesh and VertexBuffer */
  Mesh mesh;
  VertexBuffer vBuffer;
  /* Shader */
  ShaderHandle shader;
  /* Texture */
  Texture texture;
  /* Model matrix */
  m4f32 model;
  /* Material */
  Material material;
} Object;

/* Create and destroy object */
Object createObject(ObjectCreateInfo createInfo);
void destroyObject(Object* object);

/* Draw object */
void drawObject(Object* object, m4f32 view, m4f32 projection, v3f32 camPos);

#endif /* NH_OBJECT_H */
