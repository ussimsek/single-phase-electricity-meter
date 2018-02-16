#include <18F4620.h>
#fuses XT,NOWDT,NOPROTECT,NOBROWNOUT,NOLVP,NOPUT,NOWRT,NODEBUG,NOCPD
#use delay(clock=4000000)
#use fast_io(a)
#use fast_io(b)
#use fast_io(c)
#define use_portb_lcd TRUE
#include <LCD.C>
#include <math.h>
#include <DS1302.c>
unsigned long int vbilgi,abilgi;
float voltaj,vtop,atop,gtop,volt,akim,amper,guc,vkare,akare,deger;
int i,j;
byte saniye,dakika,saat,gun,ay,yil,haftanin_gunu; 
void main()
{

   setup_adc_ports(AN0_TO_AN2|VSS_VDD);
   setup_adc(ADC_CLOCK_DIV_2|ADC_TAD_MUL_0);
   setup_psp(PSP_DISABLED);
   setup_spi(SPI_SS_DISABLED);
   setup_wdt(WDT_OFF);
   setup_timer_0(RTCC_INTERNAL);
   setup_timer_1(T1_DISABLED);
   setup_timer_2(T2_DISABLED,0,1);
   setup_timer_3(T3_DISABLED|T3_DIV_BY_1);
   setup_comparator(NC_NC_NC_NC);
   setup_vref(FALSE);
   lcd_init();
   rtc_init();  // DS1302 başlangıç ayarları yapılıyor
   set_tris_a(0x07);
   set_tris_b(0x00);
   set_tris_c(0x00);
   rtc_set_datetime(24,04,07,6,22,42); // Tarih ve Saat ayarları yapılıyor

while(1)
{
   
      rtc_get_time(saat,dakika,saniye);       
      rtc_get_date(gun,ay,yil,haftanin_gunu); 
      printf(lcd_putc,"\f %02d/%02d/20%02d ",gun,ay,yil); 

      switch(haftanin_gunu) 
      {                     
         case 1: printf(lcd_putc,"PAZ"); break; 
         case 2: printf(lcd_putc,"PZT"); break; 
         case 3: printf(lcd_putc,"SAL"); break; 
         case 4: printf(lcd_putc,"CRS"); break; 
         case 5: printf(lcd_putc,"PER"); break; 
         //case 6: printf(lcd_putc,"CUM"); break; 
         case 7: printf(lcd_putc,"CTS"); break; 
      }
      printf(lcd_putc,"\n  %02d:%02d:%02d",saat,dakika,saniye); 
     
      deger=0.0048828125;
       for(i=0;i<200;i++)
       { 
         set_adc_channel(0);
         delay_us(20); 
         vbilgi=read_adc();
         volt=deger*vbilgi;
         vkare=volt*volt;
         vtop=vtop+vkare;
         delay_us(1970);
       }
         output_high(pin_c5);
         voltaj=vtop/200;
         voltaj=sqrt(voltaj);
             {
               if(voltaj>=1.950 && voltaj<1.960)
               {
               voltaj=voltaj*123.0769231;  
               }
               if(voltaj>=1.940 && voltaj<1.950)
               {
               voltaj=voltaj*123.1958763;  
               }
               if(voltaj>=1.930 && voltaj<1.940)
               {
               voltaj=voltaj*123.3160622;
               }
               if(voltaj>=1.9200 && voltaj<1.930)
               {
               voltaj=voltaj*123.4375;
               }
               if(voltaj>=1.910 && voltaj<1.920)
               {
               voltaj=voltaj*123.5602094;
               }


               if(voltaj>=1.900 && voltaj<1.910)
               {
               voltaj=voltaj*123.6842105;
               }
               if(voltaj>=1.890 && voltaj<1.900)
               {
               voltaj=voltaj*123.8095238;
               }
               if(voltaj>=1.880 && voltaj<1.890)
               {
               voltaj=voltaj*123.9361702;
               }
               if(voltaj>=1.870 && voltaj<1.880)
               {
               voltaj=voltaj*124.0641711;
               }
               if(voltaj>=1.860 && voltaj<1.870)
               {
               voltaj=voltaj*124.1935484;
               }
               if(voltaj>=1.850 && voltaj<1.860)
               {
               voltaj=voltaj*124.3243243;
               }
               if(voltaj>=1.840 && voltaj<1.850)
               {
               voltaj=voltaj*124.4565217;
               }



               if(voltaj>=1.830 && voltaj<1.840)
               {
                 voltaj=voltaj*124.5901639;  
               }
               if(voltaj>=1.820 && voltaj<1.830)
               {
               voltaj=voltaj*124.7252747;
               }
               if(voltaj>=1.810 && voltaj<1.820)
               {
               voltaj=voltaj*124.8618785;
               }
               if(voltaj>=1.800 && voltaj<1.810)
               {
               voltaj=voltaj*125;
               }
               if(voltaj>=1.790 && voltaj<1.800)
               {
               voltaj=voltaj*125.1396648;
               }
               if(voltaj>=1.780 && voltaj<1.790)
               {
               voltaj=voltaj*125.2808989;
               }
               if(voltaj>=1.770 && voltaj<1.780)
               {
               voltaj=voltaj*125.4237288;
               }



               if(voltaj>=1.760 && voltaj<1.770)
               {
               voltaj=voltaj*125.5681818;
               }
               if(voltaj>=1.750 && voltaj<1.760)
               {
               voltaj=voltaj*125.7142857;
               }
               if(voltaj>=1.740 && voltaj<1.750)
               {
               voltaj=voltaj*125.862069;
               }
               if(voltaj>=1.730 && voltaj<1.740)
               {
               voltaj=voltaj*126.0115607;
               }   
               if(voltaj>=1.720 && voltaj<1.730)
               {
               voltaj=voltaj*126.1627907;
               }
               if(voltaj>=1.710 && voltaj<1.720)
               {
               voltaj=voltaj*126.3157895;
               }
               if(voltaj>=1.700 && voltaj<1.710)
               {
               voltaj=voltaj*126.4705882;
               }  


 
               if(voltaj>=1.690 && voltaj<1.700)
               {
               voltaj=voltaj*126.6272189;
               }
               if(voltaj>=1.680 && voltaj<1.690)
               {
               voltaj=voltaj*126.7857143;
               }
               if(voltaj>=1.670 && voltaj<1.680)
               {
               voltaj=voltaj*126.9461078;
               }
               if(voltaj>=1.660 && voltaj<1.670)
               {
               voltaj=voltaj*127.1084337;
               }
               if(voltaj>=1.650 && voltaj<1.660)
               {
               voltaj=voltaj*127.2727273;
               }
               if(voltaj>=1.640 && voltaj<1.650)
               {
               voltaj=voltaj*127.4390244;
               }       
               if(voltaj>=1.630 && voltaj<1.640)
               {
               voltaj=voltaj*127.607362;
               }



               if(voltaj>=1.620 && voltaj<1.630)
               {
               voltaj=voltaj*127.7777778;
               }
               if(voltaj>=1.610 && voltaj<1.620)
               {
               voltaj=voltaj*127.9503106;
               }       
               if(voltaj>=1.600 && voltaj<1.610)
               {
               voltaj=voltaj*128.125;
               }         
               if(voltaj>=1.590 && voltaj<1.600)
               {
               voltaj=voltaj*128.3018868;
               }
               if(voltaj>=1.580 && voltaj<1.590)
               {
               voltaj=voltaj*128.4810127;
               }       
               if(voltaj>=1.570 && voltaj<1.580)
               {
               voltaj=voltaj*128.6624204;
               }
               if(voltaj>=1.560 && voltaj<1.570)
               {
               voltaj=voltaj*128.8461538;
               }    


          
               if(voltaj>=1.550 && voltaj<1.560)
               {
               voltaj=voltaj*129.0322581;
               }              
             }
             voltaj=floor(voltaj);

         for(j=0;j<200;j++)
       { 
         set_adc_channel(1);
         delay_us(20); 
         abilgi=read_adc();
         akim=deger*abilgi;
         akare=akim*akim;
         atop=atop+akare;
         delay_us(1970);
       }
       
         amper=atop/100;
         amper=sqrt(amper);
         amper=amper+amper/75.2;
         amper=amper*10;
      printf(lcd_putc,"\f%fV/%0.4fA",voltaj,amper);
      delay_us(100);
         guc=voltaj*amper;
         guc=guc/3600000;
         gtop=gtop+guc;
      printf(lcd_putc,"\n   %0.5fkWh",gtop);
         write_eeprom(0,gtop);
         output_low(pin_c5);
              akim=0;
              amper=0;
              abilgi=0;
              atop=0;
              vkare=0;
              voltaj=0;
              vbilgi=0;
              vtop=0;
        delay_ms(1000);
 }
}




