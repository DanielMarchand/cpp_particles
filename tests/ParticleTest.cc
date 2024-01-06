// ParticleTest.cc
#include "Particle.hh"
#include <gtest/gtest.h>

class ParticleTest : public ::testing::Test {
protected:
    // Set up test environment here, if needed
};

TEST_F(ParticleTest, Initialization) {
    Eigen::Vector2d position(0, 0);
    Eigen::Vector2d velocity(1, 1);
    double mass = 1.0;
    Particle particle(position, velocity, mass);

    ASSERT_TRUE(particle.getPosition().isApprox(position));
    ASSERT_TRUE(particle.getVelocity().isApprox(velocity));
    ASSERT_DOUBLE_EQ(particle.getMass(), mass);
}

// Add more tests as needed


