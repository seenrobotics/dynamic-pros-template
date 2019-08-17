#include "robot_factory.hpp"
#include "robot.hpp"

Robot* RobotFactory::create_robot(std::string robot_type) {
	Robot* instance = nullptr;
	auto it = factory_function_registry.find(robot_type);
	if (it != factory_function_registry.end()) {
		// mapped value (std::function<Robot*(void)>).
		instance = it->second();
	}

	if (instance != nullptr) {
		return instance;
	} else {
		return nullptr;
	}
}

void RobotFactory::register_factory_function(std::string robot_type,
                                             std::function<Robot*(void)> class_factory_function) {
	factory_function_registry[robot_type] = class_factory_function;
}

RobotFactory* RobotFactory::instance() {
	static RobotFactory factory;
	return &factory;
}