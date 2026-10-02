#include <Arduino.h> // Wajib untuk PlatformIO
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include "VideoFrame.h" // Dipanggil dari folder 'include'

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_RESET -1

// Pin I2C Default ESP32
#define OLED_SDA 21
#define OLED_SCL 22

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

unsigned long previousMillis = 0;
int currentFrame = 0;

void setup() {
  Serial.begin(115200);
  
  // Disesuaikan untuk ESP32 (SDA = 21, SCL = 22)
  Wire.begin(OLED_SDA, OLED_SCL);

  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    Serial.println(F("OLED not found. Check wiring!"));
    for (;;);
  }

  // Meningkatkan kecepatan I2C ke 800kHz agar animasi lebih mulus
  Wire.setClock(800000); 
  
  display.clearDisplay();
  display.display();
}

void loop() {
  unsigned long currentMillis = millis();

  if (currentMillis - previousMillis >= FRAME_DELAY) {
    previousMillis = currentMillis;

    display.clearDisplay();
    display.drawBitmap(0, 0, video_frames[currentFrame], SCREEN_WIDTH, SCREEN_HEIGHT, WHITE);
    display.display();

    currentFrame++;
    if (currentFrame >= TOTAL_FRAMES) {
      currentFrame = 0;
    }
  }
}
