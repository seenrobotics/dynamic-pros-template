#include "robot.hpp"
#include "globals.hpp"
#include "robot_factory.hpp"

Robot::~Robot() {}

Robot* robot = RobotFactory::instance()->create_robot("Holonomic");