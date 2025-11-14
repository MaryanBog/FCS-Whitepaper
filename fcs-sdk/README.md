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

## Features

- Full nonlinear control cycle **FXI–Δ–E** implemented in C++
- Pluggable operators: **F**, **E**, **F⁻¹**, **G**
- Deterministic execution (no dynamic allocation)
- Default linear operators included
- Suitable for high-frequency loops (100–1000 Hz)
- Ready for embedded use (MCUs, SBCs, industrial controllers)

---

## Directory Structure

```text
fcs-sdk/
│
├── include/
│   └── fcs/
│       ├── fcs.h
│       ├── fcs_config.h
│       └── operators/
│           ├── f_operator.h
│           ├── e_operator.h
│           ├── finv_operator.h
│           └── g_operator.h
│
├── src/
│   ├── fcs.cpp
│   ├── f_operator.cpp
│   ├── e_operator.cpp
│   ├── finv_operator.cpp
│   └── g_operator.cpp
│
├── examples/
│   ├── simple_loop_test.cpp
│   ├── drone_altitude_control.cpp
│   └── servo_position_control.cpp
│
└── CMakeLists.txt

Quick Start
1. Include headers
#include "fcs/fcs.h"
#include "fcs/operators/f_operator.h"
#include "fcs/operators/e_operator.h"
#include "fcs/operators/finv_operator.h"
#include "fcs/operators/g_operator.h"

2. Initialize controller
#include "fcs/fcs.h"
#include "fcs/operators/f_operator.h"
#include "fcs/operators/e_operator.h"
#include "fcs/operators/finv_operator.h"
#include "fcs/operators/g_operator.h"

fcs::FCS ctrl;

void setup_fcs() {
    ctrl.setF(fcs::default_F);
    ctrl.setE(fcs::default_E);
    ctrl.setFInv(fcs::default_FInv);
    ctrl.setG(fcs::default_G);
}

3. Use in control loop
double loop_step(double delta) {
    // delta = current deviation (error)
    double u = ctrl.update(delta);
    return u; // control signal for actuator
}

Control Cycle (FXI–Δ–E + G)

The update() call implements the following sequence:

X = F(Δ) — deviation transformation into FXI-space

X' = E(X) — equilibrium contraction (‖E(X)‖ < ‖X‖)

Δ' = F⁻¹(X') — mapping back to deviation space

u = G(Δ') — control signal for the physical actuator

This provides smooth, monotonic convergence and robust behavior in nonlinear and turbulent environments where classical PID controllers often become unstable.

Integration Notes

Recommended usage in loops of 100–1000 Hz

Safe for microcontrollers (no heap allocations inside update())

Can replace or augment existing PID loops

Custom operators F, E, F⁻¹, G can be implemented for:

saturation,

asymmetry,

adaptive behavior,

hardware-specific constraints.

License

All SDK materials are the intellectual property of the author.
For commercial use, licensing terms are available on request.
