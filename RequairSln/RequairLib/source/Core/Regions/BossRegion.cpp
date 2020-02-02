#include <Requair/Core/Regions/BossRegion.h>
#include <SFML/Graphics/RectangleShape.hpp>
#include <algorithm>

using namespace REQ;

BossRegion::BossRegion(std::string jsonFile) : RuntimeRegion(jsonFile)
{
	auto pot = std::make_unique<Pot>(400, 300);
	addDrawable(4, pot.get());
	item_list.push_back(std::move(pot));
	auto pot2 = std::make_unique<Pot>(350, 300);
	addDrawable(3, pot2.get());
	item_list.push_back(std::move(pot2));
	addDrawable(5, &boss);
}

void BossRegion::HandleEvent(sf::Event& event)
{
	if (event.type == sf::Event::KeyPressed)
	{
		if (event.key.code == sf::Keyboard::Key::X)
		{
			auto bossPosition = boss.getPosition();
			auto nearestItem = std::min_element(
				item_list.begin(),
				item_list.end(),
				[&bossPosition](const std::unique_ptr<Item>& a, const std::unique_ptr<Item>& b) {
					auto aPosition = a->GetObjectPosition();
					auto bPosition = b->GetObjectPosition();
					auto aDistance = sqrt(pow(bossPosition.x - aPosition.x, 2) + pow(bossPosition.y - aPosition.y, 2));
					auto bDistance = sqrt(pow(bossPosition.x - bPosition.x, 2) + pow(bossPosition.y - bPosition.y, 2));
					return aDistance < bDistance;
				}
			);
			if (nearestItem != item_list.end())
			{
				auto nearestItemPosition = nearestItem->get()->GetObjectPosition();
				auto distance = sqrt(pow(bossPosition.x - nearestItemPosition.x, 2) + pow(bossPosition.y - nearestItemPosition.y, 2));
				if (distance <= maxInteractionDistance)
				{
					nearestItem->get()->Interact();
					std::cout << "Interacted with item at (" << nearestItem->get()->GetObjectPosition().x << ", " << nearestItem->get()->GetObjectPosition().y << ")" << std::endl;
				}
			}
		}
	}
}

void BossRegion::update(sf::Int64 elapsedTime)
{
	RuntimeRegion::update(elapsedTime);
	boss.update(elapsedTime);
}
