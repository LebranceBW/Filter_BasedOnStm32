/* S1--->PB12 KEY0
 * S2--->PB13 KEY1
 * S3--->PB14 KEY2
 * S4--->PB15 KEY3
 */
#include "Key.h"

void Key_GPIO_Config(void)
{
	GPIO_InitTypeDef GPIO_InitStructure=
	{
		.GPIO_Pin=0xf000,
		.GPIO_Mode=GPIO_Mode_IPU,	
	};
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB,ENABLE);
	GPIO_Init(GPIOB,&GPIO_InitStructure);          
}

