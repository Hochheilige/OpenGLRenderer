cmake_minimum_required(VERSION 3.8)

project(OpenGLRenderer)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR})

set(CubeExample 1)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)

configure_file(${CMAKE_CURRENT_SOURCE_DIR}/src/shaders/shader.vert ${CMAKE_CURRENT_BINARY_DIR}/shaders/shader.vert)
configure_file(${CMAKE_CURRENT_SOURCE_DIR}/src/shaders/shader.frag ${CMAKE_CURRENT_BINARY_DIR}/shaders)
file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/src/textures/container.jpg DESTINATION ${CMAKE_CURRENT_BINARY_DIR}/textures)
file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/src/textures/wall.jpg DESTINATION ${CMAKE_CURRENT_BINARY_DIR}/textures)
file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/src/textures/awesomeface.png DESTINATION ${CMAKE_CURRENT_BINARY_DIR}/textures)
file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/src/textures/blue.jpg DESTINATION ${CMAKE_CURRENT_BINARY_DIR}/textures)

add_subdirectory(resources/glfw)
add_subdirectory(resources/glew)
add_subdirectory(resources/glm)

add_subdirectory(src)
add_subdirectory(examples)




