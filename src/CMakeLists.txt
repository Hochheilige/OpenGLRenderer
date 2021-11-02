cmake_minimum_required (VERSION 3.8)

set(RENDER RenderResourcesLib)

add_library(
    ${RENDER}
    STATIC
    "Window.h"
    "Window.cpp" 
	"Buffer.h" 
	"ElementBuffer.h" 
	"ElementBuffer.cpp" 
	"VertexBuffer.h" 
	"VertexBuffer.cpp" 
	"VertexArray.h" 
	"VertexArray.cpp"
    "Vertex.h"
	"Shaders.h"
	"Shaders.cpp"
    "BufferLayout.h" 
	"Texture.h"
	"Texture.cpp" 
	"Camera.h" 
	"Camera.cpp"
)

target_include_directories(
	${RENDER}
	PUBLIC ${CMAKE_SOURCE_DIR}/resources
	PUBLIC ${CMAKE_SOURCE_DIR}/resources/glfw/include
	PUBLIC ${CMAKE_SOURCE_DIR}/resources/glm
	PUBLIC ${CMAKE_SOURCE_DIR}/resources/glew-cmake/include
	PUBLIC ${CMAKE_SOURCE_DIR}/resources/stb
	PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}
)

target_link_directories(
	${RENDER}
	PUBLIC ${CMAKE_SOURCE_DIR}/resources
	PUBLIC ${CMAKE_SOURCE_DIR}/resources/glfw/src
	PUBLIC ${CMAKE_SOURCE_DIR}/resources/glm
	PUBLIC ${CMAKE_SOURCE_DIR}/resources/glew/lib
	PUBLIC ${CMAKE_SOURCE_DIR}/resources/stb
	PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}
)

target_link_libraries(${RENDER} glfw libglew_static)