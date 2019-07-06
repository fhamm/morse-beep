char incomingByte = 0;

// Digital pins
const short messageDigitalPin = 13;
const short errorDigitalPin = 7;
const short statusDigitalPin = 6;

// Set the period of the beeps
unsigned int period = 100;

void setup() {

    // Initialize digital pins
    pinMode(messageDigitalPin, OUTPUT);
    pinMode(errorDigitalPin, OUTPUT);
    pinMode(statusDigitalPin, OUTPUT);

    // Open serial port
    Serial.begin(9600);
}

void loop() {
    
    // Translate text to morse beeps
    morseBeep();
}
