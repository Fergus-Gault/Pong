﻿# CMakeList.txt : CMake project for Pong, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

# Enable Hot Reload for MSVC compilers if supported.
if (POLICY CMP0141)
  cmake_policy(SET CMP0141 NEW)
  set(CMAKE_MSVC_DEBUG_INFORMATION_FORMAT "$<IF:$<AND:$<C_COMPILER_ID:MSVC>,$<CXX_COMPILER_ID:MSVC>>,$<$<CONFIG:Debug,RelWithDebInfo>:EditAndContinue>,$<$<CONFIG:Debug,RelWithDebInfo>:ProgramDatabase>>")
endif()

project ("Pong")

include_directories(${PROJECT_SOURCE_DIR}/include)

# Set up vcpkg toolchain
set(CMAKE_TOOLCHAIN_FILE "${VCPKG_ROOT}/scripts/buildsystems/vcpkg.cmake" CACHE STRING "Vcpkg toolchain file")

# Find SFML packages
find_package(SFML CONFIG REQUIRED COMPONENTS system window graphics network)

# Add source to this project's executable.
add_executable (Pong "src/Pong.cpp" "include/Pong.h" "src/Entity.cpp" "include/Entity.h" "src/Ball.cpp" "include/Ball.h" "src/Player.cpp" "include/Player.h" "src/Text.cpp" "include/Text.h")

# Link libraries
target_link_libraries(Pong PRIVATE sfml-system sfml-window sfml-graphics sfml-network)

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET Pong PROPERTY CXX_STANDARD 20)
endif()

# TODO: Add tests and install targets if needed.
