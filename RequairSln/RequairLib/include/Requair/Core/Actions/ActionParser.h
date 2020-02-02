#pragma once

#include <Requair/Utils/DllUtils.h>

#include <Requair/Core/Actions/Action.h>
#include <Requair/Utils/json.hpp>

#include <string>
#include <memory>

namespace REQ
{
    class libRequair ActionParser
    {
    public:
        ActionParser(const std::string& jsonFile);
        ActionParser() = delete;

    private:
        std::unique_ptr<Action> ProcessJson(const std::string& jsonFile);
    };
}