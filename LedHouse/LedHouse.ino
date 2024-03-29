#include <FastLED.h>

#define DATA_PIN      7  	// this is the data pin connected to the LED strip.  If using WS2801 you also need a clock pin
#define NUM_LIGHTS   50 	// change this for the number of LEDs in the strip
#define COLOR_ORDER RGB

#define COLOR_WHITE         CRGB(255, 255, 255)
#define COLOR_AQUA          CRGB(  0, 255, 255)
#define COLOR_ORCHID        CRGB(153, 50,  204) //dark orchid
#define COLOR_YELLOW        CRGB(255, 255,   0) //yellow
#define COLOR_GREEN_SPRING  CRGB(  0, 255, 127) //spring green
#define COLOR_ORANGE        CRGB(255, 165,   0) //orange 
#define COLOR_BLUE_ROYAL    CRGB( 65, 105, 255) //royal blue
#define COLOR_PURPLE_DARK   CRGB( 76,   0, 153) //dark purple
#define COLOR_PINK_HOT      CRGB(255, 105, 180) //hot pink
#define COLOR_GREEN_DARK    CRGB(  0, 128,   0) //dark green 
#define COLOR_RED           CRGB(255,   0,   0) //red

#define HOUSE_COLOR CRGB(255, 145, 25)

CRGB leds[NUM_LIGHTS] = { };

class Range
{
public:
    Range(int _start=0, int _count=0)
        : start(_start)
        , count(_count)
    { }

    int start;
    int count;
};

#define NUM_HOUSES 5
#define FIRST_HOUSE 0
#define LAST_HOUSE 5

Range houses[NUM_HOUSES] = { 
  Range(10, 2),
  Range(19, 3),
  Range(34, 2),  
  Range(39, 2),  
  Range(47, 3)  
};

void setup()
{
  FastLED.addLeds<WS2811, DATA_PIN>(leds, NUM_LIGHTS); //setting up the FastLED
  FastLED.clear();

  for(int ii=FIRST_HOUSE; ii < LAST_HOUSE; ii++)
  {
    for(int jj=0; jj < houses[ii].count; jj++)
    {
      leds[jj + houses[ii].start] = HOUSE_COLOR;
    }
  }
}

void loop()
{
  FastLED.show();
  delay(2000);
}
