#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2); // Dirección I2C de la pantalla LCD
const int buttonPin1 = 4;           // Pin al que está conectado el botón 1 NEXT
const int buttonPin2 = 3;           // Pin al que está conectado el botón 2 BACK
const int buttonPin3 = 2;           // Pin al que está conectado el botón 3 (para reiniciar el contador)
int counter = 1;                    // Contador inicializado en 0
int lastButtonState1 = LOW;         // Estado anterior del botón 1
int currentButtonState1 = LOW;      // Estado actual del botón 1
int lastButtonState2 = LOW;         // Estado anterior del botón 2
int currentButtonState2 = LOW;      // Estado actual del botón 2
int lastButtonState3 = LOW;         // Estado anterior del botón 3
int currentButtonState3 = LOW;      // Estado actual del botón 3

void setup() {
  lcd.init();
  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print("Contador:");
  lcd.setCursor(0, 1);
  lcd.print(counter);
  
  pinMode(buttonPin1, INPUT);
  pinMode(buttonPin2, INPUT);
  pinMode(buttonPin3, INPUT);
}

void loop() {
  currentButtonState1 = digitalRead(buttonPin1);
  currentButtonState2 = digitalRead(buttonPin2);
  currentButtonState3 = digitalRead(buttonPin3);

  if (currentButtonState1 == HIGH && lastButtonState1==LOW){
    delay(50);
    if (counter < 13)
    {
      counter++;
      lcd.setCursor(0,1);
      lcd.print("                "); // Limpiar la línea
      lcd.setCursor(0, 1);
      lcd.print(counter);
    }
  }

  if (currentButtonState2 == HIGH && lastButtonState2 == LOW) {
    delay(50); // Anti-rebote
    if (counter > 1) {
      counter--;
      lcd.setCursor(0, 1);
      lcd.print("                "); // Limpiar la línea
      lcd.setCursor(0, 1);
      lcd.print(counter);
    } 
  }

  if (currentButtonState3 == HIGH && lastButtonState3 == LOW) {
    delay(50); // Anti-rebote
    counter = 1;
    lcd.setCursor(0, 1);
    lcd.print("                "); // Limpiar la línea
    lcd.setCursor(0, 1);
    lcd.print(counter);
    }

    lastButtonState1 = currentButtonState1;
    lastButtonState2 = currentButtonState2;
    lastButtonState3 = currentButtonState3;
}