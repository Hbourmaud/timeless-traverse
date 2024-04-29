#include "Character.h"

Character::Character() {
	collisionComponent = new CollisionComponent(1, 1, 0,0);
	spriteComponent = new SpriteComponent();
}

Character::~Character() = default;