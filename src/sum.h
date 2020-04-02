#include"ros/ros.h"
#include"ros_random/cmsg1"
#include"ros_random/cmsg2"
#include<iostream>
#include<stdlib.h>
#include<time.h>
#include"std_msgs/String.h"
#ifndef SUM_H_
#define SUM_H_

//CUSTOM MESSAGE cmsg1 with following fields
//float32 r1
//float32 r2
class sum
{
	public:
		sum();
		void run();		
		void topicCallback(const ros_random::cmsg1::ConstPtr& rand_msg);
		float res;
	private://Questo nodo è subscriber di random, ma a sua volta è un publisher
		ros::NodeHandle nodehandle;
		ros::Subscriber sub;
				
		
}
#endif /* RANDOMGEN_H_ */
