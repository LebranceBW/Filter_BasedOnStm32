/**
  ******************************************************************************
  * @file    Project/STM32F10x_StdPeriph_Template/main.c 
  * @author  BlueWhite
  * @version V3.5.0
  * @date    2017-6-2 13:55:51
  * @brief   Main program body
  ******************************************************************************
  * @attention
  *
  * THE PRESENT FIRMWARE WHICH IS FOR GUIDANCE ONLY AIMS AT PROVIDING CUSTOMERS
  * WITH CODING INFORMATION REGARDING THEIR PRODUCTS IN ORDER FOR THEM TO SAVE
  * TIME. AS A RESULT, STMICROELECTRONICS SHALL NOT BE HELD LIABLE FOR ANY
  * DIRECT, INDIRECT OR CONSEQUENTIAL DAMAGES WITH RESPECT TO ANY CLAIMS ARISING
  * FROM THE CONTENT OF SUCH FIRMWARE AND/OR THE USE MADE BY CUSTOMERS OF THE
  * CODING INFORMATION CONTAINED HEREIN IN CONNECTION WITH THEIR PRODUCTS.
  *
  * <h2><center>&copy; COPYRIGHT 2011 STMicroelectronics</center></h2>
  ******************************************************************************
  */  

/* Includes ------------------------------------------------------------------*/
#include "messageQueue.h"
#define ORDER 10

double filterCoefficients[ORDER] = {0,                                    
0.016389135268014336,                 
0.064553796556307774,                 
0.12971074956317299,                  
0.18557930879511905,                  
0.20753401963477147,                  
0.18557930879511905,                  
0.12971074956317299,                  
0.064553796556307774,                 
0.016389135268014336 };//滤波器系数

int ADInput[ORDER] = {};//A/D数据存储区
double DAOutput;//D/A输出
	
MessageQueue_Class messageQueue_Obj(30);
	
bool DMAFrom_AD_Var_Init()
{
	
}	
int main(void)
{
	DMAFrom_AD_Var_Init();
	messagePackage_Struct *currentMessagePackage=0;
	if(messageQueue_Obj.QuiteQueue(currentMessagePackage)&&currentMessagePackage!=0)
		switch(currentMessagePackage->messagetype)
		{
			case Null_Message: break;
			case ADInput_Message: break;
		};
}

