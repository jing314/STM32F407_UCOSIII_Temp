#ifndef _LED_H
#define _LED_H
#include "stm32f4xx.h"
#include "stdint.h"
#include  "os.h"

#define LED1    LED1_Light()
#define LED2    LED2_Light()
#define LED3    LED3_Light()
#define LED4    LED4_Light()
void LED_Config(unsigned short pin );
void LED1_Light(void);
void LED2_Light(void);
void LED3_Light(void);
void LED4_Light(void);


void LED_Lighting(uint16_t GPIO_Pin);
#endif

