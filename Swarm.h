#ifndef SWARM_H_
#define SWARM_H_

#include "Particle.h"

namespace Particles {

class Swarm
{
public:
  static const int NPARTICLES = 5000;

private:
  Particle * m_particles;
public:
  Swarm();
  ~Swarm();
  void update();

  const Particle * const getParticles(){return m_particles;}
};

}

#endif // !SWARM_H_