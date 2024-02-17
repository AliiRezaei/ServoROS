#include <ros.h>
#include <std_msgs/Int16.h>
#include <Servo.h>


// global variables :
ros::NodeHandle  nh;                                   // node handler
Servo micro_servo;                                     // micro servo onject

std_msgs::Int16 position;                              // publisher var
ros::Publisher PosePublisher("servo_pose", &position); // position publisher

int pos = 0;                                           // micro servo initial position
int servo_pin = 9;                                     // data attached pin
// end of global variables.

void setup() 
{

  micro_servo.attach(servo_pin);  // configue micro servo object
  nh.initNode();                  // initialize node handler
  nh.advertise(PosePublisher);    // advertise position publisher

}


void loop()
{

  // servo start position --> 0   degrees
	// servo start position --> 180 degrees
	// direction --> counter clockwise
  for (pos = 0; pos <= 180; pos += 1) 
  {
    // write current position :
    micro_servo.write(pos);
    
    // assigning loop var to the publishher var :
    position.data = pos;
    
    // publish current position :
    PosePublisher.publish(&position);
    
    // ros spin :
    nh.spinOnce();

    // get some delay :
    delay(15);
  } // end of for loop

  // servo start position --> 180 degrees
  // servo start position --> 0   degrees
	// direction --> clockwise
  for (pos = 180; pos >= 0; pos -= 1)
  {
    // write current position :
    micro_servo.write(pos);

    // assigning loop var to the publishher var :
    position.data = pos;

    // publish current position :
    PosePublisher.publish(&position);
    
    // ros spin :
    nh.spinOnce();

    // get some delay :
    delay(15);
  } // end of for loop

} // end of void loop