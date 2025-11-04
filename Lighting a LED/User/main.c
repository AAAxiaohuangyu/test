#include "stm32f10x.h"                  // Device header

int main()
{
	
	/*RCC->APB2ENR = 	0x00000010; //使能GPIOC时钟
	GPIOC->CRH = 0x00300000; //PC13通用推挽输出模式,最大速度50MHz
	GPIOC->ODR = 0x00000200; //数据输出,00000000为低电频(亮),00002000为高电频(灭)*/
	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC,ENABLE); //使能GPIOC时钟
	GPIO_InitTypeDef GPIO_InitStructure; //定义结构体类型,下面对其配置参数
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;//通用推挽输出
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_13;//GPIO端口
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;//GPIO端口速度
	GPIO_Init(GPIOC,&GPIO_InitStructure); 
	//GPIO_ResetBits(GPIOC,GPIO_Pin_13); //低电频(亮)
	GPIO_SetBits(GPIOC,GPIO_Pin_13); //高电频(灭)
	while(1){
	
	}
	return 0;
}
