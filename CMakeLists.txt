cmake_minimum_required(VERSION 3.5)
project(main C CXX)

set(CMAKE_CXX_STANDARD 11)

# Setting parameters for OpenGL
set(OpenGL_GL_PREFERENCE GLVND)

# Setting parameters for raylib
set(BUILD_EXAMPLES OFF CACHE BOOL "" FORCE) # don't build the supplied examples
set(BUILD_GAMES    OFF CACHE BOOL "" FORCE) # or games

add_subdirectory(libs/raylib)

add_executable(Bubbleshoot 
	src/main.cpp
	src/bubble.cpp
	src/bubble.h
	src/level1.cpp
	src/level1.h
	src/level2.cpp
	src/level2.h
	src/level3.cpp
	src/level3.h

	framework/entity.cpp
	framework/entity.h
	framework/gui.cpp
	framework/gui.h
	framework/guibutton.cpp
	framework/guibutton.h
	framework/superlevel.cpp
	framework/superlevel.h
	framework/superscene.cpp
	framework/superscene.h
)
target_link_libraries(Bubbleshoot PRIVATE raylib)
file(
	COPY assets
	DESTINATION ${CMAKE_BINARY_DIR}
)

# target_compile_definitions(${PROJECT_NAME} PUBLIC ASSETS_PATH="${CMAKE_CURRENT_SOURCE_DIR}/assets/") # Set the asset path macro to the absolute path on the dev machine
#target_compile_definitions(${PROJECT_NAME} PUBLIC ASSETS_PATH="relative-path-to-assets-in-the-game-package") # Set the asset path macro in release more
