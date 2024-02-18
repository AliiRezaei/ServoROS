# Servo Control Package for ROS and Arduino

This package allows you to connect your servo motor to ROS and Arduino, and control its position using ROS commands. Follow the steps below to install and use the package:

## Installation

Before using the package, make sure you have installed the necessary packages. If not, run the following commands:

```bash
$ sudo apt install rosserial-arduino
$ sudo apt install rosserial-python
```

## Setting Permissions

In this part, you must change your serial-port permission and activate read and write permissions for this purpose open a new terminal and write the following command:

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

Now, you can echo servo_pose topic for visualize transformated data in this topic by this command :

```bash
$ rostopic echo /servo_pose
```

as you can see, the servo position printed in terminal environment.

## Conclusion

With this package, you can easily control your servo motor using ROS commands. By following these simple steps, you can connect ROS and Arduino and control your servo motor's position.
