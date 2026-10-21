
#include "uart.h"

int main(void)
{

	RCC->APB2ENR |= (1<<2) | (1<<14); // GPIOA and USART1 clock enabled

	//UART1 pin configuration
	GPIOA->CRH &= ~((0xF<<4) | (0xF<<8)); //Resetting pin 9&10
	GPIOA->CRH |= (0xB<<4) | (0x4<<8); // Setting 9 (AF output push/pull 50 Hz)& 10 (floating input)

	//Baud Rate Calculation for 9600 | 8MHz/(16x9600)=52.08333
	USART1->BRR = 0x341; //DIV_Mantissa,52=0x34. DIV_Fraction,0.0833x16=1.3333 eq. to 1 =0x1.
}
