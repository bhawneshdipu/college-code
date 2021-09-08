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
	DDRB=0b00000000;
	int lm,l,m,r,rm,ps,flag=0,lc=0,rc=0,diff=0,flagend=0,f=0,flagrend=0,flagstraight=0;;
    while (1)
    {
		lm=PINC & 0b00000001;
		l=PINC & 0b00000010;
		m=PINC & 0b00000100;
		r=PINC & 0b00001000;
		rm=PINC & 0b00010000;
		ps=PINC & 0b00100000;

		if(ps==PS_T){
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
		}else if(ps==FALSE && lm==LM_T && l==FALSE && m==FALSE && r==FALSE && rm==RM_T && flagrend==0 ){


			while(1 && flagstraight==0){
				PORTD=FORWARD;
					lm=PINC & 0b00000001;
					l=PINC & 0b00000010;
					m=PINC & 0b00000100;
					r=PINC & 0b00001000;
					rm=PINC & 0b00010000;

				if( lm==FALSE && l==L_T && m==M_T && r==R_T && rm==FALSE )
					{
						flagstraight=1;
						break;
					}
			}
			while(1 && flagstraight==1){
				lm=PINC & 0b00000001;
				l=PINC & 0b00000010;
				m=PINC & 0b00000100;
				r=PINC & 0b00001000;
				rm=PINC & 0b00010000;

				if(lm==FALSE && l==L_T && m==M_T && r==R_T && rm==FALSE){
					flagrend=1;
					break;
				}
				PORTD=RIGHT;

			}/*extra*/
			if(flagend==1 &&  lm==LM_T && l==FALSE && m==FALSE && r==FALSE && rm==RM_T){
				while(1)
				PORTD=STOP;
			}/*extra*/
		}else
		if(lm==FALSE && l==L_T && m==M_T && r==R_T && rm==FALSE ){
			PORTD=FORWARD;
			flag=0;
		}
		else if(lm==FALSE && l==L_T && m==M_T && r==FALSE  && rm==FALSE)
			PORTD=LEFT;
		else if(lm==FALSE && l==L_T && m==FALSE && r==FALSE  && rm==FALSE)
			PORTD=LEFT;
		else if(lm==LM_T && l==L_T && m==M_T && r==R_T  && rm==FALSE){
			if(flag==0)
				lc++;

			flag=1;
			PORTD=FORWARD;


		}
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
		else if(lm==FALSE && l==L_T && m==M_T && r==R_T  && rm==RM_T){
			if(flag==0)
				rc++;
			flag=1;
			PORTD=FORWARD;
		}
		else if(lm==FALSE && l==FALSE && m==FALSE && r==FALSE  && rm==FALSE)
			PORTD=STOP;
		else if(lm==LM_T && l==FALSE && m==FALSE && r==FALSE  && rm==RM_T){

				while(1 && flagend==0){
				lm=PINC & 0b00000001;
				l=PINC & 0b00000010;
				m=PINC & 0b00000100;
				r=PINC & 0b00001000;
				rm=PINC & 0b00010000;

				if(lm==FALSE && l==L_T && m==M_T && r==R_T && rm==FALSE){
					flagend=1;
					break;
				}
				PORTD=FORWARD;
				}
				if(flagend==1)
					PORTD=STOP;

		}
		else if((lm==LM_T && l==L_T && m==M_T && r==R_T  && rm==RM_T)){
			if(f==0){
				PORTD=STOP;
				diff=(lc-rc);
				if(diff<0)diff=-1*diff;

				switch(diff){
					case 0:
							break;
					case 1:PORTB=0x01;
							_delay_ms(1000);
							break;
					case 2:PORTB=0x03;
							_delay_ms(2000);
							break;
					case 3:PORTB=0x07;
							_delay_ms(3000);
							break;
					case 4:PORTB=0x0f;
							_delay_ms(4000);
							break;
					default:PORTB=0x00;

				}

				_delay_ms(2000);
				PORTB=0x00;
				PORTD=FORWARD;
				f=1;
			}
			else{
				PORTD=FORWARD;
			}
		}
	}

}
