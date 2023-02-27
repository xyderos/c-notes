# Undefined behavior

## A weird situation where __the compiler doesnt know how to behave in certain situations__ or rather the __language do not know how to interpret these situations__, eg when dividing by zero, __the CPU yields a problem, the language chooses to ignore it and behave as if nothing happened__

### A few examples are:

### __Dereference a pointer beyond its lifetime__

* ### eg return a memory address from stack from a function, but not if the variable is __static__

* ### Essentially, it points to trash

### __Copy overlap memory__

* ### If you try to either copy or move memory within memory regions that overlap, the behavior is __undefined__

* ### __ONLY memmove FIXES THAT__, it internally copies all the data in a buffer and then rewrites

### __Signed integer overflow__

* ### Any uncontrolled math over those can lead to that

### __Use of an uninitialized value__

* ### This is only true for __local storage__, __static, thread local and global variables are always initialized to either 0, their initial value or NULL__

### __Read value from a pointer that was freed (dangling pointer)__

* ### Anything that is accessed beyond its lifetime causes __undefined behavior__

### __Read value from a pointer before its intialization or assignment (wild pointer)__

* ### Points to trash, you never what know is there

### __Modify a string literal__

* ### These are stored in the __.rodata__ segment, in most operating systems this should be a seg fault

### __Freeing memory twice__

* ### Again, in most operating systems this is a seg fault

### __Bit shifting either with a negative number or a negative number or beyond its width__

* ### Keep in mind that right shifting a positive number by a negative one is __implementation defined__

### __Return from a function declard as no return__

* ### Eg interrupt handlers should not be returning any values to the caller, if they do, the behavior is undefined 

### __Access memory that has not been allocated__

* ### Accessing memory after the allocated memory eg a chunk of memory is __undefined behavior__

### __Modifying a const variable through a pointer__

* ### Compilers warn that you __discard the const qualifier from pointer target types__

### __Bad pointer arithmetic__

### __Dereferencing a null pointer__

* ### Most operating systems treat that as a seg fault

### __If within the same translation unit, a variable is declared with both internal and external linkage__

* ### Caveats
#### __If an identifier is declared as extern and prior to that__
1) There is either external or internal linkage, the prior is kept
2) If the prior declaration specifies no linkage, then the identifier has external linkage

### __Missing a return statement in a function returning a value__

### __Division by 0__

* ### This is not true for __floats__, their standard specifies that __INFINITY__ is returned

### __Bad pointer alignment__

* ### If eg we return an __uint32_t__ that has an alignemnt of either 2 or 4 and try to assign it to an address with an odd alignemnt, the behavior is undefined

* ### Caveat

* #### __memcpy__
