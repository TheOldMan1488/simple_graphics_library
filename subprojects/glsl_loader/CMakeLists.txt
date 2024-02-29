cmake_minimum_required(VERSION 3.4 FATAL_ERROR)
project(glsl_loader LANGUAGES CXX)

set (SOURCES 
    ${PROJECT_SOURCE_DIR}/src/Shader.cpp
    ${PROJECT_SOURCE_DIR}/src/ShaderLoader.cpp
)

add_library(${PROJECT_NAME} SHARED ${SOURCES})

if (WIN32 AND MSVC)
    set_target_properties(${PROJECT_NAME} PROPERTIES WINDOWS_EXPORT_ALL_SYMBOLS TRUE)

endif()

set (INCLUDE_DIRS
    ${PROJECT_SOURCE_DIR}/include
)

target_include_directories(${PROJECT_NAME} PUBLIC ${INCLUDE_DIRS})
target_include_directories(${PROJECT_NAME} PRIVATE ${INCLUDE_DIRS}/glsl_loader)

set (LIBRARIES
    glew
    opengl32
    glfw
    glm::glm
)

target_link_libraries(${PROJECT_NAME} ${LIBRARIES})
