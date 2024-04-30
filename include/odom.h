#ifndef ODOM_H
#define ODOM_H


class odom{
    public:
        odom();
        const double degToRad = M_PI / 180;

        double x;
        double y;
        double heading;
        double bearing;
        double centerPos;
        double prevCenterPos;
        double deltaCenter;

        void updatePosition(double initialX, double initialY, double initialHeading);
};

#endif // ODOM_H