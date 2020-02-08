ADD_SUBDIRECTORY(external)

ADD_EXECUTABLE({{cookiecutter.project_name}} main.cpp)
TARGET_LINK_LIBRARIES({{cookiecutter.project_name}} PUBLIC raylib imgui)
TARGET_INCLUDE_DIRECTORIES({{cookiecutter.project_name}} PUBLIC external)
