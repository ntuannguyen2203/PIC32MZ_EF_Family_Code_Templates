# UART Interrupt Example for PIC32MZ EF

This application demonstrates interrupt-driven UART communication using UART2 on a PIC32MZ2048EFM144 microcontroller.

## Features

- Configures UART2 with:
  - 115200 baud rate
  - 8-bit data
  - No parity
  - 1 stop bit
  - High-speed mode
- Implements interrupt-driven reception
- Includes debug LED feedback (RH0 pin toggles on receive)
- Supports printf() through custom _write() implementation
- Buffer size of 255 bytes for received data
- Provides system reset cause detection and reporting

## Hardware Configuration

- UART2:
  - RX: Pin G6 
  - TX: Pin B14
- Debug LED: Pin H0

## System Clock Configuration

- System Clock: 200 MHz
- Peripheral Bus Clock: 100 MHz
- UART derived from PBCLK

## Usage

1. The system initializes and prints "UART2 Initialized"
2. System reports reset cause through printf()
3. Prints welcome message
4. Enters echo mode where:
   - Received characters are buffered
   - Complete messages (terminated by CR/LF) are echoed back
   - LED on RH0 toggles with each received character

## Build Information

Built using:
- MPLAB X IDE
- XC32 Compiler v4.60
- PIC32MZ-EF_DFP v1.5.173