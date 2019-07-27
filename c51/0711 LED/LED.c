#include <reg51.h>
sbit LED=P3^7;
sbit Btn=P3^6;
//void delay(uint z);
void main()
{
	while(1)
	{
			//delay(1000);
			if(Btn==0)
			LED=!LED;
	}
}


/*void delay(uint z)
{
	uint x,y;
		for(x=z;x>0;x--)
			for(y=110;y>0;y--);
}
	*/