/**
 * \file robot.hpp
 * \brief
 */
#ifndef ROBOT_H_
#define ROBOT_H_
#include "main.h"
#include "okapi/api.hpp"

enum DrivingStyle { ARCADE_DRIVING = 0, SPLIT_ARCADE_DRIVING = 1, TANK_DRIVING = 2 };
enum DriveType { MECANUM_DRIVE = 0, TANK_DRIVE_4 = 1, TANK_DRIVE_6 = 2, X_DRIVE = 3 };

/**
 * \class Robot
 * \brief A singleton thread safe robot class
 */
class Robot {
	public:
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

	static okapi::MotorGroup mtrgroup_left;
	static okapi::MotorGroup mtrgroup_right;

	DrivingStyle driving_style;
	DriveType drive_type;

	static Robot& get_robot();

	void begin_tasks();
	void create_motor_groups();
	void drive();
	void stop();

	private:
	Robot();
	~Robot();
	// Prevent copy construction.
	Robot(const Robot&) = delete;
	// Prevent copy assignment.
	Robot& operator=(const Robot&) = delete;
};

#endif