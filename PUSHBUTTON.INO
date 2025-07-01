// Codtech Embedded Systems Internship
// Task 1: Push Button Counter


const int buttonPin = 2;     // Pin where the push button is connected
int counter = 0;             // Counter variable
int buttonState = 0;         // Current state of button
int lastButtonState = 0;     // Previous state of button

void setup() {
  pinMode(buttonPin, INPUT);     // Set button pin as input
  Serial.begin(9600);            // Start Serial Monitor
  Serial.println("Push Button Counter Started");
  Serial.print("Count: ");
  Serial.println(counter);
}

void loop() {
  buttonState = digitalRead(buttonPin);  // Read the current state of button

  // Detect rising edge: button just pressed
  if (buttonState == HIGH && lastButtonState == LOW) {
    counter++;                             // Increase counter
    Serial.print("Count: ");              // Print updated count
    Serial.println(counter);
    delay(200);                           // Simple debounce
  }

  lastButtonState = buttonState;  // Save the state for next loop
}
