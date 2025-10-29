#ifndef SCENEC
#define SCENEC

// Include necessary standard or custom headers here
#include <string>
#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>
#include <SDL3_image/SDL_image.h>
#include <SDL3/SDL_render.h>
#include <SDL3_ttf/SDL_ttf.h>
#include <vector>
#include "ConstantDefs.h"

class SceneC {
public:
    // Constructor and Destructor (virtual destructor due to derived classes) 
    SceneC();
    virtual ~SceneC();

    // Virtual methods (to be overridden in derived scenes)
    virtual void    Initialize(void) = 0;
            
    // Common methods for all scenes
    void    GetMousePositionOverScene(float* x, float* y);

private:

    static int sm_Volume;
    
};

#endif // SCENEC