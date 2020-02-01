#pragma once

#include <Requair/Utils/DllUtils.h>

#include <Requair/Core/Regions/RuntimeRegion.h>


namespace REQ
{
    class libRequair BossRegion : public RuntimeRegion
    {
    public:
        BossRegion(std::string jsonFile);
        BossRegion() = delete;

    private:
        // Player (boss)

    };
}