#ifndef ROBOT_H
#define ROBOT_H

class Robot {
private:
    double x;
    double y;
    double theta;
    double base_speed;
    double left_speed;
    double right_speed;

public:
    Robot(double start_x, double start_y, double base_speed);

    void setMotorSpeeds(double correction);
    void update(double dt);

    double getX() const {return x;}
    double getY() const {return y;}
    double getLeftSpeed() const {return left_speed;}
    double getRightSpeed() const {return right_speed;}
};

#endif