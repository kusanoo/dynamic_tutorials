#include <ros/ros.h>
#include <dynamic_reconfigure/client.h>
#include <dynamic_tutorials/TutorialsConfig.h>

int main(int argc, char **argv){
  ros::init(argc, argv, "dynamic_reconfigure_client");
  dynamic_reconfigure::Client<dynamic_tutorials::TutorialsConfig> client("/dynamic_tutorials/");
  dynamic_tutorials::TutorialsConfig config;

  int x = 0;
  bool b = false;
  while(ros::ok())
  {
    x = x + 1;
    if (x > 10) x = 0;
    if (b) {
      b = false;
    } else {
      b = true;
    }
    config.int_param= x;
    config.double_param=(1/x+1);
    config.str_param="aaa";
    config.bool_param = b;
    config.size = 1;
    client.setConfiguration(config);
    ros::Duration(1).sleep();
  }
  return 0;
}