#include <ros/ros.h>
#include <nav_msgs/Odometry.h>
#include <geometry_msgs/PoseWithCovarianceStamped.h>

class OdomToPose
{
  public:

    OdomToPose();

  private:

    ros::NodeHandle nh_, nhp_;

    ros::Subscriber odom_sub_;
    ros::Publisher pose_pub_;

  // helper functions

    void odomCallback(const nav_msgs::Odometry::ConstPtr& odom_msg);
};

OdomToPose::OdomToPose()
  : nhp_("~")
{
  odom_sub_ = nh_.subscribe("odom", 100, &OdomToPose::odomCallback, this);
  pose_pub_ = nh_.advertise<geometry_msgs::PoseWithCovarianceStamped>("pose", 100);
}

void OdomToPose::odomCallback(const nav_msgs::Odometry::ConstPtr& odom_msg)
{
  geometry_msgs::PoseWithCovarianceStamped pose_msg;
  pose_msg.header = odom_msg->header;
  pose_msg.pose = odom_msg->pose;

  pose_pub_.publish( pose_msg );
}

int main(int argc, char *argv[])
{
  ros::init(argc, argv, "odom_to_pose");

  OdomToPose odom_to_pose;

  ROS_INFO("odom_to_pose node running...");

  ros::spin();

  return 0;
}
 
