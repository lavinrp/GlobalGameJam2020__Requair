#pragma once

#include <Requair/Utils/DllUtils.h>

#include <GameBackbone/Core/GameRegion.h>
#include <Requair/Core/GameObjects/Pot.h>


namespace REQ
{
    class libRequair TemplateRegion : public GB::GameRegion
    {
    public:
        TemplateRegion() : m_pot(400, 400)
        {
            addDrawable(1, &m_pot);
        }
        Pot m_pot;
    };
}