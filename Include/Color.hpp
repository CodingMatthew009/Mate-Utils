#pragma once

#include <cstdint>
#include <vector>

#include "Math/General.hpp"

namespace cmate::core
{
    struct Color
    {
        uint8_t R;
        uint8_t G;
        uint8_t B;

        Color() {};
        Color(uint8_t red, uint8_t green, uint8_t blue)
        {   
            R = red; G = green; B = blue;
        }

        inline Color operator+(Color other)
        {
            Color result(
                R + other.R,
                G + other.G,
                B + other.G
            );

            return result;
        }

        inline Color operator-(Color other)
        {
            Color result(
                R - other.R,
                G - other.G,
                B - other.G
            );

            return result;
        }

        inline Color operator*(double factor)
        {
            Color result(
                R * factor,
                G * factor,
                B * factor
            );

            return result;
        }

        inline Color SmoothStep(Color from, Color to, double t)
        {
            Color result(
                mathf::SmoothStep(from.R, to.R, t),
                mathf::SmoothStep(from.G, to.G, t),
                mathf::SmoothStep(from.B, to.B, t)
            );

            return result;
        }
    };

    inline Color ValueToColor(double value)
    {
        Color color(
            value * 255,
            value * 255,
            value * 255
        );
        return color;
    }

    inline double ColorToValue(Color color)
    {
        double value = (double)(color.R + color.G + color.B) / 3 / 255;
        return value;
    }

    inline std::vector<std::vector<Color>> ValueMapToPixelMap(std::vector<std::vector<double>> values)
    {
        std::vector<std::vector<Color>> collumns;
        for (int c = 0; c < values.size(); c++)
        {
            std::vector<Color> pixels;
            for (int i = 0; i < values[c].size(); i++)
            {
                pixels.push_back(ValueToColor(values[c][i]));
            }

            collumns.push_back(pixels);
        }
        return collumns;
    } 

    inline std::vector<std::vector<double>> PixelMapToValueMap(std::vector<std::vector<Color>> pixels)
    {
        std::vector<std::vector<double>> collumns;
        for (int c = 0; c < pixels.size(); c++)
        {
            std::vector<double> colors;
            for (int i = 0; i < pixels[c].size(); i++)
            {
                colors.push_back(ColorToValue(pixels[c][i]));
            }

            collumns.push_back(colors);
        }
        return collumns;
    } 
}