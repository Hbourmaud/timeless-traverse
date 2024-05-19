#include "../Math/Vector2D.h"

#include "Component.h"

class TransformComponent : public Component
{
public:
	TransformComponent();
	~TransformComponent();

	Vector2D::TVector2D<float>GetPosition() { return position; }
	Vector2D::TVector2D<float> GetRotation() { return rotation; }
	Vector2D::TVector2D<float> GetScale() { return scale; }
	
	void SetPosition(float x, float y);
	void SetPosition(Vector2D::TVector2D<float>);
	void SetRotation();
	void SetScale(float x, float y);

private:
	Vector2D::TVector2D<float> position;
	Vector2D::TVector2D<float> rotation;
	Vector2D::TVector2D<float> scale;
};