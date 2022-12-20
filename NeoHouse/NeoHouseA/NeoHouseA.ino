#include "neo_house.h"

#define A_DATA_PIN      7  	// this is the data pin connected to the LED strip.  If using WS2801 you also need a clock pin
#define B_DATA_PIN      6  	// this is the data pin connected to the LED strip.  If using WS2801 you also need a clock pin
#define NUM_LIGHTS     50 	// change this for the number of LEDs in the strip

// Create an instance of the Adafruit_NeoPixel class called "leds".
// RGB color order, 800 KHz
Adafruit_NeoPixel A_leds = Adafruit_NeoPixel( NUM_LIGHTS, A_DATA_PIN, NEO_RGB + NEO_KHZ800 );
Adafruit_NeoPixel B_leds = Adafruit_NeoPixel( NUM_LIGHTS, B_DATA_PIN, NEO_RGB + NEO_KHZ800 );

#define NUM_HOUSES_A  5
#define NUM_HOUSES_B  4

#define FIRST_HOUSE   0
#define LAST_HOUSE    5

House A_houses[NUM_HOUSES_A] = { 
    House(10, 2),
    House(19, 3),
    House(34, 2),  
    House(39, 2),  
    House(47, 3)  
};

House B_houses[NUM_HOUSES_B] = { 
    House(15, 3),
    House(22, 4),
    House(31, 3),  
    House(47, 3)  
};

void update_houses(Adafruit_NeoPixel* leds, House* houses, int count)
{
    leds->clear();
    int last_house = min(count, LAST_HOUSE);

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
    setup_houses(&B_leds, B_houses, NUM_HOUSES_B);
}

void loop()
{
    update_houses(&A_leds, A_houses, NUM_HOUSES_A);
    update_houses(&B_leds, B_houses, NUM_HOUSES_B);
    
    delay(2000);
}
