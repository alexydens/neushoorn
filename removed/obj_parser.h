/* Include guard */
#if !defined(NH_OBJ_PARSER_H)
#define NH_OBJ_PARSER_H

/* Base library */
#include "base.h"

/* Vertex buffer structure */
typedef struct {
  f32* data;
  u32 vertexCount;
} VertexBuffer;

/* Create vertex buffer */
VertexBuffer createVertexBuffer(const char* obj_path);

/* Destroy vertex buffer */
void destroyVertexBuffer(VertexBuffer* buffer);

#endif /* NH_OBJ_PARSER_H */
