#include "exit_KEY.h"
#include "OUT_IN.h"
void EXIT_Key_Config(void)
{
	//��ʼ����Ҫ���ӵ�EXTI�ߵ�GPIO
	EXTI_InitTypeDef EXTI_InitStructure;
	IN_Config(RCC_AHB1ENR_GPIOEEN,GPIOE,GPIO_Pin_3);
	//��ʼ��EXIT
	
	RCC_APB2PeriphClockCmd(RCC_APB2ENR_SYSCFGEN,ENABLE);//����EXTIʱ��
	SYSCFG_EXTILineConfig(EXTI_PortSourceGPIOE,EXTI_PinSource3);//��PE3��EXTI3����
	EXTI_InitStructure.EXTI_Line = EXTI_Line3;
	EXTI_InitStructure.EXTI_Mode = EXTI_Mode_Interrupt;
	EXTI_InitStructure.EXTI_Trigger = EXTI_Trigger_Falling;
	EXTI_InitStructure.EXTI_LineCmd = ENABLE;
	EXTI_Init(&EXTI_InitStructure);

}



	//����NVIC���ж�Դ�����ȼ����飬���ȼ���
	

	
void NVIC_Config(void)
{
	NVIC_InitTypeDef NVIC_InitStructure;																					//��ʼ���ṹ��
	NVIC_InitStructure.NVIC_IRQChannel = EXTI3_IRQn;															//�����ж�Դ
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 1; 	//��ռ���ȼ�
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 1;														//�����ȼ�
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;																//ʹ���ж�ͨ��
	NVIC_Init(&NVIC_InitStructure);


}


//��д�жϷ�����
