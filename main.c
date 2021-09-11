/*  Name     : main.c
 *  Author   : Ahmed Gaber
 *  Date     : 30-07-21
 */

#include "RTC.h"
sbit Mmc_Chip_Select           at LATC1_bit;
sbit Mmc_Chip_Select_Direction at TRISC1_bit;
sbit Soft_I2C_Scl at portb.B1;
sbit Soft_I2C_Sda at portb.b2;
sbit Soft_I2C_Scl_Direction at trisb.b1;
sbit Soft_I2C_Sda_Direction at trisb.b2 ;
sbit DHT11_Pin at PORTB.B0;
sbit DHT11_DIR at TRISB.B0;


Clock  ds1307;

extern unsigned int DHT11_TMP;
extern unsigned int DHT11_HUM;
extern char DHT11_CHKSM;
char filename[14] = "LOG.TXT";
char Print[] = "31/07/2021 12:15:30 | Temperature = 00.0°C | Humidity = 00.0%  \r\n";
char last_second = 0;


void M_Create_New_File() {
  filename[14] = "LOG.TXT";
  Mmc_Fat_Set_File_Date(2010, 4, 19, 9, 0, 0);
  Mmc_Fat_Assign(&filename, 0xA0);
  Mmc_Fat_Append();
}



void main() {
  ADCON1 |= 0x0F;
  CMCON  |= 7;
  Clock_init_s();
  DHT11_init();
  Delay_ms(10);

  SPI1_Init_Advanced(_SPI_MASTER_OSC_DIV64, _SPI_DATA_SAMPLE_MIDDLE, _SPI_CLK_IDLE_LOW, _SPI_LOW_2_HIGH);


  if (Mmc_Fat_Init() == 0) {

    SPI1_Init_Advanced(_SPI_MASTER_OSC_DIV4, _SPI_DATA_SAMPLE_MIDDLE, _SPI_CLK_IDLE_LOW, _SPI_LOW_2_HIGH);
    M_Create_New_File();
  }
  while(1)
  {
   Dht11_Start();
   DHT11_Read();
   Read_All_s();
   if (last_second != ds1307._Second)
   {
     Print[0] = (((unsigned int)ds1307._Date) / 10) + 48;
     Print[1] = (((unsigned int)ds1307._Date) % 10) + 48;
     Print[3] = (((unsigned int)ds1307._Month) / 10) + 48;
     Print[4] = (((unsigned int)ds1307._Month) % 10) + 48;
     Print[8] = (((unsigned int)ds1307._Year) / 10) + 48;
     Print[9] = (((unsigned int)ds1307._Year) % 10) + 48;
     Print[11] = (((unsigned int)ds1307._Hour) / 10) + 48;
     Print[12] = (((unsigned int)ds1307._Hour) % 10) + 48;
     Print[14] = (((unsigned int)ds1307._Minute) / 10) + 48;
     Print[15] = (((unsigned int)ds1307._Minute) % 10) + 48;
     Print[17] = (((unsigned int)ds1307._Second) / 10) + 48;
     Print[18] = (((unsigned int)ds1307._Second) % 10) + 48;
     Print[36] = ((((DHT11_TMP)) / 100) + 48);
     Print[37] = (((((DHT11_TMP)) % 100)/10) + 48);
     Print[39] = (((((DHT11_TMP)) % 100)%10) + 48);
     Print[56] = ((((DHT11_HUM)) / 100) + 48);
     Print[57] = (((((DHT11_HUM)) % 100)/10) + 48);
     Print[59] = (((((DHT11_HUM)) % 100)%10) + 48);
     Mmc_Fat_Write(Print, 65);
     last_second = ds1307._Second;
   }
  }
}
