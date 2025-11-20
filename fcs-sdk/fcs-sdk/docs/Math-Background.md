# Mathematical Background of the FXI–Δ–E Architecture

This document summarizes the mathematical principles behind the Flexionization Control System (FCS) implemented in the FCS-SDK.

---

## 1. Deviation Δ

Let Δ be the deviation from a target state:

\[
\Delta = x_{\text{target}} - x_{\text{current}}
\]

---

## 2. Transformation Operator F

The operator **F : Δ → ℝ** must be strictly monotonic.  
It maps the deviation into a space where correction dynamics are stable and smooth.

Typical simple form:

\[
F(\Delta) = k_F \Delta
\]

---

## 3. Equilibrium Operator E

The operator **E : ℝ → ℝ** reduces or smooths the deviation in FXI-space.

Example:

\[
E(x) = \alpha x,\quad 0 < \alpha < 1
\]

---

## 4. Inverse Transformation F⁻¹

The inverse operator returns the corrected value back to the Δ-domain:

\[
F^{-1}(x) = \frac{x}{k_F}
\]

---

## 5. Corrected Deviation

Let:

\[
x = F(\Delta)
\]
\[
x_e = E(x)
\]
\[
\Delta' = F^{-1}(x_e)
\]

---

## 6. Output Mapping G

The final actuator control signal is produced by the mapping:

\[
u = G(\Delta')
\]

Common forms include:

- linear mapping  
- piecewise mapping  
- saturation functions  
- adaptive/nonlinear mappings  

Example:

\[
G(\Delta') = k_G \Delta'
\]

---

## 7. Full FXI–Δ–E Loop

Putting it all together:

\[
\Delta \xrightarrow[]{F} x \xrightarrow[]{E} x_e \xrightarrow[]{F^{-1}} \Delta' \xrightarrow[]{G} u
\]

This defines the Flexionization control structure implemented in the SDK.

---

## 8. Properties

- monotonicity  
- stability under bounded operators  
- deterministic closed-form evaluation  
- suitable for real-time embedded systems  

