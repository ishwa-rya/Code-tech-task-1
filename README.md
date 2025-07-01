COMPANY: CODTECH IT SOLUTIONS

NAME: Samayamanthula Ishwarya 

INTERN ID:CT04DF2770

DOMAIN: Embedded Systems

DURATION: 4 WEEKS

MENTOR: Neela Santhosh Kumar

DESCRIPTION:

The Push Button Counter is a simple embedded systems project where a digital counter increases each time a button is pressed. It uses a microcontroller like Arduino to read the push button input and display the count on an LCD or OLED screen. A pull-down resistor is used to ensure stable input readings. Debouncing is implemented in code to prevent false triggering. This project helps in understanding digital input, output display interfacing, and basic programming logic. It is commonly used in applications like people counters, product counting systems, and digital scoreboards. It’s an ideal beginner-level project in electronics.

CIRCUIT DIAGRAM:

![file_00000000e9cc622fbb7281ff79c66694](https://github.com/user-attachments/assets/006ea90e-17ca-4084-ab90-83c0447223cd)


CODE:
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// Set the LCD I2C address — common ones are 0x27 or 0x3F
LiquidCrystal_I2C lcd(0x27, 16, 2);  

const int buttonPin = 2;     // Push button connected to digital pin 2
int counter = 0;             // Count value
bool lastButtonState = LOW;
bool currentButtonState;
unsigned long lastDebounceTime = 0;
unsigned long debounceDelay = 50; // milliseconds

void setup() {
  pinMode(buttonPin, INPUT);
  lcd.begin();
  lcd.backlight();

  lcd.setCursor(0, 0);
  lcd.print("Count: 0");
}

void loop() {
  int reading = digitalRead(buttonPin);

  if (reading != lastButtonState) {
    lastDebounceTime = millis();  // reset debounce timer
  }

  if ((millis() - lastDebounceTime) > debounceDelay) {
    if (reading == HIGH && lastButtonState == LOW) {
      counter++;
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Count: ");
      lcd.print(counter);
    }
  }

  lastButtonState = reading;
}

OUT PUT:

![file_000000008eb061f69ee4894b58bdc485](https://github.com/user-attachments/assets/02bbe4a5-acec-476a-9b06-065512ceba36)

WORKING DEMO:

https://youtu.be/hIQgd8ydFac?si=n8fogsGnqSqnytBo
