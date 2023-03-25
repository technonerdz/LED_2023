#include <FastLED.h>

#define LED_PIN     7
#define NUM_LEDS  150

CRGB leds[NUM_LEDS];

int grey = 70;
int red = 50;

int j = 0;

void setup() {

  FastLED.addLeds<WS2812, LED_PIN, GRB>(leds, NUM_LEDS);
  
    for(int i = 0; i < 150; i++){
      leds[i] = CRGB(0, 0, 0);
      FastLED.show();
      delay(10);
  }
}

void loop() {
  for(int i = 0; i < 150; i++){
    leds[i] = CRGB(125,125,125);
    FastLED.show();
    if(i>=grey){
      leds[i-grey] = CRGB(255,0,0);
      FastLED.show();
    }else{
      leds[i+(150-grey)] = CRGB(255,0,0);
      FastLED.show();
    }
    if(i >= grey+red){
      leds[i-(grey+red)] = CRGB(255,100,0);
      FastLED.show();
    }else{
      leds[i+150-(grey+red)] = CRGB(255,100,0);
      FastLED.show();
    }
    delay(5);
 }
}
