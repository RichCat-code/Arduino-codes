#include <DHT11.h>
#include <Wire.h>             // Required for I2C communication
#include <Adafruit_GFX.h>     // Core graphics library
#include <Adafruit_SSD1306.h> // Library for SSD1306 displays

// Unnecessary includes removed for clarity and efficiency:
// #include <Adafruit_GrayOLED.h>
// #include <Adafruit_SPITFT.h>
// #include <Adafruit_SPITFT_Macros.h>
// #include <gfxfont.h>
// #include <splash.h>

//---------------------------------------
DHT11 dht11(7);
#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 32
#define OLED_RESET -1
#define SCREEN_ADR 0x3C //Try 0x3D if this one doesn't work.
#define DHT11_PIN 7

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);
//---------------------------------------

void setup() {
  Serial.begin(9600);

  if (!display.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADR)) { // Typo corrected: SSD1306_SWITCHCAPVCC
    Serial.println(F("SSD1306 Allocation failed."));
    for(;;); // Stay in this infinite loop if display fails to initialize
    // Typo corrected: delay(1000); (This line was also unreachable due to for(;;))
  }

  display.setTextSize(1);
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(0,0);

  display.clearDisplay();
  display.println("Hi! :)");
  display.println("Yippie");
  display.display();

  delay(10000);
  display.clearDisplay(); 
  display.display();
}

void loop() {
    int temperature = dht11.readTemperature();

    if (temperature != DHT11::ERROR_CHECKSUM && temperature != DHT11::ERROR_TIMEOUT) {
        Serial.print("Temperature: ");
        Serial.print(temperature);
        Serial.println(" °C");
    } else {
        Serial.println(DHT11::getErrorString(temperature));
    }
}