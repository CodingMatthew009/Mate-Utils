#include <unordered_map>
#include <string>
#include <iostream>

namespace utils::mathf
{
    //LUTs 
    std::unordered_map<double, double> sin_lookup;


    static double sqrt(double number);

    static double pow(double number, int factor);

    static double lerp(double number, double lower, double higher);

    static double round(double number, int digits);

    static double sin(double input);

    static double cosin(double input);

    static double tan(double input);

} // namespace utils::mathf
