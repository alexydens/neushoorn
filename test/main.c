#if 1
#include <neushoorn/base.h>
#include <neushoorn/logging.h>
#include <neushoorn/window.h>
#include <neushoorn/shader.h>
#include <neushoorn/mesh.h>

#include <GLES3/gl3.h>

void resize_callback(u32 w, u32 h, void* win) {
  Window* window = win;
  /* nh_info("Window resized to: %d, %d", w, h); */
  makeCurrent(window);
  glViewport(0, 0, w, h);
}

ShaderHandle shader;
Mesh mesh;

float vertices[] = {
  -0.5f, -0.5f, 0.0f,   1.0f, 0.0f, 0.0f,
   0.5f, -0.5f, 0.0f,   0.0f, 1.0f, 0.0f,
   0.0f,  0.5f, 0.0f,   0.0f, 0.0f, 1.0f,
}; 
u32 attribs[] = { 3, 3 };

i32 main() {
  Window window;
  Window* ppWindows[1];
  WindowInit();
  window = createWindow("Window", 0, 0, 1280, 720);
  window.resizeCallback = resize_callback;
  initGL(&window);
  makeCurrent(&window);
  glViewport(0, 0, window.width, window.height);
  ppWindows[0] = &window;

  shader = createShader("assets/test.vert", "assets/test.frag");

  {
    MeshCreateInfo createInfo;
    createInfo.attribs = attribs;
    createInfo.numAttribs = 2;
    createInfo.vertices = vertices;
    createInfo.numVertices = 3;
    mesh = createMesh(createInfo);
  }

  while (window.running) {
    bool* keyboard_state;
    updateWindows(ppWindows, 1);
    updateKeyboardState();
    keyboard_state = getKeyboardState();
    if (window.running) {

    if (keyboard_state[KEY_A]) glClearColor(0.3f, 0.5f, 1.0f, 1.0f);
    else glClearColor(0.2f, 0.2f, 0.2f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    bindShader(shader);
    drawMesh(&mesh);

    presentGL(&window);

    }
  }
  destroyMesh(&mesh);
  destroyShader(shader);
  WindowQuit();
  return 0;
}
#endif

#if 0
/* Base library */
#include <neushoorn/base.h>         /* Core */
#include <neushoorn/arena_alloc.h>  /* Linear allocator */
#include <neushoorn/logging.h>      /* Logger */
#include <neushoorn/file_io.h>      /* File handling */

#include <stdio.h>
#include <string.h>
#define EVAL_BOOL(EXPR) nh_info("%s = %s", #EXPR, (EXPR) ? "true" : "false");

#define DONT_TEST_LOGGING

i32 main() {
  /* base.h */
#if !defined(DONT_TEST_BASE)
  { /* Operating system */
    bool os_linux = OS_LINUX;
    bool os_windows = OS_WINDOWS;
    bool os_macos = OS_MACOS;
    EVAL_BOOL(os_linux);
    EVAL_BOOL(os_windows);
    EVAL_BOOL(os_macos);
    printf("\n");
  }
  { /* System architecture */
    bool cpu_arm = CPU_ARM;
    bool cpu_arm64 = CPU_ARM64;
    bool cpu_x86 = CPU_X86;
    bool cpu_x86_64 = CPU_X86_64;
    EVAL_BOOL(cpu_arm);
    EVAL_BOOL(cpu_arm64);
    EVAL_BOOL(cpu_x86);
    EVAL_BOOL(cpu_x86_64);
    printf("\n");
  }
  { /* Helper macros */
    /* Clamp */
    ASSERT(CLAMP(10, 0, 5) == 5);
    ASSERT(CLAMP(-3, 0, 5) == 0);
    ASSERT(CLAMP(3, 0, 5) == 3); 
    { /* Swap */
      i32 a = 0;
      i32 b = 1;
      SWAP(a, b);
      ASSERT(a);
    }
    /* Min */
    ASSERT(MIN(10, 0) == 0);
    ASSERT(MIN(0, 10) == 0);
    /* Max */
    ASSERT(MAX(10, 0) == 10);
    ASSERT(MAX(0, 10) == 10);
    { /* Arrlen */
      u32 arr[8];
      ASSERT(ARRLEN(arr) == 8);
    }
    /* Strfrom */
    ASSERT(strcmp("hello", STRFROM(hello)) == 0);
    /* Concat */
    ASSERT(CONCAT(tr, ue));
  }
#endif
  /* arena_alloc.h */
#if !defined (DONT_TEST_ARENA_ALLOC)
  /**/
#endif
  /* logging.h */
#if !defined (DONT_TEST_LOGGING)
  nh_info("Testing info...");
  nh_warn("Testing warn...");
  nh_error("Testing error...");
  nh_fatal("Testing fatal...");
#endif
  {
    Arena arena = create_arena(9000);
    const char* string = read_file(&arena, "src/base.h");
    nh_info("Contents of base.h:\n%s", string);
  }
  return 0;
}
#endif
