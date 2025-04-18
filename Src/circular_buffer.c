
/*
 *
 * We have TWO UARTS
 * 1. UART: for Debug
 * 2. UART: for ESP
 *
 * hence, we will have two receive circular buffers.
 * and two transmit buffers.
 *
 *
 *
 * */


/*
 * Use the reference manual to find the registers and the pins,
 * such as Control Register 1 for USART, USART_CR1,
 * then one can find pins, e.g. the TXEIE = Transmit Interrupt Enable, is bit number 7.
 *
 * */


#include "circular_buffer.h"

// Naming Register bits

#define CR1_RXNEIE		(1U<<5)
#define CR1_TXEIE		(1U<<7)



#define SR_RXNE			(1U<<5)
#define SR_TXE			(1U<<7)




// Ports
portType debug_port = 	0;
portType esp_port = 	1;



// UART0 circular buffers
circular_buffer rx_buffer1 = {{INIT_VAL}, INIT_VAL, INIT_VAL};
circular_buffer tx_buffer1 = {{INIT_VAL}, INIT_VAL, INIT_VAL};

// UART1 circular buffers
circular_buffer rx_buffer2 = {{INIT_VAL}, INIT_VAL, INIT_VAL};
circular_buffer tx_buffer2 = {{INIT_VAL}, INIT_VAL, INIT_VAL};


// Pointers

circular_buffer* rx_buffer1_ptr;
circular_buffer* tx_buffer1_ptr;

circular_buffer* rx_buffer2_ptr;
circular_buffer* tx_buffer2_ptr;




// Initialize buffers


void init_circular_buffer()
{

	// Initialize pointers
	rx_buffer1_ptr = &rx_buffer1;
	tx_buffer1_ptr = &tx_buffer1;

	rx_buffer2_ptr = &rx_buffer2;
	tx_buffer2_ptr = &tx_buffer2;


	// Initialize interrupts

	USART1->CR1 |= CR1_RXNEIE;
	USART2->CR1 |= CR1_RXNEIE;

}




//--------- Methods ----------//


int8_t find_str(char* sub, char* main)
{
	int length, i,j;

	for(l=0; sub[l] != '\0'; l++){}

	for(i=0, j=0; main[i] != '\0' && sub[j]!='\0'; i++)
	{
		if(main[i]  == sub[j])
		{
			j++;
		}
		else
		{
			j=0;
		}
	}

	if(j == l)
	{
		return 1;
	}
	else
	{
		return -1;
	}
}














