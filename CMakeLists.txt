cmake_minimum_required(VERSION 3.5)
project(bubbleshooter C CXX)

set(CMAKE_CXX_STANDARD 17)

# Setting parameters for OpenGL and raylib
set(OpenGL_GL_PREFERENCE GLVND)
set(BUILD_EXAMPLES OFF CACHE BOOL "" FORCE) # Disable building of examples in dependencies
set(BUILD_GAMES    OFF CACHE BOOL "" FORCE) # Disable building of games in dependencies

# Add raylib as a dependency from the libs directory
add_subdirectory(libs/raylib)

# Define WORKING_DIRECTORY and get all .cpp files from the source folder and set the working directory to the current source directory
set(WORKING_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}")

# Glob all .cpp files from specified directories into SOURCES variable
file(GLOB SOURCES "${WORKING_DIRECTORY}/framework/src/*.cpp" "${WORKING_DIRECTORY}/project/src/*.cpp")

# Create an executable with the project name and all the source files
add_executable(${PROJECT_NAME} ${SOURCES})

# Include directories for the project
target_include_directories(${PROJECT_NAME} PUBLIC ${WORKING_DIRECTORY}/framework/headers ${WORKING_DIRECTORY}/project/headers) 

# Link the raylib library privately to the project
target_link_libraries(${PROJECT_NAME} PRIVATE raylib)

# Copy assets to the binary directory
file(COPY assets/ DESTINATION ${CMAKE_BINARY_DIR})