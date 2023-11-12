#include "window.h"

#include <SDL2/SDL.h>
#include <string.h>

/*
 * Arena contents:
 * - WindowState
 * - RenderState
 */
#define NUM_KEYS 43
bool keyboardState[NUM_KEYS];
const u8* sdl_keys;

typedef struct {
  SDL_Window* handle;
  bool opengl;
} WindowState;

typedef union {
  SDL_Renderer* renderer;
  SDL_GLContext gl_context;
} RenderState;

void WindowInit() {
  if (!SDL_WasInit(SDL_INIT_EVERYTHING)) {
    SDL_Init(SDL_INIT_EVERYTHING);

    SDL_GL_LoadLibrary(NULL);
    SDL_GL_SetAttribute(SDL_GL_ACCELERATED_VISUAL, 1);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 3);
    SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
    SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 24);
    memset(keyboardState, 0, NUM_KEYS * sizeof(bool));
    sdl_keys = SDL_GetKeyboardState(NULL);
  }
}
void WindowQuit() {
  SDL_Quit();
}

Window createWindow(
    const char* title,
    i32 x, i32 y,
    u32 width, u32 height) {
  Window window;
  WindowState* state;

  window.arena = create_arena(WINDOW_STATE_SIZE);
  state = arena_alloc(&window.arena, sizeof(WindowState));

  state->handle = SDL_CreateWindow(
      title, x, y, width, height, SDL_WINDOW_OPENGL);
  window.width = width;
  window.height = height;
  window.running = true;
  state->opengl = false;

  return window;
}
void destroyWindow(Window* window) {
  if (window->running) {
    WindowState* state = (WindowState*)window->arena.start;
    if (state->opengl) {
      quitGL(window);
    }
    SDL_DestroyWindow(state->handle);
    state = NULL;
    arena_free(&window->arena);
    window->running = false;
  }
}
void initGL(Window* window) {
  WindowState* windowState = (WindowState*)window->arena.start;
  RenderState* renderState = arena_alloc(&window->arena, sizeof(RenderState));
  renderState->gl_context = SDL_GL_CreateContext(windowState->handle);
  windowState->opengl = true;
}
void quitGL(Window* window) {
  RenderState* renderState =
    (RenderState*)(window->arena.start + sizeof(WindowState));
  SDL_GL_DeleteContext(renderState->gl_context);
}
void makeCurrent(Window* window) {
  WindowState* windowState = (WindowState*)window->arena.start;
  RenderState* renderState =
    (RenderState*)(window->arena.start + sizeof(WindowState));
  SDL_GL_MakeCurrent(windowState->handle, renderState->gl_context);
}
void presentGL(Window* window) {
  WindowState* state = (WindowState*)window->arena.start;
  SDL_GL_SwapWindow(state->handle);
}

void updateWindows(Window** ppWindows, u32 numWindows) {
  SDL_Event event;
  u32 i;
  while (SDL_PollEvent(&event)) {
    switch (event.type) {
      case SDL_WINDOWEVENT:
        {
          Window* window;
          WindowState* windowState;
          for (i = 0; i < numWindows; i++) {
            windowState = (WindowState*)ppWindows[i]->arena.start;
            if (SDL_GetWindowID(windowState->handle) == event.window.windowID) {
              window = ppWindows[i];
              break;
            }
          }
          switch (event.window.event) {
            case SDL_WINDOWEVENT_RESIZED:
              {
                window->width = event.window.data1;
                window->height = event.window.data2;
                window->resizeCallback(window->width, window->height, window);
              } break;
            case SDL_WINDOWEVENT_CLOSE:
              {
                destroyWindow(window);
              } break;
          }
        } break;
    }
  }
}
void updateKeyboardState() {
  keyboardState[KEY_A] = sdl_keys[SDL_SCANCODE_A];
  keyboardState[KEY_B] = sdl_keys[SDL_SCANCODE_B];
  keyboardState[KEY_C] = sdl_keys[SDL_SCANCODE_C];
  keyboardState[KEY_D] = sdl_keys[SDL_SCANCODE_D];
  keyboardState[KEY_E] = sdl_keys[SDL_SCANCODE_E];
  keyboardState[KEY_F] = sdl_keys[SDL_SCANCODE_F];
  keyboardState[KEY_G] = sdl_keys[SDL_SCANCODE_G];
  keyboardState[KEY_H] = sdl_keys[SDL_SCANCODE_H];
  keyboardState[KEY_I] = sdl_keys[SDL_SCANCODE_I];
  keyboardState[KEY_J] = sdl_keys[SDL_SCANCODE_J];
  keyboardState[KEY_K] = sdl_keys[SDL_SCANCODE_K];
  keyboardState[KEY_L] = sdl_keys[SDL_SCANCODE_L];
  keyboardState[KEY_M] = sdl_keys[SDL_SCANCODE_M];
  keyboardState[KEY_N] = sdl_keys[SDL_SCANCODE_N];
  keyboardState[KEY_O] = sdl_keys[SDL_SCANCODE_O];
  keyboardState[KEY_P] = sdl_keys[SDL_SCANCODE_P];
  keyboardState[KEY_Q] = sdl_keys[SDL_SCANCODE_Q];
  keyboardState[KEY_R] = sdl_keys[SDL_SCANCODE_R];
  keyboardState[KEY_S] = sdl_keys[SDL_SCANCODE_S];
  keyboardState[KEY_T] = sdl_keys[SDL_SCANCODE_T];
  keyboardState[KEY_U] = sdl_keys[SDL_SCANCODE_U];
  keyboardState[KEY_V] = sdl_keys[SDL_SCANCODE_V];
  keyboardState[KEY_W] = sdl_keys[SDL_SCANCODE_W];
  keyboardState[KEY_X] = sdl_keys[SDL_SCANCODE_X];
  keyboardState[KEY_Y] = sdl_keys[SDL_SCANCODE_Y];
  keyboardState[KEY_Z] = sdl_keys[SDL_SCANCODE_Z];

  keyboardState[KEY_1] = sdl_keys[SDL_SCANCODE_1];
  keyboardState[KEY_2] = sdl_keys[SDL_SCANCODE_2];
  keyboardState[KEY_3] = sdl_keys[SDL_SCANCODE_3];
  keyboardState[KEY_4] = sdl_keys[SDL_SCANCODE_4];
  keyboardState[KEY_5] = sdl_keys[SDL_SCANCODE_5];
  keyboardState[KEY_6] = sdl_keys[SDL_SCANCODE_6];
  keyboardState[KEY_7] = sdl_keys[SDL_SCANCODE_7];
  keyboardState[KEY_8] = sdl_keys[SDL_SCANCODE_8];
  keyboardState[KEY_9] = sdl_keys[SDL_SCANCODE_9];
  keyboardState[KEY_0] = sdl_keys[SDL_SCANCODE_0];

  keyboardState[KEY_LSHIFT] = sdl_keys[SDL_SCANCODE_LSHIFT];
  keyboardState[KEY_RSHIFT] = sdl_keys[SDL_SCANCODE_RSHIFT];
  keyboardState[KEY_LCTRL] = sdl_keys[SDL_SCANCODE_LCTRL];
  keyboardState[KEY_RCTRL] = sdl_keys[SDL_SCANCODE_RCTRL];
  keyboardState[KEY_SPACE] = sdl_keys[SDL_SCANCODE_SPACE];
  keyboardState[KEY_TAB] = sdl_keys[SDL_SCANCODE_TAB];
  keyboardState[KEY_ENTER] = sdl_keys[SDL_SCANCODE_RETURN];
}
bool* getKeyboardState() {
  return keyboardState;
}
