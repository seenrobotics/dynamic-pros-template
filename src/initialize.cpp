#include <exception>
#include <iostream>

#include "globals.hpp"
#include "main.h"
#include "robot_factory.hpp"

/**
 * Runs initialization code. This occurs as soon as the program is started.
 *
 * All other competition modes are blocked by initialize; it is recommended
 * to keep execution time for this mode under a few seconds.
 */
void initialize() {
	try {
		robot->begin_tasks();
	} catch (std::exception& ex) {
		std::cerr << "Initialization exception: " << ex.what() << std::endl;
		while (true) {
			pros::delay(1000);
		}
	} catch (...) {
		std::cerr << "Unknown initialization exception: " << std::endl;
		while (true) {
			pros::delay(1000);
		}
	}
}

/**
 * Runs while the robot is in the disabled state of Field Management System or
 * the VEX Competition Switch, following either autonomous or opcontrol. When
 * the robot is enabled, this task will exit.
 */
void disabled() {}

/**
 * Runs after initialize(), and before autonomous when connected to the Field
 * Management System or the VEX Competition Switch. This is intended for
 * competition-specific initialization routines, such as an autonomous selector
 * on the LCD.
 *
 * This task will exit when the robot is enabled and autonomous or opcontrol
 * starts.
 */
void competition_initialize() {}
