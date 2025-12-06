
#include <SFML/Graphics.hpp>
#include <time.h>
#include <list>
#include <sstream>
#include <iostream>
#include "Globals.h"
#include "Animation.h"
#include "Entity.h"
#include "Asteroid.h"
#include "Bullet.h"
#include "Player.h"
#include "PowerUp.h"
#include "GameState.h"

using namespace sf;

int main()
{
    srand(time(0));

    RenderWindow app(VideoMode(W, H), "Asteroid Blaster!");
    app.setFramerateLimit(60);

    // Game State Manager
    GameStateManager gameStateManager;
    gameStateManager.setupTexts(W, H);

    Texture t1,t2,t3,t4,t5,t6,t7;
    t1.loadFromFile("images/spaceship.png");
    t2.loadFromFile("images/bg11.png");
    t3.loadFromFile("images/explosions/type_C.png");
    t4.loadFromFile("images/rock.png");
    t5.loadFromFile("images/fire_blue.png");
    t6.loadFromFile("images/rock_small.png");
    t7.loadFromFile("images/explosions/type_B.png");

    Texture tHeart;
    tHeart.loadFromFile("images/heart.png");

    Texture tChai, tPakola, tParatha;
    tChai.loadFromFile("images/chai.png");
    tPakola.loadFromFile("images/pakola.png");
    tParatha.loadFromFile("images/paratha.png");

    Font font;
    if (!font.loadFromFile("fonts/arial.ttf"))
    {
        return -1;
    }

    int score = 0;
    Text scoreText;
    scoreText.setFont(font);
    scoreText.setCharacterSize(30);
    scoreText.setFillColor(Color::White);
    scoreText.setPosition(W - 150, 20);

    int lives = 5;

    t1.setSmooth(true);
    t2.setSmooth(true);

    Sprite background(t2);

    Animation sExplosion(t3, 0,0,256,256, 48, 0.5);
    Animation sRock(t4, 0,0,64,64, 16, 0.2);
    Animation sRock_small(t6, 0,0,64,64, 16, 0.2);
    Animation sBullet(t5, 0,0,32,64, 16, 0.8);
    Animation sPlayer(t1, 40,0,40,40, 1, 0);
    Animation sPlayer_go(t1, 40,40,40,40, 1, 0);
    Animation sExplosion_ship(t7, 0,0,192,192, 64, 0.5);

    std::list<Entity*> entities;
    Player *p = nullptr;

    // Function to start/restart game
    auto startGame = [&]() {
        // Clear entities
        for(auto e : entities) delete e;
        entities.clear();
        
        // Reset game variables
        score = 0;
        lives = 5;
        
        // Create asteroids
        for(int i=0;i<10;i++)
        {
            Asteroid *a = new Asteroid();
            a->settings(sRock, rand()%W, rand()%H, rand()%360, 25);
            entities.push_back(a);
        }
        
        // Create player
        p = new Player();
        p->settings(sPlayer,200,200,0,20);
        entities.push_back(p);
        
        gameStateManager.setGameState(GameState::PLAYING);
    };

    while (app.isOpen())
    {
        Event event;
        while (app.pollEvent(event))
        {
            if (event.type == Event::Closed)
                app.close();
            
            if (event.type == Event::KeyPressed && event.key.code == Keyboard::Escape)
                app.close();
            
            // Handle text input for name
            gameStateManager.handleTextInput(event);
            
            // Handle Enter key
            if (event.type == Event::KeyPressed && event.key.code == Keyboard::Return)
            {
                if (gameStateManager.getCurrentState() == GameState::MAIN_MENU && 
                    gameStateManager.isNameEntered())
                {
                    startGame();
                }
                else if (gameStateManager.getCurrentState() == GameState::GAME_OVER)
                {
                    gameStateManager.resetForNewGame();
                }
            }
            
            // Shooting (only when playing)
            if (gameStateManager.getCurrentState() == GameState::PLAYING)
            {
                if (event.type == Event::KeyPressed && event.key.code == Keyboard::Space)
                {
                    Bullet *b = new Bullet();
                    b->settings(sBullet,p->x,p->y,p->angle,10);
                    entities.push_back(b);
                }
            }
        }

        // Game Logic - only when playing
        if (gameStateManager.getCurrentState() == GameState::PLAYING)
        {
            if (Keyboard::isKeyPressed(Keyboard::Right)) p->angle+=3;
            if (Keyboard::isKeyPressed(Keyboard::Left))  p->angle-=3;
            if (Keyboard::isKeyPressed(Keyboard::Up)) p->thrust=true;
            else p->thrust=false;

            for(auto a:entities)
            for(auto b:entities)
            {
                if (a->name=="asteroid" && b->name=="bullet")
                if (isCollide(a,b))
                {
                    a->life=false;
                    b->life=false;
                    score++;

                    Entity *e = new Entity();
                    e->settings(sExplosion,a->x,a->y);
                    e->name="explosion";
                    entities.push_back(e);

                    for(int i=0;i<2;i++)
                    {
                        if (a->R==15) continue;
                        Entity *e = new Asteroid();
                        e->settings(sRock_small,a->x,a->y,rand()%360,15);
                        entities.push_back(e);
                    }
                }

                if (a->name=="player" && b->name=="asteroid")
                if (isCollide(a,b))
                {
                    if (!p->hasShield)
                    {
                        b->life=false;

                        Entity *e = new Entity();
                        e->settings(sExplosion_ship,a->x,a->y);
                        e->name="explosion";
                        entities.push_back(e);

                        p->settings(sPlayer,W/2,H/2,0,20);
                        p->dx=0;
                        p->dy=0;
                        
                        lives--;
                        
                        if (lives <= 0)
                        {
                            gameStateManager.setFinalScore(score);
                            gameStateManager.saveScore();
                            gameStateManager.setGameState(GameState::GAME_OVER);
                        }
                    }
                    else
                    {
                        b->life=false;
                    }
                }

                if (a->name=="player" && b->name=="powerup")
                if (isCollide(a,b))
                {
                    PowerUp* pw = dynamic_cast<PowerUp*>(b);
                    if (pw)
                    {
                        if (pw->type == PowerUpType::CHAI)
                        {
                            p->activateSpeedBoost();
                        }
                        else if (pw->type == PowerUpType::PAKOLA)
                        {
                            p->addLife(lives);
                        }
                        else if (pw->type == PowerUpType::PARATHA)
                        {
                            p->activateShield();
                        }
                        pw->life = false;
                    }
                }
            }

            if (p->thrust) p->anim = sPlayer_go;
            else p->anim = sPlayer;

            for(auto e:entities)
            if (e->name=="explosion")
            if (e->anim.isEnd()) e->life=false;

            if (rand()%200==0)
            {
                Asteroid *a = new Asteroid();
                a->settings(sRock,0,rand()%H,rand()%360,25);
                entities.push_back(a);
            }

            if (rand()%400==0)
            {
                int powerupCount = 0;
                for(auto e : entities)
                {
                    if (e->name == "powerup")
                        powerupCount++;
                }
                
                if (powerupCount < 5)
                {
                    PowerUpType randomType = static_cast<PowerUpType>(rand() % 3);
                    
                    Texture* tex = nullptr;
                    if (randomType == PowerUpType::CHAI) tex = &tChai;
                    else if (randomType == PowerUpType::PAKOLA) tex = &tPakola;
                    else tex = &tParatha;
                    
                    PowerUp* pw = new PowerUp(randomType, tex);
                    pw->x = rand() % W;
                    pw->y = rand() % H;
                    pw->R = 20;
                    pw->sprite.setPosition(pw->x, pw->y);
                    entities.push_back(pw);
                }
            }

            for(auto i=entities.begin(); i!=entities.end();)
            {
                Entity *e = *i;

                e->update();
                e->anim.update();

                if (e->life==false) {i=entities.erase(i); delete e;}
                else i++;
            }
        }

        // Drawing
        app.clear();
        app.draw(background);

        if (gameStateManager.getCurrentState() == GameState::MAIN_MENU)
        {
            gameStateManager.drawMainMenu(app);
        }
        else if (gameStateManager.getCurrentState() == GameState::PLAYING)
        {
            for(auto i:entities)
                i->draw(app);

            std::stringstream ss;
            ss << "Score: " << score;
            scoreText.setString(ss.str());
            app.draw(scoreText);

            for(int i = 0; i < lives; i++)
            {
                Sprite heartSprite(tHeart);
                heartSprite.setPosition(20 + i * 40, 20);
                heartSprite.setScale(0.05f, 0.05f);
                app.draw(heartSprite);
            }

            if (p->hasShield)
            {
                CircleShape shieldCircle(p->R + 10);
                shieldCircle.setFillColor(Color(0, 255, 255, 50));
                shieldCircle.setOutlineColor(Color(0, 255, 255, 200));
                shieldCircle.setOutlineThickness(3);
                shieldCircle.setPosition(p->x, p->y);
                shieldCircle.setOrigin(p->R + 10, p->R + 10);
                app.draw(shieldCircle);
            }
        }
        else if (gameStateManager.getCurrentState() == GameState::GAME_OVER)
        {
            gameStateManager.drawGameOver(app);
        }
       
        app.display();
    }

    // Cleanup
    for(auto e : entities) delete e;

    return 0;
}