# CIS 22B Lab 1 - Itty Bitty Airfreight (IBA)

## 500 Points

### Topics Covered:
- Functions
- Struct
- Pass by Reference
- Dynamic Memory Allocation (`new` and `delete`)

---

## Anti-AI Constraints:
You may use any C++ terms, constructs, and methodologies covered in **CIS 22A**.
Only additional C++ constructs covered in **modules 1 and 2** of the course zyBook (ebook) readings are allowed.
Deviation from these constraints will result in point deductions.

---

## Overview:
Welcome to **Itty Bitty Airfreight (IBA)**! We are a small, single-airplane, local airfreight company specializing in **freight charters, special handling, and quick turnaround shipments**. Your task is to build a simple **cargo tracking system** using **structs and functions**.

### Objective:
Develop a program that **inputs, stores, and outputs cargo unit data** using a **struct**, dynamically allocated on the heap.

#### **Cargo Data Fields:**
- **uld**: Unit type (**Container** or **Pallet**) - `string`
- **abbr**: Abbreviation (e.g., `AYF`, `PAG`) - `string`
- **uldid**: Unique identifier (`abbreviation + five-digit code + airline code IB`, e.g., `AYF12345IB`) - `string`
- **air**: Aircraft type (**737**) - `int`
- **weight**: Weight of the loaded unit (**pounds**) - `int`
- **dest**: Destination (**Three-letter IATA airport code**, e.g., `MFR`, `PDX`) - `string`

---

## Implementation Details:
### Required Functionality:
1. **Define a `Cargo` struct** in the **global scope**.
2. **Prompt the user for cargo details** and store them in a struct **allocated on the heap** using `new`.
3. **Pass the struct by reference** to the appropriate functions.
4. **Output the stored cargo details in a neat format**.
5. **Delete the struct using `delete`** before terminating the program.

### Required Functions:
Your program **must** include at least **three functions**, including:
1. **`main()`** - Controls the program flow.
2. **`input(Cargo &)`** - Prompts the user for cargo details and stores them in the struct.
3. **`output(const Cargo &)`** - Outputs the stored cargo details.

### **Sample Output Format:**
```
Unit type:           Container
Unit abbreviation:   AYF
Unit ID:            AYF12345IB
Aircraft:           737
Weight:             1104 pounds
Destination:        SMF
```

---

## Suggested Struct Definition:
```cpp
struct Cargo {
    string uld;
    string abbr;
    string uldid;
    int air;
    int wt;
    string dest;
};
```

---

## Submission Instructions:
- Submit **only one `.cpp` file** via **Canvas**.
- Name your file using the convention: `YourNameLab1.cpp` (e.g., `FlintstoneFredLab1.cpp`).
- **Late submissions lose points**.

---

## Notes:
- **Use `new` to allocate memory dynamically**.
- **Pass the struct by reference** to avoid unnecessary copying.
- **Ensure memory cleanup** using `delete` before the program terminates.
- **Follow proper function design principles** for clarity and maintainability.

---

## Good Luck! 🚀

