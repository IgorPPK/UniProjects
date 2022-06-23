#include"stdafx.h"
#include "Player.h"
#include "Game.h"


Player::Player()
{
	this->initVariables();
	this->initTexture();
	this->initSprite();
	this->initAnimations();
	this->updateAttack();
}

Player::~Player()
{

}

const sf::Vector2f& Player::getPos() const
{
	return this->sprite.getPosition();
}

const sf::FloatRect Player::getBounds() const
{
	return this->sprite.getGlobalBounds();
}

const int& Player::getHp() const
{
	return this->hp;
}

const int& Player::getHpMax() const
{
	return this->hpmax;
}

void Player::setPosition(const sf::Vector2f pos)
{
	this->sprite.setPosition(pos);
}

void Player::setPosition(const float x, const float y)
{
	this->sprite.setPosition(x, y);
}

void Player::setHp(const int hp)
{
	this->hp = hp;
}

void Player::loseHp(const int value)
{
	this->hp -= value;
	if (this->hp < 0)
	{
		this->hp = 0;
	}
}

const bool Player::canAttack()
{
	if (this->attackCooldown >= this->attackCooldownMax)
	{
		this->attackCooldown = 0.f;
		return true;
	}
	return false;
}


void Player::updateAttack()
{
	if(this->attackCooldown<this->attackCooldownMax)
	this->attackCooldown += 0.25f;
}

void Player::updateMovement()
{
	this->animState = PLAYER_ANIMATION_STATES::IDLE;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		this->sprite.move(-3.f, 0.f);
		this->animState = PLAYER_ANIMATION_STATES::MOVING_LEFT;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		this->sprite.move(3.0f, 0.f);
		this->animState = PLAYER_ANIMATION_STATES::MOVING_RIGHT;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
	{
		this->sprite.move(0.f, -3.0);
		this->animState = PLAYER_ANIMATION_STATES::MOVING_UP;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	{
		this->sprite.move(0.f, 3.0);
		this->animState = PLAYER_ANIMATION_STATES::MOVING_DOWN;
	}
	
}


void Player::update()
{
	this->updateMovement();
	this->updateAnimations();
	this->updateAttack();
}

void Player::render(sf::RenderTarget& target)
{
	target.draw(this->sprite);
}

void Player::initTexture()
{
	if (!this->texturesheet.loadFromFile("Textures/mainCFrames.png"))
	{
		std::cout << "ERROR::PLAYER::Could not load mainCFrames\n";
	}
}

void Player::initSprite()
{
	this->sprite.setTexture(this->texturesheet);
	sprite.setScale(5.5f, 5.5f);
	sprite.setPosition(450, 800);
	this->currentFrame = sf::IntRect(0, 0, 16, 16);
	this->sprite.setTextureRect(this->currentFrame);

}

void Player::initAnimations()
{
	this->animationTimer.restart();
}

void Player::initVariables()
{
	this->animState=IDLE;
	this->attackCooldownMax = 10.f;
	this->attackCooldown = this->attackCooldownMax;
	this->playerDirX = 1.f;
	this->playerDirY = 0.f;

	this->hpmax = 50;
	this->hp = this->hpmax;


	
}

void Player::updateAnimations()
{
	if(this->animState==PLAYER_ANIMATION_STATES::IDLE)
	{
		/*this->playerDirX = 0.f;
		this->playerDirY = 1.f;*/
		if(this->animationTimer.getElapsedTime().asSeconds() >= 0.4f)
		{
			this->currentFrame.top = 0.f;
			this -> currentFrame.left += 16.f;
			if (this->currentFrame.left >= 64)
			{
				this->currentFrame.left = 0;
			}
			this->animationTimer.restart();
			this->sprite.setTextureRect(this->currentFrame);
		}
	}
	else if (this->animState == PLAYER_ANIMATION_STATES::MOVING_RIGHT)
	{
		this->playerDirX = 1.f;
		this->playerDirY = 0.f;
		if (this->animationTimer.getElapsedTime().asSeconds() >= 0.4f)
		{
			this->currentFrame.top = 48.f;
			this->currentFrame.left += 16.f;
			if (this->currentFrame.left >= 64)
			{
				this->currentFrame.left = 0;
			}
			this->animationTimer.restart();
			this->sprite.setTextureRect(this->currentFrame);
		}
	}
	else if (this->animState == PLAYER_ANIMATION_STATES::MOVING_LEFT)
	{
		this->playerDirX = -1.f;
		this->playerDirY = 0.f;
		if (this->animationTimer.getElapsedTime().asSeconds() >= 0.4f)
		{
			this->currentFrame.top = 64.f;
			this->currentFrame.left += 16.f;
			if (this->currentFrame.left >= 64)
			{
				this->currentFrame.left = 0;
			}
			this->animationTimer.restart();
			this->sprite.setTextureRect(this->currentFrame);
		}
	}
	else if (this->animState == PLAYER_ANIMATION_STATES::MOVING_DOWN)
	{
		this->playerDirX = 0.f;
		this->playerDirY = 1.f;
		if (this->animationTimer.getElapsedTime().asSeconds() >= 0.4f)
		{
			this->currentFrame.top = 16.f;
			this->currentFrame.left += 16.f;
			if (this->currentFrame.left >= 64)
			{
				this->currentFrame.left = 0;
			}
			this->animationTimer.restart();
			this->sprite.setTextureRect(this->currentFrame);
		}
	}
	else if (this->animState == PLAYER_ANIMATION_STATES::MOVING_UP)
	{

		this->playerDirX = 0.f;
		this->playerDirY = -1.f;
		if (this->animationTimer.getElapsedTime().asSeconds() >= 0.4f)
		{
			this->currentFrame.top = 32.f;
			this->currentFrame.left += 16.f;
			if (this->currentFrame.left >= 64)
			{
				this->currentFrame.left = 0;
			}
			this->animationTimer.restart();
			this->sprite.setTextureRect(this->currentFrame);
		}
	}
}

