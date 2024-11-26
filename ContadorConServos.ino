#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <Servo.h> // Librería para los servos

LiquidCrystal_I2C lcd(0x27, 16, 2); // Dirección I2C de la pantalla LCD
const int buttonPin1 = 2;           // Pin al que está conectado el botón 1
const int buttonPin2 = 3;           // Pin al que está conectado el botón 2
const int buttonPin3 = 1;           // Pin al que está conectado el botón 3 (para reiniciar el contador)
int counter = 1;                    // Contador inicializado en 1
int lastButtonState1 = LOW;         // Estado anterior del botón 1
int currentButtonState1 = LOW;      // Estado actual del botón 1
int lastButtonState2 = LOW;         // Estado anterior del botón 2
int currentButtonState2 = LOW;      // Estado actual del botón 2
int lastButtonState3 = LOW;         // Estado anterior del botón 3
int currentButtonState3 = LOW;      // Estado actual del botón 3

Servo servoPin9; // Servo conectado al pin 9
Servo servoPin6; // Servo conectado al pin 6
Servo servoPin5; // Servo Futaba conectado al pin 5

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

  // Inicializar los servos y moverlos a 0°
  servoPin9.attach(9);
  servoPin6.attach(6);
  servoPin5.attach(5);

  servoPin9.write(0); 
  servoPin6.write(0); 
  servoPin5.write(0);
}

void loop() {
  currentButtonState1 = digitalRead(buttonPin1);
  currentButtonState2 = digitalRead(buttonPin2);
  currentButtonState3 = digitalRead(buttonPin3);

  if (currentButtonState1 == HIGH && lastButtonState1 == LOW) {
    delay(50); // Anti-rebote
    if (counter < 13) {
      counter++;
      lcd.setCursor(0, 1);
      lcd.print("                "); // Limpiar la línea
      lcd.setCursor(0, 1);
      lcd.print(counter);
      controlServos(); // Llamar función para controlar los servos
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
      controlServos(); // Llamar función para controlar los servos
    }
  }

  if (currentButtonState3 == HIGH && lastButtonState3 == LOW) {
    delay(50); // Anti-rebote
    counter = 0; // Cambiar el contador a 0
    lcd.setCursor(0, 1);
    lcd.print("                "); // Limpiar la línea
    lcd.setCursor(0, 1);
    lcd.print(counter);
    
    // Mover los servos a 0°
    servoPin9.write(0); 
    servoPin6.write(0); 
    servoPin5.write(0);
  }

  lastButtonState1 = currentButtonState1;
  lastButtonState2 = currentButtonState2;
  lastButtonState3 = currentButtonState3;
}

void controlServos() {
  switch (counter) {
    case 4:
      servoPin6.write(40); // Servo en pin 6 a 40°
      break;
    case 5:
      servoPin9.write(180); // Servo en pin 9 a 180°
      break;
    case 6:
      servoPin6.write(0);  // Servo en pin 6 a 0°
      servoPin5.write(22); // Servo en pin 5 a 22°
      break;
    case 7:
      servoPin9.write(90); // Servo en pin 9 a -90° (mover a 90° para simular)
      break;
    case 8:
      servoPin9.write(0);  // Servo en pin 9 a 0°
      break;
    case 9:
      servoPin9.write(90); // Servo en pin 9 a 90°
      break;
    case 10:
      servoPin5.write(158); // Servo en pin 5 a -22° (mover a 158° para simular)
      break;
    case 11:
      servoPin9.write(180); // Servo en pin 9 a 180°
      break;
    case 12:
      servoPin9.write(90); // Servo en pin 9 a -90° (mover a 90° para simular)
      break;
    case 13:
      servoPin9.write(0);  // Servo en pin 9 a 0°
      break;
    default:
      break;
  }
}
