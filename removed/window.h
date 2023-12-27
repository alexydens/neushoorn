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
#define NUM_KEYS 47
#define NH_KEY_A               0
#define NH_KEY_B               1
#define NH_KEY_C               2
#define NH_KEY_D               3
#define NH_KEY_E               4
#define NH_KEY_F               5
#define NH_KEY_G               6
#define NH_KEY_H               7
#define NH_KEY_I               8
#define NH_KEY_J               9
#define NH_KEY_K               10
#define NH_KEY_L               11
#define NH_KEY_M               12
#define NH_KEY_N               13
#define NH_KEY_O               14
#define NH_KEY_P               15
#define NH_KEY_Q               16
#define NH_KEY_R               17
#define NH_KEY_S               18
#define NH_KEY_T               19
#define NH_KEY_U               20
#define NH_KEY_V               21
#define NH_KEY_W               22
#define NH_KEY_X               23
#define NH_KEY_Y               24
#define NH_KEY_Z               25

#define NH_KEY_1               26
#define NH_KEY_2               27
#define NH_KEY_3               28
#define NH_KEY_4               29
#define NH_KEY_5               30
#define NH_KEY_6               31
#define NH_KEY_7               32
#define NH_KEY_8               33
#define NH_KEY_9               34
#define NH_KEY_0               35

#define NH_KEY_LSHIFT          36
#define NH_KEY_RSHIFT          37
#define NH_KEY_LCTRL           38
#define NH_KEY_RCTRL           39
#define NH_KEY_SPACE           40
#define NH_KEY_TAB             41
#define NH_KEY_ENTER           42

#define NH_KEY_UP              43
#define NH_KEY_DOWN            44
#define NH_KEY_LEFT            45
#define NH_KEY_RIGHT           46

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
