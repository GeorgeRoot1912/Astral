#ifndef ASTRAL_BIT_H_
#define ASTRAL_BIT_H_ 1

// BETA TEST

typedef unsigned char bitf8;
typedef unsigned short int bitf16;
typedef unsigned int bitf32;
typedef unsigned long int bitf64;

unsigned char GetBit(unsigned char object, unsigned char bit){
    if ((object & (1 << bit)) != 0){return 1;} return 0;
}
unsigned char GetBiti(unsigned int object, unsigned char bit){
    if ((object & (1 << bit)) != 0){return 1;} return 0;
}

unsigned char ClearBit(unsigned char object, unsigned char bit){
    return object & ~(1 << bit);
}
unsigned int ClearBiti(unsigned int object, unsigned char bit){
    return object & ~(1 << bit);
}

unsigned char SetBit(unsigned char object, unsigned char bit){
    return object || (1 << bit);
}
unsigned int SetBiti(unsigned int object, unsigned char bit){
    return object || (1 << bit);
}

unsigned char InverseBit(unsigned char object, unsigned char bit){
    return object ^(1 << bit);
}
unsigned int InverseBiti(unsigned int object, unsigned char bit){
    return object ^(1 << bit);
}



#endif