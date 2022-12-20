#pragma once

#include <Adafruit_NeoPixel.h>
#include "nu_range.h"
#include "nu_color.h"

#define HOUSE_COLOR CRGB(255, 145, 25)

class House : public NuRange
{
public:
    House(int _start=0, int _count=0, uint32_t _color=HOUSE_COLOR)
        : NuRange(_start, _count)
        , m_color(_color)
    { }

    void update(Adafruit_NeoPixel* leds)
    {
        house_lights(leds);
        //house_party(leds);
    }

private:
    void house_lights(Adafruit_NeoPixel* leds)
    {
        for(int jj=0; jj < m_count; jj++)
        {
            leds->setPixelColor(m_start + jj, m_color);
        }
    }

    void house_party(Adafruit_NeoPixel* leds)
    {
        for(int jj=0; jj < m_count; jj++)
        {
            auto c = NuColor::random_color();
            leds->setPixelColor(m_start + jj, c);
        }
    }

    uint32_t m_last_color;
    uint32_t m_color;
};

