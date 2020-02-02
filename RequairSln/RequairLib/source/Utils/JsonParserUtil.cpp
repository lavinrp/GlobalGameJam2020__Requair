#pragma once

#include <Requair/Utils/JsonParserUtil.h>

#include <Requair/Core/Actions/Action.h>
#include <Requair/Core/Actions/AnimationAction.h>
#include <Requair/Core/Actions/ForkAction.h>
#include <Requair/Core/Actions/MoveAction.h>
#include <Requair/Core/GameObjects/Item.h>
#include <Requair/Core/GameObjects/Pot.h>
#include <Requair/Utils/json.hpp>

#include <SFML/System/Vector2.hpp>

#include <string>
#include <memory>


const float tile_x_length = 128;
const float tile_y_length = 128;


std::unique_ptr<REQ::Item> REQ::ProcessItem(int classID, std::pair<int, int> location)
{
    // Pot object
    if (classID == 10)
    {
        return std::make_unique<Pot>(location.first * tile_x_length, location.second * tile_y_length);
    }
}

std::unique_ptr<REQ::Item> REQ::ProcessItem(nlohmann::json itemJson)
{
    int itemType = itemJson["Type"];
    nlohmann::json itemToCreate = itemJson["Location"];

    std::pair<int, int> location = { itemToCreate["x"], itemToCreate["y"] };
    return REQ::ProcessItem(itemType, location);
}

std::unique_ptr<REQ::Action> REQ::ProcessAction(nlohmann::json actionJson)
{
    std::unique_ptr<REQ::Action> returnAction;

    std::string actionType = actionJson["Type"];
    int AnimationToUse = actionJson["AnimationToUse"];

    if (actionType == "ForkAction")
    {
        nlohmann::json nextActionJson = actionJson["nextAction"];
        std::unique_ptr<REQ::Action> nextAction = REQ::ProcessAction(actionJson);

        nlohmann::json otherNextActionJson = actionJson["otherNextAction"];
        std::unique_ptr<REQ::Action> otherNextAction = REQ::ProcessAction(actionJson);

        return {}; // TODO: FIX ME std::make_unique<ForkAction>(nextAction, otherNextAction);
    }
    else
    {
        std::unique_ptr<REQ::Action> nextAction;
        nlohmann::json::iterator nextActionJson = actionJson.find("nextAction");
        if (nextActionJson == actionJson.end())
        {
            nextAction = REQ::ProcessAction(*nextActionJson);
        }

        nlohmann::json itemJson = actionJson["Item"];
        if (actionType == "AnimationAction")
        {
            std::unique_ptr<REQ::Item> item = REQ::ProcessItem(itemJson);
            returnAction = {}; // TODO: FIX ME std::make_unique<AnimationAction>(*(item.get()));

            /*if (nextAction)
            {
                returnAction->Then(std::move(nextAction));
            }*/
        }
        else if (actionType == "MoveAction")
        {
            std::unique_ptr<REQ::Item> item = REQ::ProcessItem(itemJson);

            nlohmann::json itemToCreate = actionJson["Destination"];
            sf::Vector2f location = { itemToCreate["x"], itemToCreate["y"] };
            returnAction = {}; // TODO: FIX ME std::make_unique<MoveAction>(*(item.get()), location);

            /*if (nextAction)
            {
                returnAction->Then(std::move(nextAction));
            }*/
        }
        else
        {
            // TODO: Throw
        }
    }

    return std::move(returnAction);
}
