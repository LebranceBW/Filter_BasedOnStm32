#ifndef MESSAGEQUEUE_H
#define MESSAGEQUEUE_H

typedef enum{Null_Message,ADInput_Message } MessageType ;	 //消息类型的枚举
typedef struct 
{
	 MessageType messagetype;
	 int messageContent;
}messagePackage_Struct;
class MessageQueue_Class
{
	  int QueueSize;
		messagePackage_Struct* messageArray;
	  int rear;
	  int front;
	  public:
	  MessageQueue_Class(int initQueueSize=30);
		bool EnterQueue(messagePackage_Struct messagePackage_Struct);
		bool  QuiteQueue( messagePackage_Struct* messagePackage_Struct);
}	;

#endif
