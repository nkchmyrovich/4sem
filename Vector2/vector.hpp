#pragma once
#include <iostream>
#include <math.h>

struct Vector2 {
	float x,y;
	Vector2();
	Vector2(float x, float y);
    Vector2 operator+ (const Vector2& other) const;
    Vector2 operator- (const Vector2& other) const;
    Vector2& operator+= (const Vector2& other);
    Vector2& operator-= (const Vector2& other);
    Vector2 operator- () const;
    float operator* (const Vector2& other) const;
    friend float operator^ (const Vector2& that, const Vector2& other);
    Vector2 operator* (const float value) const;
    Vector2 operator/ (const float value) const;
    friend Vector2 operator* (const float value, const Vector2& vec);
    friend std::ostream& operator<< (std::ostream& stream,const Vector2& vec);
    friend std::istream& operator>> (std::istream& stream, Vector2& vec);
    float Len () const;
    Vector2 GetNorm () const;
    Vector2 GetPerp () const;
    Vector2& Rotate (float angle);
    Vector2 GetRotated (float angle) const;
	~Vector2();
};