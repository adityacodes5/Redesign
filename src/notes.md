**To whoever uses this code:**

This code includes my months of hard work, research and development. 
I have spent countless hours on this code and hope that whatever you do
with it, you do it well. Send me a email at aditya.mak08@gmail.com at any 
time for help with this code

Thanks and hope it helps you in your journey to success.
- Aditya Makhija


**Different things in V5 then C++**

1. Any V5 Smart devices declaration should be done in the 'robot-config.cpp' file. This file requires you
to declare any ports and devices you are using in your robot to be accessible in your code (for example,
drive motors, solenoids for pistons, etc.)

2. Any declaration of your V5 devices must also be written in the corresponding header file (so, for
every device you add to 'robot-config.cpp', you must also add it to 'robot-config.h')

Example:

    robot-config.cpp:

    ```cpp
    motor RightDrive = motor(PORT1, ratio18_1, false);
    ```

    This line should be reciprocated in the header file:

    robot-config.h:

    ```h
    extern motor RightDrive;
    ```

    'extern' gives the ability of the motor to be accessed from any part of the project, which is required
    to use it in different files within your project



3. Similar to the last part, any functions you create must be also be externed in their corresponding 
header file. 

Example:

    functions.cpp:

    ```cpp
    void myFunction(paramater1){
        do something...
    };
    ```

    functions.h:

    ```h
    extern void myFunction(paramater1);
    ```





