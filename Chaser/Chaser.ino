/*    
  Chase spews out random colored pixels traveling at random speeds
  down a NeoPixel strip. There are a predetermined number of pixels
  traveling the strip; when one gets to the end a new one is 
  regenerated at the beginning.
  
  Chase requires the Adafruit NeoPixel library.
  https://github.com/adafruit/Adafruit_NeoPixel

  R. Gutmann
  1/4/2021
  
*/

#include <Adafruit_NeoPixel.h>

// hardware
#define PIN 7          // data output to the strip
#define NUM_LEDS 50   // how many pixels in the whole strip

// play with these numbers for different effects
#define NUM_CHASERS 10 // number of pixels on at any one time
#define MIN_DELAY 45    // min dwell time for a chaser
#define MAX_DELAY 45   // max dwell time for a chaser (MAX_DELAY - 1 : see random() )

// Create an instance of the Adafruit_NeoPixel class called "leds".
// RGB color order, 800 KHz
Adafruit_NeoPixel leds = Adafruit_NeoPixel( NUM_LEDS, PIN, NEO_RGB + NEO_KHZ800 );

// data for each chaser ("class" data)
unsigned long moveTimes[ NUM_CHASERS ];  // millis() at which the n-th pixel should move
unsigned int  delays[ NUM_CHASERS ];     // dwell time for n-th chaser at each pixel (ms)
unsigned long colors[ NUM_CHASERS ];     // n-th chaser's color
int positions[ NUM_CHASERS ];            // n-th chaser's current position

void setup()
{
  Serial.begin(57600);  // print for debug
  leds.begin();         // NeoPixel init
  for ( int n = 0; n < NUM_CHASERS; n++ )  // for each chaser
  {
    newChaser( n ); // create new chaser
  }
}  // end of setup()


void loop()
{ 
  unsigned long now = millis();  // current time
  leds.clear();                  // clear all the pixels
  
  for ( int n = 0; n < NUM_CHASERS; n++ )  // for each chaser
  {
    if ( now >= moveTimes[n] ) // time to move or start over
    {
      if ( ++positions[n] >= NUM_LEDS )  // run off the end?
      {
        newChaser(n);  // respawn
      }
      moveTimes[n] = now + delays[n];  // next time to move
    }  // end time to move 
     
    leds.setPixelColor( positions[n], colors[n] );  // turn on pixel for this chaser

  }  // end of for each chaser
  
  leds.show();  // turn on all NUM_LEDS leds
}  // end of loop()


// create new Chaser parameters
void newChaser( int n )
{
  // pick a random color
  unsigned long r = random( 0, 0x100 );
  unsigned long g = random( 0, 0x100 );
  unsigned long b = random( 0, 0x100 );

  colors[n] = (r << 16) + (g << 8) + b;
  
  /*Serial.print(r, HEX); Serial.print(" ");
  Serial.print(g, HEX); Serial.print(" ");
  Serial.print(b, HEX); Serial.print(" ");
  Serial.println( colors[n], HEX ); */
  
  delays[n] = random( MIN_DELAY, MAX_DELAY );  // pick a random delay
  //Serial.println( delays[n] );
  positions[n] = random(0, NUM_CHASERS);       // start in a random spot
  moveTimes[n] = millis() + delays[n];         // next time to move
}  // end of newChaser()