# Arduino Crosstalk Measurement using Frequency Sweep

This repository contains an Arduino-based experiment for measuring crosstalk between nearby wires, PCB traces, or signal lines. The Arduino generates a square-wave signal on digital pin `D9` and sweeps through different frequencies. The generated signal is used as the aggressor signal, while the coupled signal on a nearby victim line is measured using an oscilloscope.

---

## Project Overview

Crosstalk is the unwanted coupling of a signal from one conductor to another nearby conductor. It can happen between wires, PCB traces, cables, or other electrical paths.

In this project, the Arduino produces a square wave at different frequencies. By placing another wire or trace close to the output signal line, the induced signal on the nearby line can be measured and analyzed.

The project is useful for studying:

- signal integrity
- electromagnetic interference
- capacitive coupling
- inductive coupling
- PCB trace spacing effects
- wire layout effects
- frequency-dependent noise coupling

---

## Main Idea

The Arduino output pin acts as the **aggressor line**.

```text
Arduino D9  ---> Aggressor signal
