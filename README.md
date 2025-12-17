# ODE Solver (C)

Menu-driven C program for solving common first-order and second-order ordinary differential equations used in engineering and physics. Analytical formulas are used where possible; numerical solutions use the 4th-order Runge–Kutta (RK4) method.

---

## Features

### First-Order ODEs
- Exponential population growth  
- Logistic population growth  
- RL circuit current response  
- Newton’s law of cooling  

### Second-Order ODEs (RK4)
- LCR circuit (charge and current)  
- Mass–spring–damper system (displacement and velocity)  

---

## Project Structure

- main.c - Menu system and input validation
- models.c - Mathematical models and solvers
- models.h - Function declarations
- Makefile - Build automation


---

## Mathematical Models

**Analytical**
- Exponential growth: `P(t) = P0 * e^(kt)`
- Logistic growth: `P(t) = M / (1 + ((M − P0)/P0) * e^(−kt))`
- RL circuit: `I(t) = (E/R)(1 − e^(−(R/L)t))`
- Newton’s cooling: `T(t) = T_env + (T0 − T_env)e^(−kt)`

**Numerical (RK4)**
- LCR circuit using charge `q` and current `i`
- Mass–spring–damper using displacement `y` and velocity `y'`
- Fixed step size: `h = 0.0001`

---

## Build Instructions

Requirements:
- GCC
- math library

Compile:
```
make
```
Run:
```
./odesolver
```
## Usage

- Run the executable.
- Choose first-order or second-order ODE.
- Select the required model.
- Enter parameters as prompted.
- Program outputs the solution at the specified time.
- All menu inputs are validated to prevent invalid selections.

## Design Notes

- Clear separation between user interface and solvers
- Modular and readable C code
- Explicit RK4 implementation without external libraries
- Intended for numerical methods and engineering coursework

## Limitations

- Fixed step size (no adaptive RK)
- No error estimation
- No data export or plotting
