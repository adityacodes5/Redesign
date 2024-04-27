#ifndef GYRO_H
#define GYRO_H

class gyro{
    public:

        gyro();
        void calibrate();
        void resetHeading(bool leftTurn);
        double getHeading();
}

#endif //GYRO_H