#pragma once
#include"stdafx.h";
class Enemy
{
private:

	int type=0;
	int hp=0;
	int hpMax=10;
	int damage=2;
	int points=1;

	sf::Clock movementTimer;

	sf::Sprite sprite;
	sf::Texture texture;

	void initTexture();
	void initSprite();
	void initVariables();
	void updateMovement();
	void updateEnemies();

	int enemyCounterMax = 20;

public:
	Enemy(float pos_X, float pos_Y);
	virtual ~Enemy();
	void update();
	void render(sf::RenderTarget& target);

	float start_x = 0.f;
	float start_y =0.f;
	
	sf::FloatRect getBounds() const;
	const int& getPoints();
	const int& getDmage()const;

};

