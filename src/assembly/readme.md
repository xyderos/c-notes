# Inlining assembly in C code

## Simple format

* ### Improves the __runtime of the program__ for processes like __AES__ (check example)

```
unsigned int w;          // 32-bit
unsigned char subkey[4]; // 8-bit, 4*8 = 32 

subkey[0] = w >> 24;     // hold 8 bit, MSB, leftmost group of 8-bits 
subkey[1] = w >> 16;     // hold 8 bit, second group of 8-bit from left    
subkey[2] = w >> 8;      // hold 8 bit, second group of 8-bit from right
subkey[3] = w;           // hold 8 bit, LSB, rightmost group of 8-bits

/// subkey <- w
```

* Something like that can be substituted with single __rotate right__ operation

`__asm__ ("l.ror %0,%1,%2" : "=r" (* (unsigned int *) subkey) : "r" (w), "r" (0x10));`

* ### All the assembly instruction you are passing are __platofrm dependent__ and therefore not portable.

## Extended format

### In general, there are __two__ tenmplates

```
asm [volatile] ( AssemblerTemplate
 : OutputOperands
 [ : InputOperands
 [ : Clobbers ] ])
 asm [volatile] goto ( AssemblerTemplate
 :
: InputOperands
: Clobbers
: GotoLabels)
```

### Where: 

* __Assembler template__ is the template for the assembly instructions

* __Output operands__ are any variables that can be modified by the assembly

* __Input operands__ are any variables that work as an input from the C code

* __Clobbers__ is a list of registers that will be modified from the assembly code

* __GotoLabels__ are any __goto__ statements that may be used from the assembly code

```
//example from the Linux kernel for byte swapping 16-bit and 32-bit //numbers for an ARM processor:

/* From arch/arm/include/asm/swab.h in Linux kernel version 4.6.4 */
#if __LINUX_ARM_ARCH__ >= 6
static inline __attribute_const__ __u32 __arch_swahb32(__u32 x)
{
 __asm__ ("rev16 %0, %1" : "=r" (x) : "r" (x));
 return x;
}
#define __arch_swahb32 __arch_swahb32
#define __arch_swab16(x) ((__u16)__arch_swahb32(x))
static inline __attribute_const__ __u32 __arch_swab32(__u32 x)
{
 __asm__ ("rev %0, %1" : "=r" (x) : "r" (x));
 return x;
}
#define __arch_swab32 __arch_swab32
#endif
```

* ### Keep in mind that on the __extended format__, the compilers will try to optimize the input as some normal C code, in order to avoid that, use the __volatile keyword__