#pragma once

#define CRGB(r,g,b) (((uint32_t)r << 16) + ((uint32_t)g << 8) + (uint32_t)b)

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

class NuColor
{
public:
    static uint32_t random_color()
    {
        // pick a random color
        unsigned long r = random( 0, 0x100 );
        unsigned long g = random( 0, 0x100 );
        unsigned long b = random( 0, 0x100 );

        return CRGB(r, g, b);
    }
}; 