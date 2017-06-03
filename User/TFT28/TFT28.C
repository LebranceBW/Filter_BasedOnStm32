/****************************************************************************************************  
ÎÄ¼ş¹¦ÄÜÃèÊö£º320x240TFTÇı¶¯³ÌĞò£¬¿ØÖÆTFTÊµÏÖºº×Ö,×Ö·ûÏÔÊ¾,»­µã¹¦ÄÜ¡£
****************************************************************************************************/
#include "TFT28.h"

//**************ÉùÃ÷Íâ²¿º¯ÊıºÍ±äÁ¿**************

void GPIO_Config(void)

{

	/* é…ç½®æ•°æ®å£çš„GPIOç®¡è„šæ¨¡å¼ï¼Œè¾“å‡ºæ¨¡å¼*/
		GPIO_InitTypeDef GPIO_InitStructure;
  	RCC_APB2PeriphClockCmd(RCC_GPIO_TFT, ENABLE); 					//ä½¿èƒ½GPIOæ—¶é’Ÿ

  	GPIO_InitStructure.GPIO_Pin = DS1_PIN|DS2_PIN|DS3_PIN|DS4_PIN|DS5_PIN|DS6_PIN|DS7_PIN|DS8_PIN; //ä½¿ç”¨PC0~PC7

  	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;				//GPIOå·¥ä½œåœ¨è¾“å‡ºæ¨¡å¼

  	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_10MHz;

  	GPIO_Init(GPIO_TFT_DATA, &GPIO_InitStructure);  				//ç›¸å…³çš„GPIOå£åˆå§‹åŒ–

	

	/* é…ç½®æ§åˆ¶å£Açš„GPIOç®¡è„šæ¨¡å¼ï¼Œè¾“å‡ºæ¨¡å¼*/

  	RCC_APB2PeriphClockCmd(RCC_GPIO_CTRA, ENABLE); 					//ä½¿èƒ½GPIOæ—¶é’Ÿ

  	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0 | GPIO_Pin_1;  //ä½¿ç”¨PA0ã€PA1

  	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;				//GPIOå·¥ä½œåœ¨è¾“å‡ºæ¨¡å¼

  	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_10MHz;

  	GPIO_Init(GPIO_CTRA, &GPIO_InitStructure);  						//ç›¸å…³çš„GPIOå£åˆå§‹åŒ–

		

		/* é…ç½®LEDç¯ä½¿ç”¨çš„GPIOç®¡è„šæ¨¡å¼ï¼Œè¾“å‡ºæ¨¡å¼*/

  	RCC_APB2PeriphClockCmd(RCC_GPIO_CTRB, ENABLE); 					//ä½¿èƒ½GPIOæ—¶é’Ÿ

  	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0 | GPIO_Pin_1 |GPIO_Pin_2 |GPIO_Pin_8 ; //ä½¿ç”¨PB0.1.2.8

  	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;				//GPIOå·¥ä½œåœ¨è¾“å‡ºæ¨¡å¼

  	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_10MHz;

  	GPIO_Init(GPIO_CTRB, &GPIO_InitStructure);  						//ç›¸å…³çš„GPIOå£åˆå§‹åŒ–

		

		GPIO_ResetBits(GPIO_CTRB,GPIO_Pin_8);

}
/****************************************************************************************************
//	ÊµÏÖ¹¦ÄÜ£º	ÑÓÊ±
//	ÊäÈë²ÎÊı£º	count ÉèÖÃÑÓÊ±Ê±¼ä
****************************************************************************************************/
void delayms(unsigned int count)
{
    int i,j;                                                                                
    for(i=0;i<count;i++)                                                                    
       {
	     for(j=0;j<0x640;j++);
       }                                                                                     
}



/****************************************************************************************************
//	ÊµÏÖ¹¦ÄÜ£º	Ğ´ÃüÁî
//	ÊäÈë²ÎÊı£º  DH ĞèÒªÊäÈë16bitsÃüÁîµÄ¸ß8Î»
//              DL ĞèÒªÊäÈë16bitsÃüÁîµÄµÍ8Î»
****************************************************************************************************/
	void Write_Cmd(unsigned char DH,unsigned char DL)
{
	int Device_code = 0x9320;
	CS_CLR;
	RS_CLR;
  RD_SET;
  RW_CLR;
	
	if(Device_code==0x9328)
	{

		//æ³¨æ„ï¼šå½“ä½¿ç”¨8ä½æ•°æ®å£é©±åŠ¨16ä½æ•°æ®æ¨¡å¼æ—¶ï¼Œä½¿ç”¨74HC573ä½œä¸ºIOæ‰©å±•ï¼Œç¨‹åºå¦‚ä¸‹           
		GPIO_Write(DataPort,(u16)(DL | 0xff00));     	//é€ä½8ä½å‘½ä»¤ç»™573å¾…é”å­˜
		LE_SET;                   										//é”å­˜ä½
		LE_CLR;                   										//æ–­å¼€é”å­˜,ä½é€‰573çš„Q7~Q0ä»ä¿æŒ           
		GPIO_Write(DataPort,(u16)(DH | 0xff00));			//é€é«˜8ä½å‘½ä»¤ç»™TFT
	}
	else if(Device_code==0x9320)
	{
		//æ³¨æ„ï¼šå½“ä½¿ç”¨8ä½æ•°æ®å£é©±åŠ¨16ä½æ•°æ®æ¨¡å¼æ—¶ï¼Œä½¿ç”¨74HC573ä½œä¸ºIOæ‰©å±•ï¼Œç¨‹åºå¦‚ä¸‹           
		GPIO_Write(DataPort,(u16)(DH | 0xff00));     	//é€ä½8ä½å‘½ä»¤ç»™573å¾…é”å­˜
		LE_SET;                   										//é”å­˜ä½
		LE_CLR;                   										//æ–­å¼€é”å­˜,ä½é€‰573çš„Q7~Q0ä»ä¿æŒ           
		GPIO_Write(DataPort,(u16)(DL | 0xff00));			//é€é«˜8ä½å‘½ä»¤ç»™TFT
	}

	/*
    //å¦‚æœä½¿ç”¨16ä½æ•°æ®å£é©±åŠ¨16ä½æ•°æ®æ¨¡å¼ï¼Œåˆ™æ— éœ€IOæ‰©å±•ï¼Œç›´æ¥å°†æ•°æ®é€åˆ°æ•°æ®å£å³å¯
    DataPort_L=DL; 
    DataPort_H=DH;
	*/

	RW_SET;
	CS_SET;
}


/****************************************************************************************************
//	ÊµÏÖ¹¦ÄÜ£º	Ğ´Êı¾İ(2*8bits)
//	ÊäÈë²ÎÊı£º  DH ĞèÒªÊäÈë16bitsÊı¾İµÄ¸ß8Î»
//              DL ĞèÒªÊäÈë16bitsÊı¾İµÄµÍ8Î»
****************************************************************************************************/
void Write_Data(unsigned char DH,unsigned char DL)
{
	int Device_code = 0x9320;	
	CS_CLR;
	RS_SET;
	if(Device_code==0x9328)
	{
   //æ³¨æ„ï¼šå½“ä½¿ç”¨8ä½æ•°æ®å£é©±åŠ¨16ä½æ•°æ®æ¨¡å¼æ—¶ï¼Œä½¿ç”¨74HC573ä½œä¸ºIOæ‰©å±•ï¼Œç¨‹åºå¦‚ä¸‹           
	 GPIO_Write(DataPort,(u16)(DL | 0xff00)); //é€ä½8ä½æ•°æ®ç»™573å¾…é”å­˜
   LE_SET;                   //é”å­˜ä½
   LE_CLR;                   //æ–­å¼€é”å­˜,ä½é€‰573çš„Q7~Q0ä»ä¿æŒ           
	 GPIO_Write(DataPort,(u16)(DH | 0xff00));  //é€é«˜8ä½æ•°æ®ç»™TFT
	 //delayms(1);
	}
	
	else if(Device_code==0x9320)
	{
		//æ³¨æ„ï¼šå½“ä½¿ç”¨8ä½æ•°æ®å£é©±åŠ¨16ä½æ•°æ®æ¨¡å¼æ—¶ï¼Œä½¿ç”¨74HC573ä½œä¸ºIOæ‰©å±•ï¼Œç¨‹åºå¦‚ä¸‹           
		GPIO_Write(DataPort,(u16)(DH | 0xff00));     	//é€ä½8ä½å‘½ä»¤ç»™573å¾…é”å­˜
		LE_SET;                   										//é”å­˜ä½
		LE_CLR;                   										//æ–­å¼€é”å­˜,ä½é€‰573çš„Q7~Q0ä»ä¿æŒ           
		GPIO_Write(DataPort,(u16)(DL | 0xff00));			//é€é«˜8ä½å‘½ä»¤ç»™TFT
	}

	/*
    //å¦‚æœä½¿ç”¨16ä½æ•°æ®å£é©±åŠ¨16ä½æ•°æ®æ¨¡å¼ï¼Œåˆ™æ— éœ€IOæ‰©å±•ï¼Œç›´æ¥å°†æ•°æ®é€åˆ°æ•°æ®å£å³å¯
    DataPort_L=DL; 
    DataPort_H=DH;
	*/

	RW_CLR;
	RW_SET;
	CS_SET;
}

/****************************************************************************************************
//	ÊµÏÖ¹¦ÄÜ£º	Ğ´Êı¾İ(16Î»)
//	ÊäÈë²ÎÊı£º  y ĞèÒªÊäÈë16bitsÊı¾İ
****************************************************************************************************/
void  Write_Data_U16(unsigned int y)
{
	unsigned char m,n;
	m=y>>8;
	n=y;
	Write_Data(m,n);
}

/****************************************************************************************************
//	ÊµÏÖ¹¦ÄÜ£º	Ïòx¼Ä´æÆ÷Ğ´ÈëyÊı¾İ
//	ÊäÈë²ÎÊı£º  x ĞèÒªÊäÈëµÄÃüÁî 16Î»
//              y ĞèÒªÊäÈëµÄÊı¾İ 16Î»
****************************************************************************************************/
void  Write_Cmd_Data (unsigned char x,unsigned int y)
{
	unsigned char m,n;
	m=y>>8;
	n=y;
	Write_Cmd(0x00,x);
	Write_Data(m,n);
}

/****************************************************************************************************
//	ÊµÏÖ¹¦ÄÜ£º	ÉèÖÃ×ø±ê
//  ÊäÈë²ÎÊı£º  x0£¬y0 ÆğÊ¼×ø±ê
//              x1£¬y1 ½áÊø×ø±ê
****************************************************************************************************/
void LCD_SetPos(unsigned int x0,unsigned int x1,unsigned int y0,unsigned int y1)
//void LCD_SetPos(int x0,int x1,int y0,int y1)
{

  Write_Cmd_Data(0x50,x0);  // Horizontal GRAM Start Address
  Write_Cmd_Data(0x51,x1);  // Horizontal GRAM End Address
  Write_Cmd_Data(0x52,y0);  // Vertical GRAM Start Address
  Write_Cmd_Data(0x53,y1);  // Vertical GRAM Start Address
  Write_Cmd_Data(0x20,x0);  // GRAM horizontal Address
  Write_Cmd_Data(0x21,y0);  // GRAM Vertical Address
  Write_Cmd (0x00,0x22);    // 0x0022,Start to Write Data to GRAM 
}

/****************************************************************************************************
//	ÊµÏÖ¹¦ÄÜ£º	TFTÇåÆÁ
//	ÊäÈë²ÎÊı£º	bColor ÇåÆÁËùÊ¹ÓÃµÄ±³¾°É«
****************************************************************************************************/
void CLR_Screen(unsigned int bColor)
{
 unsigned int i,j;
 LCD_SetPos(0,239,0,319);													//320x240£¬×ø±ê´Ó0¿ªÊ¼
 for (i=0;i<240;i++)
	{
	   for (j=0;j<320;j++)
	       Write_Data_U16(bColor);
	}
}

/****************************************************************************************************
//	ÊµÏÖ¹¦ÄÜ£º	ÏÔÊ¾Ascii×Ö·û
//  ÊäÈë²ÎÊı£º  x ºá×ø±ê
//              y ×İ×ø±ê
//		        c ĞèÒªÏÔÊ¾µÄ×Ö·û
//		        fColor ×Ö·ûÑÕÉ«
//		        bColor ×Ö·û±³¾°ÑÕÉ«
****************************************************************************************************/
void LCD_PutChar(unsigned int x, unsigned int y, char c, unsigned int fColor, unsigned int bColor)
{
 unsigned int i,j;
 LCD_SetPos(x,x+16-1,y-8+1,y);                    //ÉèÖÃ×Ö·ûÏÔÊ¾Î»ÖÃ
 for(i=0; i<16;i++) {                             //Ñ­»·Ğ´Èë16×Ö½Ú£¬Ò»¸ö×Ö·ûÎª16×Ö½Ú
		unsigned char m=Font8x16[(c-0x20)*16+i];  //ÌáÈ¡c×Ö·ûµÄµÚi¸ö×Ö½ÚÒÔ,c¼õÈ¥0x20ÊÇÓÉÓÚAsciiÂë¿âÖĞµÄ0~1f±»È¥µô
		for(j=0;j<8;j++) {                        //Ñ­»·Ğ´Èë8Î»£¬Ò»¸ö×Ö½ÚÎª8Î»
			if((m&0x80)==0x80) {                  //ÅĞ¶Ï×î¸ßÎ»ÊÇ·ñÎª1
				Write_Data_U16(fColor);           //×î¸ßÎ»Îª1£¬Ğ´Èë×Ö·ûÑÕÉ«
				}
			else {
				Write_Data_U16(bColor);           //×î¸ßÎ»Îª0£¬Ğ´Èë±³¾°ÑÕÉ«
				}
			m<<=1;                                //×óÒÆ1Î»£¬×¼±¸Ğ´ÏÂÒ»Î»
			}
		}
}

/****************************************************************************************************
//	ÊµÏÖ¹¦ÄÜ£º	ÏÔÊ¾µ¥¸öAscii×Ö·û£¬Ö÷ÒªÊÇÎªºáÆÁ¶øÉèÖÃ
//  ÊäÈë²ÎÊı£º x ºá×ø±ê
//            y ×İ×ø±ê
//		        c ĞèÒªÏÔÊ¾µÄ×Ö·û
//		        fColor ×Ö·ûÑÕÉ«
//		        bColor ×Ö·û±³¾°ÑÕÉ«
****************************************************************************************************/
void LCD_PutSingleChar(unsigned int x, unsigned int y, char c, unsigned int fColor, unsigned int bColor)
{
 unsigned int i,j;
	
	i=y;
	j=x;
	x=i;
	y=319-j;
	
 LCD_SetPos(x,x+16-1,y-8+1,y);                    //ÉèÖÃ×Ö·ûÏÔÊ¾Î»ÖÃ
 for(i=0; i<16;i++) {                             //Ñ­»·Ğ´Èë16×Ö½Ú£¬Ò»¸ö×Ö·ûÎª16×Ö½Ú
		unsigned char m=Font8x16[(c-0x20)*16+i];  		//ÌáÈ¡c×Ö·ûµÄµÚi¸ö×Ö½ÚÒÔ,c¼õÈ¥0x20ÊÇÓÉÓÚAsciiÂë¿âÖĞµÄ0~1f±»È¥µô
		for(j=0;j<8;j++) {                        		//Ñ­»·Ğ´Èë8Î»£¬Ò»¸ö×Ö½ÚÎª8Î»
			if((m&0x80)==0x80) {                  			//ÅĞ¶Ï×î¸ßÎ»ÊÇ·ñÎª1
				Write_Data_U16(fColor);           				//×î¸ßÎ»Îª1£¬Ğ´Èë×Ö·ûÑÕÉ«
				}
			else {
				Write_Data_U16(bColor);           				//×î¸ßÎ»Îª0£¬Ğ´Èë±³¾°ÑÕÉ«
				}
			m<<=1;                                			//×óÒÆ1Î»£¬×¼±¸Ğ´ÏÂÒ»Î»
			}
		}
}

/****************************************************************************************************
//	ÊµÏÖ¹¦ÄÜ£º	ÏÔÊ¾16x16ºº×Ö
//  ÊäÈë²ÎÊı£º x ºá×ø±ê
//            y ×İ×ø±ê
//		        g ĞèÒªÏÔÊ¾µÄ×Ö·û±àÂë
//		        fColor ×Ö·ûÑÕÉ«
//		        bColor ×Ö·û±³¾°ÑÕÉ«
****************************************************************************************************/


/****************************************************************************************************
º¯Êı¹¦ÄÜ: ÏÔÊ¾ºº×Ö24x24
ÊäÈë²ÎÊı£ºx ºá×ø±ê
         y ×İ×ø±ê
         c ĞèÒªÏÔÊ¾µÄºº×ÖÂë
	       fColor ×Ö·ûÑÕÉ«
         bColor ×Ö·û±³¾°ÑÕÉ«
****************************************************************************************************/


/****************************************************************************************************
//	ÊµÏÖ¹¦ÄÜ£º	ÏÔÊ¾ÖĞÓ¢ÎÄ×Ö·û´®
//  ÊäÈë²ÎÊı£º x ºá×ø±ê
//            y ×İ×ø±ê
//		        *s ´ıÏÔÊ¾µÄ×Ö·û´®,ÀıÈçLCD_PutString(24,16,"123Eee",White,Blue);¼´°Ñ"123Eee"µÄµÚÒ»¸ö×Ö·ûµØÖ·¸³¸øÖ¸Õë±äÁ¿s.
//		        bColor ×Ö·û±³¾°ÑÕÉ«
****************************************************************************************************/
void LCD_PutString(unsigned short x, unsigned short y, unsigned char *s, unsigned int fColor, unsigned int bColor) 
{
	 unsigned char l=0;                            	//ÏÔÊ¾ÆÁÎ»ÖÃÔöÁ¿
	 unsigned short i,j;
	
	i=y;                                            //ÕâÀï½øĞĞ×ø±ê±ä»»£¬ÓÉÊúÆÁ±äºáÆÁĞèÒª±ä»»
	j=x;
	x=i;
	y=319-j;
	
     while(*s) 
	 {
		if( *s < 0x80)                             		//ÅĞ¶ÏsÖ¸ÏòµÄ×Ö·û´®ÖĞµÄÄ³×Ö·ûµÄ±àÂëÖµÊÇ·ñĞ¡ÓÚ128,Èç¹ûĞ¡ÓÚ,¼´ÎªASCII×Ö·û
		    {
			 LCD_PutChar(x,y-l*8,*s,fColor,bColor);			//ÏÔÊ¾¸Ã×Ö·û
		     s++;l++;                              		//Ö¸Õë¼Ó1,Î»ÖÃ¼Ó1
			}
	 }
}

/****************************************************************************************************
º¯Êı¹¦ÄÜ:ÏÔÊ¾×Ö·û´®24x24´óĞ¡,¿ÉÒÔÖĞÓ¢ÎÄÍ¬Ê±ÏÔÊ¾
ÊäÈë²ÎÊı£ºx ºá×ø±ê
         y ×İ×ø±ê
         *s ĞèÒªÏÔÊ¾µÄ×Ö·û´®
				 fColor ×Ö·ûÑÕÉ«
         bColor ×Ö·û±³¾°ÑÕÉ«
****************************************************************************************************/
void LCD_PutString24(unsigned short x , unsigned short y, unsigned char *s, unsigned int fColor, unsigned int bColor) {
	 unsigned char l=0;
	 unsigned short i,j;
	i=y;																											//×ø±ê±ä»»
	j=x;
	x=i;
	y=319-j;
	while(*s) {
		if( *s < 0x80) 
		    {
			LCD_PutChar(x,y-l*8,*s,fColor,bColor);
			s++;l++;
			}
		}
	}

/****************************************************************************************************
//	ÊµÏÖ¹¦ÄÜ£º	Ö¸¶¨Î»ÖÃÏÔÊ¾RGBÑÕÉ«
//  ÊäÈë²ÎÊı£º x0£¬y0 ÆğÊ¼×ø±ê
//            x1£¬y1 ½áÊø×ø±ê
//		        Color  ±³¾°ÑÕÉ«
****************************************************************************************************/

void Show_RGB (unsigned short x0,unsigned short x1,unsigned short y0,unsigned short y1,unsigned int Color)
{
	unsigned int i,j;
	
	LCD_SetPos(y0,y1,319-x1,319-x0);												//ºáÆÁÕâÀïÒª½øĞĞ×ø±ê±ä»»£¬Èç¹ûÊÇÊúÆÁ£¬ÔòÖ±½ÓÊÇx0,x1,y0,y1×ö²ÎÊı
	for (i=x0;i<=x1;i++)
	{
	   for (j=y0;j<=y1;j++)
	       Write_Data_U16(Color);
	}
}

/****************************************************************************************************
//	ÊµÏÖ¹¦ÄÜ£º	TFT³õÊ¼»¯
****************************************************************************************************/
void TFT_Initial()
{      
	int Device_code = 0x9320;
	GPIO_Config();
	RST_SET;    
	delayms(1);                    			// Delay 1ms 
	RST_CLR;  
	delayms(10);                   			// Delay 10ms            
	RST_SET;  
	delayms(50);                   			// Delay 50 ms  
  
	if(Device_code==0x9320)
     {

    //************* Start Initial Sequence **********//
	Write_Cmd_Data(0x00,0x0001);   		//Set the OSC bit as â€˜1â€™ to start the internal oscillator
  Write_Cmd_Data(0x01,0x0100);   	// set SS and SM bit
	Write_Cmd_Data(0x02,0x0700);   		// set 1 line inversion
	Write_Cmd_Data(0x03,0x1098);   		//set GRAM Write direction and BGR=1
  Write_Cmd_Data(0x04,0x0000);   	// Resize register
	Write_Cmd_Data(0x08,0x0202);   		// set the back porch and front porch
  Write_Cmd_Data(0x09,0x0000);   	// set non-display area refresh cycle ISC[3:0]
  Write_Cmd_Data(0x0A,0x0000);   	// FMARK function
  Write_Cmd_Data(0x0C,0x0000);   	// RGB interface setting
	Write_Cmd_Data(0x0D,0x0000);   		// Frame marker Position
  Write_Cmd_Data(0x0F,0x0000);   	// RGB interface polarity
  delayms(30);
	//*************Power On sequence ****************//
	Write_Cmd_Data(0x10, 0x16b0);   // SAP, BT[3:0], AP, DSTB, SLP, STB
	delayms(30);
	Write_Cmd_Data(0x11, 0x0007);   //Write final userâ€™s setting values to VC bit
	Write_Cmd_Data(0x12, 0x013a);   // set Internal reference voltage
	Write_Cmd_Data(0x13, 0x1a00);   // VDV[4:0] for VCOM amplitude
  delayms(30);
  Write_Cmd_Data(0x29, 0x000c);   // Set VCM[5:0] for VCOMH
	delayms(30); // Delay 50ms

	// ----------- Adjust the Gamma Curve ----------//
	Write_Cmd_Data(0x0030, 0x0000);
	Write_Cmd_Data(0x0031, 0x0505);
	Write_Cmd_Data(0x0032, 0x0304);
	Write_Cmd_Data(0x0035, 0x0006);
	Write_Cmd_Data(0x0036, 0x0707);
	Write_Cmd_Data(0x0037, 0x0105);
	Write_Cmd_Data(0x0038, 0x0002);
	Write_Cmd_Data(0x0039, 0x0707);
	Write_Cmd_Data(0x003C, 0x0704);
	Write_Cmd_Data(0x003D, 0x0807);

	//------------------ Set GRAM area ---------------//
	Write_Cmd_Data(0x0050, 0x0000); // Horizontal GRAM Start Address
	Write_Cmd_Data(0x0051, 0x00EF); // Horizontal GRAM End Address
	Write_Cmd_Data(0x0052, 0x0000); // Vertical GRAM Start Address
	Write_Cmd_Data(0x0053, 0x013F); // Vertical GRAM Start Address
	Write_Cmd_Data(0x0060, 0x2700); // Gate Scan Line
	Write_Cmd_Data(0x0061, 0x0001); // NDL,VLE, REV
	Write_Cmd_Data(0x006A, 0x0000); // set scrolling line
  Write_Cmd_Data(0x20, 0x0000);   // GRAM horizontal Address
	Write_Cmd_Data(0x21, 0x0000);   // GRAM Vertical Address

	//-------------- Partial Display Control ---------//
	Write_Cmd_Data(0x0080, 0x0000);
	Write_Cmd_Data(0x0081, 0x0000);
	Write_Cmd_Data(0x0082, 0x0000);
	Write_Cmd_Data(0x0083, 0x0000);
	Write_Cmd_Data(0x0084, 0x0000);
	Write_Cmd_Data(0x0085, 0x0000);

	//-------------- Panel Control ---------//
  Write_Cmd_Data(0x90,0x0010);   //Frame Cycle Contral
	Write_Cmd_Data(0x92,0x0000);   //Panel Interface Contral
	Write_Cmd_Data(0x93,0x0003);   //Panel Interface Contral 3. 
	Write_Cmd_Data(0x95,0x0110);   //Frame Cycle Contral
	Write_Cmd_Data(0x97,0x0000);   // 
	Write_Cmd_Data(0x98,0x0000);   //Frame Cycle Contral.     

	//-------------- Display on ---------//
  Write_Cmd_Data(0x07,0x0173); 

	}

	else if(Device_code==0x1505 )
     {

    //************* Start Initial Sequence **********//
	Write_Cmd_Data(0x00,0x0001);   //Set the OSC bit as â€˜1â€™ to start the internal oscillator
  Write_Cmd_Data(0x01,0x0100);   // set SS and SM bit
	Write_Cmd_Data(0x02,0x0700);   // set 1 line inversion
	Write_Cmd_Data(0x03,0x1030);   //set GRAM Write direction and BGR=1
  Write_Cmd_Data(0x04,0x0000);   // Resize register
	Write_Cmd_Data(0x08,0x0202);   // set the back porch and front porch
  Write_Cmd_Data(0x09,0x0000);   // set non-display area refresh cycle ISC[3:0]
  Write_Cmd_Data(0x0A,0x0000);   // FMARK function
  Write_Cmd_Data(0x0C,0x0000);   // RGB interface setting
	Write_Cmd_Data(0x0D,0x0000);   // Frame marker Position
  Write_Cmd_Data(0x0F,0x0000);   // RGB interface polarity
  delayms(30);
	//*************Power On sequence ****************//
	Write_Cmd_Data(0x10, 0x16b0);   // SAP, BT[3:0], AP, DSTB, SLP, STB
	delayms(30);
	Write_Cmd_Data(0x11, 0x0007);   //Write final userâ€™s setting values to VC bit
	Write_Cmd_Data(0x12, 0x013a);   // set Internal reference voltage
	Write_Cmd_Data(0x13, 0x1a00);   // VDV[4:0] for VCOM amplitude
  delayms(30);
  Write_Cmd_Data(0x29, 0x000c);   // Set VCM[5:0] for VCOMH
	delayms(30); // Delay 50ms

	// ----------- Adjust the Gamma Curve ----------//
	Write_Cmd_Data(0x0030, 0x0000);
	Write_Cmd_Data(0x0031, 0x0505);
	Write_Cmd_Data(0x0032, 0x0304);
	Write_Cmd_Data(0x0035, 0x0006);
	Write_Cmd_Data(0x0036, 0x0707);
	Write_Cmd_Data(0x0037, 0x0105);
	Write_Cmd_Data(0x0038, 0x0002);
	Write_Cmd_Data(0x0039, 0x0707);
	Write_Cmd_Data(0x003C, 0x0704);
	Write_Cmd_Data(0x003D, 0x0807);

	//------------------ Set GRAM area ---------------//
	Write_Cmd_Data(0x0050, 0x0000); // Horizontal GRAM Start Address
	Write_Cmd_Data(0x0051, 0x00EF); // Horizontal GRAM End Address
	Write_Cmd_Data(0x0052, 0x0000); // Vertical GRAM Start Address
	Write_Cmd_Data(0x0053, 0x013F); // Vertical GRAM Start Address
	Write_Cmd_Data(0x0060, 0x2700); // Gate Scan Line
	Write_Cmd_Data(0x0061, 0x0001); // NDL,VLE, REV
	Write_Cmd_Data(0x006A, 0x2700); // set scrolling line
  Write_Cmd_Data(0x20, 0x0000);   // GRAM horizontal Address
	Write_Cmd_Data(0x21, 0x0000);   // GRAM Vertical Address

	//-------------- Partial Display Control ---------//
	Write_Cmd_Data(0x0080, 0x0000);
	Write_Cmd_Data(0x0081, 0x0000);
	Write_Cmd_Data(0x0082, 0x0000);
	Write_Cmd_Data(0x0083, 0x0000);
	Write_Cmd_Data(0x0084, 0x0000);
	Write_Cmd_Data(0x0085, 0x0000);

	//-------------- Panel Control ---------//
  Write_Cmd_Data(0x90,0x0010);   //Frame Cycle Contral
	Write_Cmd_Data(0x92,0x0000);   //Panel Interface Contral
	Write_Cmd_Data(0x93,0x0003);   //Panel Interface Contral 3. 
	Write_Cmd_Data(0x95,0x0110);   //Frame Cycle Contral
	Write_Cmd_Data(0x97,0x0000);   // 
	Write_Cmd_Data(0x98,0x0000);   //Frame Cycle Contral.     

	//-------------- Display on ---------//
  Write_Cmd_Data(0x07,0x0173); 

	}

  else if(Device_code==0x9328)
     {

    //************* Start Initial Sequence **********//
	 Write_Cmd_Data(0x0001,0x0100);   //set SS and SM bit //è®¾ç½®æ‰«ææ–¹å‘  100
   Write_Cmd_Data(0x0002,0x0700);   //EOR=1 and B/C=1 to set the line inversion  //è®¾ç½®è¡Œåè½¬
   Write_Cmd_Data(0x0003,0x1098);   //set Entry Mode  //è®¾ç½®è¿›å…¥æ¨¡å¼    1030
   Write_Cmd_Data(0x0004,0x0000);   //
   Write_Cmd_Data(0x00A4,0x0001);
   Write_Cmd_Data(0x0008,0x0202); // set the back porch and front porch
   Write_Cmd_Data(0x0009,0x0000); // set non-display area refresh cycle ISC[3:0]
   Write_Cmd_Data(0x000A,0x0000); // FMARK function
   Write_Cmd_Data(0x000C,0x0000); // RGB interface setting
   Write_Cmd_Data(0x000D, 0x0000); // Frame marker Position
   Write_Cmd_Data(0x000F, 0x0000); // RGB interface polarity



//*************Power On sequence ****************//
    Write_Cmd_Data(0x0010, 0x0000); // SAP, BT[3:0], AP, DSTB, SLP, STB 
    Write_Cmd_Data(0x0011, 0x0007); // DC1[2:0], DC0[2:0], VC[2:0]
    Write_Cmd_Data(0x0012, 0x0000); // VREG1OUT voltage
    Write_Cmd_Data(0x0013, 0x0000); // VDV[4:0] for VCOM amplitude 
    delayms(30);
    Write_Cmd_Data(0x0010, 0x1690); // SAP, BT[3:0], AP, DSTB, SLP, STB 
    Write_Cmd_Data(0x0011, 0x0227); // R11h=0x0221 at VCI=3.3V, DC1[2:0], DC0[2:0], VC[2:0]
    delayms(30);
    Write_Cmd_Data(0x0012, 0x001C); // External reference voltage= Vci;
    delayms(30); 
    Write_Cmd_Data(0x0013, 0x1800); // R13=1200 when R12=009D;VDV[4:0] for VCOM amplitude
    Write_Cmd_Data(0x0029, 0x001C); // R29=000C when R12=009D;VCM[5:0] for VCOMH
    Write_Cmd_Data(0x002B, 0x000D); // Frame Rate = 91Hz
    delayms(30);    
    Write_Cmd_Data(0x0020, 0x0000); // GRAM horizontal Address
    Write_Cmd_Data(0x0021, 0x0000); // GRAM Vertical Address
// ----------- Adjust the Gamma Curve ----------// 		 
	  Write_Cmd_Data(0x0030, 0x0007);
	  Write_Cmd_Data(0x0031, 0x0302);
    Write_Cmd_Data(0x0032, 0x0105);
	  Write_Cmd_Data(0x0035, 0x0206);
    Write_Cmd_Data(0x0036, 0x0808);	          
    Write_Cmd_Data(0x0037, 0x0206);
    Write_Cmd_Data(0x0038, 0x0504);
    Write_Cmd_Data(0x0039, 0x0007);
    Write_Cmd_Data(0x003C, 0x0105);
    Write_Cmd_Data(0x003D, 0x0808);
//------------------ Set GRAM area ---------------//
    Write_Cmd_Data(0x0050, 0x0000); // Horizontal GRAM Start Address
    Write_Cmd_Data(0x0051, 0x00EF); // Horizontal GRAM End Address
    Write_Cmd_Data(0x0052, 0x0000); // Vertical GRAM Start Address
	  delayms(30);
    Write_Cmd_Data(0x0053, 0x013F); // Vertical GRAM End Address
	  delayms(30);
    Write_Cmd_Data(0x0060, 0xA700); // Gate Scan Line
    Write_Cmd_Data(0x0061, 0x0001); // NDL,VLE, REV  
    Write_Cmd_Data(0x006A, 0x0000); // set scrolling line
//-------------- Partial Display Control ---------//
    Write_Cmd_Data(0x0080, 0x0000);
    Write_Cmd_Data(0x0081, 0x0000);
    Write_Cmd_Data(0x0082,0x0000); 
    Write_Cmd_Data(0x0083,0x0000); 
    Write_Cmd_Data(0x0084,0x0000); 
    Write_Cmd_Data(0x0085,0x0000); 
//-------------- Panel Control -------------------//        
    Write_Cmd_Data(0x0090, 0x0010);
    Write_Cmd_Data(0x0092, 0x0000);
    Write_Cmd_Data(0x0093, 0x0003);
    Write_Cmd_Data(0x0095, 0x0110);
    Write_Cmd_Data(0x0097, 0x0000);
    Write_Cmd_Data(0x0098, 0x0000);
    Write_Cmd_Data(0x0007, 0x0133); // 262K color and display ON

	}
}

/****************************************************************************************************
//	ÊµÏÖ¹¦ÄÜ£º	»­µã
//  ÊäÈë²ÎÊı£º x£¬y ĞèÒª»­µã×ø±ê
//            color µãµÄÑÕÉ«
****************************************************************************************************/
void Put_pixel(unsigned int x,unsigned int y,unsigned int color)
{
	LCD_SetPos(y,y,319-x,319-x);												//ºáÆÁÕâÀïÒª½øĞĞ×ø±ê±ä»»£¬Èç¹ûÊÇÊúÆÁ£¬ÔòÖ±½ÓÊÇx0,x1,y0,y1×ö²ÎÊı

	Write_Data_U16(color);      												//ÔÚÖ¸¶¨µãĞ´ÈëÑÕÉ«Êı¾İ
}



