# SetWifiCredentials

Arduino Library to avoid having WiFi SSID and password hardcoded in the code.
It reads two files from an EEPROM and set variables to establish a connection.
The expected file structure looks as follows:

- /
    - ssid.txt
    - pw.txt

Where `ssid.txt` contains the SSID of a WiFi network and the `pw.txt` contains the password of that WiFi.