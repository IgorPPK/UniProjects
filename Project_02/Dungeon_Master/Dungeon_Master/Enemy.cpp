#include "Enemy.h"


Enemy::Enemy(float pos_x,float pos_y)
{

	this->initVariables();
	this->sprite.setPosition(rand() % 900, 10.f);
	this->initTexture();
	this->initSprite();
	//this->sprite.setPosition(pos_x, pos_y);
}

void Enemy::updateMovement()
{
	if ((this->sprite.getPosition().y < 1000)&&(rand()%2==0))
	{
		this->sprite.move(2.f, 4.f);
	}
	else
	{
		this->sprite.move(-2.f, 4.f);
	}
	//
	
}
Enemy::~Enemy()
{
}

void Enemy::update()
{
	this->updateMovement();
}

void Enemy::render(sf::RenderTarget& target)
{
	target.draw(this->sprite);
}



sf::FloatRect Enemy::getBounds() const
{
	return this->sprite.getGlobalBounds();
}

const int& Enemy::getPoints()
{
	return this->points;
}

const int& Enemy::getDmage() const
{
	return this->damage;
}

void Enemy::initVariables()
{
	this->type	= 0;
	this->hpMax = 10;
	this->hp	= 0;
	this->damage= 2;
	this->points = 5;
}



void Enemy::updateEnemies()
{
}

void Enemy::initTexture()
{
	srand(static_cast<unsigned>(time(0)));
	this->type = rand() % 3;
	

	if (type == 0)
	{
		if (!this->texture.loadFromFile("Textures/Enemy_1.png"))
		{
			this->points = type + 1;
			this->hpMax= 10;//10
			std::cout << "ERROR::PLAYER::Could not load enemy 1\n";
		}
	}
	if (type == 1)
	{
		this->points = type + 1;
		this->hpMax = 15;
		if (!this->texture.loadFromFile("Textures/Enemy_02.png"))
		{
			std::cout << "ERROR::PLAYER::Could not load enemy 1\n";
		}
	}
	if (type == 2)
	{
		this->points = type + 1;
		this->hpMax = 20;//30
		if (!this->texture.loadFromFile("Textures/Enemy.png"))
		{
			std::cout << "ERROR::PLAYER::Could not load enemy 1\n";
		}
	}
}

void Enemy::initSprite()
{
	this->sprite.setTexture(this->texture);
//	sprite.setPosition((rand()+40)%1500, 100.f);
	sprite.setScale(5.5f, 5.5f);

}

