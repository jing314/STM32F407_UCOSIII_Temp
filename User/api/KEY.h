#ifndef _KEY_H
#define _KEY_H
#include "stm32f4xx.h"
#include "stdint.h"
#define Key_ON    0
#define Key_OFF   1
void Key_Config(void);
uint8_t Key_Sanf(GPIO_TypeDef *GPIOx,uint16_t GPIO_Pin);
void delay(uint32_t x);
#endif
