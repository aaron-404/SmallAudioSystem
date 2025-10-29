#ifndef MUSICSCENEC
#define MUSICSCENEC

// Include necessary standard or custom headers here
#include <string>
#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>
#include <SDL3_image/SDL_image.h>
#include <SDL3/SDL_render.h>
#include <SDL3_ttf/SDL_ttf.h>
#include <vector>
#include "ConstantDefs.h"


class MusicSceneC {
public:
    // Constructor and Destructor (virtual destructor due to derived classes) 
    MusicSceneC();
    virtual ~MusicSceneC();

    void    Initialize(void);
    void    Update(void);

private:

    
};

#endif // SCENEC