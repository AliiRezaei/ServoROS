#include "ros/ros.h"
#include "std_msgs/Int16.h"


int main(int argc, char **argv)
{
	ros::init(argc, argv, "pose_cmd");
	ros::NodeHandle nh;

	ros::Publisher PosePublisher = nh.advertise<std_msgs::Int16>("servo_pose", 1000);

	ros::Rate rate(15);

	while(ros::ok())
	{
		std_msgs::Int16 position;
		int pos = 0;

		for (pos = 0; pos <= 180; pos += 1)
	       	{
			position.data = pos;
			PosePublisher.publish(position);
			rate.sleep();	
		}  

		for (pos = 180; pos >= 0; pos -= 1)
                {
                        position.data = pos;
                        PosePublisher.publish(position);
                        rate.sleep();
                }
	}

	return 0;
}







