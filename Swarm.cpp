#include "Swarm.h"

namespace Particles {

Swarm::Swarm(/* args */)
{
  m_particles = new Particle[NPARTICLES];
}

Swarm::~Swarm()
{
  delete [] m_particles;
}

void Swarm::update(){
  for(int i = 0; i < Swarm::NPARTICLES; i++){
      m_particles[i].update();
    }
}

}