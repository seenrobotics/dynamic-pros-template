/**
 * \file holonomic_robot.cpp
 *
 * This file defines all devices present on the robot.
 */
#include "holonomic_robot.hpp"
#include "globals.hpp"
#include "json.hpp"
#include "main.h"

HolonomicRobot::HolonomicRobot()
    : controller{pros::E_CONTROLLER_MASTER},
      partner{pros::E_CONTROLLER_PARTNER},
      mtr_lfront{MTR_PORT_LFRONT},
      mtr_rfront{MTR_PORT_RFRONT},
      mtr_lback{MTR_PORT_LBACK},
      mtr_rback{MTR_PORT_RBACK},
      mtr_util1{MTR_PORT_UTIL1},
      mtr_util2{MTR_PORT_UTIL2},
      mtr_util3{MTR_PORT_UTIL3},
      mtr_util4{MTR_PORT_UTIL4},
      driving_style{DrivingStyle::SPLIT_ARCADE_DRIVING},
      drive_type{DriveType::X_DRIVE} {}

/**
 * Begin robot tasks
 */
void HolonomicRobot::begin_tasks() {}

/**
 * Drive robot with controller
 */
void HolonomicRobot::drive() {}

/**
 * Stop all motors
 */
void HolonomicRobot::stop() {
	mtr_lfront.moveVoltage(0);
	mtr_lfront.moveVoltage(0);
	mtr_rfront.moveVoltage(0);
	mtr_lback.moveVoltage(0);
	mtr_rback.moveVoltage(0);
	mtr_util1.moveVoltage(0);
	mtr_util2.moveVoltage(0);
	mtr_util3.moveVoltage(0);
	mtr_util4.moveVoltage(0);
}