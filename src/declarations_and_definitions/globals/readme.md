# Declaration and Definition

## __Declaration vs definition__

### __Declaration introduces an intentifier and describes a type__

* #### eg __a function in a header file__

* __Note that for functions, the extern modifier can be ommited__

### __Definition implements the type__

* #### __This is what the linker essentially needs in order to reference these entities__

 ### __Definition can happen in place of a declaration, __but it must happen only once____

* #### If its not defined, the linker complains about missing references/symbols

* #### If there more than one implementation, the linker complains about duplicate references/symbols

### __Strong vs weak symbols__

* ### Global variables have three types

1) __Initialized to 0__

2) __Initialized to something that is non zero__

3) __Just defined__

* #### Case __1 and 2__ contains definitions that are called __strong symbols__, meaning that they are stored in the __.data__ section of the program, whereas case __3__ stores them in the __.common section__

### __Rule of three for global variables__

1) __Only one strong symbol is allowed with the same name__

2) __If there is a strong symbol and several weak symbols, the weak symbols are overrode by the strong symbol__

3) __If there are several weak symbols, the compiler chooses the one with the largest memory occupation__

### __Note that this is not the case in C++, everything global is considered a strong symbol__
* ### A workaround is to declared each redefinition with the __weak attribute__

### __Good programming habits__

* ### Of course, __eliminate all global variables__ (hard)

* ### Use ___static___ for globals, provide an interface to access them (complicated)

* ### __Initialize all globals__ (easy)

* ### Weak symbols exist mostly for __library functions__, if something is weak, the end user can override that

### __A workaround__:

* ### __Declare a header and defines all your globals there__
* ### __Declare an implementation file and initialize everything there__
* ### __Then include the header and use the variables__