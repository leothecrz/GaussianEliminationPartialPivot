# Gaussian Elimination Solver

This C++ program provides an interface for solving systems of linear equations using the Gaussian Elimination method.

## Table of Contents

- [Getting Started](#getting-started)
  - [Prerequisites](#prerequisites)
  - [Compiling and Running](#compiling-and-running)
- [Usage](#usage)

## Getting Started

### Prerequisites

- [C++ Compiler](https://gcc.gnu.org/)
- [CMake](https://cmake.org/)

### Compiling and Running

1. Clone the repository:

   ```
   git clone https://github.com/leothecrz/GaussianEliminationPartialPivot.git
   ```

2. Navigate to the project directory:

   ```
   cd GaussianEliminationPartialPivot
   ```

3. Compile the program using CMake:

   ```
   cmake .
   ```

4. Run the program in console:

   ```
   GaussElem.exe
   ```

## Usage

1. Upon running the program, you will be prompted to choose between manual input or input from a formatted text file.

2. If you choose manual input, you will be asked to enter the number of equations, and then to input the coefficients.

3. If you choose input from a file, you will be prompted to enter the file path. The file should be formatted with one equation per line, where coefficients are separated by spaces.

