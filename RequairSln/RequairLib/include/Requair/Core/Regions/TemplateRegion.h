#pragma once

#include <Requair/Utils/DllUtils.h>

#include <Requair/Core/GameObjects/Pot.h>
#include <Requair/Core/GameObjects/Wall.h>

#include <GameBackbone/Core/GameRegion.h>


namespace REQ
{
    class libRequair TemplateRegion : public GB::GameRegion
    {
    public:
        TemplateRegion() : m_pot(100, 450), m_wall(400, 100)
        {
            addDrawable(1, &m_pot);
            addDrawable(1, &m_wall);

            m_pot.SetVelocity({ 0.4, -0.1 });
        }

        void update(sf::Int64 elapsedTime) override
        {
            m_pot.Collide(m_wall);
            m_pot.update(elapsedTime);
            m_wall.update(elapsedTime);
        }

        Pot m_pot;
        Wall m_wall;
    };
}