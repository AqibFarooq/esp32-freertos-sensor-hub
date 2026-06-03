# ESP32 FreeRTOS Sensor Hub

A modern embedded software project developed in C++ using ESP-IDF and FreeRTOS.

## Overview

This project is designed to demonstrate embedded software development concepts commonly used in real-world products, including:

- Task-based software architecture
- Real-time scheduling
- Inter-task communication
- Synchronization primitives
- Hardware abstraction
- Sensor integration
- System diagnostics

The goal is to build a modular sensor hub running on ESP32 using modern C++ and FreeRTOS.

---

## Planned Features

### Phase 1 - In Progress
- FreeRTOS task creation
- Periodic task scheduling
- Serial logging

### Phase 2
- Queue-based communication
- Mutex protection
- LCD output

### Phase 3
- Sensor integration
- Health monitoring
- Stack usage tracking

### Phase 4
- Wireless telemetry
- MQTT communication
- Remote monitoring

---

## Planned Architecture

```text
Sensor Task
    |
    v
  Queue
    |
    +------> Display Task
    |
    +------> Logger Task

Health Monitor Task
```

## Technology Stack

- ESP32
- ESP-IDF
- FreeRTOS
- C++17
- Git

---

## Getting Started

Install ESP-IDF, open an ESP-IDF terminal, then build the firmware:

```sh
idf.py set-target esp32
idf.py build
```

Flash and monitor the board:

```sh
idf.py -p /dev/ttyUSB0 flash monitor
```

On macOS, the serial port is often named like `/dev/cu.usbserial-*` or `/dev/cu.SLAB_USBtoUART`.

---

## Future Enhancements

- CAN bus communication
- SPI peripherals
- MQTT telemetry
- Fault injection testing
- Watchdog monitoring
- Persistent storage
- 

## Project Status

🚧 In Development


---

## Author

Aqib Farooq
