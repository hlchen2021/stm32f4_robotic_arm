#include "sys.h"
#include "delay.h"
#include "usart.h"
#include "led.h"
#include "pwm.h"
#include "GUI.h"
#include "Lcd_Driver.h"

//PWM���ʵ��-�⺯���汾
//STM32F4����ģ��-�⺯���汾
//�Ա����̣�http://mcudev.taobao.com	
	u16 pwmval=0;    
	u8 dir=1;
int main(void)
{ 

	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);//����ϵͳ�ж����ȼ�����2
	delay_init(168);  //��ʼ����ʱ����
	
		Lcd_Init();	 //1.44��Һ����--��ʼ������
	Lcd_Clear(GRAY0);//����
	Gui_DrawFont_GBK16(0,16,RED,GRAY0,"    STM32 PWM ");
  Gui_DrawFont_GBK16(0,48,BLUE,GRAY0,"  Ƕ��ʽ������   ");	 
	Gui_DrawFont_GBK16(0,64,BLUE,GRAY0,"mcudev.taobao.com "); 
	
	uart_init(115200);//��ʼ�����ڲ�����Ϊ115200
 	TIM3_PWM_Init(200000-1,84-1);	//84M/84=1Mhz�ļ���Ƶ��,��װ��ֵ500������PWMƵ��Ϊ 1M/500=2Khz.     
   while(1) //ʵ�ֱȽ�ֵ��0-300��������300���300-0�ݼ���ѭ��
	{
		Servo1_SetAngle(0);
		delay_ms(1500);
		Servo1_SetAngle(90);
		delay_ms(1500);
		Servo1_SetAngle(180);	//�޸ıȽ�ֵ���޸�ռ�ձ�
		delay_ms(1500);
	}
}
