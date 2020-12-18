#include "lm4f120h5qr.h"

#define LED_RED   (1U << 1)
#define LED_BLUE  (1U << 2)
#define LED_GREEN (1U << 3)

int main(){     
    SYSCTL_RCGCGPIO_R |= (1U << 5);
    GPIO_PORTF_DIR_R |= (LED_RED | LED_BLUE | LED_GREEN);
    GPIO_PORTF_DEN_R |= (LED_RED | LED_BLUE | LED_GREEN);
    
    GPIO_PORTF_DATA_R = LED_BLUE;
    while (1) {
        // GPIO_PORTF_DATA_R = GPIO_PORTF_DATA_R | LED_RED;
        *((unsigned long volatile *)(0x40025000 + (LED_RED << 2))) = LED_RED;
        int volatile counter = 0;
        while (counter < 500000){
            ++counter;
        }
        // GPIO_PORTF_DATA_R = GPIO_PORTF_DATA_R & ~LED_RED;
        GPIO_PORTF_DATA_R &= ~LED_RED;
        counter = 0;
        while (counter < 1000000){
            ++counter;
        }
    }
    return 0;
}
