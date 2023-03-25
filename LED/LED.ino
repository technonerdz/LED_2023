#include <FastLED.h>

#define LED_PIN     7
#define NUM_LEDS  150

#define BUTTON_JAUNE_PIN 8
#define BUTTON_MAUVE_PIN 9

CRGB leds[NUM_LEDS];

int grey = 50;
int red = 50;

int j = 0;

int buttonState1 = 0;
int buttonState2 = 0;

void setup() {

  pinMode(BUTTON_JAUNE_PIN, INPUT_PULLUP);
  pinMode(BUTTON_MAUVE_PIN, INPUT_PULLUP);

  FastLED.addLeds<WS2812, LED_PIN, GRB>(leds, NUM_LEDS);
  
    for(int i = 0; i < 150; i++){
      leds[i] = CRGB(0, 0, 0);
      FastLED.show();
      delay(10);
  }
}

void loop() {
  for(int i = 0; i < 150; i++){
    buttonState1 = digitalRead(BUTTON_JAUNE_PIN);
    buttonState2 = digitalRead(BUTTON_MAUVE_PIN);

    if(buttonState1 == HIGH) {
      leds[i] = CRGB(255, 100, 0);
      FastLED.show();
      continue;
    }

    if(buttonState2 == HIGH) { 
      leds[i] = CRGB(153, 0, 153);
      FastLED.show();
      continue;
    }

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
