#include "gy906.h"
#include "delay.h"


//------------------------------
float Get_Tem_DATA( u8 ReaAd)    //��ȡ�����������¶�ֵ���棬�����ȡ��RAM��ַ��������϶�
{
	//Slave Address (SA) can be 0x00 for any MLX90614
	//using Read Word: SA(write) - Command - SA(read) - LSByte - MSByte - PEC
   u8 Pecreg = 0;
	 u8 DataL = 0 ,DataH = 0;
	 u16 tem = 0;
	float Temp = 0;
	
	  IIC_Start();
	
	  IIC_Send_Byte(0x00); //SA + write to slave
	  IIC_Wait_Ack();	
  	IIC_Send_Byte(ReaAd); //RAM address 0x07, object temperature 1     //000X XXXX   RAM Access    001x xxxx* EEPROM Access

		IIC_Wait_Ack();
	//------------
		IIC_Start();
	  IIC_Send_Byte(0x01);  //SA + read from slave    	
  	IIC_Wait_Ack();
	
  	DataL=IIC_Read_Byte(1);
  	DataH=IIC_Read_Byte(1);
  	Pecreg=IIC_Read_Byte(1);
  	IIC_Stop();
  	tem = (DataH<<8) | DataL;;   //���յ���������16�����¶�ֵ
		//��16������ֵ�¶�ת��Ϊ��  //���У��˴�ֱ�ӷ���int�ͣ��ᶪʧС�����ݣ��ʻ��Ƿ��ظ�����
		Temp =  (((float)tem * 2) - 27315)/100;  //T= (DataH:DataL)*0.02-273.15  ??:DataH:DataL=0x27AD,??? T=-70.01��	  
	return Temp;
}


void GY906_Init(void)
{
		IIC_Init();
}

