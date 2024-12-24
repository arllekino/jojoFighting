#pragma once
#include <string>
#include <unordered_map>
#include <SFML/Graphics.hpp>

#include "ActionType.h"
#include "CharacterType.h"
#include "ActionPathMap.h"

typedef std::unordered_map<CharacterType, ActionPathMap> CharacterActionMap;