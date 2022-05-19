#include "setup_motor.h"
#include <avr/io.h>

void setup_pin()
{
	DDRA = 0xff;
	PORTA = 0x00; 
	// led 설정 핀으로 모터 작동이나 각종 동작에의해 if문을 걸어서 디버깅용으로 사용 
	
	DDRB = 0xff;
	PORTB = 0b00001111;
	//OC1A, OC1B --> PB5, PB6
	//OC0, OC2 --> PB4, PB7
	DDRE = 0b00011000;
	PORTE = 0x00;
	
	DDRD = 0xff;
	PORTD = 0x00; // switch 
	
	
	DDRF = 0x00;// ADC PIN setup
	
}


 void setup_pwm_1()// 자동문 제어주기 1초
{
	TCCR1A = (1 << COM1A0) | (0 << COM1A1) | (1 << WGM11) | (1 << WGM10);
	TCCR1B = (1 << WGM13) | (1 << WGM12) | (0 << CS12) | (1 << CS11) | (0 << CS10);
	TCCR1C = 0x00;

	TCCR3A = (1 << COM3A0) | (0 << COM3A1) | (1 << WGM31) | (1 << WGM32);
	TCCR3B = (1 << WGM33) | (1 << WGM32) | (0 << CS32) | ( 1 << CS31) | (0 << CS30);
	TCCR3C = 0x00;
	
	TCNT1 = 0;
	TCNT3 = 0;
	ICR1 = 2047; // 976.6hz == 대충 1초
	ICR3 = 2047;
	//fastpwm mode, compare match, non-inverting ,prescaler 8로 설정,. clear oc1a, oc1b
	//OCR1A = ICR1 * 0.1 ==> 10% duty
}


 void setup_pwm_2() // fan제어주기 1초
{
	TCCR0 = (1 << WGM01) | (1 << WGM00) | (1 << COM01) | (0 << COM00) | (1 << CS02) | (1 << CS01) | (0 << CS00);
	TCNT0 = 0;
	
	//fast pwm mode, prescaler 256 //main문에서 count를 활용
}

void setup_servo()
{
	TCCR2 |= (1 << WGM21) | (1 << WGM20) | (1 << COM21) | (0 << COM20) | (1 << CS22) | (1 << CS21) | (0 << CS20);
	TCNT2 = 0;
	
	//fast pwm mode, prescaler 256 //main문에서 count를 활용 어케함
	
}
void timer_counter_interrupt()
{
	TIMSK |= (1 << TOIE2) | (1 << TOIE1) | (1 << TOIE0);
	ETIMSK |= (1 << TOIE3);
	
	// 0,2 // 1,3 timercounter interrupt 활성화
	// isr(time_ovf_어쩌고 설정 가능
}