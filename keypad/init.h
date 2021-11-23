#define C1 0x10 //0000 0010
#define C2 0x20 //0000 0100
#define C3 0x40 //0000 1000
#define C4 0x80 //0100 0000

#define R1 0x02 
#define R2 0x04 
#define R3 0x08
#define R4 0x10

#define sw1 (1U<<4)
#define sw2  (1U<<0)
   // rows E1 , E2,E3,E4
  //COL   D2, D3 ,D6 , D7

void initKeypad(void);
char keypad_getkey();
void mohem(int i ,int size);
