# FCS-SDK API Reference

This document describes all public functions and types available in the FCS-SDK.

---

## 1. Types

### FOperator
```cpp
typedef double (*FOperator)(double);
```
Transforms deviation Δ into FXI-space.

### EOperator
```cpp
typedef double (*EOperator)(double);
```
Applies equilibrium correction.

### FInvOperator
```cpp
typedef double (*FInvOperator)(double);
```
Inverse of F.

### GOperator
```cpp
typedef double (*GOperator)(double);
```
Generates actuator command.

---

## 2. Class `fcs::FCS`

### Constructor
```cpp
FCS();
```
Creates a controller with uninitialized operators.

---

### `setF`
```cpp
void setF(FOperator f_op);
```
Sets the transformation operator **F**.

---

### `setE`
```cpp
void setE(EOperator e_op);
```
Sets equilibrium operator **E**.

---

### `setFInv`
```cpp
void setFInv(FInvOperator finv_op);
```
Sets inverse transformation operator **F⁻¹**.

---

### `setG`
```cpp
void setG(GOperator g_op);
```
Sets output mapping **G**.

---

### `update`
```cpp
double update(double delta);
```
Runs the full FXI–Δ–E loop and returns control output:

\[
u = G(F^{-1}(E(F(\Delta))))
\]

Returns `0.0` if operators are not initialized.

---

## 3. Default Operators

### `default_F`
```cpp
double default_F(double delta);
```
Linear mapping:

\[
F(\Delta) = k_F \Delta
\]

---

### `default_E`
```cpp
double default_E(double x);
```

\[
E(x) = \alpha x
\]

---

### `default_FInv`
```cpp
double default_FInv(double x);
```

\[
F^{-1}(x) = \frac{x}{k_F}
\]

---

### `default_G`
```cpp
double default_G(double delta);
```

\[
G(\Delta') = k_G \Delta'
\]

---

## 4. Requirements

- All operators must be set before calling `update()`
- All functions are deterministic
- No dynamic memory allocation is used
- Suitable for microcontrollers, PX4 modules, ROS2 nodes

---

## 5. Error Handling

If any operator pointer is null:

- `update()` returns `0.0`
- No exception is thrown (SDK is embedded-safe)

