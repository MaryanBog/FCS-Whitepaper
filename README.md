# FCS-SDK — Flexionization Control System
## Technical SDK & Whitepaper for Robotics and UAV Control

FCS-SDK is a lightweight C++ implementation of the Flexionization Control System (FCS),  
based on the FXI–Δ–E architecture and the control function **G : Δ → U**.

The repository includes:

- **FCS-Whitepaper** – formal description of the FXI–Δ–E architecture and control loop.
- **FCS-SDK** – production-ready C++ library for real-time control loops (100–1000 Hz).
- **Presentations** – investor and technical pitch decks (`PITCH.pdf`, `FCS.pdf`).

---

## Core Architecture: FXI–Δ–E + G

FCS is built on the FXI–Δ–E control loop, which transforms the deviation, stabilizes it, and maps it back into the control domain:

1. **Δ** — current deviation from the target state  
2. **F(Δ)** — monotonic transformation into the FXI-space  
3. **E** — equilibrium operator that smooths and reduces the deviation  
4. **F⁻¹** — inverse mapping back to the physical domain  
5. **G** — final control output shaping (linear, saturated, asymmetric, PWM, servo mapping)

This structure generalizes PID-like behavior but remains stable, monotonic, and suitable for nonlinear actuators and heterogeneous environments.

---

## Project Structure

```text
FCS/
├── FCS-Whitepaper-v1.0.md          # Original Russian whitepaper
├── FCS-Whitepaper-v1.1-EN.md       # English whitepaper (updated FXI–Δ–E model)
├── README.md                       # Main project overview
├── FCS-SDK/                         # C++ implementation of the FXI–Δ–E control system
│   ├── fcs-sdk/
│   │   ├── CMakeLists.txt
│   │   ├── README.md
│   │   ├── include/
│   │   │   └── fcs/
│   │   │       ├── fcs.h
│   │   │       ├── fcs_config.h
│   │   │       └── operators/
│   │   │           ├── f_operator.h
│   │   │           ├── e_operator.h
│   │   │           ├── finv_operator.h
│   │   │           └── g_operator.h
│   │   └── src/
│   │       ├── fcs.cpp
│   │       ├── f_operator.cpp
│   │       ├── e_operator.cpp
│   │       ├── finv_operator.cpp
│   │       └── g_operator.cpp
│   │
│   └── releases/
│       └── fcs-sdk-clean.zip
└── docs/
    └── presentations/
        ├── PITCH.pdf
        └── FCS.pdf
```

## Quick Start

```cpp
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

double loop_step(double delta) {
    double u = ctrl.update(delta);
    return u;
}
```

---

## Use Cases

FCS is designed for real-time control systems where stability, smooth response, and nonlinear actuator handling are required. Typical applications include:

- UAV flight controllers (PX4, ArduPilot)
- robotic manipulators and servo systems
- autonomous ground robots
- ROS2 motion control nodes
- STM32/ESP32/ARM-based embedded platforms
- gimbal and stabilization systems

---

## Features

- Lightweight C++ implementation suitable for real-time loops (100–1000 Hz)
- No dynamic memory allocation (MCU-friendly)
- Fully modular operator design: F, E, F⁻¹, G can be replaced or customized
- Stable monotonic control behavior based on the FXI–Δ–E architecture
- Works as a drop-in replacement or extension for PID controllers
- Supports custom nonlinear output shaping (saturation, asymmetric curves, PWM mapping)

---

## Operators Overview

FCS consists of four modular operators that form the FXI–Δ–E control loop:

- **F(Δ)** — transforms the deviation into the FXI-space (strictly monotonic mapping)
- **E(x)** — equilibrium operator that smooths and reduces the transformed deviation
- **F⁻¹(x)** — maps the corrected value back into the physical domain
- **G(x)** — control output shaping (linear, saturated, asymmetric, servo/PWM mapping)

Each operator can be replaced with a custom implementation without modifying the core controller.

---

## Documentation & Presentations

The project includes complete technical and investor-ready documentation:

- **FCS-Whitepaper-v1.0.md** — original Russian specification of the FXI–Δ–E architecture  
- **FCS-Whitepaper-v1.1-EN.md** — updated English whitepaper  
- **PITCH.pdf** — investor pitch deck (short version)  
- **FCS.pdf** — extended technical presentation for deep-tech review

---

## License

The FCS-SDK is released under a dual licensing model:

- **MIT License** for open-source and academic use  
- **Commercial License** available upon request for proprietary or industrial applications

Contact the author for commercial licensing terms.

---

## Contact

For technical questions, commercial licensing, or collaboration requests, please use:

**Email:** m7823445@gmail.com  
**GitHub:** https://github.com/MaryanBog
