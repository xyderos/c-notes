# Numbers

## Integers

### There are four ways of representing an int:

1) __char__, 1 byte long
2) __short__, 2 bytes long
3) __int__, 4 bytes long
4) __long__, 8 bytes long

#### A few properties:

1) All these types can be either __signed__ or __unsigned__

2) All numbers are assumed to be __signed__ if this identifier is missing

3) Characters is a special case, __if the signess is not included__, the actual type is __platform dependent__

### Numbers can be represented as

1) Decimals

2) Octals

3) Hexadecimals

#### A few properties:

1) Decimals are __always signed__

2) The rest are either signed or unsigned, depending on __whether or not the value fits into the signed type or not__


### Suffixes can also be used to show the width and the sign of a number

#### Header __<limits.h>__ contains all the min and max values of every type

## Floating point decimals

### C includes

1) __float__,

2) __double__,

3) __long double__

* __Floating point is implementation defined, it strctly depends on the platform you are developing__

* Use header __<float.h>__ for floating point arithmetic

## Portability

* Using plain __int__, __long__ etc are platform defined from the compiler
* Prefer using the __stdint.h__ to obtain numbers __with specific bit length__ as well as __2s complement representation__

## Implicit and explicit conversions

* When converting a value of an integer type to another integer type, __if the value can be represented from the new type, it will be unchanged__

* If doing the opposite, the behavior is __implementation defined__ and thus not portable

### Pointer comversions to function calls

* Everything to __void*__ is implicit, but any other conversion must be __explicit__, accessing an object from a different type is __undefined behavior__ (__unless its a character type__)