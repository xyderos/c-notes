# Bitwise operators

## Manipulate bits, 6 basic operations

### bitwise AND, & 
* Compare bit by bit

* __If a bit is 0, return 0, else 1__

### bitwise OR, | 
* Compare bit by bit

* __If a bit is 1, return 1, else 0__

### bitwise XOR, ^ 
* Compare bit by bit

* __If the bits are the same, return 0, else 1__

### bitwise NOT, ~ 
* Flip all bits

### bitwise shift left, <<
* Shift the binary form by __n__ bits to the left

* Appends 0s

### bitwise shift right, >>
* Shift the binary form by __n__ bits to the right

* Appends 0s if the number is signed, 1s otherwise

### **AVOID BIT MANIPULATION OF SIGNED NUMBERS**
* ### The sign bit has a particular meaning

* ### Left shifting 1 bit to the signed bit is **undefined behaviour**

* ### Right shift a negative value is __implementation defined__, not portable at all

* ### If the value of the right operand of a shift operator is **negative** or **greater than or equal** of the width of the left operand, this is **undefined behaviour**

## Masking

### **The process of extracting or modifying specific bits by bitwise operartions**

#### **Why**?

1) Deside the bit pattern of a variable

2) Copy a portion of a bit pattern into a new variable and the reminder shall be filled with zeroes (**AND**)

3) Copy a portion of a bit pattern into a new variable and the reminder shall be filled with ones (**OR**)

4) Copy a portion of a bit pattern into a new variable and the reminder shall be inverted with the new variable (**XOR**)

### You can either:

1) __Toogle__ bytes and/or bits

2) __extract__ bytes and/or bits

3) __set__ bytes and/or bits

4) __clean__ bytes and/or bits