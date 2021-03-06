Lab4Cabusora
============

Assembly -> C Etch-n-Sketch

C2C Kevin Cabusora, Dr. George York, ECE 382, M2

# Prelab

We were directed to identify a datatype given a unsigned/signed size of a variable and to list the max and min values that can be represented by the datatype.  To do this, I consulted p. 76 of the C Compiler User's Guide.

| Size   | Signed/Unsigned | Type                                  | Min value                  | Max Value                  |
|--------|-----------------|---------------------------------------|----------------------------|----------------------------|
| 8-bit  | unsigned        | unsigned char, bool, _Bool            | 0                          | 255                        |
| 8-bit  | signed          | signed char                           | -128                       | 127                        |
| 16-bit | unsigned        | unsigned short, unsigned int, wchar_t | 0                          | 65,535                     |
| 16-bit | signed          | int, signed int                       | -32,768                    | 32,767                     |
| 32-bit | unsigned        | unsigned long                         | 0                          | 4,294,967,295              |
| 32-bit | signed          | long                                  | -2,147,483,648             | 2,147,483,647              |
| 64-bit | unsigned        | unsigned long long                    | 0                          | 18,446,744,073,709,551,615 |
| 64-bit | signed          | long long, signed long long           | -9,223,372,036,854,775,808 | 9,223,372,036,854,775,807  |

Next, I used the above table to fill in the appropriate C typedef declaration.

| Type   | Meaning               | C typedef declaration             |
|--------|-----------------------|-----------------------------------|
| int8   | unsigned 8-bit value  | typedef unsigned char int8;       |
| sint8  | signed 8-bit value    | typedef signed char sint8;        |
| int16  | unsigned 16-bit value | typedef unsigned short int16;     |
| sint16 | signed 16-bit value   | typedef signed int int16;         |
| int32  | unsigned 32-bit value | typedef unsigned long int32;      |
| sint32 | signed 32-bit value   | typedef signed long int 32;       |
| int64  | unsigned 64-bit value | typedef unsigned long long int64; |
| sint64 | signed 64-bit value   | typedef signed long long sint 64; |

I then used CCS to step through simpleLab4.c to examine the a, b, c, d, e variables.

| Iteration | a  | b  | c  | d  | e  |
|-----------|----|----|----|----|----|
| 1st       | 2  | 2  | 3  | 4  | 2  |
| 2nd       | 8  | 9  | 8  | 7  | 8  |
| 3rd       | 14 | 15 | 14 | 13 | 14 |
| 4th       | 20 | 21 | 20 | 19 | 20 |
| 5th       | 26 | 27 | 26 | 25 | 26 |

Following that, I examined the assembly code, found the code for func and then wrote down the starting and ending address in the table, as well as the registers which pass the input parameters from main to the function, as well as the register which returns the value from func to main.

| Parameter                     | Value Sought |
|-------------------------------|--------------|
| Starting address of func      | 0xC0BA       |
| Ending address of func        | 0xC0C6       |
| Register holding w            | r12          |
| Register holding x            | r13          |
| Register holding y            | r14          |
| Register holding z            | r15          |
| Register holding return value | r12          |

I then answered the following questions:

What is the role of the extern directive in a .c file? Hint: check out the external variable Wikipedia page. 

•	Extern declares a variable by telling the compiler that the variable is already defined.  The variable must be declared in each function.

What is the role of the .global directive in an .asm file (used in lines 28-32)? Hint: reference section 2.6.2 in the MSP 430 Assembly Language Tools v4.3 User's Guide.

•	Global refers to a file being either defined in a program which could be used in other programs or that it is referenced in the current program but defined elsewhere.

# Main Lab

## Basic Functionality

For basic functionality, the goal was to make an etch-a-sketch.  The basis of the code which came from Lab 3 was provided, the only necessary modification was to use the auxiliary button to switch between black and white (eraser).  To do this, I defined BLACK and WHITE, and set the Aux Button to toggle color between BLACK and WHITE.  Here is the code I added in the while loop in the main.c file:
~~~
} else if (AUX_BUTTON == 0) {
				while(AUX_BUTTON == 0);
				if (color == BLACK) color = WHITE;
				else if (color == WHITE) color = BLACK;
				button_press = TRUE;
~~~

In the nokia.asm file, I added register R14 as the register for adjusting color.  A block would be drawn as a 8 pixel column multiplied 8 times horizontally.

## B Functionality

The goal for this portion was to have a ball simply bounce around the screen.  In editing the basic functionality, I replaced the push-button code in the main.c file with code that would tell the ball when to bounce.  I got the x and y limits by experimentally playing around with the code to make sure the ball didn't go off the screen, only bounce in the middle, etc.

In the nokia file, I took out the color change register.  I added a bit of delay so that the program would not be moving blazingly fast.  To perform this, I added a couple of nop operations to eat up some clock cycles.

### Extra Functionality

The extra functionality I pursued was forming the block into a ball shape.  Therefore, I manually moved the corresponding hex code for each column, and then called to #writeNokiaByte each time.

# Debugging

Most of the debugging I did had to do for B functionality.  It mostly involved finding the x and y limits for the block to bounce around, at a place where part of the ball would not disappear out of the scren.  I also added the .global moveDelay which I forgot since it was not being recognized by the compiler.

# Documentation

C2C Erik Thompson helped point out that I forgot to add the .global moveDelay line.  I also received his help in finding out the corresponding hex code for each column of the block to turn it into a more ball-like shape.  C2C Alex Leaf demonstrated to me how to use multiple nop's to slow to code down.
