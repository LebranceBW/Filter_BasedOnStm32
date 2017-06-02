#include "adc1.h"
void adc1_Init()
{
	ADC_InitTypeDef adc1InitStructure=
	{
		.ADC_Mode=ADC_Mode_Independent,
		.ADC_ScanConvMode=DISABLE,
		.ADC_ContinuousConvMode=ENABLE,
		.ADC_ExternalTrigConv=ADC_ExternalTrigConv_None,
		.ADC_DataAlign=ADC_DataAlign_Right,
		.ADC_NbrOfChannel=1,
	};
	GPIO_InitTypeDef PA1Structure=
	{
		.GPIO_Pin=GPIO_Pin_1,
		.GPIO_Mode=GPIO_Mode_AIN,
	};
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_ADC1|RCC_APB2Periph_GPIOA,ENABLE);
	RCC_ADCCLKConfig(RCC_PCLK2_Div8);
	GPIO_Init(GPIOA,&PA1Structure);
	{
		ADC_Init(ADC1,&adc1InitStructure);
		ADC_RegularChannelConfig(ADC1,ADC_Channel_1,1,ADC_SampleTime_55Cycles5);
		ADC_DMACmd(ADC1,ENABLE);
		ADC_Cmd(ADC1,ENABLE);
		ADC_ResetCalibration(ADC1);
		while(ADC_GetResetCalibrationStatus(ADC1));
		ADC_StartCalibration(ADC1);
		while(ADC_GetCalibrationStatus(ADC1));
		ADC_SoftwareStartConvCmd(ADC1,ENABLE);
	}
}
