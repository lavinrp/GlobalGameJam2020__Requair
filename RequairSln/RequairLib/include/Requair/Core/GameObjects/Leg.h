
#include <Requair/Utils/DllUtils.h>

#include <Requair/Core/GameObjects/SpriteItem.h>
#include <SFML/Graphics/Texture.hpp>



namespace REQ
{
	class libRequair Leg : public SpriteItem
	{
	public:

		Leg(float x, float y);

		void Interact() override;

		bool IsCollectible() override;

	private:
		sf::Texture m_texture = []() {
			sf::Texture tex{};
			tex.loadFromFile("Textures/boss man legs.png");
			return tex;
		}();

	};

}