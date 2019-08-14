/**
 * \file nonholonomic_robot.hpp
 * \brief
 */
#ifndef NONHOLONOMIC_ROBOT_H_
#define NONHOLONOMIC_ROBOT_H_
#include "robot.hpp"

/**
 * \class NonHolnomicRobot
 * \brief A singleton thread safe robot class
 */
class NonHolonomicRobot : public Robot {
	public:
	enum class DriveType { TANK_DRIVE_MTR_4 = 0, TANK_DRIVE_MTR_6 = 1 };
	enum class DrivingStyle { SPLIT_ARCADE_DRIVING = 0, ARCADE_DRIVING = 1, TANK_DRIVING = 2 };
	static NonHolonomicRobot& get_robot();

	void begin_tasks();
	void create_motor_groups();
	void drive();
	void stop();

	private:
	NonHolonomicRobot();
	~NonHolonomicRobot();
	// Prevent copy construction.
	NonHolonomicRobot(const NonHolonomicRobot&) = delete;
	// Prevent copy assignment.
	NonHolonomicRobot& operator=(const NonHolonomicRobot&) = delete;
};

#endif