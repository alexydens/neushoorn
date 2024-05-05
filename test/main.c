/* Include base */
#include "../nh_base.h"
/* Include logging */
#include "../ext/nh_logging.h"

/* Entry point */
int main(void) {
  NH_INFO("Does 1 equal 2? %s", BOOLSTR_COL(1 == 2));
  NH_INFO("Does 1 equal 1? %s", BOOLSTR_COL(1 == 1));
  return 0;
}
