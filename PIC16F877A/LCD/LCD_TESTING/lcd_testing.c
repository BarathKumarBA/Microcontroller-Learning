

 #include <htc.h>

#define _XTAL_FREQ 20000000

// LCD control pins
#define RS RB0
#define RW RB1
#define EN RB2

// Function prototypes
void Command(unsigned char cmd);
void Data(unsigned char data);
void LCD_Init(void);
void LCD_Print(const char *str);
void LCD_Enable(void);

void LCD_Enable(void)
{
    EN = 1;
    __delay_ms(2);
    EN = 0;
    __delay_ms(2);
}

void Command(unsigned char cmd)
{
    RS = 0;             // Command mode
    RW = 0;             // Write mode

    PORTD = cmd;        // Send command to LCD

    LCD_Enable();
}

void Data(unsigned char data)
{
    RS = 1;             // Data mode
    RW = 0;             // Write mode

    PORTD = data;       // Send data to LCD

    LCD_Enable();
}

void LCD_Init(void)
{
    // LCD initialization
    __delay_ms(20);

    Command(0x38);  // 8-bit mode, 2 lines, 5x7 matrix
    Command(0x0C);  // Display ON, cursor OFF
    Command(0x06);  // Increment cursor
    Command(0x01);  // Clear display
    __delay_ms(2);
    Command(0x80);  // Cursor at first line
}

void LCD_Print(const char *str)
{
    while(*str)
    {
        Data(*str);
        str++;
    }
}

void main(void)
{
    TRISB = 0x00;       // PORTB as output-->For Command Signals
    TRISD = 0x00;       // PORTD as output __>For Data Signals

    PORTB = 0x00;
    PORTD = 0x00;

    LCD_Init();

    LCD_Print("WELCOME");

    Command(0xC0);  // Move cursor to second line

    LCD_Print("LCD TESTING 1..2..3");

    while(1)
    {
        // Infinite loop
    }
}