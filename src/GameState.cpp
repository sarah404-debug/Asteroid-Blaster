#include "GameState.h"
#include <iostream>

GameStateManager::GameStateManager()
    : currentState(GameState::MAIN_MENU), fontLoaded(false), nameEntered(false), finalScore(0)
{
    fontLoaded = font.loadFromFile("fonts/arial.ttf");
    if (!fontLoaded) {
        std::cerr << "Failed to load font for menus\n";
    }
}

void GameStateManager::setupTexts(float windowWidth, float windowHeight)
{
    if (!fontLoaded) return;
    
    // Main Menu Texts
    titleText.setFont(font);
    titleText.setString("ASTEROID BLASTER");
    titleText.setCharacterSize(70);
    titleText.setFillColor(sf::Color::Cyan);
    titleText.setStyle(sf::Text::Bold);
    titleText.setPosition(windowWidth / 2 - 300.f, 100.f);
    
    namePromptText.setFont(font);
    namePromptText.setString("Enter Your Name:");
    namePromptText.setCharacterSize(30);
    namePromptText.setFillColor(sf::Color::White);
    namePromptText.setPosition(windowWidth / 2 - 150.f, 300.f);
    
    nameInputText.setFont(font);
    nameInputText.setString("");
    nameInputText.setCharacterSize(35);
    nameInputText.setFillColor(sf::Color::Yellow);
    nameInputText.setPosition(windowWidth / 2 - 100.f, 350.f);
    
    startText.setFont(font);
    startText.setString("Press ENTER to Start");
    startText.setCharacterSize(28);
    startText.setFillColor(sf::Color::Green);
    startText.setPosition(windowWidth / 2 - 150.f, 450.f);
    
    // Game Over Texts
    gameOverText.setFont(font);
    gameOverText.setString("GAME OVER");
    gameOverText.setCharacterSize(80);
    gameOverText.setFillColor(sf::Color::Red);
    gameOverText.setStyle(sf::Text::Bold);
    gameOverText.setPosition(windowWidth / 2 - 250.f, 150.f);
    
    finalScoreText.setFont(font);
    finalScoreText.setCharacterSize(40);
    finalScoreText.setFillColor(sf::Color::White);
    finalScoreText.setPosition(windowWidth / 2 - 150.f, 300.f);
    
    restartText.setFont(font);
    restartText.setString("Press ENTER to Play Again\nPress ESC to Exit");
    restartText.setCharacterSize(25);
    restartText.setFillColor(sf::Color::Yellow);
    restartText.setPosition(windowWidth / 2 - 180.f, 450.f);
}

void GameStateManager::handleTextInput(sf::Event& event)
{
    if (currentState != GameState::MAIN_MENU) return;
    
    if (event.type == sf::Event::TextEntered)
    {
        if (event.text.unicode == '\b' && !playerName.empty()) // Backspace
        {
            playerName.pop_back();
        }
        else if (event.text.unicode == '\r' || event.text.unicode == '\n') // Enter
        {
            if (!playerName.empty())
            {
                nameEntered = true;
            }
        }
        else if (event.text.unicode < 128 && event.text.unicode != '\r' && 
                 event.text.unicode != '\n' && playerName.length() < 15)
        {
            playerName += static_cast<char>(event.text.unicode);
        }
        
        nameInputText.setString(playerName + "_");
    }
}

void GameStateManager::drawMainMenu(sf::RenderWindow& window)
{
    if (!fontLoaded) return;
    
    window.draw(titleText);
    window.draw(namePromptText);
    window.draw(nameInputText);
    
    if (nameEntered)
    {
        window.draw(startText);
    }
}

void GameStateManager::drawGameOver(sf::RenderWindow& window)
{
    if (!fontLoaded) return;
    
    finalScoreText.setString("Score: " + std::to_string(finalScore));
    
    window.draw(gameOverText);
    window.draw(finalScoreText);
    window.draw(restartText);
}

void GameStateManager::saveScore()
{
    std::ofstream file("scores.txt", std::ios::app);
    if (file.is_open())
    {
        file << playerName << ": " << finalScore << "\n";
        file.close();
        std::cout << "Score saved: " << playerName << " - " << finalScore << std::endl;
    }
    else
    {
        std::cerr << "Could not open scores.txt to save score\n";
    }
}

void GameStateManager::resetForNewGame()
{
    playerName = "";
    nameEntered = false;
    finalScore = 0;
    nameInputText.setString("");
    currentState = GameState::MAIN_MENU;
}