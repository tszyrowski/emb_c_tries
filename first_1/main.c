#include "lm4f120h5qr.h"

int main(){ 
    unsigned int a = 0x5a5a5a5a;
    unsigned int b = 0xdeadbeef;
    unsigned int c;
    unsigned int d;
    
    c = a | b;  // OR
    c = a & b;  // AND
    c = a ^ b;  //exclusive OR
    c = ~b;     // NOT
    d = c;
    c = b >> 1; // right shift
    d = c;
    c = b << 3; // left shift
    
    int x = 1024;
    int y = -1024;
    int z;
    
    z = x >> 3;
    z = y >> 3;
    
    
    SYSCTL_RCGCGPIO_R = 0x20U;
    GPIO_PORTF_DIR_R = 0x0EU;
    GPIO_PORTF_DEN_R = 0x0EU;
    
    GPIO_PORTF_DATA_R = 0x04U;  // turn the blue LED on
    while (1) {
        GPIO_PORTF_DATA_R = 0x02U;
        int volatile counter = 0;
        while (counter < 500000){
            ++counter;
        }
        GPIO_PORTF_DATA_R = 0x00U;
        counter = 0;
        while (counter < 1000000){
            ++counter;
        }
    }
    return 0;
}
