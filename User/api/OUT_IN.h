#ifndef _OUT_IN_H
#define _OUT_IN_H
#include "stm32f4xx.h"
#include "stdint.h"

void OUT_Config(uint32_t RCC_AHB1Periph_GPIOX,GPIO_TypeDef* GPIOX,uint16_t GPIO_PIN,uint16_t GPIO_OType,uint16_t GPIO_PuPd );
void IN_Config(uint32_t RCC_AHB1Periph,GPIO_TypeDef* GPIOx,uint16_t GPIO_Pin);

#endif


