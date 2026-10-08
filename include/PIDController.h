#ifndef PID_CONTROLLER_H
#define PID_CONTROLLER_H

class PIDController {
private:
    double kp;
    double ki;
    double kd;

    double previous_error;
    double integral;

public:
    PIDController(double kp, double ki, double kd);

    double calculate(double error, double dt);
};

#endif