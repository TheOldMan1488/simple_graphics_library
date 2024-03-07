cmake_minimum_required(VERSION 3.4 FATAL_ERROR)
project(gl LANGUAGES CXX)

set (CMAKE_CXX_STANDARD 17)
set (CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})

set (CMAKE_CXX_EXTENSIONS OFF)

set(BUILD_SHARED_LIBS ON)

set (GLFW_DIR ${PROJECT_SOURCE_DIR}/subprojects/external/glfw)
set (GLFW_BUILD_EXAMPLES OFF)
set (GLFW_BUILD_TESTS OFF)
set (GLFW_BUILD_DOCS OFF)
add_subdirectory(${GLFW_DIR})

set (GLEW_DIR ${PROJECT_SOURCE_DIR}/subprojects/external/glew)
add_subdirectory(${GLEW_DIR}/build/cmake)

set (GLM_DIR ${PROJECT_SOURCE_DIR}/subprojects/external/glm)
set (GLM_BUILD_TESTS OFF)
add_subdirectory(${GLM_DIR})

if (WIN32 AND MSVC)
    set_target_properties(glm PROPERTIES WINDOWS_EXPORT_ALL_SYMBOLS TRUE)

endif()

add_subdirectory(${PROJECT_SOURCE_DIR}/subprojects/glsl_loader)

set (LIBRARIES
    opengl32
    glfw
    glew
    glm::glm
    glsl_loader
)

set (INCLUDE_DIRS
    ${PROJECT_SOURCE_DIR}/include
    ${GLEW_DIR}/include
)

set (SOURCES
    ${PROJECT_SOURCE_DIR}/src/main.cpp
    ${PROJECT_SOURCE_DIR}/src/GLEW.cpp
    ${PROJECT_SOURCE_DIR}/src/GLFW.cpp
    ${PROJECT_SOURCE_DIR}/src/Window.cpp
    ${PROJECT_SOURCE_DIR}/src/Color.cpp
    ${PROJECT_SOURCE_DIR}/src/Model.cpp
    ${PROJECT_SOURCE_DIR}/src/Cube.cpp
    ${PROJECT_SOURCE_DIR}/src/Camera.cpp
)

add_executable(${PROJECT_NAME} ${SOURCES})

target_include_directories(${PROJECT_NAME} PRIVATE ${INCLUDE_DIRS})
target_include_directories(glsl_loader PUBLIC ${GLEW_DIR}/include)
target_link_libraries(${PROJECT_NAME} PRIVATE ${LIBRARIES})

#copy shaders directory to the executable directory
add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_directory
        ${CMAKE_SOURCE_DIR}/shaders
        $<TARGET_FILE_DIR:${PROJECT_NAME}>/shaders
)