#ifndef GUI_H
#define GUI_H
#ifndef uchar
#define uchar unsigned char 
#endif

#ifndef uint
#define uint unsigned int 
#endif
#include "math.h"
void GUIline(uint x0,uint y0,uint x1,uint y1,uint line_color);   //画线函数
void GUIfull(uint x0,uint y0,uint x1,uint y1,uint full_colour) ;
void plotC(uint x,uint y,uint xc,int yc,uint yc_colour) ;
void GUIcircle(uint xc,uint yc,uint r,uint circle_colour) ;
void GUIDotline(uint x0,uint y0,uint x1,uint y1,uint line_color);   //画虚线函数
void GUIpoint(unsigned int x,unsigned int y,unsigned int color);
#endif

