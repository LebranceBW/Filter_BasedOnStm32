#ifndef USER_CONFIG_H__
#define USER_CONFIG_H__
/*8个LED接口定义*/
#define RCC_GPIO_LED8                   RCC_APB2Periph_GPIOC    //LED使用的GPIO时钟
#define LEDn                            8                       //LED数量为8
#define GPIO_LED8                       GPIOC                   //LED使用的GPIO为PC

#define DS1_PIN                         GPIO_Pin_0             	//DS1使用的GPIO管脚
#define DS2_PIN                         GPIO_Pin_1							//DS2使用的GPIO管脚
#define DS3_PIN                         GPIO_Pin_2  						//DS3使用的GPIO管脚
#define DS4_PIN                         GPIO_Pin_3							//DS4使用的GPIO管脚
#define DS5_PIN                         GPIO_Pin_4             	//DS5使用的GPIO管脚
#define DS6_PIN                         GPIO_Pin_5							//DS6使用的GPIO管脚
#define DS7_PIN                         GPIO_Pin_6  						//DS7使用的GPIO管脚
#define DS8_PIN                         GPIO_Pin_7							//DS8使用的GPIO管脚

/*2.8寸TFT触摸屏接口定义*/
#define GPIO_TFT_DATA                   GPIOC    				         //数据口PC0~PC7
#define RCC_GPIO_TFT                    RCC_APB2Periph_GPIOC

#define GPIO_CTRA                   		GPIOA    				         //控制口
#define RCC_GPIO_CTRA    		            RCC_APB2Periph_GPIOA
#define GPIO_CTRB			              		GPIOB    				         //控制口
#define RCC_GPIO_CTRB    								RCC_APB2Periph_GPIOB

#define RS_CLR	        GPIO_ResetBits(GPIO_CTRA, GPIO_Pin_0)     //RS置低
#define RS_SET	        GPIO_SetBits(GPIO_CTRA, GPIO_Pin_0)       //RS置高

#define RW_CLR	        GPIO_ResetBits(GPIO_CTRA, GPIO_Pin_1)     //RW置低
#define RW_SET	        GPIO_SetBits(GPIO_CTRA, GPIO_Pin_1)  		  //RW置高

#define RD_CLR	        GPIO_ResetBits(GPIO_CTRB, GPIO_Pin_8)     //E置低
#define RD_SET	        GPIO_SetBits(GPIO_CTRB, GPIO_Pin_8)       //E置高

#define CS_CLR	        GPIO_ResetBits(GPIO_CTRB, GPIO_Pin_0)     //CS置低
#define CS_SET	        GPIO_SetBits(GPIO_CTRB, GPIO_Pin_0)       //CS置高

#define RST_CLR	        GPIO_ResetBits(GPIO_CTRB, GPIO_Pin_1)     //RST置低
#define RST_SET	        GPIO_SetBits(GPIO_CTRB, GPIO_Pin_1)       //RST置高

#define LE_CLR	        GPIO_ResetBits(GPIO_CTRB, GPIO_Pin_2)     //LE置低
#define LE_SET	        GPIO_SetBits(GPIO_CTRB, GPIO_Pin_2)       //LE置高

#define DataPort        GPIOC                     								//PC口为数据口

#define D0              GPIO_Pin_0             										//D0使用的GPIO管脚
#define D1              GPIO_Pin_1																//D1使用的GPIO管脚
#define D2              GPIO_Pin_2  															//D2使用的GPIO管脚
#define D3							GPIO_Pin_3																//D3使用的GPIO管脚
#define D4					    GPIO_Pin_4             										//D4使用的GPIO管脚
#define D5				      GPIO_Pin_5																//D5使用的GPIO管脚
#define D6				     	GPIO_Pin_6  															//D6使用的GPIO管脚
#define D7				     	GPIO_Pin_7																//D7使用的GPIO管脚


/*全局变量-颜色代码*/

#define White          0xFFFF           													//显示颜色代码
#define Black          0x0000
#define Blue           0x001F
#define Blue2          0x051F
#define Red            0xF800
#define Magenta        0xF81F
#define Green          0x07E0
#define Cyan           0x7FFF
#define Yellow         0xFFE0

/*函数声明区*/
void RCC_Configuration(void);
void NVIC_Configuration(void);

#endif
