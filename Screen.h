
#ifndef SCREEN_H_
#define SCREEN_H_

#include "SDL2/SDL.h"

namespace Graphics {

class Screen
{
  
  public:
    static const int SCREEN_WIDTH = 900;
    static const int SCREEN_HEIGHT = 900;

  private:
    SDL_Window *m_window;
    SDL_Renderer *m_renderer;
    SDL_Texture *m_texture;
    Uint32 *m_buffer1;
    Uint32 *m_buffer2;


  public:
    Screen(/* args */);
    bool init();
    void update();
    void clear();
    void boxBlur();
    void setPixel(int x, int y, Uint8 red, Uint8 green, Uint8 blue);
    bool processEvents();
    void close();

};

}

#endif // !SCREEN_H_
