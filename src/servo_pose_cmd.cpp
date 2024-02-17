// This Node is a simple position publisher used in servo_control package.

#include "ros/ros.h"
#include "std_msgs/Int16.h"


int main(int argc, char **argv)
{	
	// init ros and create node handle objec :
	ros::init(argc, argv, "pose_cmd");
	ros::NodeHandle nh;

	// declare publisher :
	ros::Publisher PosePublisher = nh.advertise<std_msgs::Int16>("servo_pose", 1000);

	// publishing rate (Hz) :
	ros::Rate rate(15);

	// while ros master is connected, publish servo position :
	while(ros::ok())
	{
		std_msgs::Int16 position; // for publishing
		int pos = 0;              // for loop

		// servo start position --> 0   degrees
		// servo start position --> 180 degrees
		// direction --> counter clockwise
		for (pos = 0; pos <= 180; pos += 1)
	    {
			// assigning loop var to the publishher var :
			position.data = pos;

			// publish current position :
			PosePublisher.publish(position);

			// display servo angle in terminal :
			ROS_INFO("Servo Position is : %d degrees", position.data);

			// get some delay :
			rate.sleep();	
		} // end of for 

		// servo start position --> 180 degrees
		// servo start position --> 0   degrees
		// direction --> clockwise
		for (pos = 180; pos >= 0; pos -= 1)
        {
			// assigning loop var to the publishher var :
            position.data = pos;

			// publish current position :
            PosePublisher.publish(position);

			// display servo angle in terminal :
			ROS_INFO("Servo Position is : %d degrees", position.data);
            
			// get some delay :
			rate.sleep();
        } // end of for
	} // end of while

	return 0;

} // end of main







