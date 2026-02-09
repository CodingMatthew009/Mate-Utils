#pragma once

#include "INoise.hpp"
#include "../General.hpp"
#include "../Vector2.hpp"
#include <functional>


using namespace utils::mathf;


namespace utils::Noise
{
    class WhiteNoise : public utils::Interfaces::INoise
    {
        public:
            WhiteNoise(int seed, Vector2 size)
            {
                for (int c = 0; c < size.x; c++)
                {
                    std::vector<double> collumn;

                    for (int p = 0; p < size.y; p++)
                    {
                        collumn.push_back(hash(Vector2(c, p), seed));
                    }

                    value_map.push_back(collumn);
                }
            }
    };
}