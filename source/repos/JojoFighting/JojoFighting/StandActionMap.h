#pragma once
#include <string>
#include <unordered_map>
#include <SFML/Graphics.hpp>

#include "ActionType.h"
#include "StandType.h"
#include "ActionPathMap.h"

typedef std::unordered_map<StandType, ActionPathMap> StandActionMap;