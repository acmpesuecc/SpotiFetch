# SpotiFetch
An Arduino project that displays the currently playing spotify song and artist

![image](https://github.com/RazerAds/SpotiFetch/assets/77977360/7459734a-4076-4237-ac5e-6d8fa5a0297b)

## Components Required
- Arduino Uno R3
- Jumper Cables
- Alphanumeric LCD (I've used a 16x2)
- I2C Serial Interface Adapter Module (To connect to the LCD module)

## Instructions
- Download both the arduino file and the python file
- Wire up your Circuit according to the schematic. 
  - I recommend using a breadboard to connect the I2C module to the LCD
  - This ensures a secure connection

<img src="https://github.com/RazerAds/SpotiFetch/assets/77977360/af6f9dc3-a305-42ba-9bd1-2cd0b23c18dd" width="500">

### Arduino IDE
- Connect your Arduino Uno to your PC and open up the Arduino IDE
- Make note of what COM port your Arduino is using.
  - We will use the same port to transmit data in the python port.
  - In this code, I'm using the port COM7
- To check your I2C address (0x3F in this case), go to File -> Examples -> Wire -> i2C_scanner.
- Dump this code onto your Arduino. 
- Now check the Serial Monitor in Tools -> Serial Monitor.
- It will display your I2C address.
  - Mostly I2C addressses are 0x3F or 0x27.
- Update your I2C address in the arduino_fetcher.ino
- 

## Contributing
Contributions are welcome! If you have any suggestions, bug reports, or feature requests, please open an issue on the GitHub repository. If you would like to contribute code, feel free to fork the repository and submit a pull request.

## License
This project is licensed under the GNU General Public License. Feel free to use, modify, and distribute this code as per the terms of the license.
