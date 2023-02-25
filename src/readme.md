# Structs

## __General__

* ### Group variables in a single memory unit

## __Flexible Array Members__

* ### Essentially a struct with dynamic size and yet a flat memory layout

* ### A struct can contain an uninitialized array at the end of it

* ### __It is assumed to be an incomplete type so sizeof will not return the size of the array__

* ### You cannot access or initialize anything on that, it is __undefined behaviour__

* ### You can __malloc__ it though (check example)

* ### In general, it is superior to pointer because of

1) You can allocate memory faster

2) There is better locality

3) solid code generation, with a pointer in requires an extra load-initialize on the heap, inserting requires at least allocate for the object and its data member

* #### The example above leads to fragmented memory chunks

* #### sizeof returns everything else but only the memory that the first element occupies (since we decay to a pointer), and probably some padding

## Struct hack

* ### array of size 0, or 1 or whatever! the compiler is smart enough to understand it

* #### Prefer 0 though, since you will need to subtract the size of the number you gave from malloc and this is complex ansd error prone

* ## Note that both clang and gcc normalize out of bounds behavior with FAMs

* ### __Just keep it 0!__

## __OOP like programming__

* ## Use function pointers as members, gives the feeling of calling methods

* ### Still needs to pass the struct as an argument