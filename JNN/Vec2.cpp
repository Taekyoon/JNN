#include "Vec2.h"
Vec2::Vec2() {}
Vec2::Vec2(double tx, double ty):x(tx),y(ty) {}
Vec2 Vec2::operator+(const Vec2& B) {
    return Vec2(this->x+B.x, this->y+B.y);
}
Vec2 Vec2::operator-(const Vec2& B) {
    return Vec2(this->x-B.x, this->y-B.y);
}
Vec2 operator*(Vec2& A, double k) {
    return Vec2(A.x*k, A.y*k);
}
Vec2 operator*(double k, Vec2& A) {
    return Vec2(A.x*k, A.y*k);
}
double Vec2::dot(Vec2& B) {
    return this->x*B.x + this->y*B.y;
}
double Vec2::cross(Vec2& B) {
    return this->x*B.y - this->y*B.x;
}
double Vec2::size() {
    return sqrt(x*x + y*y);
}