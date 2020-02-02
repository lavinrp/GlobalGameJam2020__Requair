
#include <Requair/Utils/DllUtils.h>

#include <Requair/Core/GameObjects/SpriteItem.h>


namespace REQ
{
	class libRequair Key : public SpriteItem
	{
	public:

		void Interact() override;
		void IsCollectible() override;


	};

}