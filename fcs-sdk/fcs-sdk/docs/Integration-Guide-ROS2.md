# Integration Guide — ROS2

This document describes the minimal steps required to integrate the FCS-SDK into a ROS2 node.

## 1. Include FCS headers in your ROS2 node

```cpp
#include <fcs/fcs.h>
#include <fcs/operators/f_operator.h>
#include <fcs/operators/e_operator.h>
#include <fcs/operators/finv_operator.h>
#include <fcs/operators/g_operator.h>
```

## 2. Create controller instance

```cpp
fcs::FCS ctrl;

void setup_fcs()
{
    ctrl.setF(fcs::default_F);
    ctrl.setE(fcs::default_E);
    ctrl.setFInv(fcs::default_FInv);
    ctrl.setG(fcs::default_G);
}
```

Call this in the constructor of your ROS2 node.

## 3. Use inside the timer callback or subscription callback

Example:

```cpp
double error = target - state;
double u = ctrl.update(error);
```

Publish `u` to your actuator or control topic.

## 4. Notes

- Works in real-time or near–real-time loops.
- No heap allocations inside FCS.
- Operators may be replaced with nonlinear/custom ones.

