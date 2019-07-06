void morseToBeep (char *morseSymbols) {
  
    // Generate beeps based on morse code
    for (int i=0; morseSymbols[i] != '\0'; i++) {

        digitalWrite(messageDigitalPin, HIGH);

        if (morseSymbols[i] == '!') {
            digitalWrite(messageDigitalPin, LOW);
            delay(period * 7);
            return;
        }
        
        if (morseSymbols[i] == '*')
            delay(period);
        if (morseSymbols[i] == '-')
            delay(period * 3);
            
        digitalWrite(messageDigitalPin, LOW);

        delay(period);
    }
    
    delay(period * 3); 
}

char *asciiToMorse(char input) {

    switch (input) {

        // Alphabet

        case 'A':
        case 'a':
            return "*-";

        case 'B':
        case 'b':
            return "-***";

        case 'C':
        case 'c':
            return "-*-*";

        case 'D':
        case 'd':
            return "-**";

        case 'E':
        case 'e':
            return "*";

        case 'F':
        case 'f':
            return "**-*";

        case 'G':
        case 'g':
            return "--*";

        case 'H':
        case 'h':
            return "****";

        case 'I':
        case 'i':
            return "**";

        case 'J':
        case 'j':
            return "*---";

        case 'K':
        case 'k':
            return "-*-";

        case 'L':
        case 'l':
            return "*-**";

        case 'M':
        case 'm':
            return "--";

        case 'N':
        case 'n':
            return "-*";

        case 'O':
        case 'o':
            return "---";

        case 'P':
        case 'p':
            return "*--*";

        case 'Q':
        case 'q':
            return "--*-";

        case 'R':
        case 'r':
            return "*-*";

        case 'S':
        case 's':
            return "***";

        case 'T':
        case 't':
            return "-";

        case 'U':
        case 'u':
            return "**-";

        case 'V':
        case 'v':
            return "***-";

        case 'W':
        case 'w':
            return "*--";

        case 'X':
        case 'x':
            return "-**-";

        case 'Y':
        case 'y':
            return "-*--";

        case 'Z':
        case 'z':
            return "--**";

        // Numbers

        case '1':
            return "*----";

        case '2':
            return "**---";

        case '3':
            return "***--";

        case '4':
            return "****-";

        case '5':
            return "*****";

        case '6':
            return "-****";

        case '7':
            return "--***";

        case '8':
            return "---**";

        case '9':
            return "----*";

        case '0':
            return "-----";

        // Special characters

        case ' ':
            return "!";
        
        case ',':
            return "--*--";

        case '.':
            return "*-*-*-";

        case '?':
            return "**--**";

        case '"':
            return "*-**-*";

        case ':':
            return "---***";

        case '\'':
            return "*----*";

        case '-':
            return "-****-";

        case '/':
            return "-**-*";

        case '(':
            return "-*--*";

        case ')':
            return "-*--*-";
    }
}

void morseBeep() {

    // Signal being received
    if (Serial.available() > 0) {
      
        // Change LED's status
        digitalWrite(statusDigitalPin, HIGH);
        digitalWrite(errorDigitalPin, LOW);
      
        incomingByte = Serial.read();

        // Filter unwanted chars and print output
        if (incomingByte != 10) {
            
            Serial.print("Input: ");
            Serial.print(incomingByte, DEC);
            Serial.print(" Output: ");
            Serial.print(asciiToMorse(incomingByte));
            Serial.println("");

            morseToBeep(asciiToMorse(incomingByte));
        }
    }

    // No signal being received
    else {
        
        // Change LED's status
        digitalWrite(statusDigitalPin, LOW);
        digitalWrite(errorDigitalPin, HIGH);
    }
}
