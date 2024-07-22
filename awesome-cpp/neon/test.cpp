#include <cstdio>
#include <arm_neon.h>

int main()
{
#ifdef __ARM_NEON
    printf("ARM_NEON supported\n");
#endif

#ifdef __ARM_NEON_FP 
    printf("Neon floating-point operations are supported\n");
#endif

#ifdef __ARM_FEATURE_CRYPTO
    printf("Feature crypto\n");
#endif

#ifdef __ARM_FEATURE_FMA 
    printf("The fused multiply-accumulate instructions are available.\n");
#endif
}
