#include<stdio.h>

int main()
{
    // Binary _2_ 01
    // Decimal _10_ 0123456789
    // Octal _8_ 01234567
    // Hexa _16_ 0123456789ABCDEF

    // Code Doc
    // long double hello; // %f %llf
    float nahid = 38; // ABC = 38
    // scanf("%d", &nahid);
    float*pointer = &nahid; // ____ = ABC
    // int** pointerThree = &pointer;
    printf("Pointer %p\n", &pointer);
    printf("Pointer Value %f\n", *pointer);
    printf("Nahid Adds = %p\n", &nahid);
    // printf();
    
    void* pointerTwo = 0;
    printf("Pointer %p\n", pointerTwo);
    printf("Pointer Size = %lu\n", sizeof(pointerTwo));
    return 0;
}
