#pragma once
#include <iostream>

/*
вы здесь не используете ничего из math.h
лишние инклюды не нужны. перенесите непосредственно туда, где используете
*/
#include <math.h>

struct Vector2 {
	float x,y;
	/*
	можно написать Vector2() = default;
	и в срр ничего не писать
	*/
	Vector2();
	Vector2(float x, float y);
    Vector2 operator+ (const Vector2& other) const;
    Vector2 operator- (const Vector2& other) const;
    Vector2& operator+= (const Vector2& other);
    Vector2& operator-= (const Vector2& other);
    Vector2 operator- () const;
    float operator* (const Vector2& other) const;
	/*
	а зачем было векторное произведение выносить наружу?
	*/
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
	
	/*
        fixit:
        Компилятор сам сгенерирует за вас ровно такой же пустой деструктор.
        Явно писать не нужно.
        */
	~Vector2();
};
