#include "lcd_billboard_app.h"

#define _16x16_LCD_MATRIX 33 // Max Character that can be shown.
#define DELAY_BETWEEN 10  // Delay between the billboard text.

int atoi(char *p);

void main() {
	s8 i = 0;
	u16 n;
	u8 s[_16x16_LCD_MATRIX]];
	u8 h[DELAY_BETWEEN];
	lcd_init();
	while (1) {
		if (sw0 == 0) {
			while(sw0 == 0);
			lcd_cu(&i);
		}
		if (sw1 == 0) {
			while(sw1 == 0);
			lcd_next(&s,&i);
		}
		if (sw2 == 0) {
			while(sw2 == 0);
			lcd_prev(&s,&i);
		}
		if (sw3 == 0) {
			while(sw3 == 0);
			lcd_space(&s);
		}
		if (sw4 == 0) {
			while(sw4 == 0);
			if(i <= 26)
				i = 32;
			else
				i = 0;
		}
		if (sw5 == 0) {
			while(sw5 == 0);
			i = -17;
			lcd_cmd(0x1);
			break;
		}
	}		
	while (1) {
		if(sw0 == 0){
			while(sw0 == 0);
			lcd_cu(&i);
		}
		if(sw1 == 0) {
			while(sw1 == 0);
			lcd_next(&h,&i);
		}
		if(sw2 == 0) {
			while(sw2 == 0);
			lcd_prev(&h,&i);
		}
		if(sw5 == 0) {
			while(sw5 == 0);
			n = atoi(h);
			break;
		}
	}
	while (1) {
		lcd_cmd(0x1);
		delay_1s(n);
		lcd_string(s);  
		delay_1s(n);
	}
}

u16 atoi(u8 *p)
{
	u16 num = 0, j;
	for(j = 0;p[j];j++) {
		num = (num*10) + (p[j] -48);
	}
	return num;
}