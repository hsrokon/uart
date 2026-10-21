
#include "uart.h"

//Sending character
void uart_send_char(char c){

	while(!(USART1->SR & (1<<7))){
		//Wait for TXE of Status Register to be 1 | Transmit Data Register Empty(TXE)
		}
	USART1->DR =c; // writing characters to our data register
	//bits in data register gets shifted bit by bit from shift register through the pin to the wire
}

int main(void)
{

	RCC->APB2ENR |= (1<<2) | (1<<14); // GPIOA and USART1 clock enabled

	//UART1 pin configuration
	GPIOA->CRH &= ~((0xF<<4) | (0xF<<8)); //Resetting pin A, 9&10
	GPIOA->CRH |= (0xB<<4) | (0x4<<8);
	// Setting 9 (AF output push/pull 50 Hz) Tx, & 10 (floating input) Rx.

	//Baud Rate Calculation for 9600 | 8MHz/(16x9600)=52.08333
	USART1->BRR = 0x341; //DIV_Mantissa,52=0x34. DIV_Fraction,0.0833x16=1.3333 eq. to 1 =0x1.

	//USART Control Register Enabling
	USART1->CR1 |= (1<<13)|(1<<3)|(1<<2); //UE,TE,RE Enabled.


	while(1){

		uart_send_char('A');//Sending character A

		for(volatile int i=0; i<1000000; i++); //Delaying so terminal don't get flooded instantly
	}
}
