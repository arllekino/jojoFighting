#pragma once

#include <SFML/Graphics.hpp>
#include <string>
#include <unordered_map>

#include "ActionType.h"
#include "CharacterType.h"

typedef std::unordered_map < CharacterType, std::unordered_map <ActionType, std::string >> AudioMapSounds;