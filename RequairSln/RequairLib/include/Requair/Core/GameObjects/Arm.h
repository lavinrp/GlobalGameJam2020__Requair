
#include <Requair/Utils/DllUtils.h>

#include <Requair/Core/GameObjects/SpriteItem.h>
#include <SFML/Graphics/Texture.hpp>



namespace REQ
{
	class libRequair Arm : public SpriteItem
	{
	public:
		Arm(float x, float y);

		void Interact() override;
	private:
		sf::Texture m_texture = []() {
			sf::Texture tex{};
			tex.loadFromFile("Textures/boss man arm.png");
			return tex;
		}();

	};

}