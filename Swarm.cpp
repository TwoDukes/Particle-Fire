#include "Swarm.h"

namespace Particles {

Swarm::Swarm():lastTime(0)
{
  m_particles = new Particle[NPARTICLES];
}

Swarm::~Swarm()
{
  delete [] m_particles;
}

void Swarm::update(int elapsedMillis){

  int interval = elapsedMillis - lastTime;

  for(int i = 0; i < Swarm::NPARTICLES; i++){
      m_particles[i].update(interval);
    }

  lastTime = elapsedMillis;
}

}