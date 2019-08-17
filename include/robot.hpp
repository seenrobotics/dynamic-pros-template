/**
 * \file robot.hpp
 * \brief
 */
#ifndef ROBOT_H_
#define ROBOT_H_

/**
 * \class Robot
 * \brief A singleton thread safe robot class
 */
class Robot {
	public:
	enum class DriveType;
	enum class DrivingStyle;

	virtual ~Robot();

	virtual void begin_tasks() = 0;
	virtual void drive() = 0;
	virtual void stop() = 0;

	protected:
	Robot(){};
};

#endif