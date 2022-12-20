#pragma once

class NuRange
{
public:
    NuRange(int _start=0, int _count=0)
        : m_start(_start)
        , m_count(_count)
    { }

    int m_start;
    int m_count;
};