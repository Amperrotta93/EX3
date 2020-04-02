#include"ros/ros.h"
#include"ros_random/cmsg1"
#include<iostream>
#include<stdlib.h>
#include<time.h>
#include"std_msgs/String.h"
#ifndef RANDOMGEN_H_
#define RANDOMGEN_H_

//CUSTOM MESSAGE cmsg1 with following fields
//float32 r1
//float32 r2
class RandomGen
{
	public:
		RandomGen();
		void run()
	private:
		ros::NodeHandle nodehandle;
		ros::Publisher publisherhandle;
}
#endif /* RANDOMGEN_H_ */
