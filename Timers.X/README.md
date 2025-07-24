# PIC32MZ Timer1 Interrupt Example

This project demonstrates how to configure and use Timer1 with interrupts on a PIC32MZ2048EFM144 microcontroller. The code toggles output pins on each Timer1 interrupt.

## File Structure

```
Timers.X/
├── main.c
├── config.h
└── README.md
```

## Features

- Configures GPIO pins H0, H1, H2, and J3 as outputs.
- Sets up Timer1 with a 1:256 prescaler and a period register for periodic interrupts.
- Toggles LATH0, LATH1, and LATJ3 on each Timer1 interrupt.

## main.c Overview

- **config_GPIO()**: Initializes output pins.
- **config_Timer1()**: Sets up Timer1 and enables its interrupt.
- **TIM1_ISR()**: Interrupt Service Routine for Timer1, toggles output pins.
- **main()**: Initializes peripherals and enters an infinite loop.

## Usage

1. Open the project in MPLAB X or your preferred IDE.
2. Build and program the PIC32MZ device.
3. Observe the toggling of the configured output pins on each Timer1 interrupt.

## Dependencies

- MPLAB X IDE
- XC32 Compiler
- PIC32MZ2048EFM144 device header files

## Notes

- Adjust `PR1` and prescaler in `config_Timer1()` to change the interrupt frequency.
- Ensure the output pins are connected to LEDs or logic analyzers for observation.

---

**Author:**  
ntuannguyen2203