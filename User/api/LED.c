#include "LED.h"

void LED_Config(uint16_t pin)
{
//��һ��:�򿪶�Ӧ����ʱ��
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOC,ENABLE);
//�ڶ���������ṹ��	
	GPIO_InitTypeDef GPIO_InitStruct;
	GPIO_InitStruct.GPIO_Pin = pin ;				//����
	GPIO_InitStruct.GPIO_Mode = GPIO_Mode_OUT;		//ģʽ������or�����
	GPIO_InitStruct.GPIO_Speed = GPIO_Speed_50MHz;//����ٶ�
	GPIO_InitStruct.GPIO_OType = GPIO_OType_PP;		//����or��©
	GPIO_InitStruct.GPIO_PuPd = GPIO_PuPd_UP;			//Ĭ������
	GPIO_SetBits(GPIOC,pin);
	
//������������ṹ���Ա
	GPIO_Init(GPIOC,&GPIO_InitStruct);
//���Ĳ�������GPIO��ʼ��������Ϊ�ṹ�帳ֵ

}
void LED1_Light(void)
{
	GPIO_ResetBits(GPIOC,GPIO_Pin_4);
	GPIO_SetBits(GPIOC,GPIO_Pin_5);
	GPIO_SetBits(GPIOC,GPIO_Pin_6);
	GPIO_SetBits(GPIOC,GPIO_Pin_7);

}

void LED2_Light(void)
{
	GPIO_SetBits(GPIOC,GPIO_Pin_4);
	GPIO_ResetBits(GPIOC,GPIO_Pin_5);
	GPIO_SetBits(GPIOC,GPIO_Pin_6);
	GPIO_SetBits(GPIOC,GPIO_Pin_7);

}
void LED3_Light(void)
{
	GPIO_SetBits(GPIOC,GPIO_Pin_4);
	GPIO_SetBits(GPIOC,GPIO_Pin_5);
	GPIO_ResetBits(GPIOC,GPIO_Pin_6);
	GPIO_SetBits(GPIOC,GPIO_Pin_7);

}
void LED4_Light(void)
{
	GPIO_SetBits(GPIOC,GPIO_Pin_4);
	GPIO_SetBits(GPIOC,GPIO_Pin_5);
	GPIO_SetBits(GPIOC,GPIO_Pin_6);
	GPIO_ResetBits(GPIOC,GPIO_Pin_7);

}

void LED_Lighting(uint16_t GPIO_Pin)
{
//	OS_ERR ERR;
	GPIO_ToggleBits(GPIOC,GPIO_Pin);
//	OSTimeDly(1000,OS_OPT_TIME_DLY,&ERR);
}

