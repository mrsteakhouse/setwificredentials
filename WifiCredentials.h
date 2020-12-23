//
// Copyright (c) 2020, Fabian Frey
// All rights reserved.
//

#ifndef SETWIFICREDENTIALS_WIFICREDENTIALS_H
#define SETWIFICREDENTIALS_WIFICREDENTIALS_H

#include "FS.h"
#include "LittleFS.h"

class WifiCredentials
{
private:
    String ssid = "";
    String password = "";

    String readFile(const String &path)
    {
        File f = LittleFS.open(path, "r");
        if (!f)
        {
            Serial.print("Error opening file ");
            Serial.println(path);
            return "";
        }

        String value = f.readString();
        f.close();
        return value;
    }

    bool setWifiCredentials()
    {
        if (!LittleFS.begin())
        {
            if (Serial)
            {
                Serial.println("Error mounting file system");
            }
            return false;
        }

        ssid = readFile("/ssid.txt");
        password = readFile("/pw.txt");

        LittleFS.end();
        return true;
    }

public:
    WifiCredentials()
    {
        setWifiCredentials();
    }

    String getSsid()
    {
        return ssid;
    }

    String getPassword()
    {
        return password;
    }
};


#endif //SETWIFICREDENTIALS_WIFICREDENTIALS_H
