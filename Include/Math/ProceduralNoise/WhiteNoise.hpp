#pragma once

#include "INoise.hpp"
#include "../Vector2.hpp"

using namespace utils::mathf;


namespace utils::noise
{
    class WhiteNoise : interfaces::INoise
    {
        public:
            WhiteNoise(int seed, Vector2 size);
    };
}