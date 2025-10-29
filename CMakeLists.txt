cmake_minimum_required(VERSION 3.31.6)

set(CMAKE_CXX_STANDARD 23)


project(
    SmallAudioSystem
    VERSION 0.1
    LANGUAGES CXX
)

find_package(SDL3 REQUIRED)
find_package(SDL3_image REQUIRED)
find_package(SDL3_ttf REQUIRED)


add_executable(SmallAudioSystem main.cpp ConstantDefs.h BaseC.h BaseC.cpp LogC.h LogC.cpp
SceneC.cpp SceneC.h MusicSceneC.cpp MusicSceneC.h)


target_link_libraries(SmallAudioSystem PRIVATE 
    SDL3::SDL3
    SDL3_image::SDL3_image
    SDL3_ttf::SDL3_ttf
)
