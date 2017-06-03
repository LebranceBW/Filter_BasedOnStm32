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
				.ADC_NbrOfChannel=3,
			};
			GPIO_InitTypeDef PA1Structure=
			{
				.GPIO_Pin=GPIO_Pin_3,
				.GPIO_Mode=GPIO_Mode_AIN,
			};
			RCC_APB2PeriphClockCmd(RCC_APB2Periph_ADC1|RCC_APB2Periph_GPIOA,ENABLE);
			RCC_ADCCLKConfig(RCC_PCLK2_Div8);
			GPIO_Init(GPIOA,&PA1Structure);
			{
				ADC_Init(ADC1,&adc1InitStructure);
				ADC_NVIC_Config();
				ADC_RegularChannelConfig(ADC1,ADC_Channel_3,1,ADC_SampleTime_71Cycles5);
				ADC_ITConfig(ADC1,ADC_IT_EOC,ENABLE);
				
				ADC_Cmd(ADC1,ENABLE);
				ADC_ResetCalibration(ADC1);
				while(ADC_GetResetCalibrationStatus(ADC1));
				ADC_StartCalibration(ADC1);
				while(ADC_GetCalibrationStatus(ADC1));
				ADC_SoftwareStartConvCmd(ADC1,ENABLE);
			}
			
		}

void  ADC_NVIC_Config ()
{
	NVIC_InitTypeDef NVIC_Struct = {
		.NVIC_IRQChannel = ADC1_2_IRQn ,
		.NVIC_IRQChannelPreemptionPriority= 1,
		.NVIC_IRQChannelSubPriority= 1,
		.NVIC_IRQChannelCmd= ENABLE 
	};
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_1);
	NVIC_Init(&NVIC_Struct);
	NVIC_ClearPendingIRQ( ADC1_2_IRQn );
}
