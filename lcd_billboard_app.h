#ifndef lcdbillboardapp
#define lcdbillboardapp

#include<reg51.h>

#define port0 0
#define port1 1
#define port2 2
#define port3 3

/* standard_definition */
typedef signed char s8;
typedef signed int s16;
typedef signed long int s32;
typedef unsigned char u8;
typedef unsigned int u16;
typedef unsigned long int u32;

/* switches */
sbit sw0 = P1^0;
sbit sw1 = P1^1;
sbit sw2 = P1^2;
sbit sw3 = P1^3;
sbit sw4 = P1^4;
sbit sw5 = P1^5;

/* lcd */
sbit rw = P3^6;
sbit en = P3^7;
sbit rs = P3^5;

sfr port = 0x80;

/* delay */
extern void delay_1s(s16);

/* lcd_drivers */
extern void lcd_init();
extern void lcd_cmd(u8);
extern void lcd_input(u8);
extern u8 read_lcd();
extern void lcd_string(u8 *);
extern u16 string_len(u8 *);

/* lcd_billboard */
extern void lcd_cu(u8 *);
extern void lcd_next(u8 *,u8 *);
extern void lcd_prev(u8 *,u8 *);
extern void lcd_space(u8 *);

/* lcd_Operation */
extern void lcd_integer(u8);
extern void lcd_hex(u8);
extern u8 int_to_hex(u8);
extern u8 hex_to_int(u8);

#endif
