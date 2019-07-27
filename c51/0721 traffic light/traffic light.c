#include<reg51.h>
#define uchar unsigned char
#define uint unsigned int
sbit RED_A=P1^0;	//�������
sbit YELLOW_A=P1^1;
sbit GREEN_A=P1^2;
sbit RED_B=P1^3;	  //�ϱ���� 
sbit YELLOW_B=P1^4;
sbit GREEN_B=P1^5;
uchar Flash_Count=0,Operation_Type=1;  //��˸�������������ͱ���
//��ʱ
void DelayMS(uint x)
{
	uchar i;
	while(x--) for(i=0;i<120;i++);
}
 //��ͨ���л�
void Traffic_Light()
{
	switch(Operation_Type)
	{
		case 1:	 //������·�̵����ϱ�������
				RED_A=1;YELLOW_A=0;GREEN_A=0;
				RED_B=0;YELLOW_B=0;GREEN_B=1;
				DelayMS(10000);
				Operation_Type=2;
				break;
		case 2:		//������Ƶ���˸���̵ƹر�
				DelayMS(5000);
				YELLOW_A=~YELLOW_A;RED_A=0;
				if(++Flash_Count!=10) return; 
				GREEN_A=1;
				Flash_Count=0;
				Operation_Type=3;
				break;
		case 3:		//�������ƣ��ϱ����̵���
				RED_A=0;YELLOW_A=0;GREEN_A=1;
				RED_B=1;YELLOW_B=0;GREEN_B=0;
				DelayMS(10000);
				Operation_Type=4;
				break;
		case 4:		//�ϱ���Ƶ���˸5��
				DelayMS(5000);
				YELLOW_B=~YELLOW_B;RED_B=0;
				if(++Flash_Count!=10) return;
				GREEN_B=1;	
				Flash_Count=0;
				Operation_Type=1;
	}
}
//������
void main()
{
	while(1) Traffic_Light();
}
