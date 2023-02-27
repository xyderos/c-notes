# Effective types and aliasing

* ## The last type that was associated with the data

* ### Use __restrict__ when passing arguments to ensure that the pointer passed as arguments will never point to the same object

* ### When trying to modify a type via a pointer, this should happen via __char pointers__

1) #### You can make changes to individual bytes, especially when they are __unsigned__ so the process is well defined

2) Since you are accessing the data via a char pointer, the strong aliasing rule does not apply and thus when constructing the new value, the compiler will have t work with the bytes changed

3) Be careful when you face padding bytes/bits

## __Character types should not be accessed vi non character types__

* ### Especially if they do not have __local storage duration__

* ### This causes undefined behavior because it __violates the effective type__, __NO DATA OBJECT THAT HAS AN EFFECTIVE TYPE SHOULD BE ACCESSED VIA ANOTHER TYPE IF ITS NOT A CHARACTER TYPE__

* ### Even if there is pointer alignment, the behavior is still undefined

* This means in particular that there is no way in C to reserve a buffer object of character type that can be
used through pointers with different types, as you would use a buffer that was received by malloc or similar
function.

* ### There is a caveat by using unions, check the code examples