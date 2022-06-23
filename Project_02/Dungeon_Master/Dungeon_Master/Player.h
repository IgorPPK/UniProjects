#pragma once
#include"stdafx.h"

enum PLAYER_ANIMATION_STATES{IDLE=0, MOVING_UP = 1, MOVING_DOWN=2, MOVING_RIGHT = 3, MOVING_LEFT = 4, MOVING_RIP=5};

class Player
{
private:
	sf::Sprite sprite;
	sf::Texture texturesheet;
	//Animation
	sf::Clock animationTimer;
	short animState;
	sf::IntRect currentFrame;
	//Movement and attackpeed

	float attackCooldown;
	float attackCooldownMax;
	//stats
	int hp;
	int hpmax;

	//GUI

	//Core

	void initTexture();
	void initSprite();
	void initAnimations();
	void initVariables(); 

	//void initGUI();

public:
	Player();
	~Player();
	
	float playerDirX;
	float playerDirY;

	//Accesors
	const sf::Vector2f& getPos() const;
	const sf::FloatRect getBounds() const;
	const int& getHp() const;
	const int& getHpMax() const;
	//Modifiers
	void setPosition(const sf::Vector2f pos);
	void setPosition(const float x, const float y);
	void setHp(const int hp);
	void loseHp(const int value);

	const bool canAttack();
	void updateAttack();
	void updateMovement();
	void updateAnimations();
	void update();
	void render(sf::RenderTarget& target);
};

