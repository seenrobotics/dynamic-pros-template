/**
 * \file holonomic_robot.hpp
 * \brief
 */
#ifndef HOLONOMIC_ROBOT_H_
#define HOLONOMIC_ROBOT_H_
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
	static HolonomicRobot& get_robot();

	void begin_tasks();
	void create_motor_groups();
	void drive();
	void stop();

	private:
	HolonomicRobot();
	~HolonomicRobot();
	// Prevent copy construction.
	HolonomicRobot(const HolonomicRobot&) = delete;
	// Prevent copy assignment.
	HolonomicRobot& operator=(const HolonomicRobot&) = delete;
};

#endif