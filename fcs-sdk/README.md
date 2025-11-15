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

## API Reference

### Class: `fcs::FCS`

Main controller implementing the full FXI–Δ–E cycle.

---

### **Constructor**

```cpp
fcs::FCS();
```

Creates a controller instance.
No default operators are assigned. All operators (F, E, F⁻¹, G) must be set manually before using update().

---

### **update()**

```cpp
double update(double delta);
```

Processes the deviation through F → E → F⁻¹ → G and returns the control signal.

**Parameters:**
- `delta` — current deviation (error)

**Returns:**
- `double` — actuator command `u`

All operators (F, E, F⁻¹, G) must be assigned before calling update().

This method performs:

\[
\Delta \rightarrow F \rightarrow E \rightarrow F^{-1} \rightarrow G \rightarrow u
\]

---

### **setF()**
```cpp
void setF(const fcs::FOperator& op);
```
Assigns the forward transform operator `F`.

---

### **setE()**
```cpp
void setE(const fcs::EOperator& op);
```
Assigns the equilibrium operator `E`.

---

### **setFInv()**
```cpp
void setFInv(const fcs::FInvOperator& op);
```
Assigns the inverse transform operator `F⁻¹`.

---

### **setG()**
```cpp
void setG(const fcs::GOperator& op);
```
Assigns the control-output operator `G`.

---

### **Operator Requirements**
Each operator must be a callable object:

```cpp
double operator()(double x) const;
```

- F must be strictly monotonic.
- F⁻¹ must be the true inverse of F.
- E must be a contraction operator: 0 < k < 1 for linear versions, or an equivalent monotonic reducing map for nonlinear ones.

This ensures compatibility with embedded targets and avoids dynamic allocation.

---

### Summary

The FCS API exposes only:

- configuration of operators (F, E, F⁻¹, G)  
- single-step control update  

making it deterministic, fast, and suitable for real-time systems.

---

## Default Operators

The FCS-SDK includes a set of preconfigured default operators suitable for most real-time control applications.  
They provide stable, predictable behavior and are safe for embedded systems.

---

### **1. default_F — Forward Transform**

A monotonic mapping that shapes the deviation response.

```cpp
double default_F(double x) {
    return x;
}
```

This is a linear identity transform:

\[
F(\Delta) = \Delta
\]

It can be replaced with nonlinear forms (tanh, softsign, piecewise).

---

### **2. default_E — Equilibrium Operator**

A contracting operator that reduces the transformed deviation.

```cpp
double default_E(double x) {
    return 0.8 * x;
}
```

Mathematically:

\[
X' = k \cdot X, \quad 0 < k < 1
\]

By default:  
**k = 0.8** — stable and conservative contraction.

---

### **3. default_FInv — Inverse Transform**

The inverse mapping for the chosen `F`.

```cpp
double default_FInv(double x) {
    return x;
}
```

Identity inverse:

\[
F^{-1}(X') = X'
\]

For nonlinear `F`, users must provide matching `F⁻¹`.

---

### **4. default_G — Output Mapping**

Converts corrected deviation into actuator command.

```cpp
double default_G(double x) {
    return x;    // linear G(x) = x
}
```

This is the simplest linear control law:

\[
u = G(\Delta') = \Delta'
\]

Users can replace it with:

- saturation,
- piecewise asymmetric response,
- PWM conversion,
- servo mapping,
- thrust curves.

---

### Summary

The default operator set provides:

- linear response,  
- deterministic timing,  
- guaranteed stability,  
- safe behavior for high-frequency loops (100–1000 Hz).

They serve as a baseline and can be replaced with domain-specific nonlinear operators.

---

## Examples

Below are minimal usage examples demonstrating how to integrate the FCS controller into real systems.

---

### Example 1 — Simple Loop Test

A minimal test loop running at a fixed frequency.

```cpp
#include "fcs/fcs.h"

fcs::FCS ctrl;

void setup() {
    ctrl.setF(fcs::default_F);
    ctrl.setE(fcs::default_E);
    ctrl.setFInv(fcs::default_FInv);
    ctrl.setG(fcs::default_G);
}

double loop_step(double measured, double target) {
    double delta = measured - target;
    return ctrl.update(delta);
}
```

---

### Example 2 — Servo Position Control

Use FCS to produce a PWM-like output for a servo.

```cpp
#include "fcs/fcs.h"

fcs::FCS ctrl;

int compute_servo_pwm(double position, double target) {
    double delta = position - target;
    double u = ctrl.update(delta);

    // Convert [-1,1] → [1000,2000] µs PWM
    return 1500 + (int)(u * 500.0);
}
```

---

### Example 3 — Drone Altitude Control

A simplified altitude-hold loop (e.g. PX4/ArduPilot style).

```cpp
#include "fcs/fcs.h"

fcs::FCS ctrl;

double altitude_control(double z, double z_target) {
    double delta = z - z_target;
    double u = ctrl.update(delta);

    // Map control signal to thrust motor command
    double thrust = 0.5 + 0.5 * u; // clamps automatically if G is saturated
    return thrust;
}
```

---

These examples demonstrate:

- deviation computation  
- running the update loop  
- mapping control output to real actuators  

More advanced examples can be added for ROS2, PX4, and STM32.

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

---

## Mathematical Foundation (Flexionization Theory)

The full mathematical theory behind the FCS architecture is published here:

**Preprint:** https://zenodo.org/records/17618948  
**DOI:** 10.5281/zenodo.17618948

This document formally defines the FXI–Δ–E model, equilibrium operators, structural deviation, and stability theorems that underlie the FCS control architecture.

