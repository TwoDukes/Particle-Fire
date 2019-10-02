#include<iostream>
#include "SDL2/SDL.h"
#include <math.h>
#include "Screen.h"


using namespace std;
using namespace Graphics;

int main()
{
 
  // PROGRAM INITIALIZATION  ------------------------------------- //

  Screen screen;

  if(screen.init() == false){
    cout << "Error initializing SDL" << endl;
  }


  // SETUP ------------------------------------- //

  

  // GRAPHICS LOOP START ----------------------- //

  while (true)
  {
    // Update Particles
    int elapsedMillis = SDL_GetTicks();
    unsigned char red = (unsigned char)((1 + sin(elapsedMillis * 0.0001)) * 128);
    unsigned char green = (unsigned char)((1 + sin(elapsedMillis * 0.0002)) * 128);
    unsigned char blue = (unsigned char)((1 + sin(elapsedMillis * 0.0003)) * 128);


    for (int y = 0; y < Screen::SCREEN_HEIGHT; y++)
    {
      for(int x = 0; x < Screen::SCREEN_WIDTH; x++){
        screen.setPixel(x, y, red, green, blue);       
      }
    }

    // Draw the screen
    screen.update();

    // check for events
    if(!screen.processEvents()){
      break;
    }
  } 

  // GRAPHICS LOOP END ----------------------- //

  screen.close();
  
  return 0;
}
