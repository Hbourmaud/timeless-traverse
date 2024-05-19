#pragma once

#include <ostream>

#include "Math.h"

class Vector2D : public Math
{
public:
	Vector2D();
	~Vector2D();

	template<typename T>
	struct TVector2D {
	public:

		TVector2D() {};
		TVector2D(T XY) : X(XY), Y(XY) {};
		TVector2D(T X_, T Y_) : X(X_), Y(Y_) {};

		bool operator==(const TVector2D& Other)
		const { return X == Other.X && Y == Other.Y; }

		bool operator!=(const TVector2D& Other)
		const { return !(*this == Other); }

		friend std::ostream& operator<<(std::ostream& os,const TVector2D<float> vector)
		{
			return os << "(" << vector.X << ", " << vector.Y << ")";
		}

		TVector2D operator+(const TVector2D& Other) const
		{
			TVector2D Result = TVector2D();
			Result.X = X + Other.X;
			Result.Y = Y + Other.Y;
			return Result;
		}

		TVector2D operator-(const TVector2D& Other) const
		{
			TVector2D Result = TVector2D();
			Result.X = X - Other.X;
			Result.Y = Y - Other.Y;
			return Result;
		}

		TVector2D operator*(const TVector2D& Other) const
		{
			TVector2D Result = TVector2D();
			Result.X = X * Other.X;
			Result.Y = Y * Other.Y;
			return Result;
		}

		TVector2D operator/(const TVector2D& Other) const
		{
			TVector2D Result = TVector2D();
			Result.X = X / Other.X;
			Result.Y = Y / Other.Y;
			return Result;
		}


		TVector2D operator+(const T& Other) const
		{
			return *this + TVector2D(Other);
		}

		TVector2D operator-(const T& Other) const
		{
			return *this - TVector2D(Other);
		}

		TVector2D operator*(const T& Other) const
		{
			return *this * TVector2D(Other);
		}
		
		TVector2D operator/(const T& Other) const
		{
			return *this / TVector2D(Other);
		}

		TVector2D& operator=(const TVector2D<float>& Other)
		{
			this->X = Other.X;
			this->Y = Other.Y;
			return *this;
		}

		void operator+=(const TVector2D<float>& Other)
		{
			*this = *this + Other;
		}

		void operator-=(const TVector2D<float>& Other)
		{
			*this = *this - Other;
		}

		bool operator!=(const TVector2D<float>& Other)
		{
			if (this->X == Other.X && this->Y == Other.Y)
			{
				return false;
			}

			return true;
		}

		void Normalize();
		void SafeNormalize();
		float Length();
		float Distance(const TVector2D& Other);

	public:
		T X;
		T Y;
	};

private:

};