#pragma once

#include <Requair/Utils/DllUtils.h>

#include <Requair/Core/Regions/TemplateRegion.h>

#include <Requair/Core/Boss/Boss.h>

namespace REQ
{
    class libRequair BossRegion : public TemplateRegion
    {
    public:
        BossRegion(std::string jsonFile);
        BossRegion(const BossRegion& other) = delete;
        BossRegion operator=(const BossRegion& other) = delete;
        BossRegion(BossRegion&& other) = delete;
        BossRegion operator=(BossRegion&& other) = delete;

		void HandleEvent(sf::Event& event) override;
		void update(sf::Int64 elapsedTime) override;


    private:
        using ItemPointerVec = std::vector<std::unique_ptr<Item>>;
        using PhysicalObjectPtrVec = std::vector<std::unique_ptr<PhysicalObject>>;

        ItemPointerVec m_item_list;
        PhysicalObjectPtrVec m_physical_object_list;

        std::pair< ItemPointerVec , PhysicalObjectPtrVec > ProcessJson();
        std::string m_jsonFile;

        // Player (boss)
		REQ::Boss boss;
		sf::Vector2f bossOrigin = sf::Vector2f(200, 200);
        float maxInteractionDistance = 100.0;
    };
}