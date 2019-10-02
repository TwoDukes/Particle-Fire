
#ifndef SCREEN_H_
#define SCREEN_H_

#include "SDL2/SDL.h"

namespace Graphics {

class Screen
{
  
  public:
    static const int SCREEN_WIDTH = 800;
    static const int SCREEN_HEIGHT = 600;

  private:
    SDL_Window *m_window;
    SDL_Renderer *m_renderer;
    SDL_Texture *m_texture;
    Uint32 *m_buffer;


  public:
    Screen(/* args */);
    bool init();
    bool processEvents();
    void close();

};

}

#endif // !SCREEN_H_
