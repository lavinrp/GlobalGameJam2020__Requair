#pragma once

#include <Requair/Utils/DllUtils.h>
#include <Requair/Utils/json.hpp>

#include <Requair/Core/Regions/TemplateRegion.h>
#include <Requair/Core/GameObjects/Item.h>
#include <Requair/Core/GameObjects/PhysicalObject.h>
#include <string>
#include <utility>


namespace REQ
{
    class libRequair RuntimeRegion : public TemplateRegion
    {
    public:
        RuntimeRegion(const std::string& jsonFile);
        RuntimeRegion(const RuntimeRegion&) = delete;
        RuntimeRegion(RuntimeRegion&&) = delete;
        RuntimeRegion& operator=(const RuntimeRegion&) = delete;
        RuntimeRegion& operator=(RuntimeRegion&&) = delete;
        RuntimeRegion() = delete;
    protected:
        std::vector<std::unique_ptr<Item>> item_list;
        std::vector<std::unique_ptr<PhysicalObject>> physical_object_list; 
        
    private:
        std::pair<std::vector<std::unique_ptr<Item>>, std::vector<std::unique_ptr<PhysicalObject>> > ProcessJson();

        std::string m_jsonFile;
        // vector<stuff> put map here

    };
}