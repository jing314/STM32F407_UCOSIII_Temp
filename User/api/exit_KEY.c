#include "exit_KEY.h"
#include "OUT_IN.h"
void EXIT_Key_Config(void)
{
	//初始化需要连接到EXTI线的GPIO
	EXTI_InitTypeDef EXTI_InitStructure;
	IN_Config(RCC_AHB1ENR_GPIOEEN,GPIOE,GPIO_Pin_3);
	//初始化EXIT
	
	RCC_APB2PeriphClockCmd(RCC_APB2ENR_SYSCFGEN,ENABLE);//开启EXTI时钟
	SYSCFG_EXTILineConfig(EXTI_PortSourceGPIOE,EXTI_PinSource3);//将PE3与EXTI3连接
	EXTI_InitStructure.EXTI_Line = EXTI_Line3;
	EXTI_InitStructure.EXTI_Mode = EXTI_Mode_Interrupt;
	EXTI_InitStructure.EXTI_Trigger = EXTI_Trigger_Falling;
	EXTI_InitStructure.EXTI_LineCmd = ENABLE;
	EXTI_Init(&EXTI_InitStructure);

}



	//配置NVIC（中断源，优先级分组，优先级）
	

	
void NVIC_Config(void)
{
	NVIC_InitTypeDef NVIC_InitStructure;																					//初始化结构体
	NVIC_InitStructure.NVIC_IRQChannel = EXTI3_IRQn;															//配置中断源
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 1; 	//抢占优先级
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 1;														//子优先级
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;																//使能中断通道
	NVIC_Init(&NVIC_InitStructure);


}


//编写中断服务函数
