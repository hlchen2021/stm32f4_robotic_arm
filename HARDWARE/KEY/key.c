#include "key.h"
#include "delay.h" 
//////////////////////////////////////////////////////////////////////////////////	 
//STM32F4工程模板-库函数版本
//淘宝店铺：http://mcudev.taobao.com							  
////////////////////////////////////////////////////////////////////////////////// 	 

//按键初始化函数
void KEY_Init(void)
{
	
	GPIO_InitTypeDef  GPIO_InitStructure;

  RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA, ENABLE);//使能GPIOA时钟
 
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0;//K1对应引脚
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN;//普通输入模式
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;//100M
  GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;//上拉
	 
  GPIO_Init(GPIOA, &GPIO_InitStructure);//初始化GPIOA
 
} 
//按键处理函数
//返回按键值
//mode:0,不支持连续按;1,支持连续按;
//0，没有任何按键按下
//1，K1按下 

u8 KEY_Scan(u8 mode)
{	 
	static u8 key_up=1;//按键按松开标志
	
	if(mode)key_up=1;  //支持连按		  
	
	if(key_up&&(Key1==0))
		{
			delay_ms(10);//去抖动 
			key_up=0;
			 if(Key1==0)
				return KEY1_PRES;
		}
	else if(Key1==1)key_up=1; 
	
 	return 0;// 无按键按下
}




















