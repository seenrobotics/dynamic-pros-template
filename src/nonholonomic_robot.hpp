/**
 * \file nonholonomic_robot.hpp
 * \brief
 */
#ifndef NONHOLONOMIC_ROBOT_H_
#define NONHOLONOMIC_ROBOT_H_
#include "okapi/api.hpp"
#include "robot.hpp"


/**
 * \class NonHolnomicRobot
 * \brief A singleton thread safe robot class
 */
class NonHolonomicRobot : public Robot {
	public:
	enum class DriveType { TANK_DRIVE_MTR_4 = 0, TANK_DRIVE_MTR_6 = 1 };
	enum class DrivingStyle { SPLIT_ARCADE_DRIVING = 0, ARCADE_DRIVING = 1, TANK_DRIVING = 2 };
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
	NonHolonomicRobot();
	virtual ~NonHolonomicRobot(){};

	void begin_tasks() override;
	void drive() override;
	void stop() override;
};

#endif