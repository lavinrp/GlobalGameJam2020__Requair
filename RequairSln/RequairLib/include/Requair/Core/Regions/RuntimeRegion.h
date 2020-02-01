#pragma once

#include <Requair/Utils/DllUtils.h>
#include <Requair/Utils/json.hpp>

#include <Requair/Core/Regions/TemplateRegion.h>

#include <string>


namespace REQ
{
    class libRequair RuntimeRegion : public TemplateRegion
    {
    public:
        RuntimeRegion(const std::string& jsonFile);
        RuntimeRegion() = delete;

    private:
        void ProcessJson();

        std::string m_jsonFile;
        // vector<stuff> put map here

    };
}