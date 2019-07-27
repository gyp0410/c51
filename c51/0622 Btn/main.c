#include <reg51.h>
#include <intrins.h>
sfr AUXR        =   0x8E;
sbit LED=P3^7;
sbit Btn=P3^6;
sbit LED1=P3^5;
sbit Btn1=P3^4;
unsigned long ms=0;
unsigned long pre_ms=0;
void Timer0Init(void);
char Flag_Btn=0;
void main()
{
	char Flag_BTN=0;
	char f1,f2;
	Timer0Init();
	ET0=1; //enable timer 0 interrupt
	EA=1; //enable all interrupt
	while(1)
	{
		if(ms-pre_ms>=100)
		{
			pre_ms=ms;
			f2=f1;
			f1=Btn;
				if((f1==0)&&(f2==1))
				{
					
					if(Flag_Btn==0)
					{
						LED=!LED;
						LED1=!LED;
						Flag_Btn=1;
					}
				}
				else 
					Flag_Btn=0;
		}
		else if(Btn1==0)
					{
						LED=1;
						LED1=1;
					}
	}
}


void Timer0Init(void)		//11.0592MHz
{
	AUXR |= 0x80;		
	TMOD &= 0xF0;		
	TMOD |= 0x01;		
	TL0 = 0xCD;			
	TH0 = 0xD4;			
	TF0 = 0;		
	TR0 = 1;				
}

 void t0() interrupt 1 using 0
 {
 	TL0 = 0xCD;		
	TH0 = 0xD4;		
	ms++;
 	
 }
 