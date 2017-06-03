#include "messageQueue.h"
MessageQueue_Class:: MessageQueue_Class(int initQueueSize_Local)
{
				if(initQueueSize_Local > 0)
				{
					QueueSize=initQueueSize_Local;
					messageArray = new MessagePackage_Struct[QueueSize];
					rear=front=0;
				}
}
bool MessageQueue_Class::EnterQueue(MessagePackage_Struct messagePackage_LocalVar)
{
	if((rear+1)%QueueSize  == front)
		return false;
	messageArray[rear] = messagePackage_LocalVar;
	rear = (rear+1)% QueueSize;
	return true;
}
bool  MessageQueue_Class::IsEmpty_Fun()
{
if(front==rear)
			return  false;
else
return  true;
}
MessagePackage_Struct  MessageQueue_Class::QuiteQueue()
{
			 MessagePackage_Struct messagePackage_Local = messageArray[front];
			 front = (front+1) % QueueSize;	
			 return messagePackage_Local;
}
