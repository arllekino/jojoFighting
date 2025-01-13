#include "PollEvent.h"

#include <Windows.h>
#include <iostream>

PollEvent::PollEvent()
{}

PollEvent::~PollEvent()
{}

void PollEvent::onEventGame(sf::RenderWindow& window, std::unordered_map<UserType, UserEvent>& users)
{
	bool firstUserAction = false;
	bool secondUserAction = false;

	if (GetAsyncKeyState('A') & 0x8000)
	{
		users[firstUser] = UserEvent::onLeft;
		firstUserAction = true;
	}
	if (GetAsyncKeyState('W') & 0x8000)
	{
		users[firstUser] = UserEvent::onUp;
		firstUserAction = true;
	}
	if (GetAsyncKeyState('D') & 0x8000)
	{
		users[firstUser] = UserEvent::onRight;
		firstUserAction = true;
	}
	if (GetAsyncKeyState('E') & 0x8000)
	{
		users[firstUser] = UserEvent::onMediumArmAttack;
		firstUserAction = true;
	}
	if (GetAsyncKeyState('S') & 0x8000)
	{
		users[firstUser] = UserEvent::onCrouching;
		firstUserAction = true;
	}
	if (GetAsyncKeyState('Q') & 0x8000)
	{
		users[firstUser] = UserEvent::onCharacterStandAttackUp;
		firstUserAction = true;
	}
	if (GetAsyncKeyState('X') & 0x8000)
	{
		users[firstUser] = UserEvent::onSummonStand;
		firstUserAction = true;
	}
	if (GetAsyncKeyState('C') & 0x8000)
	{
		users[firstUser] = UserEvent::ult;
		firstUserAction = true;
	}
	if (GetAsyncKeyState('F') & 0x8000)
	{
		users[firstUser] = UserEvent::onSupportCall;
		firstUserAction = true;
	}
	if (GetAsyncKeyState('Z') & 0x8000)
	{
		users[firstUser] = UserEvent::ridicule;
		firstUserAction = true;
	}
	if (GetAsyncKeyState('W') & 0x8000 && GetAsyncKeyState('D') & 0x8000)
	{
		users[firstUser] = UserEvent::onUpRight;
		firstUserAction = true;
	}
	if (GetAsyncKeyState('W') & 0x8000 && GetAsyncKeyState('A') & 0x8000)
	{
		users[firstUser] = UserEvent::onUpLeft;
		firstUserAction = true;
	}
	if (GetAsyncKeyState('S') & 0x8000 && GetAsyncKeyState('E') & 0x8000)
	{
		users[firstUser] = UserEvent::onCrouchPunchForward;
		firstUserAction = true;
	}
	if (GetAsyncKeyState('S') & 0x8000 && GetAsyncKeyState('Q') & 0x8000)
	{
		users[firstUser] = UserEvent::onCrouchPunchPowerful;
		firstUserAction = true;
	}
	if (GetAsyncKeyState(VK_LSHIFT) & 0x8000 && GetAsyncKeyState('Q') & 0x8000)
	{
		users[firstUser] = UserEvent::onCharacterStandAttackDown;
		firstUserAction = true;
	}
	if (GetAsyncKeyState(VK_LSHIFT) & 0x8000 && GetAsyncKeyState('C') & 0x8000)
	{
		users[firstUser] = UserEvent::onMegaUlt;
		firstUserAction = true;
	}

	checkGamePadGame(users[firstUser], firstUserAction, 0);

	if (!firstUserAction)
	{
		users[firstUser] = UserEvent::none;
	}


	if (GetAsyncKeyState('J') & 0x8000)
	{
		users[secondUser] = UserEvent::onLeft;
		secondUserAction = true;
	}
	if (GetAsyncKeyState('I') & 0x8000)
	{
		users[secondUser] = UserEvent::onUp;
		secondUserAction = true;
	}
	if (GetAsyncKeyState('L') & 0x8000)
	{
		users[secondUser] = UserEvent::onRight;
		secondUserAction = true;
	}
	if (GetAsyncKeyState('U') & 0x8000)
	{
		users[secondUser] = UserEvent::onMediumArmAttack;
		secondUserAction = true;
	}
	if (GetAsyncKeyState('K') & 0x8000)
	{
		users[secondUser] = UserEvent::onCrouching;
		secondUserAction = true;
	}
	if (GetAsyncKeyState('O') & 0x8000)
	{
		users[secondUser] = UserEvent::onCharacterStandAttackUp;
		secondUserAction = true;
	}
	if (GetAsyncKeyState('M') & 0x8000)
	{
		users[secondUser] = UserEvent::onSummonStand;
		secondUserAction = true;
	}
	if (GetAsyncKeyState('N') & 0x8000)
	{
		users[secondUser] = UserEvent::ult;
		secondUserAction = true;
	}
	if (GetAsyncKeyState('H') & 0x8000)
	{
		users[secondUser] = UserEvent::onSupportCall;
		secondUserAction = true;
	}
	if (GetAsyncKeyState('B') & 0x8000)
	{
		users[secondUser] = UserEvent::ridicule;
		secondUserAction = true;
	}
	if (GetAsyncKeyState('I') & 0x8000 && GetAsyncKeyState('J') & 0x8000)
	{
		users[secondUser] = UserEvent::onUpLeft;
		secondUserAction = true;
	}
	if (GetAsyncKeyState('I') & 0x8000 && GetAsyncKeyState('L') & 0x8000)
	{
		users[secondUser] = UserEvent::onUpRight;
		secondUserAction = true;
	}
	if (GetAsyncKeyState('K') & 0x8000 && GetAsyncKeyState('U') & 0x8000)
	{
		users[secondUser] = UserEvent::onCrouchPunchForward;
		secondUserAction = true;
	}
	if (GetAsyncKeyState('K') & 0x8000 && GetAsyncKeyState('O') & 0x8000)
	{
		users[secondUser] = UserEvent::onCrouchPunchPowerful;
		secondUserAction = true;
	}
	if (GetAsyncKeyState(VK_RSHIFT) & 0x8000 && GetAsyncKeyState('O') & 0x8000)
	{
		users[secondUser] = UserEvent::onCharacterStandAttackDown;
		secondUserAction = true;
	}
	if (GetAsyncKeyState(VK_RSHIFT) & 0x8000 && GetAsyncKeyState('N') & 0x8000)
	{
		users[secondUser] = UserEvent::onMegaUlt;
		secondUserAction = true;
	}

	checkGamePadGame(users[secondUser], secondUserAction, 1);

	if (!secondUserAction)
	{
		users[secondUser] = UserEvent::none;
	}

	if (GetAsyncKeyState(VK_ESCAPE) & 0x8000)
	{
		window.close();
	}
}

void PollEvent::onEventMenu(sf::RenderWindow& window, MenuUserEvent& userEvent)
{
	bool userAction = false;

	if (GetAsyncKeyState(VK_LEFT) & 0x8000)
	{
		userEvent = MenuUserEvent::left;
		userAction = true;
	}

	if (GetAsyncKeyState(VK_RIGHT) & 0x8000)
	{
		userEvent = MenuUserEvent::right;
		userAction = true;
	}

	if (GetAsyncKeyState('1') & 0x8000)
	{
		userEvent = MenuUserEvent::onToggleFirstUser;
		userAction = true;
	}

	if (GetAsyncKeyState('2') & 0x8000)
	{
		userEvent = MenuUserEvent::onToggleSecondUser;
		userAction = true;
	}

	if (GetAsyncKeyState(VK_RETURN) & 0x8000)
	{
		userEvent = MenuUserEvent::onEnter;
		userAction = true;
	}

	checkGamePadMenu(window, userEvent, userAction, 0);

	if (!userAction)
		userEvent = MenuUserEvent::noAction;
	else
		Sleep(200);

	if (GetAsyncKeyState(VK_ESCAPE) & 0x8000)
	{
		window.close();
	}
}

void PollEvent::checkGamePadMenu(sf::RenderWindow& window, MenuUserEvent& userEvent, bool& userAction, int indexGamePad)
{
	sf::Joystick::update();
	if (sf::Joystick::isConnected(indexGamePad))
	{
		if (sf::Joystick::isButtonPressed(indexGamePad, 4))
		{
			userEvent = MenuUserEvent::left;
			userAction = true;
		}
		if (sf::Joystick::isButtonPressed(indexGamePad, 5))
		{
			userEvent = MenuUserEvent::right;
			userAction = true;
		}
		if (sf::Joystick::isButtonPressed(indexGamePad, 2))
		{
			userEvent = MenuUserEvent::onToggleFirstUser;
			userAction = true;
		}
		if (sf::Joystick::isButtonPressed(indexGamePad, 3))
		{
			userEvent = MenuUserEvent::onToggleSecondUser;
			userAction = true;
		}
		if (sf::Joystick::isButtonPressed(indexGamePad, 7))
		{
			userEvent = MenuUserEvent::onEnter;
			userAction = true;
		}
	}
}

void PollEvent::checkGamePadGame(UserEvent& userEvent, bool& userAction, int indexGamePad)
{
	sf::Joystick::update();
	if (sf::Joystick::isConnected(indexGamePad))
	{
		if (sf::Joystick::getAxisPosition(indexGamePad, sf::Joystick::X) < -50)
		{
			userEvent = UserEvent::onLeft;
			userAction = true;
		}
		if (sf::Joystick::getAxisPosition(indexGamePad, sf::Joystick::X) > 50)
		{
			userEvent = UserEvent::onRight;
			userAction = true;
		}
		if (sf::Joystick::getAxisPosition(indexGamePad, sf::Joystick::Y) < -50)
		{
			userEvent = UserEvent::onUp;
			userAction = true;
		}
		if (sf::Joystick::getAxisPosition(indexGamePad, sf::Joystick::Y) > 50)
		{
			userEvent = UserEvent::onCrouching;
			userAction = true;
		}
		if (sf::Joystick::isButtonPressed(indexGamePad, 3))
		{
			userEvent = UserEvent::onMediumArmAttack;
			userAction = true;
		}
		if (sf::Joystick::isButtonPressed(indexGamePad, 1))
		{
			userEvent = UserEvent::onCharacterStandAttackUp;
			userAction = true;
		}
		if (sf::Joystick::isButtonPressed(indexGamePad, 5))
		{
			userEvent = UserEvent::ult;
			userAction = true;
		}
		if (sf::Joystick::isButtonPressed(indexGamePad, 4))
		{
			userEvent = UserEvent::onSupportCall;
			userAction = true;
		}
		if (sf::Joystick::getAxisPosition(indexGamePad, sf::Joystick::Z) > 10)
		{
			userEvent = UserEvent::ridicule;
			userAction = true;
		}
		if (sf::Joystick::getAxisPosition(indexGamePad, sf::Joystick::Y) > 50 && sf::Joystick::isButtonPressed(indexGamePad, 2))
		{
			userEvent = UserEvent::onCrouchPunchForward;
			userAction = true;
		}
		if (sf::Joystick::getAxisPosition(indexGamePad, sf::Joystick::Y) > 50 && sf::Joystick::isButtonPressed(indexGamePad, 3))
		{
			userEvent = UserEvent::onCrouchPunchPowerful;
			userAction = true;
		}
		if (sf::Joystick::isButtonPressed(indexGamePad, 2))
		{
			userEvent = UserEvent::onCharacterStandAttackDown;
			userAction = true;
		}
	}
}