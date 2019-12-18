cmake_minimum_required(VERSION 3.12)
set(CMAKE_CXX_STANDARD 14)
set(PROJECT_NAME_VALUE
        jour3exo_spaceinvaders)

project(${PROJECT_NAME_VALUE})

file(
        GLOB_RECURSE
        source_files
        src/*
)
add_executable(
        ${PROJECT_NAME_VALUE}
        ${source_files}
        src/utils/Utils.h src/utils/Utils.cpp src/entities/Game.h src/entities/Game.cpp src/Managers/TextureManager.h src/Managers/TextureManager.cpp src/entities/GameObject.h src/entities/GameObject.cpp src/entities/ECS.h src/entities/Components.h src/entities/Laser.h)

if (WIN32)
    TARGET_LINK_LIBRARIES(
            ${PROJECT_NAME_VALUE}
            -lmingw32
            -lSDL2main
            -lSDL2
            -lSDL2_image
    )
endif ()

if (UNIX)
    TARGET_LINK_LIBRARIES(
            ${PROJECT_NAME_VALUE}
            -lSDL2main
            -lSDL2
            -lSDL2_image
    )
endif ()