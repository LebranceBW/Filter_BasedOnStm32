#include "TFT28Scope.h"
Scope_Class::Scope_Class()
{
	buffer_Array = new u8 [bufferSize_Con ];
	rear=0;
	front=0;
	Axies_Init_Fun();
}
Scope_Class::~Scope_Class()
{
	delete buffer_Array;
}

void Scope_Class::InputData_Fun(u16 data_Loc)
{
	buffer_Array[rear]=data_Loc%256;
	if((rear+1)%bufferSize_Con==front)//队列满
	{
		rear = (rear+1)%bufferSize_Con;
		front = (front+1)%bufferSize_Con;
	}
	else
		rear = (rear+1)%bufferSize_Con;

}

void Scope_Class::Axies_Init_Fun()
{
	TFT_Initial();
	CLR_Screen(Black);
	GUIline(basePoint_X_Con,basePoint_Y_Con,basePoint_X_Con+XAxis_Length_Con,basePoint_Y_Con,White);
	GUIline(basePoint_X_Con,basePoint_Y_Con,basePoint_X_Con,basePoint_Y_Con-YAxis_Length_Con,White);
}
void Scope_Class::Scope_Refresh_Fun()//刷新显示
{
		for(int i=0;i<bufferSize_Con;i++)//刷新显示
			GUIpoint(basePoint_X_Con+i,basePoint_Y_Con-buffer_Array[i],Blue);
}
