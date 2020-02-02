#include <Requair/Core/Regions/RuntimeRegion.h>
#include <Requair/Core/GameObjects/Pot.h>
#include <Requair/Core/GameObjects/Item.h>
#include <unistd.h>
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
	float tile_x_length = static_cast<float>(levelJson["tileheight"]);
	float tile_y_length = static_cast<float>(levelJson["tilewidth"]);

	auto layers = levelJson["layers"];
	int x_tile_no(0), y_tile_no(0);

	std::vector <std::unique_ptr<Item>> item_list;
	std::vector <std::unique_ptr<PhysicalObject>> physical_object_list ;
	for (auto& layer : layers){
		auto chunks = layer["chunks"];
		
		for (auto& chunk : chunks){
			x_tile_no = chunk["width"];
			y_tile_no = chunk["height"];
			auto data = chunk["data"];
			int x_loc(0), y_loc(0);
			float x_pos = static_cast<float>(chunk["x"]);
			float y_pos = static_cast<float>(chunk["y"]);

			for (auto& tile : data)
			{	
				if (tile == 0)
				{
					item_list.push_back(std::make_unique<Pot>(x_pos+(x_loc-1)*tile_x_length, y_pos+(y_loc-1)*tile_y_length));
				}
				

				if ((x_loc+1)%x_tile_no == 0)
				{
					y_loc = y_loc+1;
					x_loc = 1;
				}  else 
				{
					x_loc = x_loc+1;
				}
			}
			
		}
	}

	return std::make_pair(std::move(item_list), std::move(physical_object_list));
}