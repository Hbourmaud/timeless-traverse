#pragma once

#include "../GameObject.h"
#include "../Components/TransformComponent.h"

class Entity : public GameObject
	{
	public:
		Entity();
		~Entity();

		int GetId() const { return id; }

		void SetId(int id);

		TransformComponent* transformComponent;

		bool operator ==(const Entity * secondEntity) const { return id == secondEntity->GetId(); }

	private:
		int id;
};