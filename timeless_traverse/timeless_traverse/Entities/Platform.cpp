#include "Platform.h"

Platform::Platform() {
	collisionComponent = new CollisionComponent(1,1,0);
	renderComponent = new RenderComponent();
};

Platform::~Platform() = default;