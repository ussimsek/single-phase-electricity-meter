#ifndef RTC_SCLK
#define RTC_SCLK PIN_C1
#define RTC_IO   PIN_C2
#define RTC_RST  PIN_C0
#endif
void write_ds1302_byte(BYTE cmd) 
{
   BYTE i;
   for(i=0;i<=7;++i) 
{
      output_bit(RTC_IO, shift_right(&cmd,1,0) );
      output_high(RTC_SCLK);
      output_low(RTC_SCLK);
   }
}



void write_ds1302(BYTE cmd, BYTE data)
 {
   output_high(RTC_RST);
   write_ds1302_byte(cmd);
   write_ds1302_byte(data);
   output_low(RTC_RST);
}

BYTE read_ds1302(BYTE cmd) 
{
   BYTE i,data;
   output_high(RTC_RST);
   write_ds1302_byte(cmd);

   for(i=0;i<=7;++i) 
{
      shift_right(&data,1,input(RTC_IO));
      output_high(RTC_SCLK);
      delay_us(2);
      output_low(RTC_SCLK);
      delay_us(2);
   }
   output_low(RTC_RST);
   return(data);
}

void rtc_init() 
{
   BYTE x;
   output_low(RTC_RST);
   delay_us(2);
   output_low(RTC_SCLK);
   write_ds1302(0x8e,0);
   write_ds1302(0x90,0xa4);
   x=read_ds1302(0x81);
   if((x & 0x80)!=0)
     write_ds1302(0x80,0);
}

int get_bcd(BYTE data)
{
   int nibh;
   int nibl;
   nibh=data/10;
   nibl=data-(nibh*10);
   return((nibh<<4)|nibl);
}

int rm_bcd(BYTE data)
{
   int i;
   i=data;
   data=(i>>4)*10;
   data=data+(i<<4>>4);
   return data;
}

void rtc_set_datetime(BYTE day, BYTE mth, BYTE year, BYTE dow, BYTE hr, BYTE min) 
{
   write_ds1302(0x86,get_bcd(day));
   write_ds1302(0x88,get_bcd(mth));
   write_ds1302(0x8c,get_bcd(year));
  write_ds1302(0x8a,get_bcd(dow));
   write_ds1302(0x84,get_bcd(hr));
   write_ds1302(0x82,get_bcd(min));
   write_ds1302(0x80,get_bcd(0));
}

void rtc_get_date(BYTE& day, BYTE& mth, BYTE& year, BYTE& dow) 
{
   day = rm_bcd(read_ds1302(0x87));
   mth = rm_bcd(read_ds1302(0x89));
   year = rm_bcd(read_ds1302(0x8d));
   dow = rm_bcd(read_ds1302(0x8b));
}

void rtc_get_time(BYTE& hr, BYTE& min, BYTE& sec) 
{
   hr = rm_bcd(read_ds1302(0x85));
   min = rm_bcd(read_ds1302(0x83));
   sec = rm_bcd(read_ds1302(0x81));
}

void rtc_write_nvr(BYTE address, BYTE data) 
{
   write_ds1302(address|0xc0,data);
}

BYTE rtc_read_nvr(BYTE address) 
{
    return(read_ds1302(address|0xc1));
}
