# PC Power Switch

A very simple Wifi with webserver D1 Mini and Replay hooked up to the power switch on the computer to be able to start and do hard reboot if needed.

Add a `arduino_secrets.h`to the src folder to configure the SSID and Password

```
#ifndef ARDUINO_SECRETS_H
#define ARDUINO_SECRETS_H
#define _SSID "YOUR_SSID"
#define _PASSWORD "YOUR_PASSWORD"
#define _HOSTNAME "PCPowerSwitch"

#endif
```