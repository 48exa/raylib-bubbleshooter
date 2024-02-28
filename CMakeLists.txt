cmake_minimum_required(VERSION  3.5)
project(bubbleshooter C CXX)

set(CMAKE_CXX_STANDARD  11)

# Setting parameters for OpenGL
set(OpenGL_GL_PREFERENCE GLVND)

# Setting parameters for raylib
set(BUILD_EXAMPLES OFF CACHE BOOL "" FORCE) # don't build the supplied examples
set(BUILD_GAMES    OFF CACHE BOOL "" FORCE) # or games

add_subdirectory(libs/raylib)

# Define WORKING_DIRECTORY to the directory containing your headers
set(WORKING_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}")

# Get all .cpp files from the source folder
file(GLOB SOURCES "src/*.cpp")

# Now we add all the source files to the project
add_executable(${PROJECT_NAME} ${SOURCES})

# Now set the include directories for Bubbleshoot
target_include_directories(${PROJECT_NAME} PUBLIC ${WORKING_DIRECTORY}/headers)

# Link raylib to your executable
target_link_libraries(${PROJECT_NAME} PRIVATE raylib)

# Copy assets to the binary directory
file(
  COPY assets
  DESTINATION ${CMAKE_BINARY_DIR}
)
