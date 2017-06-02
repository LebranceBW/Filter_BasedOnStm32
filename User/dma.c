#include "dma.h"
void NVIC_Config(void)//中断优先级：0,0
{
	NVIC_InitTypeDef NVIC_InitStructure=
	{
		.NVIC_IRQChannel=DMA1_Channel4_IRQn,
		.NVIC_IRQChannelPreemptionPriority=1,
		.NVIC_IRQChannelSubPriority=1,
		.NVIC_IRQChannelCmd = ENABLE
	};//NVIC配置
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_1);
	NVIC_Init(&NVIC_InitStructure);
	NVIC_ClearPendingIRQ(DMA1_Channel4_IRQn);
}

void DMA_Config(void)
{
	RCC_AHBPeriphClockCmd(RCC_AHBPeriph_DMA1,ENABLE);
	for(int i=0;i<=0xfe;i++)
		buffer2Tx[i]=i;
	DMA_InitTypeDef DMA1Channel4Structure=
	{
		.DMA_PeripheralBaseAddr=USART1_Tx,
		.DMA_MemoryBaseAddr=(u32)buffer2Tx,
		.DMA_DIR=DMA_DIR_PeripheralDST,
		.DMA_BufferSize=0xff,
		.DMA_PeripheralInc=DMA_PeripheralInc_Disable,
		.DMA_MemoryInc=DMA_MemoryInc_Enable,
		.DMA_PeripheralDataSize=DMA_PeripheralDataSize_Byte,
		.DMA_MemoryDataSize=DMA_MemoryDataSize_Byte,
		.DMA_Mode=DMA_Mode_Normal,
		.DMA_Priority=DMA_Priority_High,
		.DMA_M2M=DMA_M2M_Disable,
	};
	DMA_Init(DMA1_Channel4,&DMA1Channel4Structure);
	DMA_Cmd(DMA1_Channel4,ENABLE);
	DMA_ITConfig(DMA1_Channel4,DMA_IT_TC,ENABLE);
	NVIC_Config();
}

