#include "stm32f10x.h"
#include "stm32f10x_conf.h"

void delay(uint32_t time);


int main(void){
    SystemInit();
    SystemCoreClockUpdate();


    // Enable GPIOC clock
    
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC, ENABLE);
    
    GPIO_InitTypeDef GPIO_InitStructure;
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_13;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_2MHz;
    GPIO_Init(GPIOC, &GPIO_InitStructure);

    while(1){
        GPIO_SetBits(GPIOC, GPIO_Pin_13);
        delay(500);
        GPIO_ResetBits(GPIOC, GPIO_Pin_13);
        delay(500);
    } 

}

void delay(uint32_t time){
    for(uint32_t i = 0; i < time; i++){
        for(uint32_t j = 0; j < (SystemCoreClock / 10000) / 3; j++);
    }
}