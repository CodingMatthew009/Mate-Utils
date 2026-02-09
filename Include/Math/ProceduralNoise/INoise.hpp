#pragma once

#include "../../Imager.hpp"
#include "../Vector2.hpp"
#include "../Random.hpp"

#include <vector>
#include <cmath>

namespace utils
{
    class Imager; //Forward decleration of Imager

    namespace Interfaces {
        class INoise
        {
            public:

                int GetSeed() const
                {
                    return seed;
                }

                double GetValue(int pos_x, int pos_y)
                {
                    return value_map[pos_x][pos_y];
                }

                void SaveAsImage(std::string path)
                {
                    Imager::ValuesToBitmap(value_map, path);
                }

                void SaveAsImage(const char* path)
                {
                    Imager::ValuesToBitmap(value_map, path);
                }

            protected:
                int seed;

                std::vector<std::vector<double>> value_map;

        };
    }  

    namespace mathf {

        // Hashing function for White-Value Noise
        inline double hash(Vector2 inputVec, int seed)
        {
           return fract(
                    std::sin(
                        Vector2::dot(inputVec, 
                            Vector2(Random::dRangeS(0, 1000000, seed + inputVec.x * 35281 + inputVec.y * 97246), 
                                    Random::dRangeS(0, 1000000, seed + inputVec.x * 28754 + inputVec.y * 21634)
                                ))* seed));
        }

        // Hashing function for Perlin Noise
        inline double hash2D(Vector2 inputVec, int seed)
        {
            inputVec = Vector2(Vector2::dot(inputVec, Vector2(Random::dRangeS(0, 1000000, seed + inputVec.x * 35281 + inputVec.y * 97246), Random::dRangeS(0, 1000000, seed + inputVec.x * 28754 + inputVec.y * 21634))),
                               Vector2::dot(inputVec, Vector2(Random::dRangeS(0, 1000000, seed + inputVec.x * 19823 + inputVec.y * 98573), Random::dRangeS(0, 1000000, seed + inputVec.x * 12384 + inputVec.y * 34202))));
                                                
            //return 
        }
    }
}