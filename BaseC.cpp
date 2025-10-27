#include "BaseC.h"
#include <iostream>
#include <vector>
#include <memory>
#include <SDL3/SDL.h>


// Default constructor
BaseC::BaseC() {

    // Initialize All Scenes
    InitializeScenes();

}

// Destructor
BaseC::~BaseC() {
    // Cleanup
}


void BaseC::InitializeScenes(void){

    //TODO

    return;

}


void BaseC::Process(std::vector<SDL_Event> &events, SDL_Renderer &renderer){


    // Set draw color to black and clear the entire window
    SDL_SetRenderDrawColor(&renderer, 0, 0, 0, SDL_ALPHA_OPAQUE);
    SDL_RenderClear(&renderer);

    // Set draw color to background color and fill entire renderer area (app area)
    SDL_SetRenderDrawColor(&renderer, 200, 200, 200, SDL_ALPHA_OPAQUE);
    SDL_RenderFillRect(&renderer, NULL);

    // Update position and logic for non-player game entities
    // for(EntityC* entity : m_Entities){
    //     entity->Update(deltaTime, events, keyboardState);
    //     entity->Render(renderer);
    // }

    //MOUSE??? AUDIO???
    

    // Put the updated rendering of game objects on the newly-cleared screen
    SDL_RenderPresent(&renderer);



    return;
}

