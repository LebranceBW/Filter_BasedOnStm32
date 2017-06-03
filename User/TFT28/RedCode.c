#include "stm32f10x.h"                   //STM32器件寄存器定义头文件，必须包含
#include "user_Config.h"                  //用户配置头文件，用于配置硬件连接资源,位于项目文件夹下

//***********************************************************************
//			遥控器键码
//***********************************************************************

#define KEY_0     0x16                 //键0
#define KEY_1     0x0C                 //键1
#define KEY_2     0x18                 //键2
#define KEY_3     0x5E                 //键3
#define KEY_4     0x08                 //键4
#define KEY_5     0x1C                 //键5
#define KEY_6     0x5A                 //键6
#define KEY_7     0x42                 //键7
#define KEY_8     0x52                 //键8
#define KEY_9     0x4A                 //键9
#define KEY_POWER 0x45                 //电源
#define KEY_MODE  0x46                 //模式
#define KEY_SOUND 0x47                 //静音

//红外接收头H1838控制脚，单脚控制
#define RCC_GPIO_1838                RCC_APB2Periph_GPIOB    //接在PB7
#define GPIO_1838                    GPIOB                   //使用的GPIO为PB
#define GPIO_Pin_1838 							 GPIO_Pin_7

#define RED_L	        GPIO_ResetBits(GPIO_1838,GPIO_Pin_1838)	    //置低电平
#define RED_H	        GPIO_SetBits(GPIO_1838,GPIO_Pin_1838)	      //置高电平
#define RED_R	        GPIO_ReadInputDataBit(GPIO_1838, GPIO_Pin_1838)		      //读电平

void delay_us(u32 Nus);
void delay_mms(u16 nms);
void LCD_PutString24(unsigned short x , unsigned short y, unsigned char *s, unsigned int fColor, unsigned int bColor);

u8 KEY_VAL=0;
u8 code_value=0;
u8 key_code[4]; 

//*************************************************************************
//			遥控器键值赋功能值子程序
//*************************************************************************
 void Key_Icode(void)
 {
   switch(key_code[2])                    //第3个字节是数据，第4个字节是反码
   {                                      //为了更稳定，可以加上第4个字节数据的判断
   case KEY_0:KEY_VAL=0;break;
   case KEY_1:KEY_VAL=1;break;
   case KEY_2:KEY_VAL=2;break;
   case KEY_3:KEY_VAL=3;break;
   case KEY_4:KEY_VAL=4;break;
   case KEY_5:KEY_VAL=5;break;
   case KEY_6:KEY_VAL=6;break;
   case KEY_7:KEY_VAL=7;break;
   case KEY_8:KEY_VAL=8;break;
   case KEY_9:KEY_VAL=9;break;
   default:KEY_VAL=10;break;
   }

   
 }
//*************************************************************************
//	遥控器解码子程序
//*************************************************************************

void Red_Code()
{
u8 i,j,k = 0;

 for(i = 0;i < 19;i++)
{
  delay_us(400);           //延时400us
  if(RED_R)                //9ms内有高电平，则判断为干扰，退出处理程序
  {
      return;
  }
}

while(!RED_R);            //等待9ms低电平过去



for(i=0;i<5;i++)          //是否连发码
{
  delay_us(500);
  if(!RED_R)
   {
     return;
   }
}


while(RED_R);               //等待4.5ms高电平过去

for(i = 0;i < 4;i++)        //接收4个字节的数据
{
  for(j = 0;j < 8;j++)      //每个字节的数据8位
  {
   

   while(!RED_R);           //等待变高电平
   while(RED_R)             //计算高电平时间
   {
    delay_us(100);
    k++;
    if(k >22)               //高电平时间过长，则退出处理程序
    {
     return;         
    }
    
   }

   code_value>>=1;          //接受一位数据
   if(k >= 7)
   {
    code_value|=0x80;       //高电平时间大于0.56，则为数据1
   }
   k = 0;                  //计时清零
  }
  key_code[i]=code_value;  //四个字节的数据
}

  Key_Icode();             //调用赋值函数

  //Display_Key(KEY_VAL);     //显示按键值
  GPIO_Write(DataPort,(u16)(KEY_VAL | 0xff00));			//显示

  delay_mms(50);

}
