# FCS-SDK Overview

The FCS-SDK provides a minimal, dependency-free implementation of the Flexionization Control System based on the FXI–Δ–E loop and the output function G(Δ).  
It is designed for embedded real-time control applications.

---

## Core Components

The SDK contains the following modules:

- **F operator** – transforms deviation Δ into the FXI-space.  
- **E operator** – applies equilibrium correction.  
- **F⁻¹ operator** – restores corrected deviation back to the original domain.  
- **G operator** – generates the final control signal.  
- **FCS class** – assembles all operators into a single control loop.

Operators are implemented as lightweight standalone functions and can be replaced with custom definitions if required.

---

## How the FXI–Δ–E Loop Works

1. The raw deviation Δ enters the controller.  
2. **F(Δ)** projects the deviation into a monotonic control space.  
3. **E(x)** reduces, smooths, or reshapes the deviation.  
4. **F⁻¹(xₑ)** returns the corrected value back to Δ-space.  
5. **G(Δ')** generates the actuator command.

This makes the system compatible with nonlinear actuators, PWM, servo drives, ESCs, and general closed-loop robotics systems.

---

## Design Principles

- deterministic execution  
- no dynamic memory allocation  
- works on microcontrollers  
- stable under actuator saturation  
- predictable monotonic behavior  
- simple C++ interface

---

## What Is Included

- header-only operator definitions  
- minimal implementation of the FCS controller  
- example integration code (PX4, ROS2, simple loop tests)  
- mathematical background documents  
- API reference for all functions

---

## Customization

All operators can be replaced.

For example:

```cpp
ctrl.setG([](double x) {
    // nonlinear output
    return tanh(x) * 0.8;
});

This allows tailoring the controller for drones, manipulators, wheeled robots, or servo systems.

Summary

The FCS-SDK provides a compact and extensible foundation for real-time robotic control based on the FXI–Δ–E architecture.
It is suitable for standalone microcontrollers as well as full-scale robotic platforms.

---
