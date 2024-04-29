#include "Character.h"

Character::Character() {
	collisionComponent = new CollisionComponent(1, 1, 0);
	renderComponent = new RenderComponent();
}

Character::~Character() = default;