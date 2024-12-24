#include "Game.h"

#include <SFML/Graphics.hpp>

#include "JojoFightingMain.h"
#include "Character.h"
#include "TextureManager.h"
#include "AudioManager.h"
#include "UserType.h"
#include "UserEvent.h"
#include "CharacterType.h"
#include "StandType.h"
#include "StartGameButton.h"

#include "Drawable.h"
#include "PollEvent.h"
#include "UseCaseAction.h"

Game::Game(sf::Vector2u windowSize)
{
    pollEvent = new PollEvent{};
    drawable = new Drawable{};
    textureManager = new TextureManager();
    audioManager = new AudioManager();
    useCaseAction = new UseCaseAction(windowSize, audioManager);

    users[firstUser] = UserEvent::none;
    users[secondUser] = UserEvent::none;

    cards.push_back(new CharacterCard(CharacterType::jotaro, "assets/jotaro/JotaroPreviewCard.png", "Jotaro"));
    cards.push_back(new CharacterCard(CharacterType::dio, "assets/dio/DioPreviewCard.png", "Dio"));
    
    supportCards.push_back(new CharacterCard(SupportType::josuke, "assets/josuke/preview.png", "Josuke"));
    supportCards.push_back(new CharacterCard(SupportType::kakyoin, "assets/kakyoin/preview.png", "Kakyoin"));
    supportCards.push_back(new CharacterCard(SupportType::kira, "assets/kira/preview.png", "Kira Yoshikage"));

    startGameButton = new StartGameButton();

    sf::Vector2f newPosFor0 = sf::Vector2f(windowSize.x / 2 - cards[0]->getSize().x - 250, (windowSize.y - cards[0]->getSize().y) / 4);
    sf::Vector2f newPosFor1 = sf::Vector2f(windowSize.x / 2 + 200, (windowSize.y - cards[1]->getSize().y) / 4);
    cards[0]->setPosition(newPosFor0);
    cards[1]->setPosition(newPosFor1);

    auto newPosForSupportCard0 = sf::Vector2f(windowSize.x / 2 - 2 * supportCards[0]->getSize().x - 200, (windowSize.y - supportCards[0]->getSize().y) * 3 / 4);
    auto newPosForSupportCard1 = sf::Vector2f(windowSize.x / 2 - supportCards[1]->getSize().x / 2, (windowSize.y - supportCards[1]->getSize().y) * 3 / 4);
    auto newPosForSupportCard2 = sf::Vector2f(windowSize.x / 2 + supportCards[2]->getSize().x + 200, (windowSize.y - supportCards[2]->getSize().y) * 3 / 4);
    supportCards[0]->setPosition(newPosForSupportCard0);
    supportCards[1]->setPosition(newPosForSupportCard1);
    supportCards[2]->setPosition(newPosForSupportCard2);


    sf::Vector2f newPosForButton = sf::Vector2f((windowSize.x - startGameButton->getSize().x) / 2, 5 * windowSize.y / 6);
    startGameButton->setPosition(newPosForButton);

    healthBars[firstUser] = new HealthBarCharacter(sf::Vector2f(0 + windowPadding, windowPadding), 1);
    healthBars[secondUser] = new HealthBarCharacter(sf::Vector2f(windowSize.x - windowPadding, windowPadding), -1);
    
    ultProgressBars[firstUser] = new UltComponent(sf::Vector2f(0 + windowPadding, windowSize.y - windowPadding), 1);
    ultProgressBars[secondUser] = new UltComponent(sf::Vector2f(windowSize.x - windowPadding, windowSize.y - windowPadding), -1);

    timerComponent = new TimerComponent(windowSize);

    backgroundTexture.loadFromFile(menuBackgroundPath);
    backgroundSprite.setTexture(backgroundTexture);

    setGameState(GameState::menu);
    unselectAll();
}

Game::~Game()
{
    delete pollEvent;
    delete useCaseAction;
    delete drawable;
    delete textureManager;
    delete audioManager;
    delete timerComponent;

    for (auto& character : characters)
    {
        delete character.second;
    }

    for (auto& card : cards)
    {
        delete card;
    }

    for (auto& supportCard : supportCards)
    {
        delete supportCard;
    }

    for (auto& healthBar : healthBars)
    {
        delete healthBar.second;
    }
    
    for (auto& ultComponent : ultProgressBars)
    {
        delete ultComponent.second;
    }

    cards.clear();
}

GameState Game::getGameState()
{
    return gameState;
}

void Game::setGameState(GameState state)
{
    std::string backgroundPath;
    if (state == GameState::game)
        backgroundPath = gameBackgroundPath;
    else
    {
        for (auto& chosenCharacter : chosedCharacters)
        {
            chosenCharacter.second = noneCharacter;
        }
        for (auto& chosenSupport : chosedSupports)
        {
            chosenSupport.second = noneSupport;
        }

        backgroundPath = menuBackgroundPath;

        for (auto& character : characters)
        {
            delete character.second;
            character.second = nullptr;
        }
        
        unselectAll();
    }

    backgroundTexture.loadFromFile(backgroundPath);
    backgroundSprite.setTexture(backgroundTexture);
    audioManager->stopMusic();
    gameState = state;
    timerComponent->restartTimer();
}

void Game::menu(sf::RenderWindow& window)
{
    pollEvent->onEventMenu(window, menuUserEvent);

    useCaseAction->menu(this, characters, chosedCharacters, chosedSupports, menuUserEvent, cards, supportCards, startGameButton);

    drawable->drawMenu(window, backgroundSprite, cards, supportCards, startGameButton);

    audioManager->playMusic(gameState);
}

void Game::main(sf::RenderWindow& window)
{
    pollEvent->onEventGame(window, users);

    useCaseAction->processGame(this, users, characters, healthBars, ultProgressBars, window.getSize());
    if (gameState != game)
        return;

    drawable->drawGame(window, backgroundSprite, users, characters, healthBars, ultProgressBars, timerComponent);
 
    audioManager->playMusic(gameState);
}

sf::Time Game::getTime()
{
    return timerComponent->getTime();
}

void Game::unselectAll()
{
    for (auto& card : cards)
    {
        card->makeCardUnselected();
        card->makeCardUnhovered();
    }
    for (auto& supportCard : supportCards)
    {
        supportCard->makeCardUnselected();
        supportCard->makeCardUnhovered();
    }
    cards[0]->makeCardHovered();
}