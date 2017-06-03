#ifndef TFT28SCOPE_H__
#define TFT28SCOPE_H__
#include "stm32f10x.h"

#ifdef __cplusplus
    extern "C" {
    #endif
		#include "./TFT28/TFT28.h"
    #ifdef __cplusplus
    }
    #endif
		
u16 const bufferSize_Con = 280;//缓冲区长度
u16 const basePoint_X_Con = 20; u16 const basePoint_Y_Con = 220; //原点坐标
unsigned int const XAxis_Length_Con = 280; u16 const YAxis_Length_Con = 180;//横竖轴长度
class Scope_Class
{
	private:
	u8 *buffer_Array;	//缓冲区
	u16 rear;
	u16 front;//循环队列指针
	void Axies_Init_Fun(void);
	public:
	Scope_Class();
	~Scope_Class();
	void InputData_Fun(u16 data_Loc);	//添加数据到缓冲区
	void Scope_Refresh_Fun();//刷新显示
};

#endif
