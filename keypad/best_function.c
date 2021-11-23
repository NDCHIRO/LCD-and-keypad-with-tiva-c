#include "tm4c123gh6pm.h"
#include "init.h"


void initKeypad()
{

 SYSCTL_RCGCGPIO_R |=( SYSCTL_RCGCGPIO_R2);
  GPIO_PORTC_DATA_R = 0X00 ;
 
    SYSCTL_RCGCGPIO_R |=( SYSCTL_RCGCGPIO_R3);
    GPIO_PORTD_DIR_R &=~(C1|C2|C3|C4);
    GPIO_PORTD_DEN_R |= (C1|C2|C3|C4);
    GPIO_PORTD_DATA_R = 0X00 ;
    
    //PORTE for commands
    SYSCTL_RCGCGPIO_R &=~( SYSCTL_RCGCGPIO_R4);
    SYSCTL_RCGCGPIO_R |= SYSCTL_RCGCGPIO_R4;
    GPIO_PORTE_DIR_R &=~ (R1|R2|R3|R4);
    GPIO_PORTE_DEN_R |= (R1|R2|R3|R4);
    GPIO_PORTE_DATA_R = 0X00 ;


}


char keypad_getkey()
{
   // rows E1 , E2,E3,E4
  //COL   D2, D3 ,D6 , D

	char Keymap[4][4] = {
	  {'1','2','3','A'},
	  {'4','5','6','B'},
	  {'7','8','9','C'},
	  {'E','0','F','D'}};

    int row, col;
    const char row_select[] = {R1, R2, R3, R4}; // one of the row is active
    const char col_select[] = {C1, C2, C3, C4}; // one of the row is active

    // check to see any key pressed first
    GPIO_PORTE_DATA_R &= ~0x3C;                			// disable all rows
    col = GPIO_PORTD_DATA_R & (C1|C2|C3|C4);           // read all columns
    

    if (col == (C1|C2|C3|C4))
    	 return -1;             // no key pressed, return a zero

    // lw key 2das b2a HN3MEL EH 5OOOOOOY?
    // hn activate one row at a time and read the input to see which column is active.
    
    for (row = 0; row < 4; row++)
    {
        GPIO_PORTE_DATA_R |= (R1|R2|R3|R4);            // disable all rows
        GPIO_PORTE_DATA_R &= ~(row_select[row]);  // enable one row
        for(int j=0;j<4;j++)
        {
        	col = GPIO_PORTD_DATA_R & col_select[j];       // read all columns
        	        if (col == 0) 
        	        	return Keymap[row][j];							// kda fe key mdas f break	
        }
                     
    }
}
/*void delayUs(int n)
{
    int i, j;
    for(i = 0 ; i < n; i++)
        for(j = 0; j < 3; j++)
            {}  // do nothing for 1 us
}*/
