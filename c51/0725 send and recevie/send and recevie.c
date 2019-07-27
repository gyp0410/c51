#include <reg52.h>
sfr AUXR = 0xfe;
sfr BRT = 0xff;
unsigned long preMs=0;
unsigned long MS=0;
unsigned char receiveArr[4];
unsigned int receiveData=0;
unsigned int send_value=0;
char receive_i=0; 
unsigned char flag,i;
char a;
bit  Flag_receive=0;
bit  Flag_send=0;
unsigned char sendArr[2]={0};
void UartInit();
void Timer0Init();
	
	
void main()
{
		Timer0Init();
		UartInit();
		EA=1;
		ES=1;
	while(1)
	{
		if(Flag_receive)
		{
				//ES=0;
				//Flag_receive=0;
				//preMs=MS;
				//	receiveArr[receive_i++]=SBUF;
				
				//if((MS-preMs>=10)&&(!Flag_receive))
				//{
			

						//receiveData=(int)receiveArr[1]*256+receiveArr[0];
					//	send_value=receiveData+1;
					//	sendArr[1]=send_value/256;
					//	Flag_receive=1;
						receiveData=send_value;
						Flag_send=1;
						SBUF=receiveData/256;
						Flag_receive=0;
					//	while(!TI);		 
					//	TI=0;	
						//ES=1;
				//}					
		}
	}
}


void Timer0Init(void)		
{
	AUXR |= 0x80;		
	TMOD &= 0xF0;		
	TL0 = 0x91;		
	TH0 = 0xFF;		
	TF0 = 0;		
	TR0 = 1;		
}
void t0_1ms() interrupt 3
{
		TL0 = 0x91;		
		TH0 = 0xFF;		
}

void UartInit(void)		
{
	PCON &= 0x7F;		
	SCON = 0x50;		
	AUXR |= 0x04;		
	BRT = 0xDC;		
	AUXR |= 0x01;		
	AUXR |= 0x10;		
}

void serial() interrupt 4 using 0
{
		if(RI)
		{
			RI=0;
			receiveData=SBUF;//????
			if(receiveArr[receive_i]==0x0A)//????????
			{
				receive_i=0;//????????????
				Flag_receive=1;//????????
			}
			if(TI)
			{
				TI=0;
				if(Flag_send)
				{
					SBUF=receiveData%256;
					Flag_send=0;
				}
			}
}
}

