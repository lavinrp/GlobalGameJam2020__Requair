#pragma once

#include <ProjectTemplate/Utils/DllUtils.h>

#include <ProjectTemplate/Core/RuntimeRegion.h>


namespace PT
{
    class libProjectTemplate BossRegion : public RuntimeRegion
    {
    public:
        BossRegion(std::string jsonFile);
        BossRegion() = delete;

    private:
        // Player (boss)

    };
}