#ifndef Vec2_h
#define Vec2_h

#include <math.h>

class Vec2 {
public:
    double x,y;
    Vec2();
    Vec2(double tx, double ty);
    Vec2            operator+(const Vec2& B);
    Vec2            operator-(const Vec2& B);
    friend Vec2     operator*(Vec2& A, double k);
    friend Vec2     operator*(double k, Vec2& A);
    
    double          dot(Vec2& B);
    double          cross(Vec2& B);
    double          size();
};

#endif