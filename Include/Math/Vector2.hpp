

namespace utils::mathf
{
    class Vector2
    {
        public:
            double x;
            double y;

            Vector2(double x, double y);

            Vector2(Vector2& other);

            //Methods
            Vector2 normalize();

            double magnitude();

            double sqrMagnitude();

            void set(double newx, double newy);

            void set(Vector2& other);

            static float Angle(Vector2 first, Vector2 second);

            #define UP Vector2(0, 1);
            #define DOWN Vector2(0, -1);
            #define LEFT Vector2(-1, 0);
            #define RIGHT Vector2(1, 1);

            #define ONE Vector2(1, 1);
            #define ZERO Vector2(0, 0);
    }; 
}