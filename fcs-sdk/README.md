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

## Installation

### 1. Clone the Repository

```bash
git clone https://github.com/your-org/fcs-sdk.git
cd fcs-sdk
```

### 2. Include the Library in Your Project

Add the `include/` directory to your compiler include paths:

```cmake
include_directories(${CMAKE_SOURCE_DIR}/fcs-sdk/include)
```

Or using modern CMake:

```cmake
add_subdirectory(fcs-sdk)
target_link_libraries(your_target PRIVATE fcs-sdk)
```

### 3. Build the SDK

```bash
mkdir build
cd build
cmake ..
make -j4
```

### 4. Add FCS-SDK to Your Sources

Include the main header in your C++ files:

```cpp
#include "fcs/fcs.h"
```

The SDK has **no external dependencies** and works on:

- Linux
- Windows
- macOS
- STM32 / ESP32 / ARM microcontrollers
- ROS2 / PX4 / embedded systems

It is fully suitable for **real-time control loops** (100–1000 Hz).

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
```

---

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
```

---

## Architecture

The FCS-SDK implements the Flexionization control loop based on four core operators:

### 1. F — Forward Transform
A strictly monotonic mapping that transforms the raw deviation Δ into the FXI-space.

\[
X = F(\Delta)
\]

F defines how sensitive the controller is to deviations and shapes the dynamic response.

---

### 2. E — Equilibrium Operator
A contraction operator that reduces the transformed deviation and drives the system toward stability.

\[
X' = E(X)
\]

E defines the correction strength and stabilizes the system.

---

### 3. F⁻¹ — Inverse Transform
Maps the system back from FXI-space into the physical deviation domain.

\[
\Delta' = F^{-1}(X')
\]

F⁻¹ guarantees consistency of the control loop and preserves monotonicity.

---

### 4. G — Control Output Mapping
Converts the corrected deviation Δ' into the actual actuator command.

\[
u = G(\Delta')
\]

G can be linear, saturated, adaptive, or domain-specific (servo output, thrust, PWM, etc.).

---

### Control Loop Summary

The controller executes the following pipeline at each update step:

\[
\Delta \rightarrow F \rightarrow E \rightarrow F^{-1} \rightarrow G \rightarrow u
\]

This architecture ensures:

- smooth convergence,  
- stability under nonlinear conditions,  
- predictable behavior at high frequencies (100–1000 Hz),  
- compatibility with embedded real-time systems.

---

## How the Control Cycle Works

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
