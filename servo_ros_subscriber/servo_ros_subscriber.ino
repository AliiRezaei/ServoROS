#include <ros.h>
#include <std_msgs/Int16.h>
#include <Servo.h>


ros::NodeHandle  nh;
Servo myservo;

std_msgs::Int16 position;

void pose_callback(const std_msgs::Int16 &pos)
{
    myservo.write(pos.data);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15ms for the servo to reach the position

}
ros::Subscriber<std_msgs::Int16> PoseSubscriber("servo_pose", pose_callback);

void setup() {

  myservo.attach(9);  // attaches the servo on pin 9 to the servo object
  nh.initNode();
  nh.subscribe(PoseSubscriber);

}


void loop() {

  nh.spinOnce();

}

