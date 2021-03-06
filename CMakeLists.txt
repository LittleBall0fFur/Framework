# CMake entry point
cmake_minimum_required (VERSION 2.6)
project (Framework)

find_package(OpenGL REQUIRED)


if( CMAKE_BINARY_DIR STREQUAL CMAKE_SOURCE_DIR )
    message( FATAL_ERROR "Please select another Build Directory ! (and give it a clever name, like 'build')" )
endif()
if( CMAKE_SOURCE_DIR MATCHES " " )
	message( "Your Source Directory contains spaces. If you experience problems when compiling, this can be the cause." )
endif()
if( CMAKE_BINARY_DIR MATCHES " " )
	message( "Your Build Directory contains spaces. If you experience problems when compiling, this can be the cause." )
endif()

if(UNIX)
	#set(CMAKE_CXX_FLAGS "-Wall -std=c++0x -pedantic -O2 -g -pg")
	#set(CMAKE_CXX_FLAGS "-Wall -Wstrict-aliasing -std=c++0x -O2")

	set(CMAKE_CXX_FLAGS "-Wall -std=c++11")

	# valgrind --leak-check=full ./demo
	# ./demo # creates cmon.out
	# gprof demo gmon.out > analysis.txt
	#set(CMAKE_CXX_FLAGS "-Wall -pg -std=c++11")
endif(UNIX)

# Compile external dependencies
add_subdirectory (external)

# On Visual 2005 and above, this module can set the debug working directory
list(APPEND CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/external/rpavlik-cmake-modules-1c73e35")
include(CreateLaunchers)
include(MSVCMultipleProcessCompile) # /MP

if(INCLUDE_DISTRIB)
	add_subdirectory(distrib)
endif(INCLUDE_DISTRIB)

include_directories(
	external/glfw-3.0.3/include/GLFW/
	external/glm-0.9.7.0/
	external/glew-1.9.0/include/
	.
)

set(ALL_LIBS
	${OPENGL_LIBRARY}
	GLFW_303
	GLEW_190
)

add_definitions(
	-DTW_STATIC
	-DTW_NO_LIB_PRAGMA
	-DTW_NO_DIRECT3D
	-DGLEW_STATIC
	-D_CRT_SECURE_NO_WARNINGS
)

add_subdirectory (external/openal)
include_directories(
	${CMAKE_SOURCE_DIR}/external/openal/include/
)

link_directories(
	${CMAKE_SOURCE_DIR}/external/openal/
)

IF(WIN32)
	SET(OPENAL OpenAL32)
ELSE()
	SET(OPENAL openal)
ENDIF()

add_executable(altonegenrt
		external/openal/examples/altonegen.c
		external/openal/examples/common/alhelpers.c
	)
	target_link_libraries(altonegenrt
		${OPENAL}
	)


# Demo
add_executable(demo
	demo/demo.cpp
  demo/mainscene.cpp
  demo/mainscene.h
  demo/ai.cpp
  demo/ai.h
  demo/factory.cpp
  demo/factory.h
  demo/map.cpp
  demo/map.h
  demo/bullet.cpp
  demo/bullet.h
  demo/building.cpp
  demo/building.h
  demo/base.cpp
  demo/base.h
  demo/healthsystem.cpp
  demo/healthsystem.h
  demo/canvas.cpp
  demo/canvas.h
  demo/hudelement.cpp
  demo/hudelement.h
  demo/buildmenu.cpp
  demo/buildmenu.h
  demo/button.cpp
  demo/button.h

	common/shader.cpp
  common/shader.h
	common/camera.cpp
  common/camera.h
	common/texture.cpp
  common/texture.h
  common/renderer.cpp
  common/renderer.h
  common/vector2.cpp
  common/vector2.h
  common/mesh.cpp
  common/mesh.h
  common/entity.cpp
  common/entity.h
  common/scene.cpp
  common/scene.h
  common/sprite.cpp
  common/sprite.h
  common/core.cpp
  common/core.h
  common/collision.cpp
  common/collision.h
  common/spritesheet.cpp
  common/spritesheet.h
  common/input.cpp
  common/input.h
  common/resourcemanager.cpp
  common/resourcemanager.h
  common/audio.cpp
  common/audio.h
  common/wav.cpp
  common/wav.h
  common/sound.cpp
  common/sound.h
  common/line.cpp
  common/line.h
)
target_link_libraries(demo
	${ALL_LIBS}
  ${OPENAL}
)
# Xcode and Visual working directories
set_target_properties(demo PROPERTIES XCODE_ATTRIBUTE_CONFIGURATION_BUILD_DIR "${CMAKE_CURRENT_SOURCE_DIR}/demo/")
create_target_launcher(demo WORKING_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/demo/")


SOURCE_GROUP(common REGULAR_EXPRESSION ".*/common/.*" )
SOURCE_GROUP(shaders REGULAR_EXPRESSION ".*/.*shader$" )


if (NOT ${CMAKE_GENERATOR} MATCHES "Xcode" )
#add_custom_command(
#   TARGET demo POST_BUILD
#   COMMAND ${CMAKE_COMMAND} -E copy "${CMAKE_CURRENT_BINARY_DIR}/${CMAKE_CFG_INTDIR}/demo${CMAKE_EXECUTABLE_SUFFIX}" "${CMAKE_CURRENT_SOURCE_DIR}/demo/"
#)
elseif (${CMAKE_GENERATOR} MATCHES "Xcode" )

endif (NOT ${CMAKE_GENERATOR} MATCHES "Xcode" )


# Copy assets to the build directory
file(
	COPY demo/assets
	DESTINATION ${CMAKE_BINARY_DIR}
)
file(
	COPY demo/shaders
	DESTINATION ${CMAKE_BINARY_DIR}
)
