#include "stm32f10x.h"
#include "stm32f10x_conf.h"

void delay(uint32_t time);

int main(void){

    // Enable GPIOC clock
    
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC, ENABLE);

    SystemInit();
    SystemCoreClockUpdate(); 

    GPIO_InitTypeDef GPIO_InitStructure;
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_13;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_2MHz;
    GPIO_Init(GPIOC, &GPIO_InitStructure);

    for (uint32_t i = 0; i < (SystemCoreClock / 10000) / 3; i++){
        GPIO_SetBits(GPIOC, GPIO_Pin_13); // Set PC13 high
        delay(500); // Delay for 1 second
        GPIO_ResetBits(GPIOC, GPIO_Pin_13); // Set PC13 low
        delay(500); // Delay for 1 second
    }

}

void delay(uint32_t time){
    for(uint32_t i = 0; i < time; i++){
        for(uint32_t j = 0; j < (SystemCoreClock / 10000) / 3; j++);
    }
}