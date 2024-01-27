#include <nh_base.h>
#include <nh_logging.h>

i32 main() {
  nh_info("Hello world.");
  nh_warn("Hello world.");
  nh_error("Hello world.");
  ASSERT(0);
  return 0;
}
