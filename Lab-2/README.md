# CIS 22B Lab 2 - Itty Bitty Airfreight (IBA)

## 500 Points

### Topics Covered:
- Heap
- Class
- Struct to Class Conversion
- Constructors
- Destructors
- Mutators (Setters)
- Accessors (Getters)

---

## Anti-AI Constraints:
You may use any C++ terms, constructs, and methodologies covered in **CIS 22A**.
Only additional C++ constructs covered in **modules 1, 2, 3, 4, and 5** of the course zyBook (ebook) readings are allowed.
Deviation from these constraints will result in point deductions.

---

## Overview:
Welcome to **Itty Bitty Airfreight (IBA)**. We are a small, one-airplane, local airfreight company specializing in freight charters, special handling, and quick turnaround shipments. We service both small local airports and major airports across the western region.

### Objective:
Develop an **object-oriented** Unit Load Delivery (**ULD**) setup and tracking program. A Unit Load is either a **Container** or a **Pallet** that is loaded onto our Boeing 737. The program should manage and track the following data:

#### Data Fields:
- **uld**: Unit Load type (**Container** or **Pallet**) - `string`
- **abrv**: Abbreviation type (e.g., `AYF, AYK, AAA, AYY` for Containers; `PAG, PMC, PLA` for Pallets) - `string`
- **uldid**: A unique identifier constructed as `Container or Pallet type + five digits + airline code (IB)`, e.g., `AYF12345IB` - `string`
- **air**: Aircraft type (**737**, but we plan to add more in the future) - `int`
- **wt**: Weight of the loaded unit (in pounds) - `int`
- **dest**: Destination code (**Three-letter IATA airport code**, e.g., `MRG, BOS, SFO`) - `string`

---

## Lab 2 - Struct to Class Conversion:
### Requirements:
- Convert the **struct** from Lab 1 into a **class** with private data members.
- Use **dynamic memory allocation (`new`)** for object creation.
- Implement full **object-oriented** programming principles:
  - **Default constructor** (no arguments)
  - **Parameterized constructor** (six arguments)
  - **Mutators (Setters)** for all six data fields
  - **Accessors (Getters)** for all six data fields
  - **Destructor**
  - **Input and Output functions**
- Maintain the same **data types** for private data members as in Lab 1.

---

## Implementation Details:
### What You Must Do:
- **No header files (`.h` files)**: Submit a **single `.cpp` file**.
- **Use Lab 2 prototype code** (provided on Canvas) as a starting point.
- **Main Function Tasks:**
  1. **Create a ULD object** on the heap using the **default constructor**.
  2. **Output the default object's contents** using the output function.
  3. **Delete the object**.
  4. **Create another ULD object** on the heap using the **default constructor**.
  5. **Call the input function** to set data fields interactively via **keyboard input**.
  6. **Use mutators (setters) to set the data fields**.
  7. **Use accessors (getters) in the output function** to print object details.
  8. **Destroy the object using `delete`**, which will automatically invoke the **destructor**.

### Important Notes:
- **Pass objects by reference** or use **pointers** to facilitate input and output functions.
- **Construct `uldid`** dynamically using:
  - `abbreviation + five-digit code + airline owner (IB)`
- **Output format should match this example:**

```
Unit load type:         Pallet
Unit load abbreviation: PMG
Unit identifier:        PMG12345IB
Aircraft type:          737
Unit weight:            1257 pounds
Destination code:       SJC
```

---

## Suggested Class Implementation:

```cpp
class Cargo {
private:
    string uld;
    string abrv;
    string id;
    int air;
    int wt;
    string dest;

public:
    // Default constructor
    Cargo();

    // Parameterized constructor
    Cargo(const string uld, const string abrv, const string id, const int air, const int wt, const string dest);

    // Destructor
    ~Cargo();

    // Mutator (Setter) Functions
    void setuldtype(string);
    void setabbrev(string);
    void setuldid(string);
    void setaircraft(int);
    void setweight(int);
    void setdestination(string);

    // Accessor (Getter) Functions
    string getuldtype() const;
    string getabbrev() const;
    string getuldid() const;
    int getaircraft() const;
    int getweight() const;
    string getdestination() const;

    // Input and Output Functions
    void input(Cargo &);
    void output(Cargo &);
};
```

---

## Submission Instructions:
- Submit **only one `.cpp` file** via **Canvas**.
- **Late submissions lose points**.
- **File format restriction:** Only `.cpp` files are accepted.

---

### Notes:
- Use **pointers** and **references** for efficient function operations.
- Ensure **proper memory management** by allocating and deallocating heap memory using `new` and `delete`.
- The assignment builds on **previous labs**, so maintaining consistency in **naming conventions** and **functionality** is crucial.

---

## Good Luck! 🚀

