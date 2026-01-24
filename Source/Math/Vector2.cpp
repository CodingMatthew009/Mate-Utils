#include "Include/Math/Vector2.hpp"
#include "Include/Math/General.hpp"

namespace utils::mathf
{

    Vector2::Vector2(double other_x, double other_y)
    {
        x = other_x; y = other_y;
    }

    Vector2::Vector2(Vector2& other)
    {
        x = other.x; y = other.y;
    }

    //Methods
    Vector2 Vector2::normalize()
    {
        return Vector2(x / magnitude(), y / magnitude());
    }

    double Vector2::magnitude()
    {
        return mathf::sqrt(mathf::pow(x, 2) + mathf::pow(y, 2));
    }

    double Vector2::sqrMagnitude()
    {
        return mathf::pow(x, 2) + mathf::pow(y, 2);
    }

    void Vector2::set(double newx, double newy)
    {
        x = newx; y = newy;
    }

    void Vector2::set(Vector2& other)
    {
        x = other.x; y = other.y;
    }

    float Vector2::Angle(Vector2 first, Vector2 second)
    {
        

    }
}