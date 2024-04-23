#include "Vector2D.h"

#include <valarray>


template <typename T>
	void Vector2D::TVector2D<T>::Normalize()
	{
		*this = *this /  Length();
	}

	template <typename T>
	float Vector2D::TVector2D<T>::Distance(const TVector2D& Other)
	{
		return std::sqrt(std::pow(Other.X - X, 2) + std::pow(Other.Y - Y, 2));
	}

	template <typename T>
	float Vector2D::TVector2D<T>::Length()
	{
		return std::sqrt(std::pow(X, 2) + std::pow(Y, 2));
	}

	template <typename T>
	void Vector2D::TVector2D<T>::SafeNormalize()
	{
		if (Length() > 0)
		{
			Normalize();
		}
	}






