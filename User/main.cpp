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
#include "main.h"


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
int earlisetVar = 0; //最早进入缓冲区的变量	

//unsigned int const basePoint_X_Con = 20; unsigned int const basePoint_Y_Con = 220; //原点坐标
//unsigned int const XAxis_Length_Con = 280; unsigned int const YAxis_Length_Con = 180;//横竖轴长度
MessageQueue_Class messageQueue_Obj(30);//30长的消息队列
Scope_Class Scope_Obj;
int main(void)
{
	adc1_Init();
	MessagePackage_Struct *currentMessagePackage=0;
//	TFT_Initial();
//	CLR_Screen(Black);
//	GUIline(basePoint_X_Con,basePoint_Y_Con,basePoint_X_Con+XAxis_Length_Con,basePoint_Y_Con,White);
//	GUIline(basePoint_X_Con,basePoint_Y_Con,basePoint_X_Con,basePoint_Y_Con-YAxis_Length_Con,White);
//	int count=0; //每十个点求个平均
	while(1)
	{
		if(messageQueue_Obj.QuiteQueue(currentMessagePackage))
			switch(currentMessagePackage->messagetype)
			{
				case Null_Message: break;
				case ADInput_Message: 
				{
//					ADInput[count] = currentMessagePackage->messageContent;
//					if(count==10)
//					{
//						 int temp;
//							for(;count>0;count--)
//										temp+=ADInput[count];
//						Scope_Obj.InputData_Fun(temp/10);
//					}220
					Scope_Obj.InputData_Fun(currentMessagePackage->messageContent);
					break;			
				}
				default: 
				Scope_Obj.Scope_Refresh_Fun();	
				break;
			};
			
	}
}

