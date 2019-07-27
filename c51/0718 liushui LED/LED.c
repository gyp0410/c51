#include <reg52.h>
#include <intrins.h>
#define led P0
sfr AUXR = 0x8E;
sbit Btn=P2^0;
sbit LED=P2^1;
sbit butten=P3^2;
unsigned long ms=0;
unsigned long pre_ms=0;
char Flag_Btn=0;
unsigned int i;
void delay(int i);
void main()
{	
		IT0=1;
		EA=1;
		EX0=1;
		while(1)
		{
				led=0x80;    		//	10000000
				for(i=0;i<7;i++)
				{
					led=_crol_(led,1);
					delay(10000);
				}
		}
					while(1)
					{
						if(Flag_Btn==0)
						{
							delay(1000);
							if(Flag_Btn==0)	
							{
									LED=!LED;
							}	
						}
					}	
}	
void serial() interrupt 0
{
			if(butten==0)
			{	
						delay(1000);
						if(butten==0)
						{
								for(i=0;i<7;i++)
								{
											led=_cror_(led,1);
											delay(1000);
								}
						}
			}
						
}
			
			
void delay(int i)
{
	int x,y;
	for(x=i;x>0;x--)
		for(y=110;y>0;y--);
}