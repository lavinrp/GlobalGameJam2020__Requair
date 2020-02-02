#include <Requair/Core/Regions/RuntimeRegion.h>
#include <Requair/Core/GameObjects/Pot.h>
#include <Requair/Core/GameObjects/Item.h>
#include <Requair/Utils/JsonParserUtil.h>

#include <string>
#include <fstream>
#include <streambuf>
#include <vector>
#include <utility>

using namespace REQ;

RuntimeRegion::RuntimeRegion(const std::string& jsonFile)
{
	m_jsonFile = jsonFile;
	auto [item_list, phycial_object_list] =  ProcessJson();
}

std::pair<std::vector<std::unique_ptr<Item>>, std::vector<std::unique_ptr<PhysicalObject>>> RuntimeRegion::ProcessJson()
{
	// read file
	std::ifstream t(m_jsonFile);
	nlohmann::json levelJson = nlohmann::json::parse(t);
	int mapHeight = levelJson["height"];
	int mapWidth = levelJson["width"];
	auto tiles_data = levelJson["layers"][0]["data"];
	int x_loc(0), y_loc(0);

	std::vector <std::unique_ptr<Item>> item_list;
	std::vector <std::unique_ptr<PhysicalObject>> physical_object_list ;
	for (auto& element : tiles_data) 
	{
		if (element == 10){
			//pot object
			item_list.push_back(ProcessItem(element, { x_loc , y_loc}));
		
		}
  		
		if (x_loc+1%mapWidth == 0)
		{
			y_loc = y_loc+1;
			x_loc = 1;
		}  else 
		{
			x_loc = x_loc+1;
		}
	}

	return std::make_pair(std::move(item_list), std::move(physical_object_list));
}