#ifndef SWARM_H_
#define SWARM_H_

#include "Particle.h"

namespace Particles {

class Swarm
{
public:
  static const int NPARTICLES = 80000;

private:
  Particle * m_particles;
  int lastTime;
public:
  Swarm();
  ~Swarm();
  void update(int elapsedMillis);

  const Particle * const getParticles(){return m_particles;}
};

}

#endif // !SWARM_H_