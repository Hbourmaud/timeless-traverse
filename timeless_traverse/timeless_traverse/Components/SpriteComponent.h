#include <SFML/Graphics/Sprite.hpp>
#include "sfml/graphics/Texture.hpp"
#include "Component.h"
#include "../Managers/AssetManager.h"
#include <string>

class SpriteComponent : public Component
{
public:
	SpriteComponent();
	~SpriteComponent();
	sf::Sprite GetSprite() { return entitySprite; }
	void SetSprite(std::string textureName);

private:
	sf::Texture* texture;
	sf::Sprite entitySprite;
	AssetManager assetManager;
};