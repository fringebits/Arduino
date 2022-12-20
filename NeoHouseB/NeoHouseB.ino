#include <Adafruit_NeoPixel.h>
#include "houes.h"

#define A_DATA_PIN      7  	// this is the data pin connected to the LED strip.  If using WS2801 you also need a clock pin
#define NUM_LIGHTS    100 	// change this for the number of LEDs in the strip

// Create an instance of the Adafruit_NeoPixel class called "leds".
// RGB color order, 800 KHz
Adafruit_NeoPixel A_leds = Adafruit_NeoPixel( NUM_LIGHTS, A_DATA_PIN, NEO_RGB + NEO_KHZ800 );

#define NUM_HOUSES_A  10

#define FIRST_HOUSE   0
#define NUM_HOUSES    NUM_HOUSES_A

House A_houses[NUM_HOUSES_A] = { 
    House( 8, 3),
    House(14, 3),
    House(21, 3),  
    House(28, 3),
    House(41, 3),  

    House(49, 3),
    House(56, 3),
    House(73, 3),
    House(85, 3),
    House(97, 3),
};

void update_houses(Adafruit_NeoPixel* leds, House* houses, int count)
{
    leds->clear();
    int last_house = min(count, FIRST_HOUSE + NUM_HOUSES);

    for(int ii=FIRST_HOUSE; ii < last_house; ii++)
    {
        houses[ii].update(leds);
    }

    leds->show();
}

void setup_houses(Adafruit_NeoPixel* leds, House* houses, int count)
{
    leds->begin();
    update_houses(leds, houses, count);
}

void setup()
{
    Serial.begin(57600);  // print for debug

    setup_houses(&A_leds, A_houses, NUM_HOUSES_A);
}

void loop()
{
    update_houses(&A_leds, A_houses, NUM_HOUSES_A);
    
    delay(2000);
}
