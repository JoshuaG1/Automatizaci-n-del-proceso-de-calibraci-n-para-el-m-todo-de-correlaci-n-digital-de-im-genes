// Libraries
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// Defining global variables

// I2C-LCD Variables
LiquidCrystal_I2C lcd(0x27, 16, 2); // I2C LCD Display

// Buttons Variables
const int buttonNext = 4;           // Button NEXT Pin
const int buttonBack = 3;           // Button BACK Pin
const int buttonHome = 2;           // Button HOME Pin

int lastNextBtnState = LOW;
int lastBackBtnState = LOW;
int lastHomeBtnState = LOW;

int currentNextBtnState = LOW;
int currentBackBtnState = LOW;
int currentHomeBtnState = LOW;

// Control variables
int counter = 1;                    // Contador inicializado en 0

void setup(){
    
    // Initializing the LCD
    lcd.init();
    lcd.backlight();
    lcd.setCursor(0, 0);
    lcd.print("Contador:");
    lcd.setCursor(0, 1);
    lcd.print(counter);
    
    // Initializing the buttons
    pinMode(buttonPin1, INPUT);
    pinMode(buttonPin2, INPUT);
    pinMode(buttonPin3, INPUT);

    // Initializing the Servo 1
    // Initializing the Servo 2
    // Initializing the Servo 3

    // Function pointers point to code instead of data ;)

    // Defining the Array function pointer with forward movements
    void (*forward[])() = {
        step01,
        step02,
        step03,
        step04,
        step05,
        step06,
        step07,
        step08,
        step09,
        step10,
        step11,
        step12,
        step13,
    }

    // Defining the Array function pointer with backward movements
    void (*backward[]) = {
        stepBack01,
        stepBack02,
        stepBack03,
        stepBack04,
        stepBack05,
        stepBack06,
        stepBack07,
        stepBack08,
        stepBack09,
        stepBack10,
        stepBack11,
        stepBack12,
        stepBack13,
    }
}

void loop(){
    
}

