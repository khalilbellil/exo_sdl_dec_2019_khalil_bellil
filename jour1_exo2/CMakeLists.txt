cmake_minimum_required(VERSION 3.13)
set(CMAKE_CXX_STANDARD 14)
set(
        PROJECT_NAME_VALUE
        jour1_exo2)

project(${PROJECT_NAME_VALUE})

file(
        GLOB_RECURSE
        source_files
        src/*
)

#si on utilise un repertoire assets pour image fichier ou autre
#il faut decomenter le code qui suit
#file(
#        COPY
#        assets
#        DESTINATION
#        ${CMAKE_BINARY_DIR}
#)

add_executable(
        ${PROJECT_NAME_VALUE}
        ${source_files} src/Image.h)

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