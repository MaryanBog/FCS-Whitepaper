# FCS-SDK — Flexionization Control System
## Technical SDK for Embedded Robotics and UAV Control

**FCS-SDK** is a lightweight C++ implementation of the Flexionization Control System (FCS) based on the **FXI–Δ–E** architecture and the control function **G : Δ → U**.

The SDK is intended for integration into embedded real-time control loops such as:

- flight controllers (PX4, ArduPilot),
- robotic manipulators,
- servo/actuator systems,
- ROS2 motion nodes,
- STM32/ESP32/ARM microcontrollers,
- autonomous ground robots.

The library is dependency-free and suitable for real-time systems.

---

## Core Idea

FCS implements the **FXI–Δ–E** loop:

1. Transform deviation Δ into FXI-space using **F**  
2. Apply equilibrium correction **E**  
3. Convert corrected value back using **F⁻¹**  
4. Generate control signal via **G**

This structure generalizes PID-like behavior while remaining stable, monotonic, and suitable for nonlinear actuators.

---

## Overview of Included Components

- `F` — deviation transformation  
- `E` — equilibrium operator  
- `F⁻¹` — inverse mapping  
- `G` — control output shaping  
- `FCS` — main control loop class  
- example applications and integration templates

All operators are easily replaceable with user-defined functions.

---

## Integration Notes

- Designed for real-time loops (100–1000 Hz)  
- Works on microcontrollers (no heap usage)  
- Can directly replace or augment PID controllers  
- G operator can be nonlinear or saturated (tanh, piecewise, adaptive)

---

## License

All SDK materials are the intellectual property of the author.  
For commercial usage, licensing terms are available on request.
