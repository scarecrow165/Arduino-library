// Button box v0.1 
// https://github.com/NicoHood/HID/wiki/Gamepad-API
// https://github.com/NicoHood/HID/blob/master/examples/Gamepad/Gamepad.ino

//Pin layouts for R3 
// D2 = Button1 -- D3 = Button2 -- D4 = Button3 -- D5 = Button4 
// D6 = Button5 -- D7 = Button6 -- D8 = 2pos toggle pos I -- D9 = 2pos toggle pos II
// D10 =  
// 

#include <HID-Project.h> // Include the HID-Project library

void setup() {
    // Initialize the button pin
    pinMode(2, INPUT_PULLUP); // Button 1 connected to pin D2
    pinMode(3, INPUT_PULLUP); // Button 2 connected to pin D3
    pinMode(4, INPUT_PULLUP); // Button 3 connected to pin D4
    pinMode(5, INPUT_PULLUP); // Button 4 connected to pin D5
    pinMode(6, INPUT_PULLUP); // Button 5 connected to pin D6
    pinMode(7, INPUT_PULLUP); // Toggle sw1 connected to pin D7
    pinMode(8, INPUT_PULLUP); // Toggle sw2 connected to pin D8
    //pinMode(9, INPUT_PULLUP); // RotEnc Pin A  connected to pin D9
    //pinMode(10, INPUT_PULLUP); // RotEnc Pin B  connected to pin D10
    //pinMode(11, INPUT_PULLUP); // RotEnc Button  connected to pin D11

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
    // Button 4 TEST
    if (digitalRead(5) == LOW) { // Button pressed
        Gamepad.press(4); // Press button 4
    } else { // Button released
        Gamepad.release(4); // Release button 4
    }
    // Button 5 TEST
    if (digitalRead(6) == LOW) { // Button pressed
        Gamepad.press(5); // Press button 5
    } else { // Button released
        Gamepad.release(5); // Release button 5
    }
    // Button 6 TEST
    if (digitalRead(7) == LOW) { // Button pressed
        Gamepad.press(6); // Press button 6
    } else { // Button released
        Gamepad.release(6); // Release button 6
    }

    // TO DO - TOGGLE SW - Setup like 2 buttons 
    // Toggle SW1 TEST
    if (digitalRead(8) == LOW) { // Button pressed
        Gamepad.press(7); // Press Toggle sw1
    } else { // Button released
        Gamepad.release(7); // Release Toggle sw1
    }
    // Toggle SW2 TEST
    if (digitalRead(9) == LOW) { // Button pressed
        Gamepad.press(8); // Press Toggle sw2
    } else { // Button released
        Gamepad.release(8); // Release Toggle sw2
    }



    // Send the gamepad state
    Gamepad.write();

    delay(10); // Small delay for stability
}

