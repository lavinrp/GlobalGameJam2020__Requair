#include <Requair/Core/Actions/ActionParser.h>


#include <Requair/Core/GameObjects/Item.h>
#include <Requair/Utils/json.hpp>
#include <Requair/Utils/JsonParserUtil.h>


#include <string>
#include <fstream>
#include <streambuf>
#include <memory>

using namespace REQ;

ActionParser::ActionParser(const std::string& jsonFile) {

}

std::unique_ptr<Action> ActionParser::ProcessJson(const std::string& jsonFile) 
{
    // read file
    std::ifstream openFile{ jsonFile };
    nlohmann::json actionFile = nlohmann::json::parse(openFile);

    nlohmann::json actionJson = actionFile["Action"];
    
    return ProcessAction(actionJson);


    /*auto tiles_data = actionJson["layers"][0]["data"];
    int x_loc(1), y_loc(1);
    for (auto& element : tiles_data)
    {
        std::cout << "x location = " << x_loc << " y location = " << y_loc << " tile id" << element << '\n';

        if (x_loc % mapWidth == 0)
        {
            y_loc = y_loc + 1;
            x_loc = 1;
        }
        else
        {
            x_loc = x_loc + 1;
        }
    }*/
}
