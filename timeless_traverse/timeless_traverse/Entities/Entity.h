#pragma once

#include "../GameObject.h"

class Entity : public GameObject
	{
	public:
		Entity();
		virtual ~Entity();
		int id;

		bool operator ==(const Entity * secondEntity) const { return id == secondEntity->id; }
	};