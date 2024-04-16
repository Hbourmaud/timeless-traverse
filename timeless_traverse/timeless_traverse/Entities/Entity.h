#pragma once

class Entity
{
public:
	Entity();
	virtual ~Entity();
	int id;

	bool operator ==(const Entity* secondEntity) const { return id == secondEntity->id; }
};