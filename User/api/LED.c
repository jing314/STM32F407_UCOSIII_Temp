#include "LED.h"

void LED_Config(uint16_t pin)
{
//第一步:打开对应外设时钟
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOC,ENABLE);
//第二部：定义结构体	
	GPIO_InitTypeDef GPIO_InitStruct;
	GPIO_InitStruct.GPIO_Pin = pin ;				//引脚
	GPIO_InitStruct.GPIO_Mode = GPIO_Mode_OUT;		//模式（输入or输出）
	GPIO_InitStruct.GPIO_Speed = GPIO_Speed_50MHz;//输出速度
	GPIO_InitStruct.GPIO_OType = GPIO_OType_PP;		//推挽or开漏
	GPIO_InitStruct.GPIO_PuPd = GPIO_PuPd_UP;			//默认上拉
	GPIO_SetBits(GPIOC,pin);
	
//第三步：定义结构体成员
	GPIO_Init(GPIOC,&GPIO_InitStruct);
//第四步：调用GPIO初始化函数，为结构体赋值

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

