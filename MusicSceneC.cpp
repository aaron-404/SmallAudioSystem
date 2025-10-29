#include "MusicSceneC.h"
#include "LogC.h"
#include <iostream>
#include <vector>
#include <memory>
#include <SDL3/SDL.h>
#include <SDL3_ttf/SDL_ttf.h>


// Default constructor
MusicSceneC::MusicSceneC() {

    // Initialize
    Initialize();

}


// Destructor (virtual destructor due to derived classes) 
MusicSceneC::~MusicSceneC() {
    // Cleanup
}


void MusicSceneC::Initialize(void)
{
    std::cout << "INIT MUSIC SCENE!!!\n";
    return;
}



void MusicSceneC::Update(void)
{
    return;
}

