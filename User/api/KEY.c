#include "KEY.h"

void Key_Config(void)
{
	RCC_AHB1PeriphClockCmd(RCC_AHB1ENR_GPIOEEN,ENABLE);	//打开时钟
	GPIO_InitTypeDef GPIO_InitStruct;
	GPIO_InitStruct.GPIO_Pin  = GPIO_Pin_3;							//引脚3
	GPIO_InitStruct.GPIO_Mode = GPIO_Mode_IN;						//模式为输入
	GPIO_InitStruct.GPIO_PuPd = GPIO_PuPd_NOPULL;				//不上拉不下拉，引脚状态由外部信号决定
	
	GPIO_Init(GPIOE,&GPIO_InitStruct);									//配置结构体
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
