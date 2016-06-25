#ifndef ORIENTATION_H
#define ORIENTATION_H


class Orientation
{
public:
    Orientation(double _pitch = 0, double _roll = 0, double _yaw = 0);

public:
    double pitch;
    double roll;
    double yaw;
};

#endif // ORIENTATION_H
