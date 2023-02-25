# Bitfields

## __General__

* ### Types occupy a specific amount of bits
* ### Bit fields extend that so __you can specify the amount of bits you want to allocate per type__
* ### Although they are part of the C standard, __they are mostly implementation defined and thus not portable__
* ### You need to __be aware of endianess__, it might be wise to use a preprocessor to check for endianess
* ### Their implementation is based on either __byte level__ or __word level__

## __Allignment__

* ### Since you can declare structures with __less__ width, they should be aligned with either __byte level__ or __word level__ masks

* ### __You need to specify the allignment__, it is not specified by the standard, __leaving it up to the compiler can decide to either use byte or word level allignment__

* ### __Unnamed bit fields cannot be referenced or assigned, but can be of any size__

## __When to use__

* ### __When you want ot pack values together and reduce memory usage, good for embedded development__

* ### A smart way to apply operations in a number eg __memory addresses__ is to __declare the address data within a union and an unnamed struct that contains bitfields you need__

## __Things to **NOT** do when using bitfields__

* ### Do not declare __arrays, pointers of functions__ of bit fields

* ### __Memory address operator cannot be applied to bitfields__

* ### __sizeof cannot be applied to fields of bitfields__

## Rule of thumb : __memory constrained situations, lots of variables, limited ranges__