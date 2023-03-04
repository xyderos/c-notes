# Arrays

## __General__

* ### Derived data types, stored contiguously in memory

* ### Support for __Variable Length Array__ at __runtime__, need to be careful about the amount of memory requested also eg an __overflow may occur__

## __Length__

* ### It would make sense to assume that __sizeof(array)/sizeof(*array)__ would return the number of elements, but __THATS NOT THE CASE__

* ### Arrays are decayed to pointers to their first elements when passed as arguments, so in a lot of cases the __length of the array__ might also have to be __passed as an argument__, unless of course we are using __either strings__ or __dynamically allocated arrays of structs that end with a NULL pointer__

## __Multi dimensional arrays__

* ### Keep in mind that in a multi dimentional array, you keep in mind 

 1) __the decay to pointer__, 
 2) __operator precedence__,
 3) __the two different ways to declare an array, eg array of arrays or array of pointers__