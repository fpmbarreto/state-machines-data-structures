#include "stm32f411xe.h"
#include <stdint.h>
#include <stdio.h>

enum states{
    STATE_A = 0,
    STATE_B,
    STATE_C
};

typedef enum states State_Type;

void state_machine_init(void);
void stateA_func(void);
void stateB_func(void);
void stateC_func(void);

static void (*state_table[])(void) = {stateA_func,
                                      stateB_func,
                                      stateC_func
};

static uint16_t clk;
static uint16_t i; 
static State_Type current_state;



void main(void)
{
    while(1)
    {
        state_table[current_state];
        while(i<500){
            i++;
        }
        clk++;
        i = 0;
    }

}

void state_machine_init(void)
{
    current_state = STATE_A;
    clk = 0;
}

void stateA_func(void)
{
    if (clk == 2)
    {
        current_state = STATE_B;
        printf("Executing STATE A\n");
    }
}
void stateB_func(void)
{
    if (clk == 5)
    {
        current_state = STATE_C;
        printf("Executing STATE B\n");
    }
}
void stateC_func(void)
{
    if (clk == 9)
    {
        current_state = STATE_A;
        clk = 0;
        printf("Executing STATE C\n");
    }
}

