#pragma once
#include"stdafx.h"
#include"Player.h"
#include"Bullet.h"
#include"Enemy.h"

/*
	Class that acts as the game engine, wrapper class.
*/

class Game
{
private:

	sf::RenderWindow window;
	sf::Event ev;
	//Player
	Player* player;

	//Resources
	std::map <std::string,sf::Texture*> textures;
	std::vector<Bullet*> bullet;
	//Enemies
	float spawnTimer;
	float spawnTimerMax;
	std::vector<Enemy*> enemies;
	//World
	sf::Texture worldBackgroundTex;
	sf::Sprite worldBackground;

	void initWindow();
	void initPlayer();
	void initEnemies();
	//PLayer GUI
	sf::RectangleShape playerHpBar;
	sf::RectangleShape playerHpBarBack;

	sf::Text gameOverText;


	//system
	unsigned points;
	void initSystems();
	//GUI
	sf::Font font;
	sf::Text pointText;
public:
	Game();
	~Game();


	void windowEvents(); 
	void initTextures();
	
	const sf::RenderWindow& getWindow() const;
	void updatePlayer();
	void update();
	void updateGUI();
	void updateWorld();
	void updateColission();
	void updateBullets();
	void bulletInput();
	void updateEnemiesAndCombat();
	void initGUI();
	void initWorld();
	void renderGUI();
	void render();
	void renderPlayer();
	void renderWorld();
	void updatePlayerAndEnemies();

};

