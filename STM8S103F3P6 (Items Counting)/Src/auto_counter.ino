#include <LiquidCrystal_I2C.h>

#define ldrPin PD2
#define laserPin PD3
#define pbPin PD4
#define LCD_ADDR 0x27

int counter = 0;
int currentState = 0;
int previousState = 0;
int ldr = 0; 
bool pushbutton = false;

LiquidCrystal_I2C(lcd, 0x27, 16, 2);

void setup() {
  Serial_begin(9600);
  device_init();
}

void loop() {
  sensor();
  reset();
  display();
}

void device_init(){
  pinMode(pbPin,INPUT);
  pinMode(ldrPin,INPUT);
  pinMode(laserPin,OUTPUT);
  digitalWrite(laserPin,HIGH);
  lcd_begin();
  lcd_backlight();
}

void sensor(){
  ldr = digitalRead(ldrPin);
  if(ldr == LOW){ currentState = 0; }
  if(ldr == HIGH){ currentState = 1; } 
  Serial_print_s("\nTotal items\t: ");
  if(currentState == 1 && currentState != previousState){ counter = counter + 1; Serial_print_i(counter-1); }
  else{ Serial_print_i(counter-1); }
  delay(1000);
}

void reset(){
  pushbutton = digitalRead(pbPin);
  if(previousState != 0 && pushbutton == HIGH){
    counter = 1;
    pushbutton == true;
  }
}

void display(){
  lcd_setCursor(2, 0);
  lcd_print_s("Total items:");
  lcd_setCursor(7, 1);
  lcd_print_i(counter); 
}
