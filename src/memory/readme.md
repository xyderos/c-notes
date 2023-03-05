# Memory managenment

## __Allocating__

* ### __Malloc__

* ### Use __sizeof__, this is __implementation defined__ which is good for protability in each platform

* ### Can return __NULL__ upon failure, check it out

* ### Use __calloc__ to initialize the whole memory chunck to __zeroes__

* ### Use __aligned_malloc__ to allocate memory based on a specific alignment (malloc is using that internally with the maximum alignment possible)

## __Deallocating__

* ### __Free__

* ### Accessing deallocated memory is __undefined behavior__ (dangling pointers)

* ### Assert the memory is gone after freeing by assigning the pointer to __NULL__

* ### __Free on NULL has no effects and thus less error prone__

## __Reallocating__

* ### __Realloc__

* ### Frees the previous pointer and returns a new one of the specified size

* ### If we expand, we initialize the extra memory

* ### If we shrink, we lose content of the memory

* ### __It is not standard that the new pointer will have the same address as the previous object__

* ### __Always assign the value of realloc to a temporary value, might return NULL__

* ### __You cannot free with reallocating a size of 0, this is implementation defined behavior__

