# ServoROS
micro servo position control with ROS and Arduino

make sure you already installed neccessary packages. if you not, try this

```bash
    $ sudo apt install rosserial-arduino
    $ sudo apt install rosserial-python
```

set /dev/ttyACM0 permission

```bash
    $ sudo chmod 666 /dev/ttyACM0
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