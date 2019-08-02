/**
 * \file pid.hpp
 * \brief
 *
 */
#ifndef PID_H_
#define PID_H_

/**
 * \class Pid
 *
 * \brief A general purpose PID class.
 */
class Pid {
	public:
	/**
	 * Construct correction value from specified constants: kp, ki, and kd.
	 * Defaults to (0,0,0)
	 *
	 * \param[in] kp proportional constant.
	 * \param[in] ki integral constant.
	 * \param[in] kd derivative constant.
	 */
	Pid(double* kp = 0, double* ki = 0, double* kd = 0);

	/**
	 * Reset the error counts. It should be called when the PID loop is not
	 * active to prevent integral windup.
	 */
	void ResetError();

	/**
	 * Return the output of the PID controller correcting the input.
	 *
	 * \param[in] setpoint current setpoint value
	 * \param[in] current_value current value eventually compared with setpoint
	 */
	double Update(double setpoint, double current_value);

	private:
	// PID constants (Proportional (P), Integral (I), Derivative (D))
	double* kp_;
	double* ki_;
	double* kd_;

	// Summation of errors used in the integral term
	double error_sum_;

	// The last error value to find the difference with the current error value
	// for the derivative term.
	double last_error_;
};

#endif
