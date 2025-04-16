

#ifndef CIRCULAR_BUFFER_H_
#define CIRCULAR_BUFFER_H_


#include "stdint.h"
#include "stm32f4xx.h"
#include "string.h"


#define UART_BUFFER_SIZE	512
#define INIT_VAL 			0

typedef uint8_t portType;


typedef struct
{
	unsigned char buffer[UART_BUFFER_SIZE];
	volatile uint8_t head;
	volatile uint8_t tail;

}circular_buffer;


void init_circular_buffer();

int8_t find_string(char* sub, char* main);

void clear_buffer(portType);
void read_buffer(portType);
void write_to_buffer(portType);


#endif /* CIRCULAR_BUFFER_H_ */
