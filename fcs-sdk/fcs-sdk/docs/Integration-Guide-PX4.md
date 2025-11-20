# Integration Guide — PX4

This document describes the minimal steps required to integrate the FCS-SDK into a PX4-based flight controller.

## 1. Include the FCS headers

In your PX4 module:

```cpp
#include <fcs/fcs.h>
#include <fcs/operators/f_operator.h>
#include <fcs/operators/e_operator.h>
#include <fcs/operators/finv_operator.h>
#include <fcs/operators/g_operator.h>

2. Create the controller instance

fcs::FCS ctrl;

void setup_fcs()
{
    ctrl.setF(fcs::default_F);
    ctrl.setE(fcs::default_E);
    ctrl.setFInv(fcs::default_FInv);
    ctrl.setG(fcs::default_G);
}

fcs::FCS ctrl;

void setup_fcs()
{
    ctrl.setF(fcs::default_F);
    ctrl.setE(fcs::default_E);
    ctrl.setFInv(fcs::default_FInv);
    ctrl.setG(fcs::default_G);
}

3. Call update() inside the control loop

Example for an attitude or altitude loop:

double u = ctrl.update(error);

Use u as actuator command or intermediate control variable.

4. Notes

FCS is deterministic and uses no dynamic allocation.

Can be used in rate, attitude, or position loops.

All operators may be replaced with custom versions tailored for PX4.

---
