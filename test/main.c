#include <neushoorn/logging.h>
#include <neushoorn/base.h>
#include <neushoorn/arena_alloc.h>
#include <neushoorn/file_io.h>

i32 main() {
  nh_info("Message type: %s", "info");
  nh_warn("Message type: %s", "warn");
  nh_error("Message type: %s", "error");
#if defined(NH_TEST_LOG_FATAL)
  nh_fatal("Message type: %s", "fatal");
#endif
  return 0;
}
