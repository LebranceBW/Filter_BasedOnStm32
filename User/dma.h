/*DMA1 配置*/
#ifndef __DMA_H
#define __DMA_H
#include "stm32f10x.h"
#define USART1_Tx USART1_BASE+0x04
static u8 buffer2Tx[0xff];
extern void DMA_Config(void);
extern void NVIC_Config(void);

#endif
