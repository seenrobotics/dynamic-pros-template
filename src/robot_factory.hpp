#ifndef ROBOT_FACTORY_H_
#define ROBOT_FACTORY_H_
#include <functional>
#include <map>
#include <string>
#include "robot.hpp"

class RobotFactory {
	public:
	std::map<std::string, std::function<Robot*(void)>> factory_function_registry;

	Robot* create_robot(std::string robot_type);
	void register_factory_function(std::string robot_type, std::function<Robot*(void)> class_factory_function);
	static RobotFactory* instance();
};
#endif