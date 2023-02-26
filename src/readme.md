# Pointers

## __A variable that stores the address of another variable__

* ### Use __*__ to declare a pointer

* ### Use __&__ to get the address of a variable

* ### Pointers must point to __a valid memory address before accessed__, otherwise its __undefined behavior__

## __Arrays and pointers__

* ### __Arrays decay to pointers__, a pointer points to the __first element of an array__ and thus pointer arithmetic is possible

* If you access some memory __either before or after the array__, its __undefined behavior__

## __Pointers to structs__

* ### __If a struct pointer is scoped on the file, it is null, else its undefined__

* ### Deep copy: __Copy by making a struct and assigning the value of the pointer struct, then by changing a member it only affects the struct itself__

* ### Shallow copy: __Make a reference by making a struct pointer and assign it to the pointer o fthe other struct, now changing a value will affect both structs__

* ### __Avoid passing struct themselves as arguments, might cause stack overflow, prefer passing a pointer to the struct and making a deep copy__

## Const pointers

* ### A const pointer can point to different integers, __but the value is unmodifiable__

* ### int pointer to const can __point to one int and you can change the value of the pointer__

* ### Const pointer to const int, pretty, much a constant, cant modify anything

## __void pointers__

* ### __Upcasting anything, essentially pass anything to anywhere.__

* ### Most libraries eg qsort uses that and also accepts a compare function where you cast the voind pointer to something you want and pass it around

## __Function pointers__

* ### __Declare a pointer to the declaration of a function, and pass it as an argument to call it eg a callback__

* ### Use typedef to make the code cleaner

## __Common pitfalls__

* ### __Always check for allocation failures from malloc__

* ### __Using magic numbers when requesting memory__, prefer using __sizeof__

* ### Failure to deallocate memory when you are done with that causes a __memory leak__, almost never nowadays is a security issue, but you just __waste resources and maybe cause some allocation failures__

### __Rule of Thumb__

1) __Allocate__

2) __Use__

3) __Deallocate__

#### __A few common missusages are__

1) You use a pointer before you allocate it (wild pointer)

2) You use a pointer after you free it (dangling pointer)

3) Double free

In any modern OS, this will be a __segmentation fault and the program will crash__

* ### __Never create pointer to the stack, this is undefined behavior, malloc and return the pointer__

* ### Keep in mind that in a case of *p++, incrementation comes before dereferencing, use (*p)++

* ### __Never deference a pointer from a memory address you wrote__, you do not know whats in there, __this is only a common practise in embedded systems where you know the addresses beforehand__