HW9: INSTRUCTIONS (kept to ensure points are not lost when making directions for HW11)
# personal
AFFILIATION:
Jacob Sambor, CMSC 313, 4/19/2025

PURPOSE OF SOFTWARE:
matrixCalc.c and matrixCalc.cpp file are made to do calculations with matricies

FILES:
matrix.c is the main source file for C code and matrix.cpp is the main source file for C++ code

BUILD INSTRUCTIONS:
Compile the program with "gcc -o matrix matrixCalc.cpp (or matrixCalc.c)"
./matrix to run the program

TESTING METHODOLOGY:
Each operation was tested seperately to ensure functionality. The resulting matrix was then printed out.

ADDITIONAL INFORMATION:
Memory leaks were prevented at all costs.


HW11: BUILD INSTRUCTIONS AND DESCRIPTION

BUILD INSTRUCTIONS:
  1. Download the hw11translate2Ascii.asm file
  2. To assemble: nasm -f elf32 -g -F dwarf -o hw11translate2Ascii.o hw11translate2Ascii.asm
  3. To link and load: ld -m elf_i386 -o hw11translate2Ascii hw11translate2Ascii.o

DESCRIPTION:
Takes the input buffer provided in the file, and converts each hex pair into ASCII characters, then prints it out to the terminal.
