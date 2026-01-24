#include "Include/Math/General.hpp"


namespace utils::mathf
{
    std::unordered_map<double, double> sin_lookup {
        {0, 0},
        {10, 0.17364818},
        {20, 0.34202014},
        {30, 0.5},
        {40, 0.64278761},
        {50, 0.76604444},
        {60, 0.8660254},
        {70, 0.93969262},
        {80, 0.98480775},
        {90, 1}
    };


    double sqrt(double number)
    {
        int result = 1;
        while(result*result <= number) {
            result++;
        }
        return result - 1;
    }

    double pow(double number, int factor)
    {
        double result;
        int i;
        while (i <= factor) {
            result *= i; i++;
        }

        return result;
    }
    
    double lerp(double number, double start, double end, double start_value, double end_value)
    {
        return start_value + (end_value - start_value) * ((number - start) / (start - end));
    }

    double round(double number, int digits)
    {
        std::string num_string = std::to_string(number);
        double counted_digits = std::stod(num_string.substr(num_string.length() - digits, num_string.length() - 1));

        std::cout << counted_digits << std::endl;
    }

    double sin(double input)
    {
        int lower_angle;
        int upper_angle;

        auto lower_value = sin_lookup[5];
        auto upper_value = sin_lookup[5];

        return lerp(
            input, 
            lower_angle,
            upper_angle,

            lower_value,
            upper_value
        );
    }

} // namespace utils::mathf
