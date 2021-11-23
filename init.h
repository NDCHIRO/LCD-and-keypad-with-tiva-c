#define C1 0X04 //0000 0010
#define C2 0x08 //0000 0100
#define C3 0x40 //0000 1000
#define C4 0x80 //0100 0000

#define R1 0x02 
#define R2 0x04 
#define R3 0x08
#define R4 0x10

void initKeypad(void);
char keypad_getkey();