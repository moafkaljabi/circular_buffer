# STM32F4 UART Circular Buffer

This project implements an efficient circular buffer system for UART communication on the STM32F4 Nucleo board. It supports both UART receive (RX) and transmit (TX) operations on two UART interfaces, making it suitable for real-time, non-blocking serial communication in embedded applications.

## Features

- Circular buffer implementation for UART RX and TX
- Support for two UART ports (e.g., USART0 and USART1)
- Non-blocking transmit and receive
- Compatible with STM32CubeIDE and HAL drivers
- Easily portable across STM32F4 series

## Target Hardware

- STM32F4 Nucleo Board (e.g., Nucleo-F411RE or similar)
- UART0 and UART1 pins connected for debugging or communication




## Getting Started

1. Open the project with **STM32CubeIDE**.
2. Ensure your `.ioc` configuration enables two UARTs (e.g., USART0 and USART1) with appropriate baud rates.
3. Build and flash the project to your Nucleo board.
4. Connect UART pins to a serial terminal or another device for testing.

## Usage

- The circular buffer handles incoming and outgoing data automatically in the background using interrupts.
- API functions are provided to enqueue and dequeue data.

## License

MIT License

---



