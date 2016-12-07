#include <FastLED.h>

#define DATA_PIN 6  	//this is the data pin connected to the LED strip.  If using WS2801 you also need a clock pin
#define NUM_LIGHTS  50 	//change this for the number of LEDs in the strip
#define NUM_LETTERS 26
#define NUM_EXTRAS  (NUM_LIGHTS - NUM_LETTERS)
#define COLOR_ORDER RGB

CRGB leds[NUM_LIGHTS];

int gLetters[NUM_LETTERS] = {
  1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26
};

int gExtras[NUM_EXTRAS];

void setup()
{
  FastLED.addLeds<WS2811, DATA_PIN>(leds, NUM_LIGHTS); //setting up the FastLED
  FastLED.clear();

  int let = 0;
  int ii = 0;
  int ex = 0;
  for(; ii < NUM_LIGHTS && let < NUM_LETTERS; ii++)
  {
    if (ii == gLetters[let])
    {
      // ii is used by a letter
      let++;
      continue;
    }

    // ii is an unused light
    gExtras[ex++] = ii;
  }
}

void loop()
{
  ClearAll();
  SendOneWord("AB");
}

void ClearAll()
{
  FastLED.clear();
  delay(2000);
}

void ClearAllExtras()
{
  for(int ii=0; ii < NUM_EXTRAS; ii++)
  {
    leds[gExtras[ii]] = CRGB::Black;
  }
}

void SendOneWord(const char* string)
{
  int onDelay = 1500;
  int offDelay = 500;
  int len = strlen(string);
  for(int ii=0; ii < len; ii++)
  {
    int index = string[0] - 'A';
    leds[gLetters[index]] = CRGB::Red;
    delay(onDelay);
    leds[gLetters[index]] = CRGB::Black;
    delay(offDelay);
  }
}

