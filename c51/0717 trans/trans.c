#include<reg52.h>
#define uchar unsigned char
uchar a,flag;
void main()
{
	TMOD=0x20;
	TH1=0xFA;
	TL1=0xFA;
	TR1=1;
	SCON=0x50;
	EA=1;
	ES=1;
	PCON=0x80;
	while(1)
	{
		if(flag==1)
		{
			ES=0;
			flag=0;
			a+=1;
			SBUF=a;
			while(!TI);
			TI=0;
			ES=1;
		}
	}
}

void serial() interrupt 4
{
	
	a=SBUF;
	flag=1;
	RI=0;
}
