#ifndef PARTICLE_H_
#define PARTICLE_H_

namespace Particles {

struct Particle
{
  double m_x;
  double m_y;

  double m_speed;
  double m_direction;

  Particle();
  ~Particle();
  void update(int interval);
};

}



#endif // !PARTICLE_H_