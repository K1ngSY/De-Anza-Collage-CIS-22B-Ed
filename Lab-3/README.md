# CIS 22B Lab 3 - Itty Bitty Airfreight (IBA)

## 500 Points

### Topics Covered:
- Friend Functions
- Copy Constructor
- Overloaded Operators

---

## Anti-AI Constraints:
You may use any C++ terms, constructs, and methodologies covered in **CIS 22A**.
Only additional C++ constructs covered in **modules 1, 2, 3, 4, 5, 6, and 7** of the course zyBook (ebook) readings are allowed.
Deviation from these constraints will result in point deductions.

---

## Overview:
This lab builds upon **Lab 2**, requiring you to refactor code to remove direct access to private data from **input and output functions** by placing their declarations **outside** the class and using **mutators and accessors** instead.

### New Requirements:
- Introduce a **new load type**, **Combo Flat**:
  - Abbreviations for the **737**: `CFE, CFK, CFM`.
- **Objects must be created on the stack (not the heap)**.
- Implement a **friend function**, `kilotopound`, to convert **kilograms to pounds**.
  - Modify the weight setter to ask the user for **kilograms or pounds**.
  - If **kilograms**, use `kilotopound` to convert to pounds (`1 kg = 2.2 lbs`).
- Add a **copy constructor**.
- Implement an **overloaded `==` operator**:
  - Two objects are **equal** if their **abbreviation** and **uldid** are the same.

---

## Implementation Details:
### Required Class Modifications:
- Move **input and output function declarations outside the class**.
- Modify **weight mutator** to prompt user for input type (**kg or lbs**) and convert accordingly.
- Implement **friend function** `kilotopound` to handle **kg-to-lbs conversion**.
- Add a **copy constructor**.
- Overload the **`==` operator** to compare two objects.

---

## Required Testing in `main()`:
### Create an object `unit1` with the following data:
```
uld – Container
abbreviation - AYK
uldid – AYK68943IB
aircraft - 737
weight – 1654 Kilograms
destination – PDX
```
- **Use `unit1` to test `kilotopound` function**, then output the modified data.

### Create a copy of `unit1` using the copy constructor:
- Name this new object **`unit2`**.
- Output both **`unit1`** and **`unit2`**.

### Create a **default object** `unit3`.

### Test overloaded `==` operator:
```cpp
if (unit1 == unit2)
    cout << "\nunit1 is the same as unit2\n";
else
    cout << "\nunit1 is not the same as unit2\n";

if (unit2 == unit3)
    cout << "\nunit2 is the same as unit3\n";
else
    cout << "\nunit2 is not the same as unit3\n";
```

### Notes:
- Code will be tested for **both pounds and kilograms as input**.
- Ensure **proper function calls and correct output formatting**.

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

    // Copy Constructor
    Cargo(const Cargo &other);

    // Destructor
    ~Cargo();

    // Mutator (Setter) Functions
    void setuldtype(string);
    void setabbrev(string);
    void setuldid(string);
    void setaircraft(int);
    void setweight(int, bool isKg);
    void setdestination(string);

    // Accessor (Getter) Functions
    string getuldtype() const;
    string getabbrev() const;
    string getuldid() const;
    int getaircraft() const;
    int getweight() const;
    string getdestination() const;

    // Friend Function
    friend int kilotopound(int kg);

    // Overloaded Operators
    bool operator==(const Cargo &other) const;

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

## Good Luck! 🚀

