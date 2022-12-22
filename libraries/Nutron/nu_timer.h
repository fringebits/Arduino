
 #pragma once

class NuTimer
{
public:
    NuTimer(unsigned long duration) 
    { 
        Reset(duration);
    }

    void Reset()
    {
        m_startTime = millis();
    }

    void Reset(unsigned long duration) 
    {
        m_duration = duration;
        Reset();
    }

    bool IsExpired()
    {
        auto runTime = millis();

        if (runTime > (m_startTime + m_duration))
        {
            return true;
        }

        return false;
    }

private:
    unsigned long m_duration;     // how long this timer lasts
    unsigned long m_startTime;    // current value
}; 