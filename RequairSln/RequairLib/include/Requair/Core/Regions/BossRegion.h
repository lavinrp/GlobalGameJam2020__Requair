#pragma once

#include <Requair/Utils/DllUtils.h>

#include <Requair/Core/Regions/TemplateRegion.h>


namespace REQ
{
    class libRequair BossRegion : public TemplateRegion
    {
    public:
        BossRegion(std::string jsonFile);
        BossRegion() = delete;


    private:
        std::unique_ptr<Item> item_list;
        std::unique_ptr<PhysicalObject> physical_object_list;

        using PhysicalObjectPtrVec = std::vector<std::unique_ptr<PhysicalObject>>;
        using ItemPointerVec = std::vector<std::unique_ptr<Item>>;

        std::pair< ItemPointerVec , PhysicalObjectPtrVec > ProcessJson();
        std::string m_jsonFile;

        // Player (boss)

    };
}