#ifndef GYRO_H
#define GYRO_H

class gyroData{
    public:

        gyroData();
        void calibrate();
        void resetHeading(bool leftTurn);
        double getHeading();
        double getBearing();
};

#endif //GYRO_H