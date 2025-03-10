# Workshop 3: Unit Testing with CppUnitTest

## Overview
This workshop focuses on creating **unit tests** for C functions using **CppUnitTest** in Visual Studio. You will:
- Implement a structure to store customer information.
- Write functions to input and validate customer data.
- Create unit tests to verify function correctness.
- Execute tests in Visual Studio.

## Tasks
### **1. Define Customer Structure**
Create a structure to store:
- First name
- Last name
- Street address
- City
- Province
- Postal code

### **2. Implement Functions**
#### **(1) Read and Validate Customer Data**
- Prompt the user for each field.
- Ensure all fields contain valid values.
- Validate postal code input and re-prompt if necessary.

#### **(2) Validate Postal Code**
- Accepts uppercase/lowercase input and converts to uppercase.
- Accepts inputs with or without spaces and formats them as `XXX XXX`.
- Returns `true` if valid, `false` if invalid.

### **3. Main Program**
- Calls the function to read customer information.
- Outputs the stored information.

### **4. Unit Testing (CppUnitTest)**
- Create a **test project** within the Visual Studio solution.
- Write **black box tests** to verify function outputs.
- Write **white box tests** to verify internal logic and edge cases.
- Add comments to explain each test case.

## Deliverables
Submit a **zipped Visual Studio project** containing:
- **Main program**
- **Unit test project** with test cases
- **Successful test results**

## Reflection
Write a **100-word reflection** on:
- How you ensured no empty inputs were accepted.
- How you could test program prompts if required.

