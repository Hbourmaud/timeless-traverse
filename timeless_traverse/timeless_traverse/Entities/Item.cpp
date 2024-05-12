#include "Item.h"

Item::Item()
{
    collisionComponent = new CollisionComponent(1,1,0,0);
    spriteComponent = new SpriteComponent();
}

Item::~Item() = default;

