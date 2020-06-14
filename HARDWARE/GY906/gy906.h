#ifndef _GY906_H
#define _GY906_H
#include "sys.h"
#include "myiic.h"


//************************************
#define uint unsigned int
#define uchar unsigned char
#define Nack_counter 10
//**************端口定义**************
//IO口
//SCL  PH4
//SDA  PH5
void GY906_Init(void);
float Get_Tem_DATA( u8 ReaAd); //读温度数据



























#endif