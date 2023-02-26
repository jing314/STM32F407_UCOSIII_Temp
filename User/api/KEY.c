#include "KEY.h"

void Key_Config(void)
{
	RCC_AHB1PeriphClockCmd(RCC_AHB1ENR_GPIOEEN,ENABLE);	//��ʱ��
	GPIO_InitTypeDef GPIO_InitStruct;
	GPIO_InitStruct.GPIO_Pin  = GPIO_Pin_3;							//����3
	GPIO_InitStruct.GPIO_Mode = GPIO_Mode_IN;						//ģʽΪ����
	GPIO_InitStruct.GPIO_PuPd = GPIO_PuPd_NOPULL;				//������������������״̬���ⲿ�źž���
	
	GPIO_Init(GPIOE,&GPIO_InitStruct);									//���ýṹ��
}

void delay(uint32_t x)
{
	while(x--);

}


	

uint8_t Key_Sanf(GPIO_TypeDef *GPIOx,uint16_t GPIO_Pin)
{
	if(GPIO_ReadInputDataBit(GPIOx, GPIO_Pin) == Key_ON )
	{
		while( GPIO_ReadInputDataBit(GPIOx, GPIO_Pin) == Key_ON )
			delay(72000);
		return Key_ON;
	}
	else return Key_OFF;
}
