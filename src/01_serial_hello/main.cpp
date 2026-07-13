// Exercise 01 — Serial Hello
//
// Simplest UART demo: print a greeting once a second on the ESP32's default
// UART0 (which is the same one the USB-serial bridge is connected to).
// No hardware beyond the ESP32 itself — the Wokwi diagram wires TX/RX
// straight to the serial monitor.

#include <Arduino.h>

void setup() {
    Serial.begin(115200);                  // 115200 baud — matches monitor_speed in platformio.ini
    Serial.println();
    Serial.println("serial-comms: 01_serial_hello online.");
}

void loop() {
    Serial.println("hello, UART!");        // send a line over TX
    delay(1000);                           // fine for a demo; real work later uses millis()
}
