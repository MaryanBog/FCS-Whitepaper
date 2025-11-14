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

## Quick Start

```cpp
// Include the headers:
#include "fcs/fcs.h"
#include "fcs/operators/f_operator.h"
#include "fcs/operators/e_operator.h"
#include "fcs/operators/finv_operator.h"
#include "fcs/operators/g_operator.h"

// Initialize the controller:
fcs::FCS ctrl;

void setup_fcs() {
    ctrl.setF(fcs::default_F);
    ctrl.setE(fcs::default_E);
    ctrl.setFInv(fcs::default_FInv);
    ctrl.setG(fcs::default_G);
}

// Use inside your control loop:
double loop_step(double delta) {
    // delta = current deviation (error)
    double u = ctrl.update(delta);
    return u; // control signal for the actuator
}

## How the Control Cycle Works

The FCS update step computes:

\[
X = F(\Delta) 
\]
— deviation transformation

\[
X' = E(X)
\]
— equilibrium contraction

\[
\Delta' = F^{-1}(X')
\]
— inverse mapping

\[
u = G(\Delta')
\]
— actuator command output

The controller provides smooth and stable convergence, even in nonlinear or turbulent environments where classical PID becomes unstable.

## Integration Notes

- Designed for real-time loops (100–1000 Hz)
- Works on microcontrollers (no heap usage)
- Can directly replace or augment PID controllers
- G operator can be nonlinear or saturated (tanh, piecewise, adaptive)

## License

All SDK materials are the intellectual property of the author.  
For commercial usage, licensing terms are available on request.

