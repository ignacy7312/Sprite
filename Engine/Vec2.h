#pragma once
#include <cmath>


template<typename T>
class Vec2
{
public:
	Vec2(T x_in, T y_in)
		:
		x(x_in),
		y(y_in)
	{
	}
	Vec2 operator+(const Vec2& rhs) const
	{
		return Vec2(x + rhs.x, y + rhs.y);
	}

	Vec2& operator+=(const Vec2& rhs)
	{
		return *this = *this + rhs;
	}

	Vec2 operator*(T rhs) const
	{
		return Vec2(x * rhs, y * rhs);
	}

	Vec2& operator*=(T rhs)
	{
		return *this = *this * rhs;
	}

	Vec2 operator-(const Vec2& rhs) const
	{
		return Vec2(x - rhs.x, y - rhs.y);
	}

	Vec2& operator-=(const Vec2& rhs)
	{
		return *this = *this - rhs;
	}

	T GetLength() const
	{
		return std::sqrt(GetLengthSq());
	}

	T GetLengthSq() const
	{
		return x * x + y * y;
	}

	Vec2& Normalize()
	{
		return *this = GetNormalized();
	}

	Vec2 GetNormalized() const
	{
		const T len = GetLength();
		if (len != 0.0f)
		{
			return *this * (1.0f / len);
		}
		return *this;
	}
public:
	T x;
	T y;
};






