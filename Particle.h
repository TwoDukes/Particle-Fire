#ifndef PARTICLE_H_
#define PARTICLE_H_

namespace Particles {

struct Particle
{
  double m_x;
  double m_y;

  double m_xspeed;
  double m_yspeed;

  Particle();
  ~Particle();
  void update();
};

}



#endif // !PARTICLE_H_