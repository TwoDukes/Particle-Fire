#include "Screen.h"

namespace Graphics {

Screen::Screen(/* args */): m_window(NULL),m_renderer(NULL),m_texture(NULL),m_buffer1(NULL)
{
    
}

bool Screen::init()
{
  if(SDL_Init(SDL_INIT_VIDEO) < 0){
    return false;
  }

  // initialize window
  m_window = SDL_CreateWindow("Particle Fire", 
                                        SDL_WINDOWPOS_UNDEFINED,
                                        SDL_WINDOWPOS_UNDEFINED,
                                        SCREEN_WIDTH, SCREEN_HEIGHT,
                                        SDL_WINDOW_SHOWN  
                                       );

  if(m_window == NULL){
    SDL_Quit();
    return false;
  }

  // initialize renderer
  m_renderer = SDL_CreateRenderer(m_window, -1, SDL_RENDERER_PRESENTVSYNC);
  m_texture = SDL_CreateTexture(m_renderer, SDL_PIXELFORMAT_RGBX8888, SDL_TEXTUREACCESS_STATIC, SCREEN_WIDTH, SCREEN_HEIGHT);

  if(m_renderer == NULL){ 
    SDL_DestroyWindow(m_window);
    SDL_Quit();
    return false;
  }

  if(m_texture == NULL){ 
    SDL_DestroyRenderer(m_renderer);
    SDL_DestroyWindow(m_window);
    SDL_Quit();
    return false;
  }

  m_buffer1 = new Uint32[SCREEN_WIDTH * SCREEN_HEIGHT];
  m_buffer2 = new Uint32[SCREEN_WIDTH * SCREEN_HEIGHT];

  // Sets pixels to full black
  memset(m_buffer1, 0, SCREEN_WIDTH * SCREEN_HEIGHT * sizeof(Uint32));
  memset(m_buffer2, 0, SCREEN_WIDTH * SCREEN_HEIGHT * sizeof(Uint32));

  return true;
}

void Screen::setPixel(int x, int y, Uint8 red, Uint8 green, Uint8 blue){

  if(x < 0 || x >= SCREEN_WIDTH || y < 0 || y >= SCREEN_HEIGHT) return; // remove for efficiency

  Uint32 color = 0;

  color += red;
  color <<= 8;
  color += green;
  color <<= 8;
  color += blue;
  color <<= 8;
  color += 0xFF;

  // RGBA

  m_buffer1[(y * SCREEN_WIDTH + x)] = color;
}

void Screen::update(){
  SDL_UpdateTexture(m_texture, NULL, m_buffer1, SCREEN_WIDTH * sizeof(Uint32));
  SDL_RenderClear(m_renderer);
  SDL_RenderCopy(m_renderer, m_texture, NULL, NULL);
  SDL_RenderPresent(m_renderer);
}

void Screen::clear(){
  memset(m_buffer1, 0, SCREEN_WIDTH * SCREEN_HEIGHT * sizeof(Uint32));
  memset(m_buffer2, 0, SCREEN_WIDTH * SCREEN_HEIGHT * sizeof(Uint32));
}

void Screen::boxBlur(){
  // buffer data swap
  Uint32 *temp = m_buffer1;
  double blurAmount = 1.0; // Best between 0.9 and 1.0
  m_buffer1 = m_buffer2;
  m_buffer2 = temp;

  for(int y = 0; y < SCREEN_HEIGHT; y++){
    for(int x = 0; x < SCREEN_WIDTH; x++){

      /*
      *   C
      *   O
      *   L
      * 0 0 0 
      * 0 1 0 row
      * 0 0 0
      */

     int redTotal = 0;
     int greenTotal = 0;
     int blueTotal = 0;

      for(int row = -1; row <= 1; row++){
        for(int col = -1; col <= 1; col++){
          int currentX = x + col;
          int currentY = y + row;

          // If pixel is on screen
          if(currentX >= 0 && currentX < SCREEN_WIDTH && currentY >= 0 && currentY < SCREEN_HEIGHT){
            Uint32 color = m_buffer2[currentY * SCREEN_WIDTH + currentX]; // get current pixel

            // Get colors from pixel
            Uint8 red = color >> 24;
            Uint8 green = color >> 16;
            Uint8 blue = color >> 8;

            // Add up amount of color in the box pattern in total
            redTotal += red;
            greenTotal += green;
            blueTotal += blue;

          }
        }
      }

      // Divide by 9 for the 9 pixels checked in box pattern for total color
      Uint8 red = redTotal/9 * blurAmount;
      Uint8 green = greenTotal/9 * blurAmount;
      Uint8 blue = blueTotal/9 * blurAmount;

      setPixel(x,y,red,green,blue);

    }
  }
}

bool Screen::processEvents()
{
  SDL_Event event;

  while(SDL_PollEvent(&event)){
      if(event.type == SDL_QUIT){
        return false;
      }
    }
    return true;
}

void Screen::close(){
  delete [] m_buffer1;
  SDL_DestroyRenderer(m_renderer);
  SDL_DestroyTexture(m_texture);
  SDL_DestroyWindow(m_window);
  SDL_Quit();
}

}