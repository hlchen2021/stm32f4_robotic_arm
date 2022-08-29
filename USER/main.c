#include "sys.h"
#include "delay.h"
#include "usart.h"
#include "led.h"
#include "pwm.h"
#include "GUI.h"
#include "Lcd_Driver.h"

//PWM输出实验-库函数版本
//STM32F4工程模板-库函数版本
//淘宝店铺：http://mcudev.taobao.com	
	u16 pwmval=0;    
	u8 dir=1;
int main(void)
{ 

	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);//设置系统中断优先级分组2
	delay_init(168);  //初始化延时函数
	
		Lcd_Init();	 //1.44寸液晶屏--初始化配置
	Lcd_Clear(GRAY0);//清屏
	Gui_DrawFont_GBK16(0,16,RED,GRAY0,"    STM32 PWM ");
  Gui_DrawFont_GBK16(0,48,BLUE,GRAY0,"  嵌入式开发网   ");	 
	Gui_DrawFont_GBK16(0,64,BLUE,GRAY0,"mcudev.taobao.com "); 
	
	uart_init(115200);//初始化串口波特率为115200
 	TIM3_PWM_Init(200000-1,84-1);	//84M/84=1Mhz的计数频率,重装载值500，所以PWM频率为 1M/500=2Khz.     
   while(1) //实现比较值从0-300递增，到300后从300-0递减，循环
	{
		Servo1_SetAngle(0);
		delay_ms(1500);
		Servo1_SetAngle(90);
		delay_ms(1500);
		Servo1_SetAngle(180);	//修改比较值，修改占空比
		delay_ms(1500);
	}
}
