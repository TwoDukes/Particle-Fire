#include<iostream>
#include "SDL2/SDL.h"
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

    for (int y = 0; y < Screen::SCREEN_HEIGHT; y++)
    {
      for(int x = 0; x < Screen::SCREEN_WIDTH; x++){
        screen.setPixel(x, y, 128, 0, 255);       
      }
    }
    

    screen.setPixel(400, 300, 255, 255, 255);

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
