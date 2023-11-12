/* Include guard */
#if !defined(NH_WINDOW_H)
#define NH_WINDOW_H

/* Base library */
#include "base.h"
#include "arena_alloc.h"

/* OpenGL */
#include <GLES3/gl3.h>
#include <GL/gl.h>

/* Scancodes */
#define KEY_A               0
#define KEY_B               1
#define KEY_C               2
#define KEY_D               3
#define KEY_E               4
#define KEY_F               5
#define KEY_G               6
#define KEY_H               7
#define KEY_I               8
#define KEY_J               9
#define KEY_K               10
#define KEY_L               11
#define KEY_M               12
#define KEY_N               13
#define KEY_O               14
#define KEY_P               15
#define KEY_Q               16
#define KEY_R               17
#define KEY_S               18
#define KEY_T               19
#define KEY_U               20
#define KEY_V               21
#define KEY_W               22
#define KEY_X               23
#define KEY_Y               24
#define KEY_Z               25

#define KEY_1               26
#define KEY_2               27
#define KEY_3               28
#define KEY_4               29
#define KEY_5               30
#define KEY_6               31
#define KEY_7               32
#define KEY_8               33
#define KEY_9               34
#define KEY_0               35

#define KEY_LSHIFT          36
#define KEY_RSHIFT          37
#define KEY_LCTRL           38
#define KEY_RCTRL           39
#define KEY_SPACE           40
#define KEY_TAB             41
#define KEY_ENTER           42

/* Maximum size of a window's internal state */
#define WINDOW_STATE_SIZE 1024 * 2   /* The state must not exceed 2KiB */

/* Resize callback type */
typedef void WindowResizeCallback(u32, u32, void*);

/* Window structure */
typedef struct {
  /* Whether the window is active */
  bool running;
  /* The window's dimensions, and a resize callback */
  u32 width, height;
  WindowResizeCallback* resizeCallback;
  /* Memory arena for an internal state specific to the implementation */
  Arena arena;
} Window;

/* Initialization code for windowing system */
NHAPI void WindowInit();
/* Ending code for windowing system */
NHAPI void WindowQuit();

/* Create a window */
NHAPI Window createWindow(
    const char* title, i32 x, i32 y, u32 width, u32 height);
/* Destroy a window */
NHAPI void destroyWindow(Window* window);
/* Add an OpenGL context */
NHAPI void initGL(Window* window);
/* Destroy an OpenGL context */
NHAPI void quitGL(Window* window);
/* Make OpenGL context current */
NHAPI void makeCurrent(Window* window);
/* Present the OpenGL window to the screen */
NHAPI void presentGL(Window* window);

/* Update all the windows */
NHAPI void updateWindows(Window** ppWindows, u32 numWindows);
/* Update the keyboard state */
NHAPI void updateKeyboardState();
/* Get the keyboard state */
NHAPI bool* getKeyboardState();

#endif /* NH_WINDOW_H */
