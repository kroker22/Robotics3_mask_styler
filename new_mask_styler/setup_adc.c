/*
 * setup_adc.c
 *
 * Created: 2022-05-19 오후 1:01:13
 *  Author: hongki
 */ 


#define TRUE 1
#define FALSE 0
#include "setup_ADC.h"
#include <avr/io.h>
#include <avr/interrupt.h>

void ADC_INIT()
{
	ADMUX = 0x00;
	ADCSRA = (1 << ADEN) | (1 << ADPS2) | ( 1<< ADPS1) | (1 << ADPS0);
	
}
double ADC_POTEN_GET()
{
	ADMUX = 0x00;
	ADCSRA |= ( 1<< ADSC);
	while(!(ADCSRA & (1 << ADIF)));
	int adc = ADC ;
	
	double Vadc = adc * 5./1023. ;
	
	return Vadc;
}

double ADC_PSD_GET()
{
	ADMUX = 0x01;
	ADCSRA |= ( 1<< ADSC);
	while(!(ADCSRA & (1 << ADIF)));
	int adc = ADC;
	
	double psd_voltage = adc * 5./1023. ;
	return psd_voltage;
}
double calc_psd(double volt)
{
	double val = 0.04 * volt;
	return (1/val);
}


double ADC_lm35_GET()
{
	ADMUX = 0x02;
	ADCSRA |= ( 1<< ADSC);
	
	while(!(ADCSRA & (1 << ADIF)));
	int adc = ADC ;
	double vadc = adc * 5./1023.;
	
	return vadc;
}
double calc_lm35(double num)
{
	double T = 100 * num;
	return T;
}
