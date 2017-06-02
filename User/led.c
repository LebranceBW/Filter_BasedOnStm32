#include "led.h"
void LED_GPIO_Config(void)
{
	GPIO_InitTypeDef GPIO_InitStructure=
	{
		.GPIO_Pin=GPIO_Pin_All,
		.GPIO_Mode=GPIO_Mode_Out_PP,
		.GPIO_Speed=GPIO_Speed_50MHz
	};
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC,ENABLE);
	GPIO_Init(GPIOC,&GPIO_InitStructure);          
	GPIO_SetBits(GPIOC,GPIO_Pin_All);
}
void LED_Init()
{
	LED_GPIO_Config(void);
}
void __LED(unsigned char n) //参数为led灯的对应十六进制数
{
	unsigned char tmp=0x80;
	LED_GPIO_Config();
	for(;tmp>0;tmp>>=1)		 
	{
			if(n&0x80)
				GPIO_ResetBits(GPIOC,tmp);
			else
				GPIO_SetBits(GPIOC,tmp);
			n<<=1;
	}		
}


	
