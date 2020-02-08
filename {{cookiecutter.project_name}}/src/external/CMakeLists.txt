### RAYLIB

ADD_LIBRARY(raylib STATIC
    raylib/src/core.c
    raylib/src/shapes.c
    raylib/src/textures.c
    raylib/src/text.c
    raylib/src/utils.c
    raylib/src/rglfw.c
    raylib/src/models.c
    raylib/src/raudio.c
)

TARGET_INCLUDE_DIRECTORIES(raylib
    PUBLIC
        raylib/src
    PRIVATE
        raylib/src/external/glfw/include
        raylib/src/external/glfw/deps/mingw
)

TARGET_COMPILE_DEFINITIONS(raylib PRIVATE PLATFORM_DESKTOP GRAPHICS_API_OPENGL_33)

TARGET_COMPILE_OPTIONS(raylib PRIVATE -std=c99 -fno-strict-aliasing)

TARGET_LINK_LIBRARIES(raylib PUBLIC X11 pthread dl)

### IMGUI

ADD_LIBRARY(imgui STATIC
    imgui/imgui.cpp
    imgui/imgui_demo.cpp
    imgui/imgui_draw.cpp
    imgui/imgui_widgets.cpp
    imgui/examples/imgui_impl_opengl3.cpp
    imgui_impl_raylib.cpp
)

TARGET_INCLUDE_DIRECTORIES(imgui
    PUBLIC imgui imgui/examples
    PRIVATE raylib/src/external raylib/src)

TARGET_COMPILE_DEFINITIONS(imgui PUBLIC IMGUI_IMPL_OPENGL_LOADER_GLAD)
