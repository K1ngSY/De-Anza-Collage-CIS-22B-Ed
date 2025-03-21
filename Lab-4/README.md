# CIS 22B Lab 4 Itty Bitty Airfreight (IBA)

**Points:** 500

## Topics
- Files

## Assignment Overview

Using the code from Lab 3 or the prototype provided on Canvas, modify your program to add the ability to read from a file. You will update the input function as follows:

- **Input Function Modifications:**
  - At the bottom of the input function, declare a `Cargo` object named `temp` using the constructor that takes six parameters (the fully loaded constructor).
  - Call the input function from the `main` function with no arguments. Remove all other code from `main` except for `return 0;`.

- **File Handling:**
  - Create (or use the provided) file named `cardata4.txt` containing at least three lines of data.
  - The data file should follow the format below:
    ```
    Pallet            PAG    PAG45982IB   737    4978   OAK
    Container         AYF    AYF23409AA   737    2209   LAS
    Combo Flat        CFE    CFE89023DL   737    5932   DFW
    ```
  - All weights are in pounds (ignore kilograms if present).
  - In the input function, declare an object of type `ifstream` named `inputFile` to read from the file.
  - Prompt the user for the name of the input file and store it in a string.
  - At the beginning of the input function, open the file. If the file fails to open, send a message to `stderr` and exit the program (this behavior may be refined later).

- **Reading and Parsing Data:**
  - Use a loop (e.g., a `while` loop) to read each line from the file.
  - For each line, use an `istringstream` to parse the data into the appropriate variables.
  - **Example Code for Parsing a Line:**
    ```cpp
    while(getline(inputFile, cargostring)) { // Read one line of data (six or seven pieces)
        istringstream cargoISS(cargostring);   // Place the line in an input string stream

        cargoISS >> type1;
        if (type1.compare("Combo") == 0) {       // Looking for "Combo"
            cargoISS >> type2 >> abrv >> uld >> plane >> weight >> dest; // Seven pieces of data
            type1 = type1 + " " + type2;           // Valid Combo Flat, further validation may be required
        } else {
            cargoISS >> abrv >> uld >> plane >> weight >> dest; // Six pieces of data
        }
    }
    ```
  - Use a `try` block for exception handling to ensure the file name is correct.

## Submission

Submit your `.cpp` file via Canvas. **Late labs lose points.**
