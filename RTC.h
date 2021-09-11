#ifndef RTC_H
#define RTC_H


extern sfr sbit Soft_I2C_Scl;
extern sfr sbit Soft_I2C_Sda ;
extern sfr sbit Soft_I2C_Scl_Direction ;
extern sfr  sbit Soft_I2C_Sda_Direction ;

typedef struct ds1307_estruct {
  char   _Second,_Minute,_Hour;
  char   _Day,_Date,_Month,_Year;
  char _control;
}Clock;

extern Clock  ds1307;


void Clock_init_s();
void Clock_init();
void Set_Second_s();
void Set_Minute_s();
void Set_Hour_s();
void Set_Day_s();
void Set_Date_s();
void Set_Month_s();
void Set_Year_s();
void Set_control_s();
void Set_All_s();
char Read_Second_s();
char Read_Minute_s();
char Read_Day_s();
char Read_Hour_s();
char Read_Date_S();
char Read_Month_S();
char Read_Year_s();
void Read_All_s();

#endif
