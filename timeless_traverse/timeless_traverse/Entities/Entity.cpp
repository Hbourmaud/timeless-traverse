#include "Entity.h"

Entity::Entity() {
	transformComponent = new TransformComponent();
}

Entity::~Entity() = default;

void Entity::SetId(int newId) {
	id = newId;
}