# ServoROS
micro servo position control with ROS and Arduino

make sure you already installed neccessary packages. if you do not, try this

```bash
    $ sudo apt install rosserial-arduino
    $ sudo apt install rosserial-python
```

set /dev/ttyACM0 permission

```bash
    $ sudo chmod 666 /dev/ttyACM0
```

connect your Arduino board and upload code. you can use servo_ros_publisher or servo_ros_subscriber for this issue. in first case you can upload servo_ros_subscriber after uploading code, you should be run a node from rosserial_python package. this node is serial_node.py . open a new terminal and execute this

```bash
    $ rosrun rosserial_python serial_node.py /dev/ttyACM0
```

by running the above command, your connection with arduino and ros has been set up.
now, you can execute servo_pose_cmd node and send position command for your servo motor. open a new terminal and try this

```bash
    $ rosrun servo_control servo_pose_cmd
```

after doing this, you can see servo motor has moved.

in other case you can upload another arduino code called servo_ros_publisher. simmilarlly, connect your board and upload code from arduino IDE. now you see servo has been moved. open another terminal and check rostopics.


```bash
    $ rostopic list
```





<!-- 
Numeric Calculation of the Mandelbulb.
For more info click here: [Mandelbulb](https://en.wikipedia.org/wiki/Mandelbulb)

Time complexity of the existing Code is O(n^3)...
So, to enhance the speed, the code was reimplemented in C++.  

Code for the Data-Generation contains of:
1. CPP
2. MATLAB

In all the codes, ***DIM*** variable indicates the resolution of the data.

Running the MATLAB code is simple but the CPP code is a bit tricky.

Compile the CPP code using the following command:

```bash
    $ g++ -std=c++11 -o MandelOut Mandel.cpp -lm
```

#### To run the code there are 2 available Flags

***-n:***
    power for the **Z** in the main equation.
***-d:***
    the same **DIM** which is the resolution of the data.

Example:

```bash
    $ ./MandelOut -n 8 -d 128
```

> ***Note:*** There is also a simpler implementation of the Mandelbulb in the cpp folder. Just set the vars and run the code. :)

![](images/basic.jpg)
![](images/topview.jpg) -->