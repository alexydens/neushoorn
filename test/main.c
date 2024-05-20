/* Base */
#include "../nh_base.h"
/* Other headers */
#include "../ext/nh_logging.h"
#include "../ext/nh_vector.h"

/* Entry point */
int main(void) {
  nh_vec3_t vec = { 1, 2, 3 };
  NH_INFO("vec: %f %f %f", vec.x, vec.y, vec.z);

  nh_vec3_t vec2 = nh_vec3_add(vec, vec);
  NH_INFO("vec2: %f %f %f", vec2.x, vec2.y, vec2.z);

  return 0;
}
