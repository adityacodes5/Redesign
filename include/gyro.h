#ifndef GYRO_H
#define GYRO_H

class gyroData{
    public:

        gyroData();
        void calibrate();
        void resetHeading(bool leftTurn);
        double getHeading();
};

#endif //GYRO_H