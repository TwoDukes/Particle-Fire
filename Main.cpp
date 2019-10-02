#include<iostream>
#include "SDL2/SDL.h"
#include <math.h>
#include <stdlib.h>
#include "Screen.h"
#include "Swarm.h"
#include "Particle.h"

using namespace std;
using namespace Graphics;
using namespace Particles;

int main()
{
 
  // PROGRAM INITIALIZATION  ------------------------------------- //

  srand(time(NULL)); // Sets random number generator seed to current time

  Screen screen;

  if(screen.init() == false){
    cout << "Error initializing SDL" << endl;
  }


  // SETUP ------------------------------------- //

  Uint32 fps = 0;
  Swarm swarm;

  // GRAPHICS LOOP START ----------------------- //

  while (true)
  {
    // Update Particles
    int elapsedMillis = SDL_GetTicks();
    
    screen.clear();
    swarm.update();

    unsigned char red = (unsigned char)((1 + sin(elapsedMillis * 0.0001)) * 128);
    unsigned char green = (unsigned char)((1 + sin(elapsedMillis * 0.0002)) * 128);
    unsigned char blue = (unsigned char)((1 + sin(elapsedMillis * 0.0003)) * 128);

    const Particle * const pParticles = swarm.getParticles();
    for(int i = 0; i < Swarm::NPARTICLES; i++){
      Particle particle = pParticles[i];

      int x = (particle.m_x + 1) * Screen::SCREEN_WIDTH/2;
      int y = (particle.m_y + 1) * Screen::SCREEN_HEIGHT/2;

      screen.setPixel(x,y,red,green,blue);
    }

    // Draw the screen
    screen.update();

    /* FPS Counter
    if(elapsedMillis % 1000 == 0){
      cout << "FPS: " << fps << endl;
      fps = 0;
    }
    ++fps;
    */

    // check for events
    if(!screen.processEvents()){
      break;
    }
  } 

  // GRAPHICS LOOP END ----------------------- //

  screen.close();
  
  return 0;
}
