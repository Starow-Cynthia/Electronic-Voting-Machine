#include <reg51.h>
#include <stdlib.h>

sbit rs = P3^2;
sbit en = P3^3;
sbit button1 = P3^0;  // Button for Student 1
sbit button2 = P3^1;  // Button for Student 2

unsigned int vote1 = 0, vote2 = 0, total_votes = 0;

// Delay function
void delay(unsigned int ms) {
    unsigned int i, j;
    for (i = 0; i < ms; i++)
        for (j = 0; j < 1275; j++);
}

// Send command to LCD
void lcd_cmd(unsigned char cmd) {
    P2 = cmd;
    rs = 0;
    en = 1;
    delay(2);
    en = 0;
}

// Send data to LCD
void lcd_data(unsigned char ch) {
    P2 = ch;
    rs = 1;
    en = 1;
    delay(2);
    en = 0;
}

// Send string to LCD
void lcd_str(char *str) {
    while (*str)
        lcd_data(*str++);
}

// Convert and send number (2 digits)
void lcd_num(unsigned int num) {
    lcd_data((num / 10) + '0');
    lcd_data((num % 10) + '0');
}

// Initialize LCD
void lcd_init() {
    lcd_cmd(0x38);  // 8-bit mode, 2 lines, 5x7 font
    lcd_cmd(0x0C);  // Display ON, Cursor OFF
    lcd_cmd(0x01);  // Clear display
    lcd_cmd(0x06);  // Increment cursor
    lcd_cmd(0x80);  // Start at first line
}

// Display Welcome Message
void welcome_screen() {
    lcd_cmd(0x80);
    lcd_str("Welcome to Class");
    lcd_cmd(0xC0);
    lcd_str("Election");
    delay(20);
    lcd_cmd(0x01); // Clear
}

// Show current votes
void show_votes() {
    lcd_cmd(0x80);
    lcd_str("Stud1 Vote=");
    lcd_num(vote1);
    lcd_cmd(0xC0);
    lcd_str("Stud2 Vote=");
    lcd_num(vote2);
}

// Display winner or tie result
void show_result() {
    lcd_cmd(0x01);
    lcd_cmd(0x80);
    lcd_str("Winner: ");
    if (vote1 > vote2)
        lcd_str("Student1");
    else if (vote2 > vote1)
        lcd_str("Student2");
    else {
        // Random tie-break
        if (rand() % 2 == 0)
            lcd_str("Student1");
        else
            lcd_str("Student2");
    }
}

void main() {
    lcd_init();
    welcome_screen();
    show_votes();

    while (total_votes < 18) {
        if (button1 == 1) {
            delay(20); // Debounce
            if (button1 == 1) {
                vote1++;
                total_votes++;
                show_votes();
                while (button1 == 1); // Wait for release
            }
        }

        if (button2 == 1) {
            delay(20); // Debounce
            if (button2 == 1) {
                vote2++;
                total_votes++;
                show_votes();
                while (button2 == 1); // Wait for release
            }
        }
    }

    delay();
    show_result();

    while (1);  // Infinite loop to halt
}
