 #define use_portb_lcd TRUE
  #include <lcd.c>
  
  int x;
  float y;
  char z;

  set_tris_b(0x00);
  lcd_init();
  x=06228027;
  y=22.10;
  
  while(1)
  {
   lcd_send_byte(0,0x0d);
   print(lcd_putc,"\f     CCS C");
   delay_ms(1000);
   printf(lcd_putc,"\n    DERLEYICISI");
   delay_ms(1000);
   lcd_gotoxy(1,2);
   print(lcd_putc,"\f X DEGERI:%d",x);
   delay_ms(1000);
   printf(lcd_putc,"\f\n Y DEGERI:%f",y);
   delay_ms(1000);
   printf(lcd_putc,"\f DIRENC");
   delay_ms(1000);
   
   z=lcd_getc(4,1);
   
   printf(lcd_putc,"\f Z=%c",z);
   delay_ms(3000);
  }
