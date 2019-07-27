#include<reg51.h>
#include<intrins.h>
#define uchar unsigned char
#define uint unsigned int
uchar a,flag;
uchar code DSY_CODE[]={
0xc0,0xf9,0xa4,0xb0,

0x99,0x92,0x82,0xf8,

0x80,0x90,0x88,0x83,

0xc6,0xa1,0x86,0x8e};
void DelayMS(uint x)
{
	uchar t;
	while(x--) for(t=0;t<110;t++);
}
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
	P0=0x00;
	while(1)
	{
		
		if(flag==1)
		{
			ES=0;
			flag=0;
			DelayMS(7000);
			SBUF=a;
			P0=~DSY_CODE[a];
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
