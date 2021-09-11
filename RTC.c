#include "RTC.h"

const d_Second=0;
const d_Minute=1;
const d_Hour=2;
const d_Day=3;
const d_Date=4;
const d_Month=5;
const d_Year=6;
const d_control=7;
const dir_ds1307=0b11010000;




void Set_control_s()
{
char tempi;


  Soft_I2C_Start();
  Soft_I2C_Write(dir_ds1307  & 0b11111110);
  Soft_I2C_Write(d_control);
  Soft_I2C_Write(0b00010000);
  Soft_I2C_Stop();

}



char Read_Second_s()
{
char leido;

 Soft_I2C_Start();
 Soft_I2C_Write(dir_ds1307  & 0b11111110);
 Soft_I2C_Write(d_Second);

 Soft_I2C_Start();

 Soft_I2C_Write(dir_ds1307  | 0b00000001);

 leido= (Bcd2Dec(Soft_I2C_Read(0))) & 0b01111111;

 Soft_I2C_Stop();

return (leido);

}

char Read_Minute_s()
{
char leido;
 Soft_I2C_Start();
 Soft_I2C_Write(dir_ds1307  & 0b11111110);
 Soft_I2C_Write(d_Minute);
 Soft_I2C_Start();
 Soft_I2C_Write(dir_ds1307  | 0b00000001);
 leido= Bcd2Dec(Soft_I2C_Read(0)) & 0b01111111;
 Soft_I2C_Stop();
return (leido);

}

char Read_Day_s()
{
char leido;

 Soft_I2C_Start();
 Soft_I2C_Write(dir_ds1307  & 0b11111110);
 Soft_I2C_Write(d_Day);

 Soft_I2C_Start();

 Soft_I2C_Write(dir_ds1307  | 0b00000001);

 leido= (Bcd2Dec(Soft_I2C_Read(0))) & 0b000001111;

 Soft_I2C_Stop();

return (leido);

}

char Read_Hour_s()
{
char leido;

 Soft_I2C_Start();
 Soft_I2C_Write(dir_ds1307  & 0b11111110);
 Soft_I2C_Write(d_Hour);

 Soft_I2C_Start();

 Soft_I2C_Write(dir_ds1307  | 0b00000001);

 leido= (Bcd2Dec(Soft_I2C_Read(0))) & 0b001111111;

 Soft_I2C_Stop();

return (leido);

}
char Read_Date_s()
{
char leido;

 Soft_I2C_Start();
 Soft_I2C_Write(dir_ds1307  & 0b11111110);
 Soft_I2C_Write(d_Date);
 Soft_I2C_Start();

 Soft_I2C_Write(dir_ds1307  | 0b00000001);

 leido= (Bcd2Dec(Soft_I2C_Read(0))) & 0b00111111;
 Soft_I2C_Stop();

return (leido);

}
char Read_Month_s()
{
char leido;

 Soft_I2C_Start();
 Soft_I2C_Write(dir_ds1307  & 0b11111110);
 Soft_I2C_Write(d_Month);
 Soft_I2C_Start();
 Soft_I2C_Write(dir_ds1307  | 0b00000001);
 leido= (Bcd2Dec(Soft_I2C_Read(0))) & 0b000111111;

 Soft_I2C_Stop();

return (leido);

}
char Read_Year_s()
{
char leido;

 Soft_I2C_Start();
 Soft_I2C_Write(dir_ds1307  & 0b11111110);
 Soft_I2C_Write(d_Year);
 Soft_I2C_Start();
 Soft_I2C_Write(dir_ds1307  | 0b00000001);
 leido= (Bcd2Dec(Soft_I2C_Read(0))) & 0b111111111;

 Soft_I2C_Stop();

return (leido);

}

void Set_Second_s()
{
char tempi;

tempi=Dec2Bcd(ds1307._Second);
tempi.b7=0;

  Soft_I2C_Start();
  Soft_I2C_Write(dir_ds1307  & 0b11111110);
  Soft_I2C_Write(d_Second);
  Soft_I2C_Write(tempi);
  Soft_I2C_Stop();

}

void Set_Minute_s()
{
char tempi;

tempi=Dec2Bcd(ds1307._Minute);
tempi.b7=0;

  Soft_I2C_Start();
  Soft_I2C_Write(dir_ds1307  & 0b11111110);
  Soft_I2C_Write(d_Minute);
  Soft_I2C_Write(tempi);
  Soft_I2C_Stop();

}

void Set_Hour_S()
{
char tempi;

tempi=Dec2Bcd(ds1307._Hour);
tempi.b7=0;
tempi.b6=0;  //para 24 Hours

  Soft_I2C_Start();
  Soft_I2C_Write(dir_ds1307  & 0b11111110);
  Soft_I2C_Write(d_Hour);
  Soft_I2C_Write(tempi);
  Soft_I2C_Stop();

}
void Set_Day_s()
{
char tempi;

tempi=Dec2Bcd(ds1307._Day);
tempi.b7=0;
tempi.b6=0;
tempi.b5=0;
tempi.b4=0;
tempi.b3=0;


  Soft_I2C_Start();
  Soft_I2C_Write(dir_ds1307  & 0b11111110);
  Soft_I2C_Write(d_Day);
  Soft_I2C_Write(tempi);
  Soft_I2C_Stop();

}
void Set_Date_s()
{
char tempi;

tempi=Dec2Bcd(ds1307._Date);
tempi.b7=0;
tempi.b6=0;

  Soft_I2C_Start();
  Soft_I2C_Write(dir_ds1307  & 0b11111110);
  Soft_I2C_Write(d_Date);
  Soft_I2C_Write(tempi);
  Soft_I2C_Stop();

}
void Set_Month_s()
{
char tempi;

tempi=Dec2Bcd(ds1307._Month);
tempi.b7=0;

  Soft_I2C_Start();
  Soft_I2C_Write(dir_ds1307  & 0b11111110);
  Soft_I2C_Write(d_Month);
  Soft_I2C_Write(tempi);
  Soft_I2C_Stop();

}
void Set_Year_s()
{
char tempi;

tempi=Dec2Bcd(ds1307._Year);



  Soft_I2C_Start();
  Soft_I2C_Write(dir_ds1307  & 0b11111110);
  Soft_I2C_Write(d_Year);
  Soft_I2C_Write(tempi);
  Soft_I2C_Stop();

}

void Set_All_s()
{
Set_control_s();
Set_Second_s();
Set_Minute_s();
Set_Hour_s();
Set_Day_s();
Set_Month_s();
Set_Date_s();
Set_Year_s();
 }

void Read_All_s()
{
ds1307._Second=Read_Second_s();
ds1307._Minute=Read_Minute_s();
ds1307._Day=Read_Day_s();
ds1307._Date=Read_Date_s();
ds1307._Hour=Read_Hour_s();
ds1307._Month=Read_Month_s();
ds1307._Year=Read_Year_s();

}

void Clock_init()
{
I2C1_Init(100000);
}


void Clock_init_s()
{
Soft_I2C_Init();
}
