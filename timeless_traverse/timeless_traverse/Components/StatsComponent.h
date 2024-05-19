#include "Component.h"

class StatsComponent : public Component
{
public:
	StatsComponent() = default;
	~StatsComponent() = default;

	int GetHealth() { return health; }
	int Getdamage() { return damage; }

	void SetHealth(int value);
	void SetDamage(int value);
private:
	int health;
	int damage;
};