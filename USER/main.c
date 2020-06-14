#include "sys.h"
#include "delay.h"
#include "usart.h"
#include "led.h"
#include "key.h"
#include "sdram.h"
#include "tftlcd.h"
#include "ltdc.h"
#include "mpu.h"
#include "timer.h"
#include "usmart.h"
#include "malloc.h"
#include "touch.h"
#include "GUI.h"
#include "WM.h"
#include "GUIDEMO.h"
#include "TemPlay02.h"

/************************************************
 ALIENTEK STM32������STemWinʵ��
 STemWin�޲���ϵͳ��ֲʵ��
 ����֧�֣�www.openedv.com
 �Ա����̣�http://eboard.taobao.com  
 ��ע΢�Ź���ƽ̨΢�źţ�"����ԭ��"����ѻ�ȡSTM32���ϡ�
 ������������ӿƼ����޹�˾  
 ���ߣ�����ԭ�� @ALIENTEK
************************************************/
void OpenScreen (void);

int main(void)
{  
    Write_Through();                //Cahceǿ��͸дģʽ
    MPU_Memory_Protection();        //������ش洢����
    Cache_Enable();                 //��L1-Cache
      
		Stm32_Clock_Init(432,25,2,9);   //����ʱ��,216Mhz 
		HAL_Init();				        //��ʼ��HAL��
    delay_init(216);                //��ʱ��ʼ��
		uart_init(115200);		        //���ڳ�ʼ��
    KEY_Init();                     //������ʼ��
    LED_Init();                     //��ʼ��LED
    SDRAM_Init();                   //SDRAM��ʼ�

		TFTLCD_Init();                  //��ʼ��LCD
    TP_Init();				        //��������ʼ��

    TIM3_Init(999,107);             //1KHZ ��ʱ��3����Ϊ1ms
    TIM4_Init(999,1079);            //������ɨ���ٶ�,100HZ.
	
    my_mem_init(SRAMIN);            //��ʼ���ڲ��ڴ��
    my_mem_init(SRAMEX);            //��ʼ���ⲿSDRAM�ڴ��
    my_mem_init(SRAMDTCM);          //��ʼ���ڲ�DTCM�ڴ��
	__HAL_RCC_CRC_CLK_ENABLE();		//ʹ��CRCʱ��
	
		WM_SetCreateFlags(WM_CF_MEMDEV);//����STemWin�洢�豸
		GUI_Init();
		GY906_Init();   //��ʼ��GY906����ʵ������ǳ�ʼ��IIC��
    WM_MULTIBUF_Enable(1);			//����STemWin�໺�壬RGB�����ܻ��õ�
	  OpenScreen();   //������ʾ���棬ûɶ�ã����

   CreateGY906_Test02();   //GY906�¶ȶ�ȡ+ GUIBuilider��ʾ����
    while(1)
    {
			GUI_Delay(100);
	}
}



void OpenScreen (void)
{
		GUI_SetBkColor(GUI_BLUE);
		GUI_SetColor(GUI_RED);
		GUI_Clear();
		GUI_SetFont(&GUI_Font32_ASCII);
		GUI_DispStringAt("HELLO YU CHENG ",300,200);
		delay_ms(3000);
		GUI_Clear();

}
