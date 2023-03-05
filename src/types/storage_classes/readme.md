# Storage classes

## __Set the scope of an identifier__

### __Auto__

* ### Automatic storage duration, if the scope ends, the identifier is invalid

* ### Any identifier that __doesnt have global scope or isnt declared static, it is declared as auto by default__

### __Register__

* ### Hint the compiler that the value should be read fast, whether or not this will happen, it is __implementation defined__

* ### __You cannot compute its address__, since this is used mostly for optimisations, __the memory address might change unexpectedly__

* ### Use mostly for variables defined within a specific storage block and you need to access them frequently

### __Static__

* ### __Confine a variable into a single translation unit__ eg cant be used outside of the file

* ### __Save some data for use on the next function call__ (see strtok)

* ### Can use it in a function parameter to denote that __an array will have a constant minimum number of elements and non null parameters__

### __Extern__

* ### Show that a variable is defined somewhere else __(external linkage)__

* ### You can combine it with the __inline keyword__ in the declaration, the compiker hints that the function might be inlined and thus __supress the generation of an external symbol__, but if you also declare the same function as __extern__ and generates an __external symbol__ and then the compiler can choose the implementation. Without making in extern, the function would not be called from other files