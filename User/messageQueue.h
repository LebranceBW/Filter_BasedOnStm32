#ifndef MESSAGEQUEUE_H
#define MESSAGEQUEUE_H
#include "stm32f10x.h"
typedef enum{Null_Message,ADInput_Message } MessageType ;	 //消息类型的枚举
typedef struct 
{
	 MessageType messagetype;
	 u16 messageContent;
}MessagePackage_Struct;
class MessageQueue_Class
{
	  int QueueSize;
		MessagePackage_Struct* messageArray;
	  int rear;
	  int front;
	  public:
	  MessageQueue_Class(int initQueueSize=30);
		bool EnterQueue(MessagePackage_Struct MessagePackage);
		MessagePackage_Struct  QuiteQueue();
		bool  IsEmpty_Fun();
		
}	;

#endif
