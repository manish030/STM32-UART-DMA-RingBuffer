# STM32 Interrupt-Driven UART & Ring Buffer Driver

Lightweight, non-blocking circular buffer and UART driver written in Embedded C for **ARM Cortex-M (STM32)** microcontrollers. Designed for reliable serial telemetry (RS232/RS485) without blocking the main execution loop.

## Key Features
* **ISR-Safe Single-Producer / Single-Consumer:** Uses `volatile` head/tail indices so UART RX interrupts push bytes safely while the main loop parses frames.
* **Zero Dynamic Memory Allocation:** Uses static caller-allocated memory buffers (`uint8_t[]`) suitable for safety-critical embedded firmware.
* **Portable Architecture:** Decoupled hardware abstraction layer (`uart_driver.c`) portable across STM32F4, STM32G0, and STM32L4 series using Keil uVision or STM32CubeIDE.

## Toolchain & Verification
* **IDE:** STM32CubeIDE / Keil uVision
* **Hardware Tested:** STM32F4xx Nucleo / Custom STM32 Industrial Board
* **Verification:** Verified zero byte-drop at 115200 bps using a USB-to-TTL adapter and Logic Analyzer.
