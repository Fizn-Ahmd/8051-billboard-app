#include<reg51.h>

#include "header1.h"

u8 line_info = 0;
u8 char_hist_arr = 0;

/* Func to point the cursor. */
void lcd_cu(u8 *n)
{
	lcd_input('A'+*n);
	lcd_cmd(0x4);
	lcd_input(' ');
	lcd_cmd(0x6);
	*n = *n+1;
	if(*n == 26)
		*n = 0;
	if(*n == 58)
		*n = 32;
	if(*n == -7 || *n == 249)
		*n = -17;
}

/* Func that print's the next character/Number. */
void lcd_next(u8 *p,u8 *n)
{
	if((*n > 239) && (*n < 249)) {
		lcd_input('A'+*n-1);
		p[char_hist_arr] = 'A'+(*n-1);
		char_hist_arr = char_hist_arr + 1;
		if(line_info == 16)
			lcd_cmd(0xC0);
	}
	if(*n > 0 && *n <26) {
		lcd_input('A'+*n-1);
		p[line_info] = 'A'+(*n-1);
		line_info = line_info + 1;
		if(line_info == 16)
			lcd_cmd(0xC0);
	}
	if(*n > 32 && *n <58) {
		lcd_input('A'+*n-1);
		p[line_info] = 'A'+(*n-1);
		line_info = line_info + 1;
		if(line_info == 16)
			lcd_cmd(0xC0);
	}
	lcd_cmd(0x6);

	if(*n >= 0 && *n <= 25)
		*n = 0;
	if(*n >=32 && *n <= 58)
		*n = 32; 
	if((*n >= 239) && (*n <= 249))
		*n = -17;
}

/* Func that prints the previous character/Number. */
void lcd_prev(u8 *p,u8 *n)
{
	if(line_info == 0)
	{
		lcd_input(' ');
		lcd_cmd(0x4);
		lcd_input(' ');
		lcd_cmd(0x6);
	}
	if(line_info > 0)
	{
		lcd_cmd(0x4);
		lcd_input(' ');
		lcd_cmd(0x6);
		p[line_info] = '\0';
		line_info = line_info - 1;
		char_hist_arr = char_hist_arr - 1;
		if(*n <= 25)
			*n = 0;
		if(*n >=32)
			*n = 32;
		if((*n >= 239) && (*n <= 249))
			*n = -17;
  }
}

/* Func to print space. */
void lcd_space(u8 *p)
{
	lcd_input(' ');
	p[line_info] = ' ';
	line_info = line_info + 1;
	if(line_info == 16)	
		lcd_cmd(0xC0);
}