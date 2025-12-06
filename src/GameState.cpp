#include "GameState.h"
#include <iostream>
#include <algorithm>

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
    gameOverText.setPosition(windowWidth / 2 - 250.f, 50.f);
    
    finalScoreText.setFont(font);
    finalScoreText.setCharacterSize(35);
    finalScoreText.setFillColor(sf::Color::Yellow);
    finalScoreText.setPosition(windowWidth / 2 - 150.f, 160.f);
    
    leaderboardTitle.setFont(font);
    leaderboardTitle.setString("--- LEADERBOARD ---");
    leaderboardTitle.setCharacterSize(30);
    leaderboardTitle.setFillColor(sf::Color::Cyan);
    leaderboardTitle.setPosition(windowWidth / 2 - 150.f, 230.f);
    
    restartText.setFont(font);
    restartText.setString("Press ENTER to Play Again | Press ESC to Exit");
    restartText.setCharacterSize(22);
    restartText.setFillColor(sf::Color::White);
    restartText.setPosition(windowWidth / 2 - 280.f, 720.f);
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
    
    finalScoreText.setString("Your Score: " + std::to_string(finalScore));
    
    window.draw(gameOverText);
    window.draw(finalScoreText);
    window.draw(leaderboardTitle);
    
    // Draw leaderboard entries
    for (size_t i = 0; i < leaderboardTexts.size(); i++)
    {
        window.draw(leaderboardTexts[i]);
    }
    
    window.draw(restartText);
}

void GameStateManager::saveScore()
{
    std::ofstream file("scores.txt", std::ios::app);
    if (file.is_open())
    {
        file << playerName << ":" << finalScore << "\n";
        file.close();
        std::cout << "Score saved: " << playerName << " - " << finalScore << std::endl;
        
        // Reload leaderboard after saving
        loadLeaderboard();
    }
    else
    {
        std::cerr << "Could not open scores.txt to save score\n";
    }
}

void GameStateManager::loadLeaderboard()
{
    leaderboard.clear();
    leaderboardTexts.clear();
    
    std::ifstream file("scores.txt");
    if (file.is_open())
    {
        std::string line;
        while (std::getline(file, line))
        {
            size_t colonPos = line.find(':');
            if (colonPos != std::string::npos)
            {
                ScoreEntry entry;
                entry.name = line.substr(0, colonPos);
                entry.score = std::stoi(line.substr(colonPos + 1));
                leaderboard.push_back(entry);
            }
        }
        file.close();
    }
    
    // Sort leaderboard by score (highest first)
    std::sort(leaderboard.begin(), leaderboard.end(), 
              [](const ScoreEntry& a, const ScoreEntry& b) {
                  return a.score > b.score;
              });
    
    // Create text objects for top 10 scores
    int displayCount = std::min(10, (int)leaderboard.size());
    for (int i = 0; i < displayCount; i++)
    {
        sf::Text scoreText;
        scoreText.setFont(font);
        scoreText.setCharacterSize(22);
        
        // Highlight current player's score
        if (leaderboard[i].name == playerName && leaderboard[i].score == finalScore)
        {
            scoreText.setFillColor(sf::Color::Yellow);
            scoreText.setStyle(sf::Text::Bold);
        }
        else
        {
            scoreText.setFillColor(sf::Color::White);
        }
        
        std::string rank = std::to_string(i + 1) + ". ";
        std::string scoreStr = rank + leaderboard[i].name + " - " + std::to_string(leaderboard[i].score);
        scoreText.setString(scoreStr);
        scoreText.setPosition(400.f, 280.f + i * 35.f);
        
        leaderboardTexts.push_back(scoreText);
    }
}

void GameStateManager::resetForNewGame()
{
    playerName = "";
    nameEntered = false;
    finalScore = 0;
    nameInputText.setString("");
    leaderboard.clear();
    leaderboardTexts.clear();
    currentState = GameState::MAIN_MENU;
}