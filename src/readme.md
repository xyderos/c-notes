# Compilation phases

### In general, there are four steps

1) Pre processing, expand all macros and includes
2) Compilation, convert your code to assembly
3) Assembly, convert assembly to objects
4) Linkage, link everything together

### __Libraries__

* ### __Compiled binary that holds the code, need to also ship the headers in order to include that to your executable__

1) ### __Static libraries__

Statically built into the program, no need to change version, code becomes bigger

2) ### __Dynamic libraries__

Loaded at runtime by the program, can be shared by many programs, less disk space, can fix bugs without breaking client code

## __The pre processor__

### Concerts source code into translation units

* __Fixes defines, includes, logical operations and deletes all the comments__

## __The compiler__

### After the pre processor __expanded all the macros and included all the header files__, it starts the compilation process.

* __From code to objects__

* In order to make an executable, __you need to include all the code from the included files__, this is where the __linker__ comes in

## __The linker__

### Link together object files, resolve symbol addresses to numeric addresses

1) Usually add some startup code to each translation unit, 

2) resolve external references, 

3) will assign load addresses (specification of where the code and data will end up in the address space of the executable)

4) Once everything is done, it will load numerical addresses to the symbolic addresses

### __Avoid calling the linker explicitly, this is platform dependent, the compiler should address that for you__

## __The compilation phases in detail__

1) ### Transform source input to source character set
2) ### Cleanup newlines
3) Parse code from whitespaces and preprocessing tokens
4) The preprocessor is applied
5) Character set values and literals are mapped to the execution character set
6) Adjacent string literals are concatenated
7) External resources are resolved