#include "ros/ros.h"
#include "ros/time.h"
#include "std_msgs/Float64.h"
#include "manipulator_gazebo/MoveArm.h"
#include "sensor_msgs/JointState.h"

using namespace std_msgs;

//  global parameters
const int	N = 200;
double		dt;
double		current_joint_states[6];


void calc_cartezian_trajectory(double CT[6][N] , double desX , double desY , double desZ ,double desROLL , double desPITCH , double desYAW)
{
	// YOUR CODE HERE
}

void calc_joint_trajectory(double CT[6][N] , double JT[6][N])
{
	// YOUR CODE HERE
}

void calc_initial_joint_state(double ijs[6],double cjs[6])
{
	// YOUR CODE HERE
}

void control_joint_trajectory(double JT[6][N])
{
	// YOUR CODE HERE
	// a command to wait half a second: ros::Duration(0.5).sleep();
}

bool move_arm(manipulator_gazebo::MoveArm::Request  &req,
              manipulator_gazebo::MoveArm::Response &res)
{
	double cartezian_trajectory[6][N];
	double joint_trajectory[6][N];
	double initial_joint_states[6];

	double desX		= req.desired_xyz[0].data;
	double desY		= req.desired_xyz[1].data;
	double desZ		= req.desired_xyz[2].data;
	double desROLL	= req.desired_rpy[0].data;
	double desPITCH	= req.desired_rpy[1].data;
	double desYAW	= req.desired_rpy[2].data;

	dt					= req.duration.data/N;

	ROS_INFO("current joint states: %.3f  %.3f  %.3f  %.3f  %.3f  %.3f ", current_joint_states[0],
																		  current_joint_states[1],
																		  current_joint_states[2],
																		  current_joint_states[3],
																		  current_joint_states[4],
																		  current_joint_states[5]);
	ROS_INFO("I got:");
	ROS_INFO("desired [ x y z ]          = [ %.3f %.3f %.3f ]",desX,desY,desZ);
	ROS_INFO("desired [ roll pitch yaw ] = [ %.3f %.3f %.3f ]",desROLL,desPITCH,desYAW);
	ROS_INFO("desired iteration time     = %f",dt);

	ROS_INFO("Calculating cartezian trajectory");
	calc_cartezian_trajectory( cartezian_trajectory , desX ,desY , desZ , desROLL , desPITCH , desYAW);

	ROS_INFO("Calculating joint trajectory");
	calc_joint_trajectory(cartezian_trajectory,joint_trajectory);

	ROS_INFO("Sending joint trajectory and controlling");
    control_joint_trajectory(joint_trajectory);

	res.success.data = "True";

	return true;
}

void jointCallback(const sensor_msgs::JointState &msg)
{
	current_joint_states[0] = msg.position[3];
	current_joint_states[1] = msg.position[0];
	current_joint_states[2] = msg.position[6];
	current_joint_states[3] = msg.position[1];
	current_joint_states[4] = msg.position[2];
	current_joint_states[5] = msg.position[7];
}

int main(int argc, char **argv)
{
  ros::init(argc, argv, "move_arm_server");
  ros::NodeHandle n;

  ros::ServiceServer 	service = n.advertiseService("move_arm", move_arm);
  ros::Subscriber 		joints_sub_ = n.subscribe("/manipulator/joint_states", 1000, jointCallback );


  ROS_INFO("Ready for commands:");
  ros::spin();

  return 0;
}
