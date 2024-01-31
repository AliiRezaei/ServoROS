<!-- # ServoROS
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
``` -->



# Servo Control Package for ROS and Arduino

This package allows you to connect your servo motor to ROS and Arduino, and control its position using ROS commands. Follow the steps below to install and use the package:

## Installation

Before using the package, make sure you have installed the necessary packages. If not, run the following commands:

```bash
$ sudo apt install rosserial-arduino
$ sudo apt install rosserial-python
```

## Setting Permissions

Set /dev/ttyACM0 permission by running the following command:

```bash
$ sudo chmod 666 /dev/ttyACM0
```

## Uploading Code

Upload the code to your Arduino board. You can use either servo_ros_publisher or servo_ros_subscriber. For the first case, upload servo_ros_subscriber to your Arduino board, and then run a node from rosserial_python package. This node is called serial_node.py. Open a new terminal and execute the following command:

```bash
$ rosrun rosserial_python serial_node.py /dev/ttyACM0
```

By running the above command, your connection with Arduino and ROS has been set up. Now, you can execute servo_pose_cmd node and send position commands for your servo motor. Open a new terminal and try the following command:

```bash
$ rosrun servo_control servo_pose_cmd
```

After executing this command, you should see your servo motor move.

Alternatively, you can upload another Arduino code called servo_ros_publisher. Similarly, connect your board and upload code from Arduino IDE. Now, check rostopics by running the following command:

```bash
$ rostopic list
```

## Conclusion

With this package, you can easily control your servo motor using ROS commands. By following these simple steps, you can connect ROS and Arduino and control your servo motor's position.

ServoREADME.txt
Displaying ServoREADME.txt.