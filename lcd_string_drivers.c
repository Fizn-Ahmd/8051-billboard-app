#include "lcd_billboard_app.h"

void lcd_string(u8 *p)
{
	u8 i, j;
	for (j = 0; p[j]; j++)
		;
	for (i = 0; i < j; i++)
		lcd_input(p[i]);
}
u16 string_len(u8 *p)
{
	u8 i;
	for (i = 0; p[i]; i++)
		;
	return i;
}