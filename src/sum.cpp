#include"ros_random/sum.h"
//Costruttore
sum::sum()
{
	sub=nodeHAndle.subscriber("RandomPub",1000,Subscriber::topicCallback,this);
	publisherHandle=nodehandle.advertise<ros_random::cmsg2>("Sum",1000);
}

//

void sum::topicCallback(const ros_random::cmsg1::ConstPtr& rand_msg)
{
		ROS_INFO("Sum listens random  numbers r1: %f",rand_msg->r1);
		ROS_INFO("r2: %f",rand_msg->r2);
		sleep(1);
		cmsg2 s;
		s.R1=rand_msg->r1 ;
		s.R2=rand_msg->r2 ;
 		s.R3= rand_msg->r1 + rand_msg->r2;
		publisherHandle.publish(s);
		ros::spinOnce();
	
				
}

void sum::run()
{
	while(ros::ok())
	{
		
		std::cout<<"Random sum numbers...\n";
		publisherHandle.publish(s);
		ros::spinOnce();
	}
}

int main(int argc, char** argv)
{
	ROS_INFO("Let start sum node");
	ros::init(argc,argv,"SumNode");
	sum s;
	s.run();
	return 0;
}
