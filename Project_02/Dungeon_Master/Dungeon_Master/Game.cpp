#include "Game.h"
#include"Player.h"
#include"Bullet.h"
#include"Enemy.h"

Game::Game()
{
	this->initWindow();
	this->initTextures();
	this->initGUI();
	this->initWorld();
	this->initSystems();
	this->initPlayer();
	this->initEnemies();

}

Game::~Game()
{
	delete this->player;
	

	//Delete textures (bullets)
	for (auto& i : this->textures)
	{
		delete i.second;
	}
	//Delete Bullets
	for (auto* i : this->bullet)
	{
		delete i;
	}
	//Delete enemies
	for (auto* i : this->enemies)
	{
		delete i;
	}
}

void Game::windowEvents()
{
	while (this->window.pollEvent(this->ev))
	{
		if (this->ev.type == sf::Event::Closed)
		{
			this->window.close();
		}
		if (this->ev.type == sf::Event::KeyPressed && this->ev.key.code == sf::Keyboard::Escape)
		{
			this->window.close();
		}
	}
}

void Game::initTextures()
{
	this->textures["BULLET"] = new sf::Texture();
	if (!this->textures["BULLET"]->loadFromFile("Textures/Bullet.png"))
	{
		std::cout << "Error: Bullet texture loading\n";
	}
		
}

void Game::updatePlayer()
{
	this->player->update();
}

void Game::update()
{
	
	


	this->updatePlayer();

	
	this->player->update();

	this->updateColission();

	this->updateBullets();

	this->windowEvents();
	if (this->player->getHp() > 0)
	{
	this->updateEnemiesAndCombat();

	this->updatePlayerAndEnemies();//!!!

	}
	
	this->updateGUI();
	
	this->updateWorld();

}

void Game::renderGUI()
{
	this->window.draw(this->pointText);
	this->window.draw(this->playerHpBarBack);
	this->window.draw(this->playerHpBar);
}

void Game::renderPlayer()
{
	this->player->render(this->window);
}

void Game::renderWorld()
{
	this->window.draw(this->worldBackground);
}

void Game::updatePlayerAndEnemies()
{
	unsigned counter = 0;
	for (auto* enemy : this->enemies)
	{
		enemy->update();

		//Bullet culling (top of screen)
		if (enemy->getBounds().top > this->window.getSize().y)
		{
			//Delete enemy
			delete this->enemies.at(counter);
			this->enemies.erase(this->enemies.begin() + counter);
		}
		//Enemy player collision
		else if (enemy->getBounds().intersects(this->player->getBounds()))
		{
			this->player->loseHp(5);
			std::cout << (this->player->getHp());
			delete this->enemies.at(counter);
			this->enemies.erase(this->enemies.begin() + counter);
		}

		++counter;
	}
}





void Game::render()
{
	this->window.clear();
	//Draw world
	this->renderWorld();
	//Render game
	this->renderPlayer();

	//bullet render
	for (auto* i : this->bullet)
	{
		i->render(&window);
	}

	//enemy render
	for (auto* i : this->enemies)
	{
		i->render(this->window);
	}

	//this->enemy->render(this->window);
	this->bulletInput();
	
	this->renderGUI();

	//game over screen

	if (this->player->getHp() <= 0)
		this->window.draw(this->gameOverText);


	this->window.display();

}

const sf::RenderWindow& Game::getWindow() const
{
	return this->window;
}

void Game::updateGUI()
{
	std::stringstream ss;
	ss << "Points: " << this->points;
	//<< "          HEALTH";
	this->pointText.setString(ss.str());

	
	float hpPercent=static_cast<float>	(this->player->getHp()) / this->player->getHpMax();
	this->playerHpBar.setSize(sf::Vector2f(300.f*hpPercent, 25.f));

}

void Game::updateWorld()
{
}

void Game::updateColission()
{
	//left 
	if (this->player->getBounds().left < 0.f)
	{
		this->player->setPosition(0.f, this->player->getBounds().top);
	}
	//right
	else if (this->player->getBounds().left + this->player->getBounds().width >= this->window.getSize().x)
	{
		this->player->setPosition(this->window.getSize().x - this->player->getBounds().width, this->player->getBounds().top);
	}


	//top
	if (this->player->getBounds().top < 0)
	{
		this->player->setPosition(this->player->getBounds().left,  0.f);
	}
	
	//bottom
	else if (this->player->getBounds().top + this->player->getBounds().height >= this->window.getSize().y)
	{
		this->player->setPosition(this->player->getBounds().left, this->window.getSize().y - this->player->getBounds().height);
	}
}

void Game::updateBullets()
{
	unsigned counter=0;
	//bullet render
	for (auto *i : this->bullet)
	{
		i->update();
		//bullet culling(top of screen)

		if (i->getBounds().top + i->getBounds().height > 900.f ||(i->getBounds().top + i->getBounds().height < 0.f)|| (i->getBounds().left + i->getBounds().height < 0.f) || (i->getBounds().left + i->getBounds().height > 1600.f))
		{
			
			delete this->bullet.at(counter);
			this->bullet.erase(this->bullet.begin() + counter);
			--counter;
			//std::cout << counter << "\n";
		}
		
		
		++counter;
		//std::cout << counter << "\n";
	}
	
}

void Game::updateEnemiesAndCombat()
{
	
	for (int i = 0; i < this->enemies.size(); ++i)
	{
		bool enemy_removed = false;
		this->enemies[i]->update();

		for(size_t k=0; k<this->bullet.size()&&!enemy_removed;++k)
		{
			if (this->bullet[k]->getBounds().intersects(this->enemies[i]->getBounds()))
			{
				this->points += this->enemies[i]->getPoints();
				this->bullet.erase(this->bullet.begin() + k);
				this->enemies.erase(this->enemies.begin() + i);

				enemy_removed = true;
			}

			
		}
		//remove enemy at the bottom of the screen
		if (!enemy_removed)
		{
			if (this->enemies[i]->getBounds().top > 1000)
			{
				this->enemies.erase(this->enemies.begin() + i);
				std::cout << this->enemies.size() << "\n";
			}
		}


	}


	this->spawnTimer += 1.f;
	if (this->spawnTimer >= this->spawnTimerMax)
	{
		this->enemies.push_back(new Enemy(0.f, 0.f));
		this->spawnTimer = 0.f;
		//++counter;
		//std::cout << counter << "\n";
	}
}

void Game::bulletInput()
{
	
	if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) && this->player->canAttack())
	{
		//std::cout << "pow\n";
		this->bullet.push_back(new Bullet(this->textures["BULLET"], this->player->getPos().x+20, this->player->getPos().y+20, this->player->playerDirX, this->player->playerDirY, 10.f));
	}
}


void Game::initWindow()
{	
	this->window.create(sf::VideoMode(1000, 900), "Dungeon Master", sf::Style::Close | sf::Style::Titlebar);
	this->window.setFramerateLimit(60);
	this->window.setVerticalSyncEnabled(false);
}

void Game::initPlayer()
{
	this->player = new Player();
	
}

void Game::initEnemies()
{
	this->spawnTimerMax = 50.f;
	this->spawnTimer = this->spawnTimerMax;
	

}

void Game::initSystems()
{
	this->points = 0;
}


void Game::initGUI()
{
	//Load font 
	if (!this->font.loadFromFile("Fonts/ka1.ttf"))
	{
		std::cout << "ERROR::GAME::Failed to load font" << "\n";
	}

	//Init point text points and hp
	this->pointText.setFont(this->font);
	this->pointText.setCharacterSize(36);
	this->pointText.setFillColor(sf::Color::White);
	this->pointText.setPosition(10.f, 15.f);

	
	this->gameOverText.setFont(this->font);
	this->gameOverText.setCharacterSize(100);
	this->gameOverText.setFillColor(sf::Color(255,215,0,255));
	this->gameOverText.setPosition(10.f, 15.f);
	this->gameOverText.setString("GAME OVER");
	this->gameOverText.setPosition(this->window.getSize().x/2.f-this->gameOverText.getGlobalBounds().width/2.f, 
									this->window.getSize().y/2.f - this->gameOverText.getGlobalBounds().height/2.f);
	//Init play GUI

	this->playerHpBar.setSize(sf::Vector2f(300.f, 25.f));
	this->playerHpBar.setFillColor(sf::Color(220.f, 20.f, 60.f, 200.f));
	this->playerHpBar.setPosition(sf::Vector2f(600.f, 30.5f));

	this->playerHpBarBack = this->playerHpBar;
	this->playerHpBarBack.setSize(sf::Vector2f(330.f, 35.f));
	this->playerHpBarBack.setFillColor(sf::Color::Black);
	this->playerHpBarBack.setPosition(sf::Vector2f(585.f, 25.5f));
}

void Game::initWorld()
{
	if (!this->worldBackgroundTex.loadFromFile("Textures/Ground.png"))
	{
		std::cout << "ERROR::GAME::COULD NOT LOAT BACKGROUND TEXTURE\n";
	}
	this->worldBackground.setTexture(this->worldBackgroundTex);
	this->worldBackground.scale(1.f, 1.f);
}








