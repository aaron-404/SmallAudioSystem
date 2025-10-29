
#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>
#include <SDL3_image/SDL_image.h>
#include <SDL3/SDL_render.h>
#include <SDL3_ttf/SDL_ttf.h>
#include <iostream>
#include <stdio.h>
#include <iomanip>
#include <vector>
#include <string>
#include "BaseC.h"
#include "LogC.h"
#include "ConstantDefs.h"

const int FPS_LIMIT = 30;
const int TICKS_PER_FRAME = SDL_MS_PER_SECOND / FPS_LIMIT;

static SDL_Window *window = NULL;
static SDL_Renderer *renderer = NULL;


int main(){

    // Write startup log
    LogC log;
    log.MakeLogEntry("SmallAudioSystem Starting...", LogC::LT_INFO);

    // Initialize SDL libraries
    if (!SDL_Init(SDL_INIT_VIDEO)){
        std::string errorMsg = SDL_GetError();
        log.MakeLogEntry("Couldn't initialize SDL: " + errorMsg, LogC::LT_ERROR);
        return SDL_APP_FAILURE;
    }

    if (!TTF_Init()){
        std::string errorMsg = SDL_GetError();
        log.MakeLogEntry("Couldn't initialize TTF: " + errorMsg, LogC::LT_ERROR);
        SDL_Quit();
        return SDL_APP_FAILURE;
    }

    // Create window and renderer
    if (!SDL_CreateWindowAndRenderer("Explorer", SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_RESIZABLE, &window, &renderer)) {
        std::string errorMsg = SDL_GetError();
        log.MakeLogEntry("Couldn't create window and/or renderer: " + errorMsg, LogC::LT_ERROR);
        TTF_Quit();
        SDL_Quit();
        return SDL_APP_FAILURE;
    }

    // Set renderer logical presentation (allows scaling screensize without complicating logic, while maintaining aspect ration)
    SDL_SetRenderLogicalPresentation(renderer, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_LOGICAL_PRESENTATION_LETTERBOX);

    // Initialize base class [contains all scenes for system]
    BaseC systemBase;

    // Create vector to store events
    std::vector<SDL_Event> events;

    // Main App Loop
    bool running = true;
    while (running){

        // Start of Loop
        // Get tickCount before processing frame
        uint64_t currentTicks = SDL_GetTicks();

        // Clear event vector to remove events already processed in previous frames
        events.clear();

        // Put events polled by SDL into event vector, quit app if closed
        SDL_Event event;
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_EVENT_QUIT) {
                running = false;
                break;
            }
            else{
                events.push_back(event);
            }
        }

        // Stop if app was quit
        if(!running){
            break;
        }
            
        // Update necessary scenes and render active scene (pass events and SDL renderer to base class to process events and update UI)
        systemBase.Process(events, *renderer);

        // End of Loop
        // If frame finished quickly, wait <#> more ticks before looping to the next frame
        // (Ensures each frame lasts at least # ticks to limit FPS)
        uint64_t endTicks = SDL_GetTicks();
        uint64_t frameTicks = endTicks - currentTicks;
        if (frameTicks < TICKS_PER_FRAME){
            SDL_Delay((TICKS_PER_FRAME - frameTicks));
        }
        
    }

    //LogC::MakeLogEntry("SmallAudioSystem shutting down...\n", LogC::LT_INFO);
    log.MakeLogEntry("SmallAudioSystem shutting down...", LogC::LT_INFO);

    // Close SDL renderer, window, and library when quit
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    TTF_Quit();
    SDL_Quit();

    return 0;
}

















