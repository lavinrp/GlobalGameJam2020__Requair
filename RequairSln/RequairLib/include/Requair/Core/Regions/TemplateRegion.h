#pragma once

#include <Requair/Utils/DllUtils.h>

#include <GameBackbone/Core/GameRegion.h>


namespace REQ
{
    class libRequair TemplateRegion : public GB::GameRegion
    {
    public:
        using GB::GameRegion::GameRegion;
    };
}