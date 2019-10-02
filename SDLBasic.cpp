#include<iostream>
#include "SDL2/SDL.h"

using namespace std;

int main()
{
 
  // PROGRAM INITIALIZATION  ------------------------------------- //

  const int SCREEN_WIDTH = 800;
  const int SCREEN_HEIGHT = 600;

  if(SDL_Init(SDL_INIT_VIDEO) < 0){
    return 1;
  }
  cout << "SDL Init Succeeded" << endl;

  // initialize window
  SDL_Window *window = SDL_CreateWindow("Particle Fire", 
                                        SDL_WINDOWPOS_UNDEFINED,
                                        SDL_WINDOWPOS_UNDEFINED,
                                        SCREEN_WIDTH, SCREEN_HEIGHT,
                                        SDL_WINDOW_SHOWN  
                                       );

  if(window == NULL){
    SDL_Quit();
    return 2;
  }

  // initialize renderer
  SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_PRESENTVSYNC);
  SDL_Texture *texture = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_RGBX8888, SDL_TEXTUREACCESS_STATIC, SCREEN_WIDTH, SCREEN_HEIGHT);

  if(renderer == NULL){ 
    cout << "Could not create renderer" << endl;
    SDL_DestroyWindow(window);
    SDL_Quit();
    return 3;
  }

  if(texture == NULL){ 
    cout << "Could not create texture" << endl;
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
    return 4;
  }

  Uint32 *buffer = new Uint32[SCREEN_WIDTH * SCREEN_HEIGHT];

  memset(buffer, 0xFF, SCREEN_WIDTH * SCREEN_HEIGHT * sizeof(Uint32));

  SDL_UpdateTexture(texture, NULL, buffer, SCREEN_WIDTH * sizeof(Uint32));
  SDL_RenderClear(renderer);
  SDL_RenderCopy(renderer, texture, NULL, NULL);
  SDL_RenderPresent(renderer);


  // SETUP ------------------------------------- //

  SDL_Event event;
  
  bool quit = false;

  // GRAPHICS LOOP START ----------------------- //

  while (!quit)
  {
    
    while(SDL_PollEvent(&event)){
      if(event.type == SDL_QUIT){
        quit = true;
      }
    }
  } 

  // GRAPHICS LOOP END ----------------------- //


  // PROGRAM EXIT  ------------------------------------- //
  delete [] buffer;
  SDL_DestroyRenderer(renderer);
  SDL_DestroyTexture(texture);
  SDL_DestroyWindow(window);
  SDL_Quit();
  cout << "Program Exit Successful" << endl;
  return 0;
}
