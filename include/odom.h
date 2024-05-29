#ifndef ODOM_H
#define ODOM_H
using namespace std;


class odom{
    public:
        odom();
        const double degToRad = M_PI / 180;
        const double radToDeg = 180 / M_PI;

        double x;
        double y;
        double heading;
        double bearing;
        double centerPos;
        double prevCenterPos;
        double deltaCenter;

        void updatePosition(double initialX, double initialY);
};

#endif // ODOM_H