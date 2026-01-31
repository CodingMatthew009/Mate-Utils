#pragma once

#include "./Vector3.hpp"
namespace utils::mathf
{
    class Vector3;

    class Vector2
    {
        public:
            double x;
            double y;

            Vector2(double x, double y);

            Vector2(const Vector2& other);

            explicit Vector2(const Vector3& other);
            

            //Methods
            Vector2 normalize();

            double magnitude();

            double sqrMagnitude();

            void set(double newx, double newy);

            void set(Vector2& other);

            static double Angle(Vector2 first, Vector2 second);

            static double dot(Vector2 first, Vector2 second);

            static double Distance(Vector2 first, Vector2 second);

            Vector2 operator- (Vector2 other) 
            {
                return Vector2(this->x - other.x, this->y - other.y);
            }

            Vector2 operator+ (Vector2 other) 
            {
                return Vector2(this->x + other.x, this->y + other.y);
            }

            Vector2 operator* (double factor) 
            {
                return Vector2(this->x * factor, this->y * factor);
            }

            Vector2 operator/ (double factor) 
            {
                return Vector2(this->x / factor, this->y / factor);
            }

            #define V2_UP Vector2(0, 1)
            #define V2_DOWN Vector2(0, -1)
            #define V2_LEFT Vector2(-1, 0)
            #define V2_RIGHT Vector2(1, 0)

            #define V2_ONE Vector2(1, 1)
            #define V2_ZERO Vector2(0, 0)
    }; 
}