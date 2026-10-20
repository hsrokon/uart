
#include "uart.h"

int main(void)
{

	RCC->APB2ENR |= (1<<2) | (1<<14); // GPIOA and USART1 clock enabled

	GPIOA->CRH &= ~((0xF<<4) | (0xF<<8)); //Resetting pin 9&10
	GPIOA->CRH |= (0xB<<4) | (0x4<<8); // Setting 9 (AF output push/pull 50 Hz)& 10 (floating input)
}
