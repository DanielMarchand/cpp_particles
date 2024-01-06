// Particlecc
#include "Particle.hh"

Particle::Particle(const Eigen::Vector2d& position, const Eigen::Vector2d& velocity, double mass)
    : position(position), velocity(velocity), mass(mass) {}

void Particle::updatePosition(double dt) {
    // Implementation of position update
}

Eigen::Vector2d Particle::getPosition() const {
    return position;
}

Eigen::Vector2d Particle::getVelocity() const {
    return velocity;
}

double Particle::getMass() const {
    return mass;
}
