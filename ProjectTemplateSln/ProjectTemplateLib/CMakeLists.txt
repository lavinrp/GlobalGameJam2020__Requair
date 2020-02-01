# CMakeLists for ProjectTemplate library

cmake_minimum_required (VERSION 3.8)
add_library(ProjectTemplate SHARED
  "include/ProjectTemplate.h"
  "include/ProjectTemplate/Core/EventController.h"
  "include/ProjectTemplate/Core/Regions/BossRegion.h"
  "include/ProjectTemplate/Core/Regions/HeroRegion.h"
  "include/ProjectTemplate/Core/Regions/MainMenuRegion.h"
  "include/ProjectTemplate/Core/Regions/RuntimeRegion.h"
  "include/ProjectTemplate/Core/Regions/TemplateRegion.h"
  "include/ProjectTemplate/Utils/DllUtils.h"
  "include/ProjectTemplate/Utils/json.hpp"
  
  
  "source/Core/EventController.cpp"
  "source/Core/Regions/BossRegion.cpp"
  "source/Core/Regions/HeroRegion.cpp"
  "source/Core/Regions/MainMenuRegion.cpp"
  "source/Core/Regions/RuntimeRegion.cpp"
  "source/Core/Regions/TemplateRegion.cpp"
  "source/ProjectTemplate.cpp"
)
set_target_properties(ProjectTemplate PROPERTIES DEBUG_POSTFIX ${CMAKE_DEBUG_POSTFIX})

# GameBackbone has SFML as a public target. This means that it is automatically
# added to the target_link_libraries for ProjectTemplate
# ProjectTemplate still needs to find SFML for GB to link against though.
find_package(SFML 2 COMPONENTS network audio graphics window system)

find_package(GameBackbone 0.3.0 REQUIRED) 
target_link_libraries(ProjectTemplate PUBLIC GameBackbone) 

message("current source dir: ${CMAKE_CURRENT_SOURCE_DIR}")

target_include_directories(ProjectTemplate PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include")