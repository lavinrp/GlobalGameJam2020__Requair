#pragma once

#include <ProjectTemplate/Utils/DllUtils.h>

#include <ProjectTemplate/Core/RuntimeRegion.h>


namespace PT
{
    class libProjectTemplate HeroRegion : public RuntimeRegion
    {
    public:
        HeroRegion(std::string jsonFile);
        HeroRegion() = delete;

    private:
        // Hero

    };
}