#include <Arduino.h>
#include <MicroOscSlip.h>
#include <FastLED.h>

#define MA_BROCHE_ANGLE 32
CRGB pixelAtom;
void setup() {
  Serial.begin(115200);//toujours 115200 dans le cours jamais autre chose
  FastLED.addLeds<WS2812, 27, GRB>(&pixelAtom, 1);
  pixelAtom = CRGB(250,250,250); // BLANC
}


MicroOscSlip<128> monOsc(&Serial);

void loop()

{
  int maLectureAngle;
   int mabrocheAngle = analogRead(MA_BROCHE_ANGLE);
   monOsc.sendInt("/light", mabrocheAngle);
   delay(20);
  if (mabrocheAngle> 1300){
    pixelAtom = CRGB(255,0,0);
  } else if (mabrocheAngle <2600)
  {
   pixelAtom = CRGB(0,255,0);
  } else
   {
    pixelAtom =CRGB(0,0,255);
    {
    FastLED.show();
  }
  }
}