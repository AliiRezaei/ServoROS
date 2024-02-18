// This is a simple subscriber node for subscribing micro servo position.
// please upload this code to your arduino (uno) board.

#include <ros.h>
#include <std_msgs/Int16.h>
#include <Servo.h>

ros::NodeHandle nh;   // node handler
Servo micro_servo;    // micro servo object
int servo_pin = 9;    // data attached pin

// pose subscriber caalback :
void pose_callback(const std_msgs::Int16 &pos)
{
    micro_servo.write(pos.data); // write subscribed position
    delay(15);                   // get some delay
}

// position subscriber :
ros::Subscriber<std_msgs::Int16> PoseSubscriber("servo_pose", pose_callback);

void setup()
{

  micro_servo.attach(servo_pin);   // config micro servo object
  nh.initNode();                   // initialize node handler
  nh.subscribe(PoseSubscriber);    // subscribe possition subscriber

}


void loop()
{

  nh.spinOnce(); // ros spin

}
