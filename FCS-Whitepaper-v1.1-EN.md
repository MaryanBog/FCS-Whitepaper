# Flexionization Control System (FCS)

## Whitepaper v1.1 (EN)
**Nonlinear Control System Based on Flexionization (FXI–Δ–E)**  
for robotics, drones, autonomous systems, and precision stabilization tasks.

---

**Author:**  
Maryan Bogdanov

**Project:**  
FCS — Flexionization Control System

**Date:**  
2025-11-14

---

# 1. Introduction

The Flexionization Control System (FCS) is a next-generation control architecture based on the Flexionization model (FXI–Δ–E). Unlike classical linear controllers, FCS relies on principles of equilibrium, monotonic mappings, and smooth nonlinear dynamics. This allows the system to achieve high stability in complex, nonlinear, and turbulent environments.

FCS is designed for robotics, drones, autonomous vehicles, servomechanisms, and other technical systems that require precise and smooth stabilization. Its structure enables robust performance even when classical PID controllers fail due to nonlinearities, noise, mechanical constraints, or rapidly changing operating conditions.

---

# 2. Motivation: Limitations of Classical PID Control

For decades, the classical PID controller has been the primary tool in robotics, automation, and technical stabilization systems. However, its fundamentally linear nature creates several limitations that become critical in modern applications. PID works efficiently only when the dynamics of the system are close to linear and external disturbances remain weak and predictable.

In real systems—drones, manipulators, autonomous vehicles, servomechanisms—the behavior is often nonlinear, affected by delays, saturations, noise, and rapid regime changes.

A PID controller cannot dynamically adapt to such complex environments. Strong disturbances often lead to overshoot, oscillations, vibration, and a loss of stability. These effects degrade the quality of control and may even cause failure of stabilization. Tuning a PID for specific conditions requires manual optimization, and any change in load or environment demands retuning.

Modern control systems require a mechanism that naturally drives the system toward equilibrium, smooths the dynamics, and keeps stabilization reliable even under nonlinear behavior. Flexionization provides such a structure: its mathematical properties enable a controller capable of functioning in scenarios where PID loses effectiveness. This makes the transition from classical linear control to the new FXI–Δ–E–based nonlinear paradigm both necessary and practical.

---

# 3. Mathematical Foundation of Flexionization (FXI–Δ–E)

Flexionization is a control structure based on transforming the deviation, applying a smooth correction, and mapping the result back into the original space. The FXI–Δ–E loop forms a stable nonlinear dynamic that makes the model suitable for complex and heterogeneous environments.

## 3.1. FXI–Δ–E Structure

The system consists of three key elements:

- **Δ** — the deviation from the target state;  
- **F : Δ → X** — strictly monotonic mapping into the FXI-space;  
- **E : X → X** — equilibrium operator that reduces the deviation;  
- **F⁻¹ : X → Δ** — inverse mapping back into the original space.

These components form a closed control loop in which the deviation is corrected in a nonlinear manner.

## 3.2. Central Dynamic Equation

The core equation of Flexionization defines the system’s behavior:

**Δₜ₊₁ = F⁻¹( E( F(Δₜ) ) )**

The target state is:

**Δ = 0**

which corresponds to complete stabilization of the controlled system.

## 3.3. Role of the Function F

The function **F : Δ → X** is a bijective and strictly monotonic mapping. It:

- translates the deviation into FXI-space,
- ensures uniqueness of transformations,
- improves structural properties of the dynamics,
- makes correction more predictable.

Without **F**, the operator **E** could not operate stably in nonlinear conditions.

## 3.4. Role of the Equilibrium Operator E

The operator **E : X → X** acts as the stabilizing mechanism and satisfies:

**|E(x)| < |x|**

It:

- reduces the magnitude of deviations,
- smooths rapid changes,
- lowers sensitivity to noise,
- creates a consistent tendency toward equilibrium.

**E** is the core of the stabilization process.

## 3.5. Resulting System Behavior

The interaction of **F**, **E**, and **F⁻¹** leads to:

- nonlinear, smooth convergence toward equilibrium,  
- absence of sharp jumps or overshoot,  
- stability even in complex environments,  
- a reliable control loop defined by FXI–Δ–E.

This mechanism makes Flexionization suitable for robotics, drones, and precision stabilization tasks.

---

# 4. Mathematical Model of the FCS Controller

The mathematical model of the Flexionization Control System (FCS) describes how the system transforms the deviation Δ, reduces it through the equilibrium operator E, and forms the control action.  
The controller operates in discrete time and is based on the central Flexionization equation that defines the dynamics of convergence toward equilibrium.

## 4.1. Core Flexionization Equation

The main dynamic of the controller is defined by:

**Δₜ₊₁ = F⁻¹( E( F(Δₜ) ) )**

The objective of the system is to reach the state:

**Δ = 0**

which corresponds to complete stabilization of the controlled object.

## 4.2. Role of the Function F

The function **F : Δ → X** is a strictly monotonic and bijective mapping. It:

- transforms the error Δ into the FXI-space,  
- ensures predictable dynamics under nonlinear conditions,  
- removes ambiguity in the transformation,  
- enables proper operation of the equilibrium operator E.

F creates an “engineering space” where the correction process becomes more stable and structured.

## 4.3. Operation of the Equilibrium Operator E

The equilibrium operator **E : X → X** reduces the transformed deviation.  
Its defining property is:

**|E(x)| < |x|**

It functions as a nonlinear stabilizer:

- smoothing the error,  
- reducing sensitivity to noise,  
- suppressing abrupt fluctuations,  
- guiding the system gently toward equilibrium.

E forms the core source of stability in FCS.

## 4.4. Inverse Mapping F⁻¹

After applying the equilibrium operator, the system must be returned to the original deviation space:

**F⁻¹ : X → Δ**

The inverse mapping ensures:

- recovery of the correct physical scale of the deviation,  
- consistent transition from FXI-space back to the real system,  
- stability of the dynamics even for large values of X.

## 4.5. Control Function G

Based on the updated deviation, the controller forms the actual control action:

**uₜ = G(Δₜ₊₁)**

The function **G : Δ → U** maps the deviation into physical control inputs, such as:

- motor thrust of a drone,  
- torque of a servomechanism,  
- wheel speed of a mobile robot,  
- joint actuation in manipulators.

G may be:

- linear (simple systems),  
- nonlinear (highly nonlinear plants),  
- adaptive (parameters depend on system state).

## 4.6. Full Operational Cycle of the Controller

1. Measure the current deviation Δₜ.  
2. Transform it into FXI-space using **F**.  
3. Apply the equilibrium operator **E**.  
4. Map the result back to deviation space via **F⁻¹**.  
5. Generate the control action using **G(Δₜ₊₁)**.  
6. Transition to the next system state.

This forms a closed nonlinear control loop that remains stable in the presence of noise, turbulence, nonlinearities, and abrupt disturbances—conditions where classical PID controllers often fail.

---

# 5. Stability and Convergence Properties

One of the key advantages of the Flexionization Control System (FCS) is its strong mathematical stability, which emerges from the combination of the monotonic transformation **F** and the equilibrium operator **E**. Together, they create a dynamic that is guaranteed to converge toward the state **Δ = 0** across a wide range of initial conditions and external disturbances.  
This makes FCS a reliable tool for controlling nonlinear systems where traditional methods often lose stability.

Stability is ensured by the contractive property of the operator **E**.  
For all values within the operational domain, it satisfies:

**|E(x)| < |x|**

This means the operator always reduces the magnitude of deviations.  
The function **F : Δ → X**, being strictly monotonic and bijective, guarantees that the transformation preserves ordering and does not distort the correctness of the update.  
Thus, the combination of **F** and **E** forms a stable dynamic loop within the FXI-space, while **F⁻¹ : X → Δ** correctly transfers the result back to the real deviation domain.

Importantly, the stability of FCS does not depend on the linearity of the controlled system.  
Even in the presence of saturations, nonlinear effects, asymmetries, and noise, the operator **E** continues to reduce deviations, and the FXI–Δ–E loop maintains convergence. This makes FCS particularly effective for tasks such as:

- drone control in turbulent airflow,  
- stabilization of robotic joints under variable load,  
- vibration suppression,  
- operation in rapidly changing conditions.

Additionally, Flexionization dynamics exhibit **smooth convergence**:  
the system approaches equilibrium gradually, without sharp jumps or overshoot—problems typical for PID controllers.  
This is critical in robotics, where excessive oscillations may damage equipment or lead to unstable behavior.

Because of these properties, FCS delivers stable, predictable, and robust stabilization across a wide variety of systems and environments.

---

# 6. Control Action Function G

The function **G** is the link between the internal Flexionization dynamics (the FXI–Δ–E loop) and the physical system being controlled. While **Δ**, **F**, **E**, and **F⁻¹** define how the system internally reduces deviations, it is **G** that converts the corrected deviation into a real control signal applied to motors, actuators, or mechanical subsystems.

## 6.1. Purpose of the Function G

The function **G : Δ → U** maps deviation values into control actions within the physical control space **U**. At each discrete time step:

**uₜ = G(Δₜ₊₁)**

where **Δₜ₊₁** is the updated (smoothed) deviation obtained from the FXI–Δ–E loop. Without **G**, the controller would remain a purely mathematical construct; through **G**, it becomes an operational control system.

## 6.2. Requirements for the Function G

For correct operation of FCS, the control function **G** must satisfy:

- **monotonicity:** larger deviations must produce stronger control signals;  
- **smoothness:** no discontinuities or sharp jumps;  
- **nonlinearity awareness:** ability to incorporate actuator limits, backlash, and asymmetries;  
- **bounded output:** the control action must stay within the physical limits  
  **U_min ≤ u ≤ U_max**.

These conditions ensure that **G** does not undermine the intrinsic stability of the FXI–Δ–E loop.

## 6.3. Linear Form of G

A simple and widely applicable form is:

**G(Δ) = k · Δ**, where **k > 0**

Effective for:

- standard servomechanisms,  
- simple stabilization mechanisms,  
- small robots and drones.

Pros: predictable, easy to tune.  
Cons: sensitive to nonlinearities and saturations.

## 6.4. Nonlinear Forms of G

### Smooth Saturation

**G(Δ) = k · tanh(Δ)**

Useful for:

- robotic arms under load,  
- gimbals under vibration,  
- drones in turbulent airflow.

### Asymmetric Control Law

$G(\Delta) = k_1 \Delta$ при $\Delta > 0$  
$G(\Delta) = k_2 \Delta$ при $\Delta < 0,$


where **k₁ ≠ k₂**.  
This models systems with directional asymmetry (up vs. down, forward vs. backward).

## 6.5. Adaptive Variants of G

Adaptive control functions depend on both the deviation and auxiliary system states:

**G : (Δ, s) → U**

where **s** may include speed, temperature, load, battery level, etc.

Examples:

- decreasing control aggressiveness under motor overheating,  
- adapting gain to payload mass,  
- compensating variable friction or inertia.

## 6.6. Role of G in the FCS Architecture

The FXI–Δ–E loop provides the internal stabilization dynamic:

- **F : Δ → X**  
- **E : X → X**  
- **F⁻¹ : X → Δ**

After this transformation, the control function **G : Δ → U** produces the physical action:

**uₜ = G(Δₜ₊₁)**

In architectural terms:

- **FXI–Δ–E** — the stabilization core,  
- **G** — the hardware-facing execution layer.

Together, they form a complete and functional Flexionization Control System.

---

# 7. Application Areas of the Flexionization Control System (FCS)

The Flexionization Control System is designed for environments where classical linear controllers, including PID, lose effectiveness due to nonlinearities, saturations, turbulence, delays, or rapidly changing operating conditions.  
Thanks to the FXI–Δ–E structure and the control function **G : Δ → U**, FCS provides smooth, stable, and adaptive dynamics suitable for a wide range of engineering applications.

## 7.1. Drone Control and Stabilization

Drone dynamics involve:

- turbulence and wind gusts,
- nonlinear thrust-to-power relationships,
- directional asymmetry,
- fast-changing aerodynamic loads.

FCS offers:

- smooth altitude stabilization,
- reduced vibration and oscillation,
- soft corrective actions,
- robustness to external disturbances.

## 7.2. Robotic Manipulators and Industrial Robotics

Robotic joints often exhibit:

- nonlinear torque behavior,
- load-dependent dynamics,
- mechanical backlash,
- elasticity in transmissions.

FCS enables:

- smooth trajectory generation,
- vibration damping,
- backlash compensation,
- stable positioning under varying loads.

## 7.3. Servomechanisms and Actuators

Servos and actuators face:

- torque saturation,
- mechanical limits,
- abrupt load changes.

FCS provides:

- smooth transients,
- reduced overshoot,
- improved position holding,
- resistance to sudden mechanical disturbances.

## 7.4. Autonomous Ground Vehicles (AGV/AMR)

Ground robots operate with:

- variable traction,
- uneven terrain,
- shifting payload mass,
- inertia-driven nonlinearities.

FCS enables:

- stable velocity control,
- smooth steering stabilization,
- robust maneuvering,
- adaptation to load variations.

## 7.5. Camera Gimbals and Stabilization Systems

Gimbal systems require:

- high smoothness,
- vibration reduction,
- real-time stabilization.

FCS provides:

- soft damping of disturbances,
- no aggressive oscillations,
- high stability during rapid motion,
- reduced sensitivity to micro-vibrations.

## 7.6. CNC Machines, 3D Printers, and Precision Mechanics

Precision systems demand:

- smooth accelerations,
- vibration control,
- accurate trajectory following.

FCS delivers:

- smoother motion profiles,
- less frame vibration,
- higher repeatability,
- better performance at high speeds.

## 7.7. Balancing Robots and Bipedal Systems

These systems exhibit extremely nonlinear and unstable dynamics.

FCS achieves:

- rapid suppression of large deviations,
- smooth correction of small deviations,
- resistance to external shocks,
- stable behavior under dynamic loads.

---

FCS is applicable to any system requiring smooth stabilization, robustness to nonlinearities, predictable dynamics, and overshoot-free operation.

---

# 8. Comparison of the Flexionization Control System (FCS) with Classical Controllers

The Flexionization Control System differs from traditional control approaches not only in internal structure, but in its fundamental operating principles.  
This section provides a structured comparison between FCS and the most widely used controllers: PID, classical nonlinear controllers, and adaptive controllers.

## 8.1. Comparison with PID Controllers

The classical PID controller is based on a linear combination of the error, its integral, and its derivative.  
Its behavior includes:

- proportional response to the current error,  
- integral compensation of constant offsets,  
- derivative damping of oscillations.

### Limitations of PID:

- high sensitivity to noise (especially the derivative term),  
- poor performance under strong nonlinearities,  
- overshoot and oscillatory behavior,  
- frequent retuning when system conditions change.

### Advantages of FCS over PID:

- the FXI–Δ–E loop provides smooth, nonlinear convergence;  
- errors are corrected without aggressive reaction;  
- stable behavior under turbulent and nonlinear conditions;  
- no need for integral tuning or derivative filtering;  
- the control function **G** adapts naturally to actuator characteristics.

FCS fundamentally changes the stabilization principle:  
instead of amplifying the error, it **smooths and reduces it**.

## 8.2. Comparison with Classical Nonlinear Controllers

Traditional nonlinear methods include:

- sliding-mode control (SMC),  
- backstepping,  
- nonlinear state feedback,  
- fuzzy-logic control.

These methods can handle nonlinearities but have significant drawbacks:

- chattering (rapid switching),  
- reliance on accurate system models,  
- poor scalability,  
- high implementation complexity.

### Why FCS is superior:

- does not require an accurate system model — only the deviation;  
- the operator **E** naturally smooths the dynamics;  
- portable across different robotic and mechanical systems;  
- no discontinuous switching behavior.

FXI–Δ–E acts as a universal stabilization framework independent of system mechanics.

## 8.3. Comparison with Adaptive Controllers

Adaptive control adjusts parameters in real time based on estimation.

Problems:

- potential gain spikes,  
- complex parameter identification,  
- instability under rapidly changing conditions.

In contrast:

- adaptability in FCS is placed in the function **G : (Δ, s) → U**  
- the internal FXI–Δ–E dynamic remains stable even when external conditions change.

This separates **adaptation** from **stability**, improving reliability.

## 8.4. Main Advantages of FCS

1. **Nonlinear stability**  
   Smooth, monotonic convergence without overshoot.

2. **Universality**  
   One controller applied to many types of systems.

3. **Noise and turbulence resilience**  
   The operator **E** filters sharp disturbances.

4. **Flexibility**  
   The function **G** adapts to any actuator constraints.

5. **Model independence**  
   Only deviation measurement is required.

6. **Engineering scalability**  
   Suitable for drones, servos, manipulators, vehicles, and precision devices.

## 8.5. Practical Conclusions

- PID remains useful for linear and simple systems.  
- Classical nonlinear controllers are powerful but difficult to implement.  
- Adaptive controllers are flexible but unstable under fast dynamics.  
- **FCS combines the strengths of all approaches while avoiding their major weaknesses.**

Flexionization provides a new, general-purpose foundation for control systems in robotics and autonomous machines.

---

# 9. Practical Aspects of Implementing FCS

Although the Flexionization Control System (FCS) is mathematically universal, successful deployment in real robotic and mechatronic systems requires correct engineering integration.  
This section summarizes the key practical considerations necessary for implementing FCS in hardware, firmware, and autonomous control systems.

## 9.1. Measuring and Filtering the Deviation Δ

FCS begins with accurate measurement of the current deviation:

**Δ : S_phys → ℝ**

where **S_phys** represents physical measurements (angle, height, position, velocity, etc.).

Real sensor data contains noise, spikes, and quantization effects.  
Recommended practices include:

- basic filtering (e.g., exponential smoothing),  
- outlier suppression,  
- matching FCS update frequency to sensor sampling rates.

Although the equilibrium operator **E** inherently smooths noisy deviations, proper preprocessing significantly improves stability.

## 9.2. Choosing and Calibrating the Function F

The mapping **F : Δ → X** must be:

- strictly monotonic,  
- bijective,  
- correctly scaled for the specific system.

Common engineering choices:

- logarithmic functions,  
- power functions,  
- piecewise linear mappings.

A poorly chosen **F** may result in overly weak or overly aggressive correction.

## 9.3. Adjusting the Equilibrium Operator E

The operator **E : X → X** determines the convergence profile:

- speed of stabilization,  
- behavior in turbulent environments,  
- degree of smoothing.

Engineering examples:

- linear contraction: **E(x) = αx**, where **0 < α < 1**,  
- nonlinear contraction: **E(x) = α · tanh(x)**,  
- adaptive α based on mode or subsystem conditions.

## 9.4. Constraints of the Inverse Mapping F⁻¹

The inverse mapping **F⁻¹ : X → Δ** must restore correct deviation values:

- no discontinuities,  
- stable behavior under large X,  
- consistency with physical system dynamics.

Improper **F⁻¹** may cause jumps in **Δₜ₊₁**.

## 9.5. Choosing the Control Function G

The function **G : Δ → U** must consider:

- actuator limits,  
- nonlinear force characteristics,  
- mechanical saturations,  
- delays,  
- load dynamics.

Typical choices:

- **G(Δ) = kΔ** (linear),  
- **G(Δ) = k · tanh(Δ)** (smooth saturation),  
- asymmetric laws,  
- adaptive laws.

## 9.6. Sampling Frequency and Computational Load

FCS operates in discrete time:

**t = 0, 1, 2, ...**

Computation must be fast enough to track the system’s dynamics.

Typical update frequencies:

- drones: **200–500 Hz**,  
- servomechanisms: **100–200 Hz**,  
- manipulators: **50–120 Hz**,  
- mobile robots: **20–80 Hz**.

The FXI–Δ–E loop and **G** have low computational complexity, allowing FCS to run on microcontrollers such as STM32, ESP32, Pixhawk boards, and industrial PLCs.

## 9.7. Stability Verification and Control Limits

Before deployment, it is essential to:

- test actuator saturation behavior,  
- simulate boundary values of Δ,  
- verify stability under fast transitions,  
- evaluate thermal loads on motors.

The FXI–Δ–E loop ensures mathematical stability,  
but hardware must withstand physical loads.

---

# 10. Case Studies and FCS Behavior Modeling

This section presents example scenarios illustrating how the Flexionization Control System behaves in typical robotics and autonomous systems tasks.  
These cases demonstrate how the FXI–Δ–E loop and control function **G : Δ → U** work together to produce stable, smooth, and robust behavior.

## 10.1. Drone Altitude Stabilization in Turbulent Conditions

**Task:** maintain a target altitude **h₀** under turbulent airflow.

Deviation:

**Δₜ = hₜ − h₀**

Example configuration:

- **F(Δ) = Δ³** — amplifies large deviations but smooths small ones,  
- **E(x) = 0.6x** — moderate contraction,  
- **G(Δ) = kΔ** — linear thrust mapping.

**Result:**

- strong gusts increase Δ,  
- nonlinear F prevents overly aggressive response,  
- E contracts the deviation smoothly,  
- G produces a proportional but gentle thrust adjustment.

Compared to PID, which often oscillates in turbulence, FCS returns to equilibrium **without overshoot**.

## 10.2. Servomechanism Control Under Mechanical Saturation

**Task:** stabilize servo position despite torque limits.

Example configuration:

- **F(Δ) = Δ**,  
- **E(x) = 0.5x**,  
- **G(Δ) = m_max · tanh(Δ)** — smooth saturation of motor torque.

**Benefits:**

- deviation is reduced smoothly,  
- torque never exceeds physical limits,  
- no oscillation bursts typical of PID near saturation,  
- stable behavior even during sudden load changes.

## 10.3. Manipulator Control with Variable Payload

**Task:** keep the end-effector in a fixed position while payload mass changes.

Adaptive control function:

**G(Δ, m) = k(m) · Δ**

where **k(m)** increases or decreases depending on payload.

**Notes:**

- F and E remain unchanged,  
- adaptive G compensates for altered dynamics,  
- no abrupt control jumps when payload changes.

Result: stable, smooth positioning regardless of load.

## 10.4. Camera Gimbal Stabilization

**Problem:** vibration, rapid camera movement, nonlinear inertia.

Example:

- **F(Δ) = Δ**,  
- **E(x) = 0.7x**,  
- **G(Δ) = k · tanh(Δ)**.

**Effect:**

- strong vibration damping,  
- no overshoot,  
- stable real-time compensation.

## 10.5. Balancing Platform (Biped or Self-Balancing Robot)

Deviation:  
**Δₜ = θₜ − θ₀**, where **θₜ** is current tilt angle.

Example:

- **F(Δ) = Δ³**,  
- **E(x) = 0.4x**,  
- **G(Δ) = kΔ**.

**Result:**

- large deviations are suppressed quickly,  
- small deviations corrected smoothly,  
- no high-frequency oscillation (“twitching”),  
- stable behavior under physical perturbations.

---

These case studies demonstrate the flexibility of FCS:  
the internal FXI–Δ–E loop remains universal, while **G** adapts to hardware-specific requirements.

---

# 11. Conclusion

The Flexionization Control System (FCS) represents a new class of controllers built on the FXI–Δ–E structure and extended with the control function **G : Δ → U**.  
This system combines the strengths of classical control methods while eliminating their fundamental weaknesses. FCS exhibits stable nonlinear dynamics, smooth convergence, and high adaptability across a wide range of real-world conditions.

Unlike PID controllers, FCS does not amplify the error proportionally to its magnitude.  
Instead, it applies a controlled nonlinear transformation through **F** and **F⁻¹**, while the equilibrium operator **E** reduces deviations without aggressive reactions.  
As a result, the system remains stable even under noise, saturations, turbulence, and nonlinear mechanical characteristics.

A major advantage of FCS over nonlinear and adaptive controllers is its simplicity:  
the FXI–Δ–E structure is universal, does not require a precise model of the system, and scales easily from small actuators to complex robotic platforms.  
The control function **G : Δ → U** allows FCS to adapt to any actuator or mechanism — from servomotors and gimbals to industrial manipulators and autonomous platforms.

FCS is a practical extension of Flexionization theory and demonstrates that the mathematical FXI–Δ–E framework is not limited to economics or abstract systems.  
It can be directly applied to real engineering domains, providing a new architecture of stabilization.  
This opens the possibility of building more reliable, flexible, and universal control systems for the next generation of robotics.

FCS is suitable for a wide range of applications, including:

- robotics,  
- drones and aerial vehicles,  
- servomechanisms and actuators,  
- balancing robots,  
- autonomous ground vehicles,  
- camera stabilization systems,  
- high-precision mechatronic devices.

Thanks to its universality and mathematical rigor,  
FCS can serve as a foundation for future control standards requiring reliability, flexibility, and stability under nonlinear real-world dynamics.

---

# 12. References

1. Åström, K. J., & Murray, R. M. *Feedback Systems: An Introduction for Scientists and Engineers.* Princeton University Press, 2008.

2. Khalil, H. K. *Nonlinear Systems.* Prentice Hall, 2002.

3. Slotine, J.-J. E., & Li, W. *Applied Nonlinear Control.* Prentice Hall, 1991.

4. Ogata, K. *Modern Control Engineering.* Prentice Hall, 2010.

5. Dorf, R. C., & Bishop, R. H. *Modern Control Systems.* Pearson, 2016.

6. Åström, K. J., & Hägglund, T. *PID Controllers: Theory, Design, and Tuning.* ISA, 1995.

7. Narendra, K. S., & Annaswamy, A. M. *Stable Adaptive Systems.* Prentice Hall, 1989.

8. Siciliano, B., & Khatib, O. (eds.) *Springer Handbook of Robotics.* Springer, 2016.

9. Spong, M. W., Hutchinson, S., & Vidyasagar, M. *Robot Modeling and Control.* Wiley, 2005.

10. Bouabdallah, S., Murrieri, P., & Siegwart, R. *Design and Control of an Indoor Micro Quadrotor.*  
    IEEE International Conference on Robotics and Automation (ICRA), 2004.
