#pragma once

#include <SFML/Graphics.hpp>
#include <unordered_map>
#include "UserType.h"
#include "UserEvent.h"
#include "MenuUserEvent.h"

class PollEvent
{
public:
	PollEvent();
	~PollEvent();

	void onEventMenu(sf::RenderWindow& window, MenuUserEvent& userEvent);
	void onEventGame(sf::RenderWindow& window, std::unordered_map<UserType, UserEvent>& users);
	void checkGamePadMenu(sf::RenderWindow& window, MenuUserEvent& userEvent, bool& userAction, int indexGamePad);
	void checkGamePadGame(UserEvent& userEvent, bool& userAction, int indexGamePad);

private:

};