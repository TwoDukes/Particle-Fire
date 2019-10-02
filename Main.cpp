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
    
    if(!screen.processEvents()){
      break;
    }
  } 

  // GRAPHICS LOOP END ----------------------- //

  screen.close();
  
  return 0;
}
