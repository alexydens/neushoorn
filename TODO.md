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
### Math:
#### Matrices:
- [ ] structs: `mat4`.
- [ ] identity matrix.
- [ ] translation matrix.
- [ ] rotation matrix.
- [ ] lookAt matrix (`gluLookAt()`).
- [ ] perspective projection matrix.
- [ ] matrix mulptiplication.
#### Vectors:
- [ ] structs: `v2i32`, `v3i32`, `v2f32`, `v3f32`.
- [ ] dot product.
- [ ] cross product.
- [ ] addition and subtraction.
- [ ] scalar multiply.
- [ ] normalization.
- [ ] linear interpolation.
### Memory:
#### Allocators:
- [x] linear allocator.
- [x] chunk allocator.
### I/O:
#### Files:
- [ ] read/write full file.
- [ ] append to file.
- [ ] delete from file.
- [ ] OBJ/JSON parsers.
### Networking:
- [ ] socket server for communication (e.g. games). PLATFORM SPECIFIC.
- [ ] web server (HTTP responses).                  PLATFORM SPECIFIC.
### Graphics:
- [ ] window abstraction.                           PLATFORM SPECIFIC.
#### Graphics API abstractions:                     PLATFORM SPECIFIC.
- [ ] FOR OPENGL.
- [ ] FOR VULKAN.
- [ ] context/instances.
- [ ] VBO, VAO.
- [ ] RBO, FBO.
- [ ] textures.
- [ ] shaders.
- [ ] shader hot reloading.
### Assets:
#### Shaders:
- 2D & 3D:
- [ ] solid color.
- [ ] texture.
- [ ] blinn-phong illumination.
- [ ] PBR lighting.
### Other:
- [ ] actual code hot reloading.
