# Embedded-Systems-Engineering


This repository contains solutions to a series of assignments focused on embedded systems engineering, finite state machines, and ARM-based system simulations. The projects demonstrate advanced programming in C, hardware simulation, and system analysis.

**Technologies and Tools Used:**

Programming Language: C  
Tools and Libraries: GCC, QEMU, Linux system calls (select, usleep, scanf)  
Concepts: Finite state machines, UART communication, ARM architecture  
Environment: Linux, QEMU emulator

Key Features:

**Identifier Extraction Program**:
Reads a text file, identifies tokens that qualify as identifiers, and outputs them in alphabetical order with their corresponding line numbers.
Demonstrates proficiency in string manipulation, sorting algorithms, and file I/O in C.

**Traffic Light Simulation:**
Models a finite state machine to simulate a traffic light controller.
Emulates real-world button presses (North, East, Both, or None) using keyboard input, transitioning states based on input and elapsed time.

**PL011 UART Analysis:**
Explores the implementation of the PL011 UART controller in QEMU.
Provides a detailed explanation of the pl011_read function, covering UART register interactions, FIFO operations, and interrupt handling.

**Cross-Compiled Traffic Light Controller for ARM SoC:**
Builds and runs a traffic light controller model on an ARM-based SoC using the QEMU emulator.
Leverages QEMU's versatilepb board for simulation, incorporating serial communication through the PL011 UART.
