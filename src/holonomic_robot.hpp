/**
 * \file holonomic_robot.hpp
 * \brief
 */
#ifndef HOLONOMIC_ROBOT_H_
#define HOLONOMIC_ROBOT_H_
#include "okapi/api.hpp"
#include "robot.hpp"


/**
 * \class HolonomicRobot
 * \brief A singleton thread safe robot class
 */
class HolonomicRobot : public Robot {
	public:
	enum class DriveType { MECANUM_DRIVE = 0, X_DRIVE = 1 };
	enum class DrivingStyle {
		SPLIT_ARCADE_DRIVING = 0

	};

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

	HolonomicRobot();
	virtual ~HolonomicRobot(){};

	void begin_tasks() override;
	void drive() override;
	void stop() override;
};

#endif