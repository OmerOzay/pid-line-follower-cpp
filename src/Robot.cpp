#include "Robot.h"
#include <cmath>

Robot::Robot(double start_x, double start_y, double base_speed)
    : x(start_x), y(start_y), theta(0.0), base_speed(base_speed),
      left_speed(base_speed), right_speed(base_speed) {}

void Robot::setMotorSpeeds(double correction){
    left_speed = base_speed - correction;
    right_speed = base_speed + correction;
}

void Robot::update(double dt){
    //Iki motor arasindaki hız farkı dönüsü (acisal hizi) belirler.
    double speed_diff = right_speed - left_speed;
    double avg_speed = (left_speed + right_speed) / 2.0;

    double omega = speed_diff * 0.05;
    theta += omega * dt;

    x += avg_speed * std::cos(theta) * dt;
    y += avg_speed * std::sin(theta) * dt;

}