# Strings

### A sequence of characters in an array

* #### __null terminated__

### If the string literal is assigned in a __char*__, the string is stored at the __data__ segment and thus its immutable
* #### Meaning that all the modification operations are __undefined behavior__
* #### Better declare it __const__ to avoid such events

### To declare a modifiable string
* #### Either declare an array with fixed length, __it has to be a compile time constant__
* #### Do not speficy the length but use __brace initializers__ with a __null terminating character at the end__

## Operations on strings

### __Tokenize__

#### Use __strok__, but be careful 

1) The implementation is based on a static buffer, __it is not thread safe__

2) __It modifies the original string__

3) Use either __strtok_r__ or __strtok_s__)

### __Length__, use __strlen__

### __Copying__

* #### Using the __=__ operator works only with the address of the string

### __strcpy__
* #### need to allocate memnory before assigning
* #### if the source string is longer than the destination memory, it is __undefined behavior__

### __strncpy__
* #### If we hit the buffer limit, __no null terminating character will be written__
* #### Fills the destination with null bytes

### __strcat__
* #### Append the string from source to destination

### __strncat__
* #### need to allocate memnory before assigning
* #### Use __sizeof -1__, the function will append the __null terminating character__

### __snprintf__
* #### need to allocate memnory before assigning
* #### Bad performance, but the simplest solution


### __Searching__

### __Comparing__