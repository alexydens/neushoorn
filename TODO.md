# Base
### Misc:
#### `nh_base.h`:
- [x] context cracking: compiler, os, cpu architecture.
- [x] utility macros: `CLAMP`, `SWAP`, `MAX`, `MIN`, `STRFROM`, `CONCAT`.
- [x] assertions: `ASSERT`, `ENABLE_ASSERT`, `ASSERT_ONFAIL`.
- [x] basic types: `u<8-64>`, `i<8-64>`, `f<32-64>`, `bool`.
- [x] global consts: max vals for types, pi and euler's number for both floats.
- [x] float utils: linear interpolation, infinity, -infinity.
#### `nh_logging.h`:
- [x] `nh_<info, warn, error, fatal`, with fatal causing crash.
- [x] `ASSERT_ONFAIL` displays fancy message with `nh_fatal()`.
### Memory:
#### Allocators:
- [x] linear allocator.
- [ ] chunk allocator. DONE, NOT TESTED, SO MAYBE NOT DONE?
#### String:
- [x] string struct.
- [ ] string utils implementation (requires all allocators).
