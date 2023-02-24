#include<stdio.h>

struct Nahid
{
    int id;
    double price;
};

typedef struct Nahid nahid;



int main() 
{
    // struct Nahid varOne;
    nahid varOne;
    // printf("Size of Nahid = %lu\n", sizeof(varOne));
    nahid* nahidPtr = &varOne;
    varOne.id = 10;
    varOne.price = 699.99;

    // printf("Nahid ID: %d\n", varOne.id);
    // printf("Nahid Price: %f\n", varOne.price);
    printf("Nahid ID: %d\n", nahidPtr->id);
    printf("Nahid Price: %f\n", nahidPtr->price);
    return 0;
}