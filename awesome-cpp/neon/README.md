# Introducing Neon for Armv8-A

## What is Neon

Neon is the implementation of Arm's Advanced SIMD architecture.

The purpose of Neon is to accelerate data manipulation by providing:

- Thirty-two 128-bit vector registers, each capable of containing multiple lanes of data.
- SIMD instructions to operate simultaneously on those multiple lanes of data.

![image](https://documentation-service.arm.com/static/62a8632131ea212bb662341a?token=)
Figure 1. Single instruction, multiple data Architecture

This can improve the multimedia user experience by accelerating audio and video encoding/decoding, user interface, 2D/3D graphics or gaming.  
Neon can also accelerate signal processing algorithms and functions to speed up applications such as audio and video processing, voice and facial recognition, computer vision and deep learning.  

As a programmer, there are a number of ways you can make use of Neon technology:

- Neon-enabled open source libraries such as the [Arm Compute Library](https://developer.arm.com/ip-products/processors/machine-learning/compute-library) provide one of the easiest ways to take advantage of Neon.
- Auto-vectorization features in your [compiler](https://developer.arm.com/tools-and-software/embedded/arm-compiler) can automatically optimize your code to take advantage of Neon.
- [Neon intrinsics](https://developer.arm.com/architectures/instruction-sets/simd-isas/neon/intrinsics) are function calls that the compiler replaces with appropriate Neon instructions. This gives you direct, low-level access to the exact Neon instructions you want, all from C/C++ code.
- For very high performance, hand-coded Neon assembler can be an alternative approach for experienced programmers.

## Single Instruction Multiple Data

Single Instruction Multiple Data (SIMD) instructions perform the same operation simultaneously for multiple data items.  
These data items are packed as separate lanes in a larger register.  

For example, the following instruction adds four pairs of single-precision (32-bit) values together.  
However, in this case, the values are packed into separate lanes in two pairs of 128-bit registers.  
Each lane in the first source register is then added to the corresponding lane in the second source register, before being stored in the same lane in the destination register:  

```text
ADD V10.4S, V8.4S, V9.4S
// This operation adds two 128-bit (quadword) registers, V8 and V9,
// and stores the result in V10.
// Each of the four 32-bit lanes in each register is added separately.
// There are no carries between the lanes.
```

This single instruction operates on all data values in the large register at the same time:

![Single Instruction Multiple Data](https://documentation-service.arm.com/static/62a8632131ea212bb662341d?token=)
Figure. Single Instruction Multiple Data

Performing the four operations with a single SIMD instruction is faster than with four separate SISD instructions.

The diagram shows 128-bit registers each holding four 32-bit values, but other combinations are possible for Neon registers:

- Two 64-bit, four 32-bit, eight 16-bit, or sixteen 8-bit integer data elements can be operated on simultaneously using all 128 bits of a Neon register.
- Two 32-bit, four 16-bit, or eight 8-bit integer data elements can be operated on simultaneously using the lower 64 bits of a Neon register (in this case, the upper 64 bits of the Neon register are unused).

> Note
The addition operations shown in the diagram are truly independent for each lane. Any overflow or carry from lane 0 does not affect lane 1, which is an entirely separate calculation.

## Fundamentals of Armv8 Neon technology

Armv8-A includes both 32-bit and 64-bit Execution states, each with their own instruction sets:  

- AArch64:
  - 64-bit Execution state of the Armv8-A architecture.
  - In AArch64 state, the processor executes the A64 instruction set, which contains Neon instructions (also referred to as SIMD instructions).
  - GNU and Linux documentation sometimes refers to AArch64 as ARM64.
- AArch32:
  - 32-bit Execution state of the Armv8-A architecture, which is almost identical to Armv7.
  - In AArch32 state, the processor can execute either the A32 (called ARM in earlier versions of the architecture) or the T32 (Thumb) instruction set.
  - The A32 and T32 instruction sets are backwards compatible with Armv7, including Neon instructions.

## Registers, vectors, lanes and elements

Armv8 cores are a 64-bit architecture and use 64-bit registers, but the Neon unit uses 128-bit registers for SIMD processing.

This is possible because the Neon unit operates on a separate register file of 128-bit registers. The Neon unit is fully integrated into the processor and shares the processor resources for integer operation, loop control, and caching. This significantly reduces the area and power cost compared to a hardware accelerator. It also uses a much simpler programming model, since the Neon unit uses the same address space as the application.

The Neon register file is a collection of registers which can be accessed as 8-bit, 16-bit, 32-bit, 64-bit, or 128-bit registers.

The Neon registers contain vectors of elements of the same data type. The same element position in the input and output registers is referred to as a lane.

Usually each Neon instruction results in n operations occurring in parallel, where n is the number of lanes that the input vectors are divided into. Each operation is contained within the lane. There cannot be a carry or overflow from one lane to another.

The number of lanes in a Neon vector depends on the size of the vector and the data elements in the vector.

A 128-bit Neon vector can contain the following element sizes:

- Sixteen 8-bit elements (operand suffix .16B, where B indicates byte)
- Eight 16-bit elements (operand suffix .8H, where H indicates halfword)
- Four 32-bit elements (operand suffix .4S, where S indicates word)
- Two 64-bit elements (operand suffix .2D, where D indicates doubleword)

A 64-bit Neon vector can contain the following element sizes (with the upper 64 bits of the 128-bit register cleared to zero):

- Eight 8-bit elements (operand suffix .8B, where B indicates byte)
- Four 16-bit elements (operand suffix .4H, where H indicates halfword)
- Two 32-bit elements (operand suffix .2S, where S indicates word)

![Figure 1. 64-bit and 128-bit vectors](https://documentation-service.arm.com/static/62a8632131ea212bb662341b?token=)

Elements in a vector are ordered from the least significant bit. That is, element 0 uses the least significant bits of the register. Let’s look at an example of a Neon instruction. The instruction ADD V0.8H, V1.8H, V2.8H performs a parallel addition of eight lanes of 16-bit (8 x 16 = 128) integer elements from vectors in V1 and V2, storing the result in V0:  

![Figure 2. Order of elements in a vector](https://documentation-service.arm.com/static/62a8632131ea212bb662341e?token=)

Some Neon instructions act on scalars together with vectors. Instructions which use scalars specify a lane index to refer to a specific element in a register. For example, the instruction MUL V0.4S, V2.4S, V3.S[2] multiplies each of the four 32-bit elements in V2 by the 32-bit scalar value in lane 2 of V3, storing the result vector in V0.  

![Figure 3. Instructions using scalars](https://documentation-service.arm.com/static/62a8632131ea212bb662341c?token=)

## Why Neon intrinsics

Intrinsics are functions whose precise implementation is known to a compiler. The Neon intrinsics are a set of C and C++ functions defined in arm_neon.h which are supported by the Arm compilers and GCC. These functions let you use Neon without having to write assembly code directly, since the functions themselves contain short assembly kernels which are inlined into the calling code. Additionally, register allocation and pipeline optimization are handled by the compiler so many difficulties faced by the assembly programmer are avoided.

See the [Neon Intrinsics Reference](https://developer.arm.com/architectures/instruction-sets/simd-isas/neon/intrinsics) for a list of all the Neon intrinsics. The Neon intrinsics engineering specification is contained in the [Arm C Language Extensions (ACLE)](https://developer.arm.com/architectures/system-architectures/software-standards/acle).

Using the Neon intrinsics has a number of benefits:

- Powerful: Intrinsics give the programmer direct access to the Neon instruction set without the need for hand-written assembly code.
- Portable: Hand-written Neon assembly instructions might need to be re-written for different target processors. C and C++ code containing Neon intrinsics can be compiled for a new target or a new execution state (for example, migrating from AArch32 to AArch64) with minimal or no code changes.
- Flexible: The programmer can exploit Neon when needed, or use C/C++ when it isn't, while avoiding many low-level engineering concerns.

However, intrinsics might not be the right choice in all situations:

- There is a steeper learning curve to use Neon intrinsics than importing a library or relying on a compiler.
- Hand-optimized assembly code might offer the greatest scope for performance improvement even if it is more difficult to write.

We shall now go through a couple of examples where we re-implement some C functions using Neon intrinsics. The examples chosen do not reflect the full complexity of their application, but they should illustrate the use of intrinsics and act as a starting point for more complex code.

## Program conventions

baseW_t

- Scalar data types

baseWxL_t

- Vector data types

baseWxLxN_t

- Vector array data types

Where:

- base refers to the fundamental data type.
- W is the width of the fundamental type.
- L is the number of scalar data type instances in a vector data type, for example an array of scalars.
- N is the number of vector data type instances in a vector array type, for example a struct of arrays of scalars.

Generally W and L are such that the vector data types are 64 or 128 bits long, and so fit completely into a Neon register. N corresponds with those instructions which operate on multiple registers at once.

In our earlier code we encountered an example of all three:

- uint8_t
- uint8x16_t
- uint8x16x3_t

## Functions

As per the Arm C Language Extensions, the function prototypes from arm_neon.h follow a common pattern. At the most general level this is:

``` ret v[p][q][r]name[u][n][q][x][_high][_lane | laneq][_n][_result]_type(args) ```

Be wary that some of the letters and names are overloaded, but in the order above:

**ret**  
the return type of the function.  
**v**  
short for  vector and is present on all the intrinsics.  
**p**  
indicates a pairwise operation. (  [value] means  value may be present).  
**q**  
indicates a saturating operation (with the exception of  vqtb[l][x] in AArch64 operations where the  q indicates 128-bit index and result operands).  
**r**  
indicates a rounding operation.  
**name**  
the descriptive name of the basic operation. Often this is an Advanced SIMD instruction, but it does not have to be.  
**u**  
indicates signed-to-unsigned saturation.  
**n**  
indicates a narrowing operation.  
**q**  
postfixing the name indicates an operation on 128-bit vectors.  
**x**  
indicates an Advanced SIMD scalar operation in AArch64. It can be one of  b,  h,  s or  d (that is, 8, 16, 32, or 64 bits).  
**_high**  
In AArch64, used for widening and narrowing operations involving 128-bit operands. For widening 128-bit operands,  high refers to the top 64-bits of the source operand(s). For narrowing, it refers to the top 64-bits of the destination operand.  
**_n**  
indicates a scalar operand supplied as an argument.  
**_lane**  
indicates a scalar operand taken from the lane of a vector.  _laneq indicates a scalar operand taken from the lane of an input vector of 128-bit width. (  left | right means only  left or  right would appear).  
**type**  
the primary operand type in short form.  
**args**  
the function's arguments.  

## Reference

[NEON Programmer's Guide](https://developer.arm.com/documentation/den0018/a/?lang=en)  

[Introducing Neon for Armv8-A](https://developer.arm.com/documentation/102474/0100/?lang=en)  

[Optimizing C Code with Neon Intrinsics](https://developer.arm.com/documentation/102467/0100/What-is-Neon-)  

[Cortex-A Series Programmer’s Guide](https://developer.arm.com/documentation/den0013/latest)

[NEON™ Programmer's Guide Version: 1.0, Armv7](https://developer.arm.com/documentation/den0018/latest)