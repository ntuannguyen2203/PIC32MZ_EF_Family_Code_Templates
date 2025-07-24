# PIC32MZ_EF Code Templates & Examples

🚀 **Code templates and example projects for Microchip PIC32MZ2048EFM144 microcontroller**  
🧰 Target family: **PIC32MZ_EF**  
🧩 IDE: MPLAB X | Compiler: XC32 | Config Tool: MPLAB Code Configurator (MCC) *(optional)*

---

## 📁 Repo Structure


---

## 🧠 About

This repository provides reusable code templates and peripheral examples targeting the **PIC32MZ2048EFM144** MCU.  
It is intended to speed up development and testing by offering pre-configured starter projects.

All examples are tested with:
- 📌 **PIC32MZ2048EFM144**
- ⚙️ **24 MHz Crystal (external POSC)**
- ⚙️ **8 MHz Crystal (Internal FRC)**
- 🔌 **On-board debug via PKOB on starter kit**

---

## ✅ Available Examples

| Example Name       | Description                              | Type         |
|--------------------|------------------------------------------|--------------|
| `gpio_toggle`      | Toggle an LED via GPIO output            | Bare-metal   |
| `uart_echo`        | Echo UART data via interrupt             | MCC + XC32   |
| `timer_interrupt`  | Periodic interrupt using Timer1          | Bare-metal   |
| `adc_read`         | Read analog value using ADC1             | MCC + Polling|
| `i2c_master`       | Communicate with I2C slave (e.g. EEPROM) | Bare-metal   |

---

## 🧰 Tools & Dependencies

- **MPLAB X IDE** (v6.x or newer, recommended 6.20)
- **XC32 Compiler** (v4.x)
- *(Optional)* **MPLAB Code Configurator (MCC)** for MCC-based examples
- Board support: **PIC32MZ2048EFM144**

---

## 🚀 Getting Started

1. Clone the repository:
   ```bash
   git clone https://github.com/ntuannguyen2203/PIC32MZ_EF_Family_Code_Templates.git

---


