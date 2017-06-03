#ifndef MAIN_H__
#define MAIN_H__
#include "messageQueue.h"
#include "TFT28Scope.h"
#ifdef __cplusplus
    extern "C" {
    #endif
		#include "adc1.h"
		#include "./TFT28/TFT28.h"
    #ifdef __cplusplus
    }
    #endif
extern MessageQueue_Class messageQueue_Obj;
extern Scope_Class Scope_Obj;
extern void adc1_Init();
#define ORDER 10
#endif
