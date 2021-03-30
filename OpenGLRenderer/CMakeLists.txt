cmake_minimum_required (VERSION 3.8)

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

add_subdirectory(Resources/glfw Resources/glfw)
add_subdirectory(Resources/glew-cmake Resources/glew)
add_subdirectory(Resources/glm Resources/glm)

add_executable (OpenGLRenderer 
	"Application.cpp" 
    "src/Window.h"
    "src/Window.cpp" 
	"src/Buffer.h" 
	"src/ElementBuffer.h" 
	"src/ElementBuffer.cpp" 
	"src/VertexBuffer.h" 
	"src/VertexBuffer.cpp" 
	"src/VertexArray.h" 
	"src/VertexArray.cpp"
    "src/Vertex.h"
	"src/Shaders.h"
	"src/Shaders.cpp"
    "src/BufferLayout.h" 
	"src/Texture.h"
	"src/Texture.cpp" 
	"src/Camera.h" 
	"src/Camera.cpp"
 )

target_include_directories(${PROJECT_NAME}
	PUBLIC Resources
	PUBLIC Resources/glfw/include
	PUBLIC Resources/glm
	PUBLIC Resources/glew-cmake/include
	PUBLIC Resources/stb
	PUBLIC src
)

target_link_directories(${PROJECT_NAME}
	PUBLIC Resources
	PUBLIC Resources/glfw/src
	PUBLIC Resources/glm
	PUBLIC Resources/glew/lib
	PUBLIC Resources/stb
)

target_link_libraries(${PROJECT_NAME} glfw libglew_static)


