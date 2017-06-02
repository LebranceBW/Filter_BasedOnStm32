#include "messageQueue.h"
MessageQueue_Class:: MessageQueue_Class(int initQueueSize_Local)
{
				if(initQueueSize_Local > 0)
				{
					QueueSize=initQueueSize_Local;
					messageArray = new messagePackage_Struct[QueueSize];
					rear=front=0;
				}
}
bool MessageQueue_Class::EnterQueue(messagePackage_Struct messagePackage_LocalVar)
{
	if((rear+1)%QueueSize  == front)
		return false;
	messageArray[rear] = messagePackage_LocalVar;
	rear = (rear+1)% QueueSize;
	return true;
}
bool  MessageQueue_Class::QuiteQueue(messagePackage_Struct* messagePackage_LocalPointer)
{
		if(front==rear)
			return  false;
		else 
			 messagePackage_LocalPointer = &messageArray[front];
			 front = (front+1) % QueueSize;	
			return  true;
}
