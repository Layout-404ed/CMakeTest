cmake_minimum_required(VERSION 3.20)
project(game LANGUAGES CXX)

# C++ standard
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Raylib
find_package(raylib CONFIG REQUIRED)

# Your executable
add_executable(game
    src/main.cpp
    src/Player.cpp
)

# Include headers
target_include_directories(game PRIVATE src)

# Link raylib
target_link_libraries(game PRIVATE raylib)

# macOS: create proper app bundle (optional but recommended)
if(APPLE)
    set(CMAKE_OSX_DEPLOYMENT_TARGET "12.0")
    set_target_properties(game PROPERTIES
        MACOSX_BUNDLE TRUE
    )
endif()

# Copy assets next to the executable after build
add_custom_command(
    TARGET game POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_directory
            ${CMAKE_SOURCE_DIR}/assets
            $<TARGET_FILE_DIR:game>/assets
)