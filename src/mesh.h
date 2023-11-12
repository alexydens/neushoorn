/* Include guard */
#if !defined(NH_MESH_H)
#define NH_MESH_H

/* Base library */
#include "base.h"

/* OpenGL */
#include <GLES3/gl3.h>

/* Mesh structure */
typedef struct {
  u32 VAO;  /* Vertex Array Object */
  u32 VBO;  /* Vertex Bufer Object */
  u32 numVertices;  /* How many vertices */
} Mesh;

/* Mesh create info */
typedef struct {
  f32* vertices;    /* Vertex data */
  u32 numVertices;  /* How many vertices */
  u32* attribs;     /* Vertex attributes */
  u32 numAttribs;   /* How many vertex attributes */
} MeshCreateInfo;

/* Creation and destruction of Mesh */
Mesh createMesh(MeshCreateInfo createInfo);
void destroyMesh(Mesh* mesh);

/* Draw the mesh */
void drawMesh(Mesh* mesh);

#endif /* NH_MESH_H */
