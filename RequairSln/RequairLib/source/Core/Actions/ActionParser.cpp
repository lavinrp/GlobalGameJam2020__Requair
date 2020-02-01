#include <Requair/Core/Actions/ActionParser.h>

#include <Requair/Core/Actions/AnimationAction.h>
#include <Requair/Core/Actions/ForkAction.h>
#include <Requair/Core/Actions/MoveAction.h>
#include <Requair/Utils/json.hpp>


#include <string>
#include <fstream>
#include <streambuf>
#include <memory>

using namespace REQ;

ActionParser::ActionParser(const std::string& jsonFile) {

}

std::vector<std::unique_ptr<Action>> ActionParser::ProcessJson(const std::string& jsonFile) 
{
    // read file
    std::ifstream openFile{ jsonFile };
    nlohmann::json actionFile = nlohmann::json::parse(openFile);

    nlohmann::json actionJson = actionFile["Action"];

    std::unique_ptr<Action> action = ProcessAction(actionJson);


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

std::unique_ptr<Action> ActionParser::ProcessAction(nlohmann::json actionJson)
{
    std::string actionType = actionJson["type"];
    std::string itemToCreate = actionJson["itemToCreate"];
    int AnimationToUse = actionJson["AnimationToUse"];

    

    if (actionType == "ForkAction")
    {
        nlohmann::json nextActionJson = actionJson["nextAction"];
        std::unique_ptr<Action> nextAction = ProcessAction(actionJson);

        nlohmann::json otherNextActionJson = actionJson["otherNextAction"];
        std::unique_ptr<Action> otherNextAction = ProcessAction(actionJson);

        std::unique_ptr<Action> action = std::make_unique<ForkAction>(nextAction, otherNextAction);
    }
    else
    {
        nlohmann::json::iterator nextActionJson = actionJson.find("nextAction");
        if (nextActionJson == actionJson.end())
        {
            std::unique_ptr<Action> nextAction = ProcessAction(*nextActionJson);
        }

        if (actionType == "AnimationAction")
        {
            // TODO: pass in item
            //Item item = std::make_unique<Item>();
            std::unique_ptr<Action> nextAction = std::make_unique<AnimationAction>(/*item*/);
        }
        else if (actionType == "MoveAction")
        {
            // TODO: pass in item
            //Item item = std::make_unique<Item>();
            std::unique_ptr<Action> nextAction = std::make_unique<MoveAction>(/*item, start, end*/);
        }
        else
        {
            // TODO: Throw
        }
    }

    std::unique_ptr<Action> action = ProcessAction(actionJson);
}