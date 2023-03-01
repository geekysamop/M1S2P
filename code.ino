// constants for the button pin and LED pin
const uint8_t BTN_PIN = 2;
const uint8_t LED_PIN = 13;

// variables to keep track of the button and LED states
uint8_t buttonPrevState = LOW;
uint8_t ledState = LOW;

// setup function for initializing pins and serial communication
void setup() {
  // sets the button pin as an input with pull-up resistor
  pinMode(BTN_PIN, INPUT_PULLUP);
  // sets the LED pin as an output
  pinMode(LED_PIN, OUTPUT);
  // starts the serial communication at 9600 baud rate
  Serial.begin(9600);
}

// main loop function to toggle the LED when the button is pressed
void loop() {
  // check if button and LED pins are initialized
  if (BTN_PIN == 0 || LED_PIN == 0) {
    Serial.println("Error: pins not initialized");
    delay(1000);
    return;
  }
  // reads the current state of the button
  uint8_t buttonState = digitalRead(BTN_PIN);


  //if the button state was changed, print the button and led status to the serial moniter
  // prints the button and LED states to the serial monitor

  if (buttonState != buttonPrevState) {
    Serial.print(buttonState);
    Serial.print(buttonPrevState);
    Serial.print(ledState);
    Serial.println("");
  }

  // if the button state has changed, toggle the LED
  if (buttonState != buttonPrevState) {
    ledState = !ledState;
    digitalWrite(LED_PIN, ledState);
  }

  // updates the previous button state
  buttonPrevState = buttonState;

  // delays the loop for half a second
  delay(500);
}
