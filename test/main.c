#include <neushoorn/base.h>
#include <neushoorn/logging.h>
#include <neushoorn/window.h>
#include <neushoorn/object.h>

#include <GLES3/gl3.h>

void resize_callback(u32 w, u32 h, void* win) {
  Window* window = win;
  /* nh_info("Window resized to: %d, %d", w, h); */
  makeCurrent(window);
  glViewport(0, 0, w, h);
}

/* Camera */
v3f32 cameraPos    = { 0.0f, 0.0f,  3.0f };
v3f32 cameraFront  = { 0.0f, 0.0f, -1.0f };
v3f32 cameraUp     = { 0.0f, 1.0f,  0.0f };
f32 pitch = 0.0f;
f32 yaw   = -90.0f;
v3f32 cameraVelocity = { 0.0f, 0.0f, 0.0f };

/* Texture info */
const char* t_names[2] = { "tex", "normals" };
const char* t_paths[2] = { "assets/basecolor.jpg", "assets/normal.jpg" };
const char* t_paths2[2] = { "assets/basecolor2.png", "assets/normal2.png" };

/* Objects */
Object suzanne;
Object scene;

/* Matrices */
m4f32 view;
m4f32 projection;

/* Timing */
u32 ticks = 0;

/* Toggle-able things */
bool wireframeMode = false;
bool gammaCorrection = false;

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

  /* Create Objects */
  { /* Suzanne */
    ObjectCreateInfo createInfo;
    createInfo.frag_path = "assets/main.frag";
    createInfo.vert_path = "assets/main.vert";
    createInfo.texture_names = (char**)t_names;
    createInfo.texture_paths = (char**)t_paths2;
    createInfo.numTextures = 2;
    createInfo.obj_path = "assets/suzanne.obj";
    suzanne = createObject(createInfo);
  }
  { /* Scene */
    ObjectCreateInfo createInfo;
    createInfo.frag_path = "assets/main.frag";
    createInfo.vert_path = "assets/main.vert";
    createInfo.texture_names = (char**)t_names;
    createInfo.texture_paths = (char**)t_paths;
    createInfo.numTextures = 2;
    createInfo.obj_path = "assets/scene.obj";
    scene = createObject(createInfo);
  }

  while (window.running) {
    bool* keyboard_state;
    updateWindows(ppWindows, 1);
    updateKeyboardState();
    keyboard_state = getKeyboardState();
    if (window.running) {

    glClearColor(0.2f, 0.2f, 0.2f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    /* Process keyboard input */
    if (keyboard_state[KEY_1]) wireframeMode = true;
    if (keyboard_state[KEY_1] && keyboard_state[KEY_RSHIFT])
      wireframeMode = false;
    if (keyboard_state[KEY_2]) gammaCorrection = true;
    if (keyboard_state[KEY_2] && keyboard_state[KEY_RSHIFT])
      gammaCorrection = false;
    if (wireframeMode)
      glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
    else
      glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
    if (gammaCorrection)
      glEnable(GL_FRAMEBUFFER_SRGB);
    else
      glDisable(GL_FRAMEBUFFER_SRGB);

    if (keyboard_state[KEY_W]) {
      v3f32 tmp;
      v3f32 front2 = { 0.0f, 0.0f, 0.0f };
      front2.x = cameraFront.x;
      front2.z = cameraFront.z;
      tmp = scale_v3f32(front2, 0.0025f);
      cameraVelocity = add_v3f32(cameraVelocity, tmp);
    }
    if (keyboard_state[KEY_S]) {
      v3f32 tmp;
      v3f32 front2 = { 0.0f, 0.0f, 0.0f };
      front2.x = cameraFront.x;
      front2.z = cameraFront.z;
      tmp = scale_v3f32(front2, 0.0025f);
      cameraVelocity = subtract_v3f32(cameraVelocity, tmp);
    }
    if (keyboard_state[KEY_A]) {
      v3f32 tmp;
      v3f32 front2 = { 0.0f, 0.0f, 0.0f };
      front2.x = cameraFront.x;
      front2.z = cameraFront.z;
      tmp = cross_v3f32(front2, cameraUp);
      tmp = normalize_v3f32(tmp);
      tmp = scale_v3f32(tmp, 0.0025f);
      cameraVelocity = subtract_v3f32(cameraVelocity, tmp);
    }
    if (keyboard_state[KEY_D]) {
      v3f32 tmp;
      v3f32 front2 = { 0.0f, 0.0f, 0.0f };
      front2.x = cameraFront.x;
      front2.z = cameraFront.z;
      tmp = cross_v3f32(front2, cameraUp);
      tmp = normalize_v3f32(tmp);
      tmp = scale_v3f32(tmp, 0.0025f);
      cameraVelocity = add_v3f32(cameraVelocity, tmp);
    }
    if (keyboard_state[KEY_LEFT]) yaw -= 0.3f;
    if (keyboard_state[KEY_RIGHT]) yaw += 0.3f;
    if (keyboard_state[KEY_UP]) pitch -= 0.3f;
    if (keyboard_state[KEY_DOWN]) pitch += 0.3f;
    if (pitch < -89.9f) pitch = -89.9f;
    if (pitch > 89.9f) pitch = 89.9f;
    if (keyboard_state[KEY_SPACE])
      cameraVelocity.y += 0.005f;
    if (keyboard_state[KEY_LSHIFT])
      cameraVelocity.y -= 0.005f;
    {
      v3f32 tmp;
      tmp = scale_v3f32(cameraVelocity, 0.2f);
      cameraPos = add_v3f32(cameraPos, tmp);
    }
    cameraVelocity.x /= 1.015f;
    cameraVelocity.y /= 1.015f;
    cameraVelocity.z /= 1.015f;

    /* Update model view projection */
    /* model */
    suzanne.model = identity_m4f32();
    {
      m4f32 translation;
      m4f32 rotation;
      translation = translation_m4f32(0.0f, 0.75f, 0.0f);
      rotation = rotationY_m4f32(ticks / 5000.0f);
      suzanne.model = multiply_m4f32(rotation, translation);
    }
    scene.model = identity_m4f32();
    {
      m4f32 translation;
      m4f32 rotation;
      translation = translation_m4f32(0.0f, -0.5f, 0.0f);
      rotation = rotationY_m4f32(270.0f * (pi32 / 180.0f));
      scene.model = multiply_m4f32(translation, rotation);
    }
    /* view */
    {
      v3f32 tmp;
      tmp = add_v3f32(cameraPos, cameraFront);
      view = lookAt_m4f32(cameraPos, tmp, cameraUp);
    }
    {
      v3f32 direction;
      direction.x = cos(yaw * (pi32 / 180.0f)) * cos(pitch * (pi32 / 180.0f));
      direction.y = sin(pitch * (pi32 / 180.0f));
      direction.z = sin(yaw * (pi32 / 180.0f)) * cos(pitch * (pi32 / 180.0f));
      cameraFront = normalize_v3f32(direction);
    }
    /* projection */
    projection = perspectiveProjection_m4f32(
        60.0f,
        (f32)window.width / window.height,
        0.1f, 100.0f
    );

    /* Draw scene */
    drawObject(&suzanne, view, projection, cameraPos);
    drawObject(&scene, view, projection, cameraPos);

    presentGL(&window);
    ticks++;

    }
  }
  /* Destroy objects */
  destroyObject(&suzanne);
  destroyObject(&scene);
  WindowQuit();
  return 0;
}
