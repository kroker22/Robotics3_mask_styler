/*
 * setup_motor.h
 *
 * Created: 2022-05-19 오후 12:57:51
 *  Author: hongki
 */ 


#ifndef SETUP_MOTOR_H_
#define SETUP_MOTOR_H_

#include <avr/io.h>

void setup_pin();
void setup_pwm_1();
void setup_pwm_2();


void setup_fan();

void timer_counter_interrupt();



#endif /* SETUP_MOTOR_H_ */