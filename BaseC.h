#ifndef BASEC
#define BASEC

// Include necessary standard or custom headers here
#include <string>
#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>
#include <SDL3_image/SDL_image.h>
#include <SDL3/SDL_render.h>
#include <SDL3_ttf/SDL_ttf.h>
#include <vector>
#include "ConstantDefs.h"
#include "SceneC.h"
#include "MusicSceneC.h"

class BaseC {
public:
    // Constructor and Destructor
    BaseC();
    ~BaseC();

    void            InitializeScenes(void);
    void            Process(std::vector<SDL_Event> &events, SDL_Renderer &renderer);

    // Struct to hold each scene used in application
    struct SceneContainerT{
        MusicSceneC* musicScene;
    };

private:

    TTF_Font* m_font;

    SceneContainerT m_scenes;
    
};

#endif // BASEC