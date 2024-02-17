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
		std_msgs::Int16 position;
		int pos = 0;

		for (pos = 0; pos <= 180; pos += 1)
	    {
			position.data = pos;
			PosePublisher.publish(position);
			ROS_INFO("Servo Position is : %d", position.data);
			rate.sleep();	
		}  

		for (pos = 180; pos >= 0; pos -= 1)
        {
            position.data = pos;
            PosePublisher.publish(position);
			ROS_INFO("Servo Position is : %d", position.data);
            rate.sleep();
        }
	}

	return 0;
}







