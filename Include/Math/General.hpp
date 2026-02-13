#pragma once

#include <cmath>

namespace cmate::core::mathf
{
    //Missing functions from cmath 
    inline double fract(double x)
    {
        return x - std::floor(x);
    }

    inline double SmoothStep(double from, double to, double amount)
    {
        float t = std::clamp((amount - from) / (to - from), (double)0.0, (double)1.0);

        return t * t * (3.0 - 2.0 * t);
    }
}