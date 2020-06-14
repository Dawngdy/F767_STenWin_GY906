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
 ALIENTEK STM32¿ª·¢°åSTemWinÊµÑé
 STemWinÎŞ²Ù×÷ÏµÍ³ÒÆÖ²ÊµÑé
 ¼¼ÊõÖ§³Ö£ºwww.openedv.com
 ÌÔ±¦µêÆÌ£ºhttp://eboard.taobao.com  
 ¹Ø×¢Î¢ĞÅ¹«ÖÚÆ½Ì¨Î¢ĞÅºÅ£º"ÕıµãÔ­×Ó"£¬Ãâ·Ñ»ñÈ¡STM32×ÊÁÏ¡£
 ¹ãÖİÊĞĞÇÒíµç×Ó¿Æ¼¼ÓĞÏŞ¹«Ë¾  
 ×÷Õß£ºÕıµãÔ­×Ó @ALIENTEK
************************************************/
void OpenScreen (void);

int main(void)
{  
    Write_Through();                //CahceÇ¿ÖÆÍ¸Ğ´Ä£Ê½
    MPU_Memory_Protection();        //±£»¤Ïà¹Ø´æ´¢ÇøÓò
    Cache_Enable();                 //´ò¿ªL1-Cache
      
		Stm32_Clock_Init(432,25,2,9);   //ÉèÖÃÊ±ÖÓ,216Mhz 
		HAL_Init();				        //³õÊ¼»¯HAL¿â
    delay_init(216);                //ÑÓÊ±³õÊ¼»¯
		uart_init(115200);		        //´®¿Ú³õÊ¼»¯
    KEY_Init();                     //°´¼ü³õÊ¼»¯
    LED_Init();                     //³õÊ¼»¯LED
    SDRAM_Init();                   //SDRAM³õÊ¼»

		TFTLCD_Init();                  //³õÊ¼»¯LCD
    TP_Init();				        //´¥ÃşÆÁ³õÊ¼»¯

    TIM3_Init(999,107);             //1KHZ ¶¨Ê±Æ÷3ÉèÖÃÎª1ms
    TIM4_Init(999,1079);            //´¥ÃşÆÁÉ¨ÃèËÙ¶È,100HZ.
	
    my_mem_init(SRAMIN);            //³õÊ¼»¯ÄÚ²¿ÄÚ´æ³Ø
    my_mem_init(SRAMEX);            //³õÊ¼»¯Íâ²¿SDRAMÄÚ´æ³Ø
    my_mem_init(SRAMDTCM);          //³õÊ¼»¯ÄÚ²¿DTCMÄÚ´æ³Ø
	__HAL_RCC_CRC_CLK_ENABLE();		//Ê¹ÄÜCRCÊ±ÖÓ
	
		WM_SetCreateFlags(WM_CF_MEMDEV);//¿ªÆôSTemWin´æ´¢Éè±¸
		GUI_Init();
		GY906_Init();   //³õÊ¼»¯GY906£¬ÆäÊµÕâÀï¾ÍÊÇ³õÊ¼»¯IIC¡£
    WM_MULTIBUF_Enable(1);			//¿ªÆôSTemWin¶à»º³å£¬RGBÆÁ¿ÉÄÜ»áÓÃµ½
	  OpenScreen();   //¿ª»úÏÔÊ¾½çÃæ£¬Ã»É¶ÓÃ£¬ÍæµÄ

   CreateGY906_Test02();   //GY906ÎÂ¶È¶ÁÈ¡+ GUIBuiliderÏÔÊ¾º¯Êı
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
