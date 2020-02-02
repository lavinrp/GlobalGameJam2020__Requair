# CMakeLists for Requair library

cmake_minimum_required (VERSION 3.8)
add_library(Requair SHARED
  "include/Requair.h"
  "include/Requair/Core/Actions/Action.h"
  "include/Requair/Core/Actions/ActionParser.h"
  "include/Requair/Core/Actions/AnimationAction.h"
  "include/Requair/Core/Actions/ForkAction.h"
  "include/Requair/Core/Actions/MoveAction.h"
  "include/Requair/Core/Boss/Boss.h"
  "include/Requair/Core/EventController.h"
  "include/Requair/Core/GameObjects/AnimatedItem.h"
  "include/Requair/Core/GameObjects/Arm.h"
  "include/Requair/Core/GameObjects/InteractiveObject.h"
  "include/Requair/Core/GameObjects/Item.h"
  "include/Requair/Core/GameObjects/Key.h"
  "include/Requair/Core/GameObjects/Leg.h"
  "include/Requair/Core/GameObjects/PhysicalObject.h"
  "include/Requair/Core/GameObjects/Pot.h"
  "include/Requair/Core/GameObjects/Wall.h"
  "include/Requair/Core/GameObjects/Floor.h"
  "include/Requair/Core/GameObjects/SpriteItem.h"
  "include/Requair/Core/Regions/BossRegion.h"
  "include/Requair/Core/Regions/HeroRegion.h"
  "include/Requair/Core/Regions/MainMenuRegion.h"
  "include/Requair/Core/Regions/TemplateRegion.h"
  "include/Requair/Utils/DllUtils.h"
  "include/Requair/Utils/json.hpp"
  "include/Requair/Utils/JsonParserUtil.h"
  
  
  "source/Core/Actions/Action.cpp"
  "source/Core/Actions/ActionParser.cpp"
  "source/Core/Actions/AnimationAction.cpp"
  "source/Core/Actions/ForkAction.cpp"
  "source/Core/Actions/MoveAction.cpp"
  "source/Core/Boss/Boss.cpp"
  "source/Core/EventController.cpp"
  "source/Core/GameObjects/Arm.cpp"
  "source/Core/GameObjects/AnimatedItem.cpp"
  "source/Core/GameObjects/Item.cpp"
  "source/Core/GameObjects/Key.cpp"
  "source/Core/GameObjects/Leg.cpp"
  "source/Core/GameObjects/PhysicalObject.cpp"
  "source/Core/GameObjects/Pot.cpp"
  "source/Core/GameObjects/Wall.cpp"
  "source/Core/GameObjects/Floor.cpp"
  "source/Core/GameObjects/SpriteItem.cpp"
  "source/Core/Regions/BossRegion.cpp"
  "source/Core/Regions/HeroRegion.cpp"
  "source/Core/Regions/MainMenuRegion.cpp"
  "source/Core/Regions/TemplateRegion.cpp"
  "source/Requair.cpp"
  "source/Utils/JsonParserUtil.cpp"

)
set_target_properties(Requair PROPERTIES DEBUG_POSTFIX ${CMAKE_DEBUG_POSTFIX})

# GameBackbone has SFML as a public target. This means that it is automatically
# added to the target_link_libraries for Requair
# Requair still needs to find SFML for GB to link against though.
find_package(SFML 2 COMPONENTS network audio graphics window system)

find_package(GameBackbone 0.3.0 REQUIRED) 
target_link_libraries(Requair PUBLIC GameBackbone) 

message("current source dir: ${CMAKE_CURRENT_SOURCE_DIR}")

target_include_directories(Requair PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include")