#include "BaseC.h"
#include "LogC.h"
#include "SceneC.h"
#include "MusicSceneC.h"
#include <iostream>
#include <vector>
#include <memory>
#include <SDL3/SDL.h>
#include <SDL3_ttf/SDL_ttf.h>


// Default constructor
BaseC::BaseC() {

    // Initialize All Scenes
    InitializeScenes();

}

// Destructor
BaseC::~BaseC() {
    // Cleanup each scene
    delete m_scenes.musicScene;
}


void BaseC::InitializeScenes(void){
    LogC log;
    log.MakeLogEntry("Creating Music Scene...", LogC::LT_INFO);
    m_scenes.musicScene = new MusicSceneC;
    
    return;
}


void BaseC::Process(std::vector<SDL_Event> &events, SDL_Renderer &renderer){


    // Set draw color to black and clear the entire window
    SDL_SetRenderDrawColor(&renderer, 0, 0, 0, SDL_ALPHA_OPAQUE);
    SDL_RenderClear(&renderer);

    // Set draw color to background color and fill entire renderer area (app area)
    SDL_SetRenderDrawColor(&renderer, 230, 230, 230, SDL_ALPHA_OPAQUE);
    SDL_RenderFillRect(&renderer, NULL);

    // Update scenes
    m_scenes.musicScene->Update();

    // Put the updated rendering of scenes on the newly-cleared screen
    SDL_RenderPresent(&renderer);


    return;
}

