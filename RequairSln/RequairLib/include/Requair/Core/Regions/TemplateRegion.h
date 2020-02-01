#pragma once

#include <Requair/Utils/DllUtils.h>

#include <GameBackbone/Core/GameRegion.h>
#include <Requair/Core/GameObjects/Pot.h>


namespace REQ
{
    class libRequair TemplateRegion : public GB::GameRegion
    {
    public:
        using GB::GameRegion::GameRegion;
    };
}