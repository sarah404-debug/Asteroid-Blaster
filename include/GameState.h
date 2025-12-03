#ifndef GAMESTATE_H
#define GAMESTATE_H

#include <SFML/Graphics.hpp>
#include <string>
#include <fstream>

enum class GameState { MAIN_MENU, PLAYING, GAME_OVER };

class GameStateManager
{
private:
    GameState currentState;
    sf::Font font;
    bool fontLoaded;
    
    // Main Menu
    sf::Text titleText;
    sf::Text startText;
    sf::Text namePromptText;
    sf::Text nameInputText;
    std::string playerName;
    bool nameEntered;
    
    // Game Over
    sf::Text gameOverText;
    sf::Text finalScoreText;
    sf::Text restartText;
    
    int finalScore;

public:
    GameStateManager();
    
    void setupTexts(float windowWidth, float windowHeight);
    void handleTextInput(sf::Event& event);
    void drawMainMenu(sf::RenderWindow& window);
    void drawGameOver(sf::RenderWindow& window);
    
    GameState getCurrentState() const { return currentState; }
    void setGameState(GameState state) { currentState = state; }
    
    std::string getPlayerName() const { return playerName; }
    bool isNameEntered() const { return nameEntered; }
    
    void setFinalScore(int score) { finalScore = score; }
    void saveScore();
    void resetForNewGame();
};

#endif