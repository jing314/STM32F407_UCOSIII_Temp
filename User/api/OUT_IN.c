#include "OUT_IN.h"


void OUT_Config(uint32_t RCC_AHB1Periph_GPIOX,GPIO_TypeDef* GPIOX,uint16_t GPIO_PIN,uint16_t GPIO_OType,uint16_t GPIO_PuPd )
{
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOX,ENABLE);
//�ڶ���������ṹ��	
	GPIO_InitTypeDef GPIO_InitStruct;
	GPIO_InitStruct.GPIO_Pin = GPIO_PIN;				//����h��
	GPIO_InitStruct.GPIO_Mode = GPIO_Mode_OUT;		//ģʽ������or�����
	GPIO_InitStruct.GPIO_Speed = GPIO_Speed_50MHz;//����ٶ�
	GPIO_InitStruct.GPIO_OType = GPIO_OType;		//����or��©
	GPIO_InitStruct.GPIO_PuPd = GPIO_PuPd;			//Ĭ������or����
	GPIO_Init(GPIOX,&GPIO_InitStruct);
	GPIO_SetBits(GPIOX,GPIO_PIN);
}


void IN_Config(uint32_t RCC_AHB1Periph,GPIO_TypeDef* GPIOx,uint16_t GPIO_Pin)
{
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph,ENABLE);
	GPIO_InitTypeDef GPIO_InitStruct;
	GPIO_InitStruct.GPIO_Pin = GPIO_Pin;
	GPIO_InitStruct.GPIO_Mode = GPIO_Mode_IN;
	GPIO_InitStruct.GPIO_PuPd = GPIO_PuPd_NOPULL;
	GPIO_Init(GPIOx,&GPIO_InitStruct);
}
	
