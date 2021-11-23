
char keypad_getkey()
{
   // rows A2 , A3 ,A4 ,A5
  //COL   D1, D2 ,D3 , D6

	char Keymap[4][4] = {
	  {'1','2','3','A'},
	  {'4','5','6','B'},
	  {'7','8','9','C'},
	  {'E','0','F','D'}};

    int row, col;
    const char row_select[] = {R1, R2, R3, R4}; // one of the row is active
    const char col_select[] = {C1, C2, C3, C4}; // one of the row is active

    // check to see any key pressed first
    GPIO_PORTA_DATA_R &= ~0x3C;                			// disable all rows
    col = GPIO_PORTD_DATA_R & (C1|C2|C3|C4);           // read all columns
    

    if (col == (C1|C2|C3|C4))
    	 return -1;             // no key pressed, return a zero

    // lw key 2das b2a HN3MEL EH 5OOOOOOY?
    // hn activate one row at a time and read the input to see which column is active.
    
    for (row = 0; row < 4; row++)
    {
        GPIO_PORTA_DATA_R |= (R1|R2|R3|R4);            // disable all rows
        GPIO_PORTA_DATA_R &= ~(row_select[row]);  // enable one row
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
