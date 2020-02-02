#pragma once

#include <Requair/Utils/DllUtils.h>

#include <Requair/Core/Actions/Action.h>
#include <Requair/Core/GameObjects/Item.h>
#include <Requair/Utils/json.hpp>

#include <memory>
#include <utility>

namespace REQ {
    libRequair std::unique_ptr<Item> ProcessItem(int classID, std::pair<int, int> location);
    libRequair std::unique_ptr<Item> ProcessItem(nlohmann::json itemJson);
    libRequair std::unique_ptr<Action> ProcessAction(nlohmann::json actionJson);
}
