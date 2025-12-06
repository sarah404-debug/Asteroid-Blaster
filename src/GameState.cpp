#include <algorithm>GameStateManager::GameStateManager()
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
