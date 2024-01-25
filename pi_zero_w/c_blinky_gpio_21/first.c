#include <stdint.h>

#define DELAY_COUNT        9000000
#define GPFSEL4            0x20200008
#define GPSET1             0x2020001c
#define GPCLR1             0x20200028
#define EXTERNAL_LED_GPIO  21
#define REG32(addr)        (*(volatile uint32_t*)(addr))
#define _BV(v)             (1U << (v))

void delay(void)
{
    uint32_t idx;

    for (idx = 0; idx < DELAY_COUNT; idx++)
    {
        asm volatile ("nop    \n\t");
    }
}

int main(void)
{
    REG32(GPFSEL4) |= _BV(EXTERNAL_LED_GPIO % 10 * 3);

    for (;;)
    {
        REG32(GPSET1) |= _BV(EXTERNAL_LED_GPIO);
        delay();

        REG32(GPCLR1) |= _BV(EXTERNAL_LED_GPIO);
        delay();
    }

    return 0;
}
