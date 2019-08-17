#include "registrar.hpp"
#include "holonomic_robot.hpp"
#include "nonholonomic_robot.hpp"
#include "robot.hpp"
#include "robot_factory.hpp"

template <class T>
Registrar<T>::Registrar(std::string robot_type) {
	// register the class factory function
	RobotFactory::instance()->register_factory_function(robot_type, [](void) -> Robot* { return new T(); });
}

static Registrar<HolonomicRobot> registrar_holonomic("Holonomic");
static Registrar<NonHolonomicRobot> registrar_nonholonomic("NonHolonomic");