#ifndef _GY906_H
#define _GY906_H
#include "sys.h"
#include "myiic.h"


//************************************
#define uint unsigned int
#define uchar unsigned char
#define Nack_counter 10
//**************�˿ڶ���**************
//IO��
//SCL  PH4
//SDA  PH5
void GY906_Init(void);
float Get_Tem_DATA( u8 ReaAd); //���¶�����



























#endif