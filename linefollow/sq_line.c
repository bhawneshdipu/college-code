/*
 * extremeIR.c
 *
 * Created: 28-01-2016 18:23:58
 * Author : DIPU
 */
#include <avr/io.h>
#define F_CPU 12000000UL
#include <util/delay.h>

#define FORWARD 0b10010000
#define STOP 0b00000000
#define RIGHT 0b00010000
#define LEFT 0b10000000
#define FALSE 0x00
#define LM_T 0x01
#define L_T 0x02
#define M_T 0x04
#define R_T 0x08
#define RM_T 0x10
#define PS_T 0x20

int main(void)
{
    /* Replace with your application code */
	DDRC=0b00000000;
	PORTC=0b00000001;
	int lm,l,m,r,rm,ps,flag=0;
    while (1)
    {
		lm=PINC & 0b00000001;
		l=PINC & 0b00000010;
		m=PINC & 0b00000100;
		r=PINC & 0b00001000;
		rm=PINC & 0b00010000;
		ps=PINC & 0b00100000;

		if(l==L_T && m==M_T && r==R_T )
			PORTD=FORWARD;
		else if(lm==FALSE && l==L_T && m==M_T && r==FALSE  && rm==FALSE)
			PORTD=LEFT;
		else if(lm==FALSE && l==L_T && m==FALSE && r==FALSE  && rm==FALSE)
			PORTD=LEFT;
		else if(lm==LM_T && l==L_T && m==M_T && r==R_T  && rm==FALSE)
			PORTD=LEFT;
		else if(lm==LM_T && l==FALSE && m==FALSE && r==FALSE  && rm==FALSE){

			while(1){

					lm=PINC & 0b00000001;
					l=PINC & 0b00000010;
					m=PINC & 0b00000100;
					r=PINC & 0b00001000;
					rm=PINC & 0b00010000;

				if(lm==FALSE && l==L_T && m==M_T && r==R_T && rm==FALSE){
						break;
				}



					PORTD=LEFT;

			}

		}
		else if(lm==FALSE && l==FALSE && m==FALSE && r==FALSE  && rm==RM_T){

			while(1){
				lm=PINC & 0b00000001;
				l=PINC & 0b00000010;
				m=PINC & 0b00000100;
				r=PINC & 0b00001000;
				rm=PINC & 0b00010000;

				if(lm==FALSE && l==L_T && m==M_T && r==R_T && rm==FALSE){

					break;
				}
				PORTD=RIGHT;

			}
		}
		else if(lm==FALSE && l==FALSE && m==FALSE && r==R_T  && rm==RM_T)
			PORTD=RIGHT;
		else if(lm==FALSE && l==FALSE && m==FALSE && r==R_T  && rm==FALSE)
			PORTD=RIGHT;
		else if(lm==FALSE && l==FALSE && m==M_T&& r==R_T  && rm==RM_T)
			PORTD=RIGHT;
		else if(lm==FALSE && l==FALSE && m==M_T&& r==R_T  && rm==FALSE)
			PORTD=RIGHT;
		else if(lm==FALSE && l==L_T && m==M_T && r==R_T  && rm==RM_T)
			PORTD=RIGHT;
		else if(lm==FALSE && l==FALSE && m==FALSE && r==FALSE  && rm==FALSE)
			PORTD=STOP;



	}


}

