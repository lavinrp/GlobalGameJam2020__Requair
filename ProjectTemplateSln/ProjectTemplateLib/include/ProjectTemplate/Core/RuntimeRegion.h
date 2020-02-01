#pragma once

#include <ProjectTemplate/Utils/DllUtils.h>

#include <ProjectTemplate/Core/TemplateRegion.h>

#include <string>


namespace PT
{
    class libProjectTemplate RuntimeRegion : public TemplateRegion
    {
    public:
        RuntimeRegion(std::string jsonFile);
        RuntimeRegion() = delete;

    private:
        void ProcessJson();

        std::string m_jsonFile;
        // vector<stuff> put map here

    };
}