#include <Requair/Core/Regions/RuntimeRegion.h>
#include <unistd.h>
#include <string>
#include <fstream>
#include <streambuf>

using namespace REQ;

RuntimeRegion::RuntimeRegion(const std::string& jsonFile)
{
	m_jsonFile = jsonFile;
	ProcessJson();
}

void RuntimeRegion::ProcessJson()
{
	// read file
	std::ifstream t(m_jsonFile);
	nlohmann::json levelJson = nlohmann::json::parse(t);
	int mapHeight = levelJson["height"];
	int mapWidth = levelJson["width"];
	auto tiles_data = levelJson["layers"][0]["data"];
	int x_loc(1), y_loc(1);
	for (auto& element : tiles_data) 
	{
  		std::cout << "x location = " << x_loc << " y location = " << y_loc << " tile id" << element << '\n';
		
		if (x_loc%mapWidth == 0)
		{
			y_loc = y_loc+1;
			x_loc = 1;
		}  else 
		{
			x_loc = x_loc+1;
		}
	}
}