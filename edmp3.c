#include<reg52.h> 
#define uchar unsigned char 
#define uint unsigned int 
   
uchar    Music1[7]={0x7e,0x05,0x42,0x00,0x01,0x46,0xef}; 
uchar    Music2[7]={0x7e,0x05,0x42,0x00,0x02,0x45,0xef}; 
uchar    Music3[7]={0x7e,0x05,0x42,0x00,0x03,0x44,0xef}; 
uchar    Music4[7]={0x7e,0x05,0x42,0x00,0x04,0x43,0xef}; 
 
uchar a; 
 
void Send_dat(uchar dat); 
void Play(uchar m,uchar d); 
void delay(uint x) 
{ 
uint i,j; 
for(i=x;i>0;i--) 
  for(j=600;j>0;j--); 
} 
 
void Uart_init() 
{ 
  TMOD=0x20; 
  TH1=0xfd;//fd 
  TL1=0xfd;//fd 
  TR1=1; 
  SM0=0; 
  SM1=1; 
  REN=1; 
  EA=1; 
  ES=1; 
  PCON=0x00; 
} 
 
void main() 
{ 
uchar i; 

Uart_init();//串口初始化 
delay(500); 
  while(1) 
  { 
 
  Play(0x09,0x4e); 
   
//Send_dat(0X7E);     
while(1); 
 
 
  } 
} 
 
void Send_dat(uchar dat) 
{ 
SBUF=dat; 
while(!TI); 
TI=0; 
} 
 
void Play(uchar m,uchar d) 
{ 
Send_dat(0X7E); 
Send_dat(0X05); 
Send_dat(0X42); 
Send_dat(0X00); 
Send_dat(m); 
Send_dat(d); 
Send_dat(0XEF); 
} 
 
void serial() interrupt 4 
{ 
  a=SBUF; 
  RI=0; 
} 