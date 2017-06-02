#include "exti.h"
void EXTI_PE5_Config(void)
{
	GPIO_InitTypeDef GPIO_InitStructure;
	EXIT_InitTypeDef EXIT_InitStructure;

	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB|RCC_APB2Periph_AFIO,ENABLE);
	NVIC_Configuration();
	GPIO_InitStructure.GPIO_Pin=GPIO_Pin_12;
	GPIO_InitStructure.GPIO_Mode=GPIO_Mode_IPD;
	GPIO_Init(GPIOB,&GPIO_InitStructure);
	GPIO_EXTILineConfig(GPIO_PortSourceGPIOB,GPIO_PinSource13);
	EXIT_InitStructure.EXTI_Line =EXTI_Line13;
	EXIT_InitStructure.EXTI_Mode=EXTI_Mode_Interrupt;
	EXIT_InitStructure.EXTI_Trigger=EXTI_Trigger_Falling;//下降沿
	EXIT_InitStructure.EXTI_LineCmd=ENABLE;
	EXIT_Init(&EXTI_InitStructure);
}
		
