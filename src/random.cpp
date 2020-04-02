#include"ros_random/random.h"

RandomGen::RandomGen()
{
	publisherHandle=nodehandle.advertise<ros_random::cmsg1>("Random generator",1000);
}

void RandomGen::run()
{
	while(ros::ok())
	{
		srand(unsigned(time(NULL)));//generatore numero casuale al clock corrente
		std::cout<<"Random numbers generation...\n";
		csmg1 rand_msg;
		rand_msg.r1= rand()/3;
		rand_msg.r2= rand()/3;
		publisherHandle.publish(rand_msg);
		ros::spinOnce();
	}
}

int main(int argc, char** argv)
{
	ROS_INFO("Let start random generator node");
	ros::init(argc,argv,"RandomNode");
	RandomGen R;
	R.run();
	return 0;
}
