cmake_minimum_required(VERSION 3.8)

if(CubeExample)
    message("-- Build CubeExample")
    add_executable(${PROJECT_NAME} Application.cpp)
endif()

target_link_libraries(${PROJECT_NAME} RenderResourcesLib)
