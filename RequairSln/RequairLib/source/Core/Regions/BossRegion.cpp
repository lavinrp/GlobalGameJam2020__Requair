#include <Requair/Core/Regions/BossRegion.h>
#include <Requair/Core/GameObjects/Arm.h>
#include <Requair/Core/GameObjects/Leg.h>
#include <Requair/Core/GameObjects/Pot.h>
#include <Requair/Core/GameObjects/Wall.h>
#include <Requair/Core/GameObjects/Door.h>
#include <Requair/Core/GameObjects/Floor.h>
#include <Requair/Core/GameObjects/Key.h>

#include <Requair/Utils/JsonParserUtil.h>
#include <Requair/Utils/json.hpp>

#include <SFML/Audio/Music.hpp>

#include <algorithm>
#include <fstream>
#include <streambuf>

using namespace REQ;

BossRegion::BossRegion(std::string jsonFile, sf::RenderWindow& window) : m_jsonFile(std::move(jsonFile)), m_window(window)
{
	// m_music = std::make_unique<sf::Music>();
	/*if (m_music->openFromFile(R"(Music/chill.wav)"))
	{
		m_music->play();
		m_music->setLoop(true);
	}*/

	auto [item_list, physical_object_list] = ProcessJson();
	m_item_list = std::move(item_list);
	m_physical_object_list = std::move(physical_object_list);

	for (const auto& item : m_item_list)
	{
		sf::Drawable* drawableItem = dynamic_cast<sf::Drawable*>(item.get());
		if (drawableItem)
		{

			addDrawable(3, drawableItem);
		}
	}
	for (const auto& object : m_physical_object_list)
	{
		sf::Drawable* drawableItem = dynamic_cast<sf::Drawable*>(object.get());
		if (drawableItem)
		{

			addDrawable(3, drawableItem);
		}
	}

	ShouldBeParsedFromJsonButIsntYet();

	addDrawable(5, &boss);
}

void BossRegion::ShouldBeParsedFromJsonButIsntYet() {

	//auto pot = std::make_unique<Pot>(400, 300);
	//addDrawable(4, pot.get());
	//m_item_list.push_back(std::move(pot));

	//auto arm = std::make_unique<Arm>(200, 100);
	//addDrawable(3, arm.get());
	//m_item_list.push_back(std::move(arm));

	//auto leg = std::make_unique<Leg>(300, 100);
	//addDrawable(3, leg.get());
	//m_item_list.push_back(std::move(leg));

	//auto key = std::make_unique<Key>(400, 100);
	//addDrawable(3, key.get());
	//m_item_list.push_back(std::move(key));

	auto door = std::make_unique<Door>(300, 100);
	addDrawable(3, door.get());
	m_item_list.push_back(std::move(door));

}

void BossRegion::HandleEvent(sf::Event& event)
{
	if (event.type == sf::Event::KeyPressed)
	{
		if (event.key.code == sf::Keyboard::Key::X)
		{
			auto bossPosition = boss.getPosition();
			auto nearestItem = std::min_element(
				m_item_list.begin(),
				m_item_list.end(),
				[&bossPosition](const std::unique_ptr<Item>& a, const std::unique_ptr<Item>& b) {
					auto aPosition = a->GetObjectPosition();
					auto bPosition = b->GetObjectPosition();
					auto aDistance = sqrt(pow(bossPosition.x - aPosition.x, 2) + pow(bossPosition.y - aPosition.y, 2));
					auto bDistance = sqrt(pow(bossPosition.x - bPosition.x, 2) + pow(bossPosition.y - bPosition.y, 2));
					return aDistance < bDistance;
				}
			);
			if (nearestItem != m_item_list.end())
			{
				auto nearestItemPosition = nearestItem->get()->GetObjectPosition();
				auto distance = sqrt(pow(bossPosition.x - nearestItemPosition.x, 2) + pow(bossPosition.y - nearestItemPosition.y, 2));
				if (distance <= maxInteractionDistance)
				{
					nearestItem->get()->Interact(boss);
					std::cout << "Interacted with item at (" << nearestItem->get()->GetObjectPosition().x << ", " << nearestItem->get()->GetObjectPosition().y << ")" << std::endl;
				}
			}
		}
		else if (event.key.code == sf::Keyboard::Key::RBracket)
		{
			sf::View view = m_window.getView();
			view.zoom(1.1f);
			m_window.setView(view);
		}
		else if (event.key.code == sf::Keyboard::Key::LBracket)
		{
			sf::View view = m_window.getView();
			view.zoom(0.9f);
			m_window.setView(view);
		}

	}
}

std::pair<std::vector<std::unique_ptr<Item>>, std::vector<std::unique_ptr<PhysicalObject>>> BossRegion::ProcessJson()
{
	// read file
	std::ifstream t(m_jsonFile);
	nlohmann::json levelJson = nlohmann::json::parse(t);
	float tile_x_length = static_cast<float>(levelJson["tileheight"]);
	float tile_y_length = static_cast<float>(levelJson["tilewidth"]);

	auto layers = levelJson["layers"];
	int x_tile_no(0), y_tile_no(0);

	std::vector <std::unique_ptr<Item>> item_list;
	std::vector <std::unique_ptr<PhysicalObject>> physical_object_list;
	for (auto& layer : layers) {
		auto chunks = layer["chunks"];

		for (auto& chunk : chunks) {
			x_tile_no = chunk["width"];
			y_tile_no = chunk["height"];
			auto data = chunk["data"];
			int x_loc(0), y_loc(0);
			float x_pos = static_cast<float>(chunk["x"]);
			float y_pos = static_cast<float>(chunk["y"]);

			for (auto& tile : data)
			{
				if (tile == 3) //pot
				{
					item_list.push_back(std::make_unique<Floor>((x_pos+x_loc)*tile_x_length, (y_pos+y_loc)*tile_y_length));
				}
				else if (tile == 2) //wall
				{
					physical_object_list.push_back(std::make_unique<Wall>((x_pos+x_loc)*tile_x_length, (y_pos+y_loc)*tile_y_length));
				}
				else if (tile == 1) //arm
				{
				}
				else if (tile == 4) //leg
				{
				}
				else if (tile == 5) //keys
				{
				}


				if ((x_loc + 1) % x_tile_no == 0)
				{
					y_loc = y_loc + 1;
					x_loc = 0;
				}
				else
				{
					x_loc = x_loc + 1;
				}
			}

		}
	}

	return std::make_pair(std::move(item_list), std::move(physical_object_list));	
}

void BossRegion::update(sf::Int64 elapsedTime)
{
	if (!m_music)
	{
		m_music = std::make_unique<sf::Music>();
		if (m_music->openFromFile(R"(Music/chill.wav)"))
		{
			m_music->play();
			m_music->setLoop(true);
		}
	}


	TemplateRegion::update(elapsedTime);
	boss.update(elapsedTime);

	sf::View view = m_window.getView();
	view.setCenter(boss.getPosition());
	m_window.setView(view);
}
