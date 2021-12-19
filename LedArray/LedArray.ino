#include <FastLED.h>

#define DATA_PIN 6  	//this is the data pin connected to the LED strip.  If using WS2801 you also need a clock pin
#define NUM_LIGHTS  50 	//change this for the number of LEDs in the strip
#define COLOR_ORDER RGB

CRGB leds[NUM_LIGHTS];

void setup()
{
  FastLED.addLeds<WS2811, DATA_PIN>(leds, NUM_LIGHTS); //setting up the FastLED
  FastLED.clear();
}

void loop()
{
  int mode = random(0, 4);

  switch(mode)
  {
    case 0: LightAllInSequence(); break;
    case 1: LightOneInSequence(); break;
    case 2: LightTheWholeStrand(); break;
    case 3: RampUpAllRedLights(0, 255); break;
  }
}

void ClearAll()
{
  FastLED.clear();
  delay(2000);
}

void LightAllInSequence()
{
  ClearAll();
  for (int ii = 0; ii < NUM_LIGHTS; ii++)
  {
    //FastLED.clear();
    leds[ii] = CRGB(255,255,255);
    FastLED.show();
    delay(100);
  }
}

void LightOneInSequence()
{
  ClearAll();

  int kDelay = 75;
  
  leds[0] = CRGB::Blue;
  FastLED.show();
  delay(kDelay);
  
  for (int ii = 1; ii < NUM_LIGHTS; ii++)
  {
    leds[ii-1] = CRGB::Black;
    leds[ii] = CRGB::Blue;
    FastLED.show();
    delay(kDelay);
  }
  
  for (int ii = NUM_LIGHTS-2; ii >= 0; ii--)
  {
    leds[ii+1] = CRGB::Black;
    leds[ii] = CRGB::Blue;
    FastLED.show();
    delay(kDelay);
  }
}

void LightTheWholeStrand()
{
  CRGB colors[10] = { 
    CRGB(0,255,255) //aqua
    ,CRGB(153, 50, 204) //dark orchid
    ,CRGB(255,255,0) //yellow
    ,CRGB(0,255,127) //spring green
    ,CRGB(255,165,0) //orange 
    ,CRGB(65,105,255) //royal blue
    ,CRGB(76, 0, 153) //dark purple
    ,CRGB(255,105,180) //hot pink
    ,CRGB(0,128,0) //dark green 
    ,CRGB(255,0,0) //red
  };

  ClearAll();

  for(int jj=0; jj < 5; jj++)
  {
    for(int ii=0; ii < 10; ii++)
    {
      leds[ii + jj * 10] = colors[ii];
    }
  }
  
  FastLED.show();
  delay(3000);
}

void RampUpAllRedLights(int startPower, int finishPower) 
{
  int kPowerStep = 10;
  for(int ii = startPower; ii < finishPower; ii += kPowerStep)
  {
    for(int jj = 0; jj < NUM_LIGHTS; jj++)
    {
        leds[jj] = CRGB(ii, 0, 0);
    }
       
    FastLED.show();
    delay(50); 
  }
}
