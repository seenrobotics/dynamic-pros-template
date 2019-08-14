/**
 * \file robot.hpp
 * \brief
 */
#ifndef ROBOT_H_
#define ROBOT_H_

#include "okapi/api.hpp"

/**
 * \class Robot
 * \brief A singleton thread safe robot class
 */
class Robot {
	public:
	enum class DriveType;
	enum class DrivingStyle;

	pros::Controller controller;
	pros::Controller partner;

	okapi::Motor mtr_lfront;
	okapi::Motor mtr_rfront;
	okapi::Motor mtr_lback;
	okapi::Motor mtr_rback;

	okapi::Motor mtr_util1;
	okapi::Motor mtr_util2;
	okapi::Motor mtr_util3;
	okapi::Motor mtr_util4;

	DrivingStyle driving_style;
	DriveType drive_type;

	virtual void begin_tasks() = 0;
	virtual void drive() = 0;
	virtual void stop() = 0;

	virtual ~Robot(){};
};

#endif