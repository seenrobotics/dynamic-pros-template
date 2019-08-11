/**
 * \file robot.cpp
 *
 * This file defines all devices present on the robot.
 */
#include "robot.hpp"
#include "json.hpp"

Robot::Robot()
    : controller{CONTROLLER_MASTER},
      partner{CONTROLLER_PARTNER},
      mtr_lfront{1},
      mtr_rfront{2},
      mtr_lback{3},
      mtr_rback{4},
      mtr_util1{5},
      mtr_util2{6},
      mtr_util3{7},
      mtr_util4{8},
      driving_style{TANK_DRIVING},
      drive_type{TANK_DRIVE_4} {}

Robot::~Robot() {}

/**
 * Get instance of Robot singleton
 */
Robot& Robot::get_robot() {
	static Robot instance;
	// volatile
	return instance;
}

/**
 * Begin robot tasks
 */
void Robot::begin_tasks() {}

/**
 * Create motor groups for easier management of tank drives
 */
void Robot::create_motor_groups() {
	if (drive_type == TANK_DRIVE_4) {
		okapi::MotorGroup mtrgroup_left({mtr_lfront, mtr_lback});
		okapi::MotorGroup mtrgroup_right({mtr_rfront, mtr_rback});
	} else if (drive_type == TANK_DRIVE_6) {
		okapi::MotorGroup mtrgroup_left({mtr_lfront, mtr_lback, mtr_util1});
		okapi::MotorGroup mtrgroup_right({mtr_rfront, mtr_rback, mtr_util2});
	}
}

/**
 * Drive robot with controller
 */
void Robot::drive() {}

/**
 * Stop all motors
 */
void Robot::stop() {}