
#include "uart.h"

int main(void)
{

RCC->APB2ENR |= (1<<2) | (1<<14); // GPIOA and USART1 clock Enabled

}
