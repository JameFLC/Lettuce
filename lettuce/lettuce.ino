#include <FastLED.h>

#define NUM_LEDS 300
#define DATA_PIN 2
#define COLOR_ORDER GRB
#define CHIPSET WS2812B
#define BRIGHTNESS 255
#define VOLT 5
#define MAX_AMPS 1500 // In mili amps

CRGB leds[NUM_LEDS];

int time = 0;

void setup()
{
    // put your setup code here, to run once:
    FastLED.addLeds<CHIPSET, DATA_PIN, COLOR_ORDER>(leds, NUM_LEDS);
    FastLED.setMaxPowerInVoltsAndMilliamps(VOLT, MAX_AMPS);
    FastLED.setBrightness(BRIGHTNESS);
    FastLED.clear();
    FastLED.show();
}

void loop()
{
    for (int i = 0; i < NUM_LEDS; i++)
    {
        leds[i] = CHSV((i * 16 + time) % 255, 255, 255);
    }
    FastLED.show();
    time++;
}
