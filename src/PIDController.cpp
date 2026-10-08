#include "PIDController.h"

PIDController::PIDController(double kp, double ki, double kd)
{
    this->kp = kp;
    this->ki = ki;
    this->kd = kd;

    previous_error = 0.0;
    integral = 0.0;
}

double PIDController::calculate(double error, double dt)
{
    integral += error * dt;

    double derivative = (error - previous_error) / dt;

    double output =
        kp * error +
        ki * integral +
        kd * derivative;

    previous_error = error;

    return output;
}