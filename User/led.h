/*接口 LED——>PC0~PC7
 *使用前先用LED_Init()初始化然后就可以简单粗暴的用__LED()控制其亮灭
 2017年2月22日10:36:33
*/
#ifndef __LED_H
#define __LED_H

#include "stm32f10x.h"
#define ON 0
#define OFF 1
 void LED_GPIO_Config(void);
 void __LED(unsigned char n);
 void LED_Init();
#endif /* __LED_H */
