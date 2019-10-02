#include<iostream>
#include "SDL2/SDL.h"

using namespace std;

int main()
{

  // INITIALIZATION

  const int SCREEN_WIDTH = 800;
  const int SCREEN_HEIGHT = 600;

  if(SDL_Init(SDL_INIT_VIDEO) < 0){
    return 1;
  }
  cout << "SDL Init Succeeded" << endl;

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

  // RUNTIME START
  // ----------------------- //

  bool quit = false;

  SDL_Event event;

  while (!quit)
  {
    
    while(SDL_PollEvent(&event)){
      if(event.type == SDL_QUIT){
        quit = true;
      }
    }
  }
  

  // ----------------------- //
  // RUNTIME END


  // EXIT
  SDL_DestroyWindow(window);
  SDL_Quit();
  cout << "Program Exit Successful" << endl;
  return 0;
}
