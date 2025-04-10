// Button box v0.1 
// https://github.com/NicoHood/HID/wiki/Gamepad-API
// https://github.com/NicoHood/HID/blob/master/examples/Gamepad/Gamepad.ino

//Pin layouts for R3 
// D2 = Button1 -- D3 = Button2 -- D4 = Button3 -- D5 = Button4 
// D6 = Button5 -- D7 = Button6 -- D8 = 2pos toggle pos I -- D9 = 2pos toggle pos II
// D10, D11 = On/Off/On switch 1 
// D12, D13 = On/Off/On switch 2
// A0, A1, 5V = joystick X, Y
// A2 = joystick button
// A3 = on/off sw 2 
// A4 = on/off sw 3
// A5 = on/off sw 1


#include <HID-Project.h> // Include the HID-Project library


// Define joystick pins good
const int joystickXPin = A0; // Joystick X-axis connected to analog pin A0
const int joystickYPin = A1; // Joystick Y-axis connected to analog pin A1
// Define joystick button pin good
const int joystickButtonPin = A2; // Joystick button connected to analog pin A2
// define analog pins for on/off switches good
const int onOffSwitch1Pin = A3; // On/Off switch 1 connected to analog pin A3
const int onOffSwitch2Pin = A4; // On/Off switch 2 connected to analog pin A4
const int onOffSwitch3Pin = A5; // On/Off switch 3 connected to analog pin A5

void setup() {
    // Initialize the digital button pins
    pinMode(2, INPUT_PULLUP); // Button 1 connected to pin D2
    pinMode(3, INPUT_PULLUP); // Button 2 connected to pin D3
    pinMode(4, INPUT_PULLUP); // Button 3 connected to pin D4
    pinMode(5, INPUT_PULLUP); // Button 4 connected to pin D5
    pinMode(6, INPUT_PULLUP); // Button 5 connected to pin D6
    pinMode(7, INPUT_PULLUP); // button 6 connected to pin D7
    pinMode(8, INPUT_PULLUP); // Toggle sw1 connected to pin D8
    pinMode(9, INPUT_PULLUP); // Toggle sw1 connected to pin D9
    pinMode(10, INPUT_PULLUP); // On/Off/On switch 1 connected to pin D10
    pinMode(11, INPUT_PULLUP); // On/Off/On switch 1 connected to pin D11
    pinMode(12, INPUT_PULLUP); // On/Off/On switch 2 connected to pin D12
    pinMode(13, INPUT_PULLUP); // On/Off/On switch 2 connected to pin D13

    // Initialize joystick pins good
    pinMode(joystickXPin, INPUT);
    pinMode(joystickYPin, INPUT);

    // Initialize joystick button pin good
    pinMode(joystickButtonPin, INPUT_PULLUP); // Use INPUT_PULLUP for the butto

    // Start USB communication
    Serial.begin(9600);
    // Start the Gamepad
    Gamepad.begin();
}

void loop() {
    // Check if the button is pressed
    
    // Button 1 good
    if (digitalRead(2) == LOW) { // Button pressed
        Gamepad.press(1); // Press button 1
    } else { // Button released
        Gamepad.release(1); // Release button 1
    }
    // Button 2 good
    if (digitalRead(3) == LOW) { // Button pressed
        Gamepad.press(2); // Press button 2
    } else { // Button released
        Gamepad.release(2); // Release button 2
    }
    // Button 3 good
    if (digitalRead(4) == LOW) { // Button pressed
        Gamepad.press(3); // Press button 3
    } else { // Button released
        Gamepad.release(3); // Release button 3
    }
    // Button 4 good
    if (digitalRead(5) == LOW) { // Button pressed
        Gamepad.press(4); // Press button 4
    } else { // Button released
        Gamepad.release(4); // Release button 4
    }
    // Button 5 good
    if (digitalRead(6) == LOW) { // Button pressed
        Gamepad.press(5); // Press button 5
    } else { // Button released
        Gamepad.release(5); // Release button 5
    }
    // Button 6 good
    if (digitalRead(7) == LOW) { // Button pressed
        Gamepad.press(6); // Press button 6
    } else { // Button released
        Gamepad.release(6); // Release button 6
    }
    // Toggle1 SW1 good
    if (digitalRead(8) == LOW) { // Button pressed
        Gamepad.press(7); // Press Toggle sw1
    } else { // Button released
        Gamepad.release(7); // Release Toggle sw1
    }
    // Toggle1 SW2 good
    if (digitalRead(9) == LOW) { // Button pressed
        Gamepad.press(8); // Press Toggle sw2
    } else { // Button released
        Gamepad.release(8); // Release Toggle sw2
    }
    // Joystick button good
    if (digitalRead(joystickButtonPin) == LOW) { // Button pressed
        Gamepad.press(9); // Press button 9 (or any unused button ID)
    } else { // Button released
        Gamepad.release(9); // Release button 9
    }
    // On/off/on1 SW1 good
    if (digitalRead(10) == LOW) { // Button pressed
        Gamepad.press(11); // Press 
    } else { // Button released
        Gamepad.release(11); // Release 
    }
    // On/off/on1 SW2 good
    if (digitalRead(11) == LOW) { // Button pressed
        Gamepad.press(12); // Press 
    } else { // Button released
        Gamepad.release(12); // Release 
    }
    // On/off/on2 SW1 good
    if (digitalRead(12) == LOW) { // Button pressed
        Gamepad.press(13); // Press 
    } else { // Button released
        Gamepad.release(13); // Release 
    }
    // On/off/on2 SW2 good
    if (digitalRead(13) == LOW) { // Button pressed
        Gamepad.press(14); // Press 
    } else { // Button released
        Gamepad.release(14); // Release 
    }
    //on/offsw1 good
    if (digitalRead(onOffSwitch1Pin) == LOW) { // Button pressed
        Gamepad.press(30); // Press button 10 (or any unused button ID)
    } else { // Button released
        Gamepad.release(30); // Release button 10
    }
    //on/offsw2 good
    if (digitalRead(onOffSwitch2Pin) == LOW) { // Button pressed
        Gamepad.press(31); // Press button 11 (or any unused button ID)
    } else { // Button released
        Gamepad.release(31); // Release button 11
    }
    //on/offsw3 good
    if (digitalRead(onOffSwitch3Pin) == LOW) { // Button pressed
        Gamepad.press(32); // Press button 12 (or any unused button ID)
    } else { // Button released
        Gamepad.release(32); // Release button 12
    }        

    // Read joystick values good
    int joystickX = analogRead(joystickXPin); // Read X-axis
    int joystickY = analogRead(joystickYPin); // Read Y-axis

    // Map joystick values to a range of -127 to 127 (Gamepad API range) good
    int mappedX = map(joystickX, 0, 1023, -127, 127);
    int mappedY = map(joystickY, 0, 1023, -127, 127);

    // Set joystick values in the Gamepad good
    Gamepad.xAxis(mappedX);
    Gamepad.yAxis(mappedY);

    // Send the gamepad state
    Gamepad.write();


    delay(10); // Small delay for stability
}



