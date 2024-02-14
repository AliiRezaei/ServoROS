#include <ros.h>
#include <std_msgs/Int16.h>
#include <Servo.h>

ros::NodeHandle  nh;
Servo myservo;

std_msgs::Int16 position;
ros::Publisher PosePublisher("servo_pose", &position);

int pos = 0;
int servo_pin = 9;


void setup() {


  myservo.attach(servo_pin);  // attaches the servo on pin 9 to the servo object
  nh.initNode();
  nh.advertise(PosePublisher);

}


void loop() {

  for (pos = 0; pos <= 180; pos += 1) { // goes from 0 degrees to 180 degrees

    // in steps of 1 degree

    myservo.write(pos);              // tell servo to go to position in variable 'pos'
    position.data = pos;
    PosePublisher.publish(&position);
    nh.spinOnce();
    delay(15);                       // waits 15ms for the servo to reach the position

  }

  for (pos = 180; pos >= 0; pos -= 1) { // goes from 180 degrees to 0 degrees

    myservo.write(pos);              // tell servo to go to position in variable 'pos'
    position.data = pos;
    PosePublisher.publish(&position);
    nh.spinOnce();
    delay(15);                       // waits 15ms for the servo to reach the position

  }

}
