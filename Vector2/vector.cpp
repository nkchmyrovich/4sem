#include "vector.hpp"

Vector2::Vector2 ()
{}

Vector2::Vector2 (float _x, float _y) :
	x(_x),
	y(_y)
{}

Vector2::~Vector2 () 
{}

float Vector2::Len () const {
	return sqrt(x*x + y*y);
};

Vector2 Vector2::operator+ (const Vector2& other) const {
	Vector2 result = Vector2();
	result.x = x + other.x;
	result.y = y + other.y;
	return result;
}

Vector2 Vector2::operator- (const Vector2& other) const {
    Vector2 result = Vector2();
	result.x = x - other.x;
	result.y = y - other.y;
	return result;
}

Vector2& Vector2::operator+= (const Vector2& other) {
    x += other.x;
    y += other.y;
    return *this;
}

Vector2& Vector2::operator-= (const Vector2& other) {
    x -= other.x;
    y -= other.y;
    return *this;
}

Vector2 Vector2::operator- () const {
    return Vector2(-x, -y);
}

float Vector2::operator* (const Vector2& other) const {
    return x*other.x + y*other.y;
}

float operator^ (const Vector2& that, const Vector2& other) {
    return that.x*other.y - that.y*other.x;
}

Vector2 Vector2::operator* (const float value) const {
    return Vector2(x*value, y*value);
}

Vector2 Vector2::operator/ (const float value) const {
    return Vector2(x/value, y/value);
}

Vector2 operator* (const float value, const Vector2& vec) {
    return vec*value;
}

Vector2 Vector2::GetNorm () const {
    float norm = Len();
    return Vector2(x/norm, y/norm);
}

Vector2 Vector2::GetPerp () const{
    return Vector2(y, -x);
}

Vector2& Vector2::Rotate (float angle) {
    float _x = x;
    float _y = y;
    x = _x * cos(angle) - _y * sin(angle);
    y = _x * sin(angle) + _y * cos(angle);
    return *this;
}

Vector2 Vector2::GetRotated (float angle) const {
    return Vector2(x, y).Rotate(angle);
}

std::istream& operator>> (std::istream& stream, Vector2& vec) {
    stream >> vec.x;
    stream >> vec.y;
    return stream;
}

std::ostream& operator<< (std::ostream& stream, const Vector2& vec) {
    stream << "(" << vec.x << ", " << vec.y << ")";
    return stream;
}
