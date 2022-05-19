/*
 * new_mask_styler.c
 *
 * Created: 2022-05-19 오후 12:56:36
 * Author : hongki
 */ 
#define F_CPU 16000000UL
#define True 1
#define False 0

#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include <math.h>
#include "setup_adc.h"
#include "setup_motor.h"
#include "uart.h"


int main(void)
{
	
	setup_pin();
	ADC_INIT();
	UART1_initialize_polling();
	setup_pwm_1();
	setup_pwm_2();
	
	sei();
    /* Replace with your application code */
    while (1) 
    {
		
		OCR1A = 8000;
    }
}

