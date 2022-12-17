#include <Adafruit_NeoPixel.h>

#define A_DATA_PIN      7  	// this is the data pin connected to the LED strip.  If using WS2801 you also need a clock pin
#define B_DATA_PIN      8  	// this is the data pin connected to the LED strip.  If using WS2801 you also need a clock pin
#define NUM_LIGHTS     50 	// change this for the number of LEDs in the strip
#define COLOR_ORDER RGB

#define CRGB(r,g,b)         ((r << 16) + (g << 8) + b)

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

// Create an instance of the Adafruit_NeoPixel class called "leds".
// RGB color order, 800 KHz
Adafruit_NeoPixel A_leds = Adafruit_NeoPixel( NUM_LIGHTS, A_DATA_PIN, NEO_RGB + NEO_KHZ800 );
Adafruit_NeoPixel B_leds = Adafruit_NeoPixel( NUM_LIGHTS, B_DATA_PIN, NEO_RGB + NEO_KHZ800 );

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

#define NUM_HOUSES_A  5
#define NUM_HOUSES_B  5

#define FIRST_HOUSE   0
#define LAST_HOUSE    5

Range A_houses[NUM_HOUSES_A] = { 
  Range(10, 2),
  Range(19, 3),
  Range(34, 2),  
  Range(39, 2),  
  Range(47, 3)  
};

Range B_houses[NUM_HOUSES_B] = { 
  Range(10, 2),
  Range(19, 3),
  Range(34, 2),  
  Range(39, 2),  
  Range(47, 3)  
};

void setup_houses(Adafruit_NeoPixel* leds, Range* houses, int count)
{
  leds->begin();
  leds->clear();
  int last_house = max(count, LAST_HOUSE);
  for(int ii=FIRST_HOUSE; ii < LAST_HOUSE; ii++)
  {
    for(int jj=0; jj < houses[ii].count; jj++)
    {
      leds->setPixelColor(jj + houses[ii].start, HOUSE_COLOR);
    }
  }
}

void setup()
{
  Serial.begin(57600);  // print for debug

  setup_houses(&A_leds, A_houses, NUM_HOUSES_A);
  setup_houses(&B_leds, B_houses, NUM_HOUSES_B);

  // for(int ii=FIRST_HOUSE; ii < LAST_HOUSE; ii++)
  // {
  //   for(int jj=0; jj < houses[ii].count; jj++)
  //   {
  //     leds.setPixelColor(jj + houses[ii].start), HOUSE_COLOR);
  //   }
  // }
}

void loop()
{
  A_leds.show();
  B_leds.show();
  delay(2000);
}
