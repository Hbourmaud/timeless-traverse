#include "Platform.h"

Platform::Platform() {
	collisionComponent = new CollisionComponent(1,1,0,0);
	spriteComponent = new SpriteComponent();
};

Platform::~Platform() = default;