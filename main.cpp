#include <iostream>
#include <SDL.h>
#include <SDL_ttf.h>
#include <SDL_image.h>
#include <SDL_mixer.h>
using namespace std;

// SDL Window
SDL_Window *_window;

// SDL Renderer to draw to
SDL_Renderer *_renderer;

// Our default font
TTF_Font *_font;

// Easy access to a useful color
SDL_Color white = {255, 255, 255};

// Window size
int _width = 1280;
int _height = 960;

// Our sample header texture and where we're drawing our header to
SDL_Rect _headerTextRect;
SDL_Texture *_headerText;

// Our sample texture
SDL_Texture *_image;

// Our sample rectangle that we can drag around the viewport
SDL_Rect _sampleRect = {.x = 10, .y = 10, .w = 100, .h = 100};
SDL_bool _inSampleRect = SDL_FALSE;

// Our sample 'music'
Mix_Music *_music = NULL;


void init_sdl()
{
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
        printf("[Error] SDL Init : %s \n", SDL_GetError());
    } else {
        printf("SDL INITIALISED\n");
        SDL_DisplayMode dm;
        SDL_GetCurrentDisplayMode(0, &dm);

        printf("Display mode is %dx%dpx @ %dhz\n", dm.w, dm.h, dm.refresh_rate);
    }
}


/**
 * Initialise an SDL Window and Renderer
 *
 * This uses SDL_CreateWindowAndRenderer. They can alternatively be created separately. See SDL2 Docs
 */
void init_window_and_renderer()
{
    if (SDL_CreateWindowAndRenderer(_width, _height, SDL_WINDOW_SHOWN, &_window, &_renderer) != 0) {
        printf("[Error] Creating Window and Renderer: %s\n", SDL_GetError());
        exit(0);
    } else {
        printf("Created Window and Renderer %dx%d\n", _width, _height);
    }
}

/**
 * Initialise TTF
 */
void init_ttf()
{
    TTF_Init();
}

/**
 * Initialise mixer
 */
void init_audio()
{
    if (Mix_OpenAudio(22050, MIX_DEFAULT_FORMAT, 2, 4096) != 0) {
        printf("[Error] Error Initialising Audio : %s\n", SDL_GetError());
    } else {
        printf("Audio Initialised\n");
    }
}



int main() {
    init_sdl();
}
