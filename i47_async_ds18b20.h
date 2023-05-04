#ifndef __I47_ASYNC_DS18B20__
#define __I47_ASYNC_DS18B20__

/*
THư viện ds18b20 bất động bộ cho arduino
Người viết: DaoNguyen IoT47
Website: Iot47.com
Email: daonguyen20798@gmail.com
*/

#define TIME       2
#define OW_OUTPUT1 0
#define OW_OUTPUT0 1
#define OW_INPUT   2
#define OW_READ_L  3
#define OW_READ_H  4
#define OW_END 255

typedef void (*ds18b20_callback_t)(float t);
ds18b20_callback_t ds18b20_read_done;

int ow_cpu=0;
uint8_t ow_byte_low;
uint8_t ow_byte_high;
const uint8_t ds18b20_protocol[]=
{
  //--------Reset onewrite---------------
  OW_OUTPUT1,500/TIME,
  OW_OUTPUT0,500/TIME,
  OW_OUTPUT1,20/TIME,
  OW_INPUT,100/TIME,
  OW_OUTPUT1,400/TIME,
  //---Write CC SKIP ROM-----------------
  OW_OUTPUT0,60/TIME,//bit0
  OW_OUTPUT1,6/TIME,
  OW_OUTPUT0,60/TIME,//bit0
  OW_OUTPUT1,6/TIME,
  
  OW_OUTPUT0,6/TIME,//bit1
  OW_OUTPUT1,60/TIME,
  OW_OUTPUT0,6/TIME,//bit1
  OW_OUTPUT1,60/TIME,
  
  OW_OUTPUT0,60/TIME,//bit0
  OW_OUTPUT1,6/TIME,
  OW_OUTPUT0,60/TIME,//bit0
  OW_OUTPUT1,6/TIME,
  
  OW_OUTPUT0,6/TIME,//bit1
  OW_OUTPUT1,60/TIME,
  OW_OUTPUT0,6/TIME,//bit1
  OW_OUTPUT1,60/TIME,
  //---Write 44--------------------------
  OW_OUTPUT0,60/TIME,//bit0
  OW_OUTPUT1,6/TIME,
  OW_OUTPUT0,60/TIME,//bit0
  OW_OUTPUT1,6/TIME,
  
  OW_OUTPUT0,6/TIME,//bit1
  OW_OUTPUT1,60/TIME,
  OW_OUTPUT0,60/TIME,//bit0
  OW_OUTPUT1,6/TIME,
  
  OW_OUTPUT0,60/TIME,//bit0
  OW_OUTPUT1,6/TIME,
  OW_OUTPUT0,60/TIME,//bit0
  OW_OUTPUT1,6/TIME,
  
  OW_OUTPUT0,6/TIME,//bit1
  OW_OUTPUT1,60/TIME,
  OW_OUTPUT0,60/TIME,//bit0
  OW_OUTPUT1,6/TIME,
  //--------Reset onewrite---------------
  OW_OUTPUT1,500/TIME,
  OW_OUTPUT0,500/TIME,
  OW_OUTPUT1,20/TIME,
  OW_INPUT,100/TIME,
  OW_OUTPUT1,400/TIME,
  //---Write CC SKIP ROM-----------------
  OW_OUTPUT0,60/TIME,//bit0
  OW_OUTPUT1,6/TIME,
  OW_OUTPUT0,60/TIME,//bit0
  OW_OUTPUT1,6/TIME,
  
  OW_OUTPUT0,6/TIME,//bit1
  OW_OUTPUT1,60/TIME,
  OW_OUTPUT0,6/TIME,//bit1
  OW_OUTPUT1,60/TIME,
  
  OW_OUTPUT0,60/TIME,//bit0
  OW_OUTPUT1,6/TIME,
  OW_OUTPUT0,60/TIME,//bit0
  OW_OUTPUT1,6/TIME,
  
  OW_OUTPUT0,6/TIME,//bit1
  OW_OUTPUT1,60/TIME,
  OW_OUTPUT0,6/TIME,//bit1
  OW_OUTPUT1,60/TIME,
  //---Write BE-----------------
  OW_OUTPUT0,60/TIME,//bit0
  OW_OUTPUT1,6/TIME,
  OW_OUTPUT0,6/TIME,//bit1
  OW_OUTPUT1,60/TIME,
  OW_OUTPUT0,6/TIME,//bit1
  OW_OUTPUT1,60/TIME,
  OW_OUTPUT0,6/TIME,//bit1
  OW_OUTPUT1,60/TIME,
  OW_OUTPUT0,6/TIME,//bit1
  OW_OUTPUT1,60/TIME,
  OW_OUTPUT0,6/TIME,//bit1
  OW_OUTPUT1,60/TIME,
  OW_OUTPUT0,60/TIME,//bit0
  OW_OUTPUT1,6/TIME,
  OW_OUTPUT0,6/TIME,//bit1
  OW_OUTPUT1,60/TIME,
  //--Read byte thap-----------
  OW_OUTPUT0,6/TIME, //dọc 1 bit 
  OW_READ_L,0x01,60/TIME,
  OW_OUTPUT1,10/TIME,

  OW_OUTPUT0,6/TIME, //dọc 1 bit 
  OW_READ_L,0x02,60/TIME,
  OW_OUTPUT1,10/TIME,

  OW_OUTPUT0,6/TIME, //dọc 1 bit 
  OW_READ_L,0x04,60/TIME,
  OW_OUTPUT1,10/TIME,

  OW_OUTPUT0,6/TIME, //dọc 1 bit 
  OW_READ_L,0x08,60/TIME,
  OW_OUTPUT1,10/TIME,

  OW_OUTPUT0,6/TIME, //dọc 1 bit 
  OW_READ_L,0x10,60/TIME,
  OW_OUTPUT1,10/TIME,

  OW_OUTPUT0,6/TIME, //dọc 1 bit 
  OW_READ_L,0x20,60/TIME,
  OW_OUTPUT1,10/TIME,

  OW_OUTPUT0,6/TIME, //dọc 1 bit 
  OW_READ_L,0x40,60/TIME,
  OW_OUTPUT1,10/TIME,

  OW_OUTPUT0,6/TIME, //dọc 1 bit 
  OW_READ_L,0x80,60/TIME,
  OW_OUTPUT1,10/TIME,
  //--Read byte cao-----------
  OW_OUTPUT0,6/TIME, //dọc 1 bit 
  OW_READ_H,0x01,60/TIME,
  OW_OUTPUT1,10/TIME,

  OW_OUTPUT0,6/TIME, //dọc 1 bit 
  OW_READ_H,0x02,60/TIME,
  OW_OUTPUT1,10/TIME,

  OW_OUTPUT0,6/TIME, //dọc 1 bit 
  OW_READ_H,0x04,60/TIME,
  OW_OUTPUT1,10/TIME,

  OW_OUTPUT0,6/TIME, //dọc 1 bit 
  OW_READ_H,0x08,60/TIME,
  OW_OUTPUT1,10/TIME,

  OW_OUTPUT0,6/TIME, //dọc 1 bit 
  OW_READ_H,0x10,60/TIME,
  OW_OUTPUT1,10/TIME,

  OW_OUTPUT0,6/TIME, //dọc 1 bit 
  OW_READ_H,0x20,60/TIME,
  OW_OUTPUT1,10/TIME,

  OW_OUTPUT0,6/TIME, //dọc 1 bit 
  OW_READ_H,0x40,60/TIME,
  OW_OUTPUT1,10/TIME,

  OW_OUTPUT0,6/TIME, //dọc 1 bit 
  OW_READ_H,0x80,60/TIME,
  OW_OUTPUT1,10/TIME,
  
  OW_END,
};



#if  IOT47_DS18B20_PIN == 0
#define MACRO_SET   (0x01)
#define MACRO_RESET (~MACRO_SET)
#define MACRO_PORT   PORTD
#define MACRO_DDDR   DDRD
#define MACRO_PIN    PIND

#elif  IOT47_DS18B20_PIN == 1
#define MACRO_SET   (0x02)
#define MACRO_RESET (~MACRO_SET)
#define MACRO_PORT   PORTD
#define MACRO_DDDR   DDRD
#define MACRO_PIN    PIND

#elif  IOT47_DS18B20_PIN == 2
#define MACRO_SET   (0x04)
#define MACRO_RESET (~MACRO_SET)
#define MACRO_PORT   PORTD
#define MACRO_DDDR   DDRD
#define MACRO_PIN    PIND

#elif  IOT47_DS18B20_PIN == 3
#define MACRO_SET   (0x08)
#define MACRO_RESET (~MACRO_SET)
#define MACRO_PORT   PORTD
#define MACRO_DDDR   DDRD
#define MACRO_PIN    PIND

#elif  IOT47_DS18B20_PIN == 4
#define MACRO_SET   (0x10)
#define MACRO_RESET (~MACRO_SET)
#define MACRO_PORT   PORTD
#define MACRO_DDDR   DDRD
#define MACRO_PIN    PIND

#elif  IOT47_DS18B20_PIN == 5
#define MACRO_SET   (0x20)
#define MACRO_RESET (~MACRO_SET)
#define MACRO_PORT   PORTD
#define MACRO_DDDR   DDRD
#define MACRO_PIN    PIND

#elif  IOT47_DS18B20_PIN == 6
#define MACRO_SET   (0x40)
#define MACRO_RESET (~MACRO_SET)
#define MACRO_PORT   PORTD
#define MACRO_DDDR   DDRD
#define MACRO_PIN    PIND

#elif  IOT47_DS18B20_PIN == 7
#define MACRO_SET   (0x80)
#define MACRO_RESET (~MACRO_SET)
#define MACRO_PORT   PORTD
#define MACRO_DDDR   DDRD
#define MACRO_PIN    PIND

#elif  IOT47_DS18B20_PIN == 8
#define MACRO_SET   (0x01)
#define MACRO_RESET (~MACRO_SET)
#define MACRO_PORT   PORTB
#define MACRO_DDDR   DDRB
#define MACRO_PIN    PINB

#elif  IOT47_DS18B20_PIN == 9
#define MACRO_SET   (0x02)
#define MACRO_RESET (~MACRO_SET)
#define MACRO_PORT   PORTB
#define MACRO_DDDR   DDRB
#define MACRO_PIN    PINB

#elif  IOT47_DS18B20_PIN == 10
#define MACRO_SET   (0x04)
#define MACRO_RESET (~MACRO_SET)
#define MACRO_PORT   PORTB
#define MACRO_DDDR   DDRB
#define MACRO_PIN    PINB

#elif  IOT47_DS18B20_PIN == 11
#define MACRO_SET   (0x08)
#define MACRO_RESET (~MACRO_SET)
#define MACRO_PORT   PORTB
#define MACRO_DDDR   DDRB
#define MACRO_PIN    PINB

#elif  IOT47_DS18B20_PIN == 12
#define MACRO_SET   (0x10)
#define MACRO_RESET (~MACRO_SET)
#define MACRO_PORT   PORTB
#define MACRO_DDDR   DDRB
#define MACRO_PIN    PINB

#elif  IOT47_DS18B20_PIN == 13
#define MACRO_SET   (0x20)
#define MACRO_RESET (~MACRO_SET)
#define MACRO_PORT   PORTB
#define MACRO_DDDR   DDRB
#define MACRO_PIN    PINB

#elif  IOT47_DS18B20_PIN == 14
#define MACRO_SET   (0x01)
#define MACRO_RESET (~MACRO_SET)
#define MACRO_PORT   PORTC
#define MACRO_DDDR   DDRC
#define MACRO_PIN    PINC

#elif  IOT47_DS18B20_PIN == 15
#define MACRO_SET   (0x02)
#define MACRO_RESET (~MACRO_SET)
#define MACRO_PORT   PORTC
#define MACRO_DDDR   DDRC
#define MACRO_PIN    PINC

#elif  IOT47_DS18B20_PIN == 16
#define MACRO_SET   (0x04)
#define MACRO_RESET (~MACRO_SET)
#define MACRO_PORT   PORTC
#define MACRO_DDDR   DDRC
#define MACRO_PIN    PINC

#elif  IOT47_DS18B20_PIN == 17
#define MACRO_SET   (0x08)
#define MACRO_RESET (~MACRO_SET)
#define MACRO_PORT   PORTC
#define MACRO_DDDR   DDRC
#define MACRO_PIN    PINC

#elif  IOT47_DS18B20_PIN == 18
#define MACRO_SET   (0x10)
#define MACRO_RESET (~MACRO_SET)
#define MACRO_PORT   PORTC
#define MACRO_DDDR   DDRC
#define MACRO_PIN    PINC

#elif  IOT47_DS18B20_PIN == 19
#define MACRO_SET   (0x20)
#define MACRO_RESET (~MACRO_SET)
#define MACRO_PORT   PORTC
#define MACRO_DDDR   DDRC
#define MACRO_PIN    PINC

#endif

void OW_OUT_H(){MACRO_PORT |= MACRO_SET;  MACRO_DDDR |= MACRO_SET;}
void OW_OUT_L(){MACRO_PORT &= MACRO_RESET;MACRO_DDDR |= MACRO_SET;}
void OW_IN()   {MACRO_PORT |= MACRO_SET;  MACRO_DDDR &= MACRO_RESET;};
uint8_t OW_PIN_VALUE(){return MACRO_PIN&MACRO_SET;}
float getTemp(){return (float)(((uint16_t)ow_byte_high*256+ow_byte_low)>>4) + (0.0625 * (float)(ow_byte_low&0x0F));}
void OW_alarm(int us_chia_2)//2us 1 xung => us max 512 => us nên là bội số của 2
{
  TCNT2 = 0;
  OCR2A = us_chia_2;
  TCCR2B |= (1 << CS21)|(1 << CS20);
}
ISR(TIMER2_COMPA_vect)
{
  TCCR2B = 0;
  if(ds18b20_protocol[ow_cpu] == OW_OUTPUT1)
  {
    OW_OUT_H();
    OW_alarm(ds18b20_protocol[ow_cpu+1]);
    ow_cpu+=2;
  }
  else if(ds18b20_protocol[ow_cpu] == OW_OUTPUT0)
  {
    OW_OUT_L();
    OW_alarm(ds18b20_protocol[ow_cpu+1]);
    ow_cpu+=2;
  }
  else if(ds18b20_protocol[ow_cpu] == OW_INPUT)
  {
    OW_IN();
    OW_alarm(ds18b20_protocol[ow_cpu+1]);
    ow_cpu+=2;
  }
  else if(ds18b20_protocol[ow_cpu] == OW_READ_L)
  {
    OW_IN();
    if(OW_PIN_VALUE() != 0)ow_byte_low|=ds18b20_protocol[ow_cpu+1];
    OW_alarm(ds18b20_protocol[ow_cpu+2]);
    ow_cpu+=3;
  }
  else if(ds18b20_protocol[ow_cpu] == OW_READ_H)
  {
    OW_IN();
    if(OW_PIN_VALUE() != 0)ow_byte_high|=ds18b20_protocol[ow_cpu+1];
    OW_alarm(ds18b20_protocol[ow_cpu+2]);
    ow_cpu+=3;
  }
  else if(ds18b20_protocol[ow_cpu] == OW_END)
  {
    ow_cpu = -1;
    if(ds18b20_read_done!=0)ds18b20_read_done(getTemp());
  }
}
char ds18b20_read()
{
  if(ow_cpu == (-1))
  {
    ow_cpu = 0;
    ow_byte_low = 0;
    ow_byte_high= 0;
    OW_OUT_H();
    OW_alarm(100); //running
    return 1; //start read
  }
  return 0; //busy
}
float ds18b20_read_and_wait_finish()
{
    ow_cpu = 0;
    ow_byte_low = 0;
    ow_byte_high= 0;
    OW_OUT_H();
    OW_alarm(100); //running
    uint32_t t = millis();
    while(ow_cpu != (-1)) //chờ đọc xong
    {
      if( millis() - t > 100)return -1;
    }
    return getTemp();
}
void ds18b20_begin(ds18b20_callback_t ds18b20_callback)
{
  //khởi tạo timer2
  TCCR2A = 0;// đặt toàn bộ thanh ghi TCCR2A thành 0 
  TCCR2B = 0;// tương tự cho TCCR2B 
  TCNT2 = 0;// khởi tạo giá trị bộ đếm thành 0 
  TCCR2B |= (1 << CS21)|(1 << CS20);   //chia 32
  TIMSK2 |= (1 << OCIE2A); 
   
  ow_cpu =-1;
  ds18b20_read_done = ds18b20_callback;
}
void ds18b20_begin()
{
  //khởi tạo timer2
  TCCR2A = 0;// đặt toàn bộ thanh ghi TCCR2A thành 0 
  TCCR2B = 0;// tương tự cho TCCR2B 
  TCNT2 = 0;// khởi tạo giá trị bộ đếm thành 0 
  TCCR2B |= (1 << CS21)|(1 << CS20);   //chia 32
  TIMSK2 |= (1 << OCIE2A); 
   
  ow_cpu =-1;
  ds18b20_read_done = 0;
}

#endif
