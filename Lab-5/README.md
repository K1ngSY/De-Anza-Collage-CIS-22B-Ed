# CIS 22B Lab 5 Itty Bitty Airfreight (IBA)

**Points:** 1000

## Topics
- Inheritance
- Virtualization
- Error Handling
- Linked Lists

---

## Overview

Utilizing the code from Lab 4 (or the provided `lab4proto.cpp` file on Canvas), replace your `Cargo` class with a new base class. This new `Cargo` class must include a pure virtual function to be redefined in its child classes, thereby making it an abstract class. The `Cargo` class will provide common functionality and parameters to its two derived classes.

Canvas also provides a `lab5stubs.cpp` file that contains stubs for much of the header code needed for Lab 5.

---

## Derived Classes

### Boeing737
- **Purpose:** Contains information specific to the 737 aircraft.
- **Unit and Type:**  
  - Container: AYF, AYK, AAA, AYY  
  - Pallet: PAG, PMC, PLA  
  - Combo Flat: CFE, CFK, CFM
- **Maximum Load:** 46,000 pounds

### Boeing767
- **Purpose:** Contains information specific to the new 767 aircraft.
- **Unit and Type:**  
  - Container: AKE, APE, AKC, AQP, AQF, AAP  
  - Pallet: P1P, P6P  
  - Combo Flat: CFQ, CFX, CFP
- **Maximum Load:** 116,000 pounds

> **Note:** Change access specifier from `private` to `protected` in the `Cargo` class only.

Each derived class should:
- Inherit the default constructor, copy constructor, a constructor with six parameters, and all getters and setters from the `Cargo` class.
- Implement one additional function: the max weight function.

The unit and type data vary between classes as does the aircraft type. The maximum load for each aircraft is provided above.

---

## Program Structure

- **Main Function:**  
  The `main` function should only call the input function and then return 0.

- **Input Function:**  
  - Read data from the file (provided by the user) line by line. The data file (`lab5data.txt`) is provided on Canvas.
  - The file format is guaranteed to be correct and will not exceed 20 lines, but the data validity is not guaranteed. Perform validity checks on:
    - Unit types (must be one of: Container, Pallet, or Combo Flat)
    - Unit Load Abbreviations must agree with the plane type.
    - Plane type must be either `737` or `767`.
    - Weight must be within the limits specified for each aircraft.
  - Based on the aircraft field in the record, call the corresponding build function to create that type of unit.
  - Ensure that adding a new unit does not cause the total weight for the aircraft to exceed its maximum load. If it would, reject the unit and continue to the next record.
  - Use try/throw/catch blocks for exception handling, especially for:
    - Validating the file name and opening the file.
    - Validating the data read from the file.

- **Data Storage:**  
  Store each unit object as a node in the appropriate linked list. At the end of the input process, there will be two linked lists (one for each aircraft type).

- **Output Function:**  
  - Print all nodes for the 737 aircraft together and all nodes for the 767 aircraft together.
  - Display the total weight for each aircraft type.

---

## Data File Format

The data file (e.g., `lab5data.txt`) will contain data similar to the following examples:

