#include "Component.h"

class StatsComponent : public Component
{
public:
	StatsComponent() = default;
	~StatsComponent() = default;

	//getter
	int GetHealth() { return health; }
	int Getdamage() { return damage; }
	//setter
	void SetHealth(int value);
	void SetDamage(int value);
private:
	int health;
	int damage;
};