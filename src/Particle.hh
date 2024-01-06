// Particle.hh
#ifndef PARTICLE_HH
#define PARTICLE_HH

#include <Eigen/Dense>

class Particle {
public:
    Particle(const Eigen::Vector2d& position, const Eigen::Vector2d& velocity, double mass);
    void updatePosition(double dt);
    
    Eigen::Vector2d getPosition() const;
    Eigen::Vector2d getVelocity() const;
    double getMass() const;

private:
    Eigen::Vector2d position;
    Eigen::Vector2d velocity;
    double mass;
};

#endif // PARTICLE_HH

