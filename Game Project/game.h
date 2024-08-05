#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <time.h>
#include <iostream>
#include "menu.h";
#include"enemy.h"
#include "inventory.h"

class Game
{
private:
	Sprite bg, endGame;                                                                               
	Texture bgTex, endTex;

	Sound powerSound, enemySound;

	SoundBuffer pbuffer, ebuffer;

	int ghost1x = 970;
	int ghost1y = 205;

	int ghost2x = 25;
	int ghost2y = 505;

	int ghost3x = 500;
	int ghost3y = 505;

	string potionBlue = "images/potion1.png";
	string potionRed = "images/potion.png";

	Menu* M;
	Maze* m;

	Inventory* inventory;
	
	//Player* player;

	bool isPaused = false;
	bool hasWon = false;
	bool hasLost = false;
	//bool gameOverDisplayed = false;

	bool enemyOnCooldown = false;
	Clock enemyCooldownTimer;
	const float enemyCooldownDuration = 6.0f;

public:
	Game()
	{
		bgTex.loadFromFile("images/2.png");
		bg.setTexture(bgTex);
		bg.setScale(1, 1);

		pbuffer.loadFromFile("sounds/powerup.wav");
		ebuffer.loadFromFile("sounds/enemy.wav");

		powerSound.setBuffer(pbuffer);
		enemySound.setBuffer(ebuffer);

		M = new Menu;

		inventory = new Inventory;

	}

	void startGame()
	{
		if (M->checkGame())
		{ 

			srand(time(0));
			RenderWindow window(VideoMode(1000, 700), title);
			Clock clock;
			float timer = 0;
			window.setFramerateLimit(60); // Limit frame rate to 60 frames per second

			string currentDirection;

			m = new Maze(64, 21, &window);
			Sword sword1(*m);
			Potion potion4(*m, potionBlue);
			Player player("images/playerb.png", *m);
			Sword sword2(*m);
			Enemy ghost1("images/g.png", ghost1x, ghost1y);
			Sword sword3(*m);
			Enemy ghost3("images/g.png", ghost3x, ghost3y);
			Enemy2 enemy1("images/enemy1.png", *m);
			Potion potion1(*m, potionBlue);
			Potion potion6(*m, potionBlue);
			Sword sword4(*m);
			Potion potion5(*m, potionBlue);
			Potion potion7(*m, potionBlue);
			Potion potion2(*m, potionBlue);
			Platform platform2(*m);
			Enemy2 enemy2("images/enemy1.png", *m);
			Key key1(*m);
			Platform platform3(*m);
			Sword sword5;
			Potion potion10(potionBlue);
			Key key2(*m);
			Potion potion3(*m, potionBlue);
			Enemy2 enemy3("images/enemy1.png", *m);
			Enemy ghost2("images/g.png", ghost2x, ghost2y);
			Key key3(*m);
			Potion potion8(*m, potionBlue);
			Potion potion9(*m, potionBlue);
			Platform platform1(*m);

			bool hasWon = false;

			enemy1.spawn();
			enemy2.spawn();
			enemy3.spawn();

				while (window.isOpen())
				{
					float time = clock.getElapsedTime().asSeconds();
					clock.restart();
					timer += time;

					//Maze tempMaze = mazeObj();

					if (hasWon == false)
					{

						Event e;

						while (window.pollEvent(e))
						{

							if (e.type == Event::Closed)                                         
							{
								window.close();
							}

							else if (e.type == Event::KeyPressed)
							{
								switch (e.key.code)
								{
								case Keyboard::Up:
									player.move("u");
									currentDirection = "u";
									break;
								case Keyboard::Down:
									player.move("d");
									currentDirection = "d";
									break;
								case Keyboard::Left:
									player.move("l");
									currentDirection = "l";
									//player.playerSprite.setOrigin(0, player.playerSprite.getLocalBounds().height * 0.5f);
									break;
								case Keyboard::Right:
									player.move("r");
									currentDirection = "r";
									//player.playerSprite.setOrigin(player.playerSprite.getLocalBounds().width, player.playerSprite.getLocalBounds().height * 0.5f);

									break;
								}

								player.move(currentDirection);


							}



						}

						enemy1.moveTowardsPlayer(player, *m);
						enemy2.moveTowardsPlayer(player, *m);
						enemy2.moveTowardsPlayer(player, *m);


						if (!enemyOnCooldown)
						{
							ghost1.moveTowardsPlayer(player, *m);
							ghost2.moveTowardsPlayer(player, *m);
							ghost3.moveTowardsPlayer(player, *m);

						}
						else 
						{
							if (enemyCooldownTimer.getElapsedTime().asSeconds() >= enemyCooldownDuration)
							{
								enemyOnCooldown = false;
							}
						}


						//sword collissiom checker
						if (player.playerSprite.getPosition().x <= sword1.swordSprite.getPosition().x + 7.5 && player.playerSprite.getPosition().x >= sword1.swordSprite.getPosition().x - 7.5)
						{
							if (player.playerSprite.getPosition().y <= sword1.swordSprite.getPosition().y + 10 && player.playerSprite.getPosition().y >= sword1.swordSprite.getPosition().y - 10)
							{
								player.score += sword1.score;

								sword1.swordSprite.setPosition(1050, 0);

								inventory->insert(sword1.score);

								powerSound.play();
							}
						}

						if (player.playerSprite.getPosition().x <= sword2.swordSprite.getPosition().x + 7.5 && player.playerSprite.getPosition().x >= sword2.swordSprite.getPosition().x - 7.5)
						{
							if (player.playerSprite.getPosition().y <= sword2.swordSprite.getPosition().y + 10 && player.playerSprite.getPosition().y >= sword2.swordSprite.getPosition().y - 10)
							{
								player.score += sword2.score;

								sword2.swordSprite.setPosition(1050, 0);

								inventory->insert(sword2.score);

								powerSound.play();
							}
						}

						if (player.playerSprite.getPosition().x <= sword3.swordSprite.getPosition().x + 7.5 && player.playerSprite.getPosition().x >= sword3.swordSprite.getPosition().x - 7.5)
						{
							if (player.playerSprite.getPosition().y <= sword3.swordSprite.getPosition().y + 10 && player.playerSprite.getPosition().y >= sword3.swordSprite.getPosition().y - 10)
							{
								player.score += sword3.score;

								sword3.swordSprite.setPosition(1050, 0);

								inventory->insert(sword3.score);

								powerSound.play();
							}
						}

						if (player.playerSprite.getPosition().x <= sword4.swordSprite.getPosition().x + 7.5 && player.playerSprite.getPosition().x >= sword4.swordSprite.getPosition().x - 7.5)
						{
							if (player.playerSprite.getPosition().y <= sword4.swordSprite.getPosition().y + 10 && player.playerSprite.getPosition().y >= sword4.swordSprite.getPosition().y - 10)
							{
								player.score += sword4.score;

								sword4.swordSprite.setPosition(1050, 0);

								inventory->insert(sword4.score);

								powerSound.play();
							}
						}

						if (player.playerSprite.getPosition().x <= sword5.swordSprite.getPosition().x + 7.5 && player.playerSprite.getPosition().x >= sword5.swordSprite.getPosition().x - 7.5)
						{
							if (player.playerSprite.getPosition().y <= sword5.swordSprite.getPosition().y + 10 && player.playerSprite.getPosition().y >= sword5.swordSprite.getPosition().y - 10)
							{
								player.score += sword5.score;

								sword5.swordSprite.setPosition(1050, 0);

								inventory->insert(sword5.score);

								powerSound.play();
							}
						}


						//potion collission checker

						if (player.playerSprite.getPosition().x <= potion1.potionSprite.getPosition().x + 10 && player.playerSprite.getPosition().x >= potion1.potionSprite.getPosition().x - 10)
						{
							if (player.playerSprite.getPosition().y <= potion1.potionSprite.getPosition().y + 8 && player.playerSprite.getPosition().y >= potion1.potionSprite.getPosition().y - 8)
							{
								player.score += potion1.score;

								potion1.potionSprite.setPosition(1050, 0);

								inventory->insert(potion1.score);

								powerSound.play();

								enemyOnCooldown = true;
								
								enemyCooldownTimer.restart();
							}

						}

						if (player.playerSprite.getPosition().x <= potion2.potionSprite.getPosition().x + 10 && player.playerSprite.getPosition().x >= potion2.potionSprite.getPosition().x - 10)
						{
							if (player.playerSprite.getPosition().y <= potion2.potionSprite.getPosition().y + 8 && player.playerSprite.getPosition().y >= potion2.potionSprite.getPosition().y - 8)
							{
								player.score += potion1.score;

								potion2.potionSprite.setPosition(1050, 0);

								powerSound.play();

								inventory->insert(potion1.score);

								enemyOnCooldown = true;

								enemyCooldownTimer.restart();
							}

						}

						if (player.playerSprite.getPosition().x <= potion3.potionSprite.getPosition().x + 10 && player.playerSprite.getPosition().x >= potion3.potionSprite.getPosition().x - 10)
						{
							if (player.playerSprite.getPosition().y <= potion3.potionSprite.getPosition().y + 8 && player.playerSprite.getPosition().y >= potion3.potionSprite.getPosition().y - 8)
							{
								player.score += potion1.score;

								potion3.potionSprite.setPosition(1050, 0);

								powerSound.play();

								inventory->insert(potion1.score);

								enemyOnCooldown = true;
								
								enemyCooldownTimer.restart();
							}

						}

						if (player.playerSprite.getPosition().x <= potion4.potionSprite.getPosition().x + 10 && player.playerSprite.getPosition().x >= potion4.potionSprite.getPosition().x - 10)
						{
							if (player.playerSprite.getPosition().y <= potion4.potionSprite.getPosition().y + 8 && player.playerSprite.getPosition().y >= potion4.potionSprite.getPosition().y - 8)
							{
								player.score += potion1.score;

								potion4.potionSprite.setPosition(1050, 0);

								powerSound.play();

								inventory->insert(potion1.score);

								enemyOnCooldown = true;
								
								enemyCooldownTimer.restart();
							}

						}

						if (player.playerSprite.getPosition().x <= potion5.potionSprite.getPosition().x + 10 && player.playerSprite.getPosition().x >= potion5.potionSprite.getPosition().x - 10)
						{
							if (player.playerSprite.getPosition().y <= potion5.potionSprite.getPosition().y + 8 && player.playerSprite.getPosition().y >= potion5.potionSprite.getPosition().y - 8)
							{
								player.score += potion1.score;

								potion5.potionSprite.setPosition(1050, 0);

								powerSound.play();

								inventory->insert(potion1.score);

								enemyOnCooldown = true;
								
								enemyCooldownTimer.restart();
							}

						}

						if (player.playerSprite.getPosition().x <= potion6.potionSprite.getPosition().x + 10 && player.playerSprite.getPosition().x >= potion6.potionSprite.getPosition().x - 10)
						{
							if (player.playerSprite.getPosition().y <= potion6.potionSprite.getPosition().y + 8 && player.playerSprite.getPosition().y >= potion6.potionSprite.getPosition().y - 8)
							{
								player.score += potion1.score;

								potion6.potionSprite.setPosition(1050, 0);

								powerSound.play();

								inventory->insert(potion1.score);

								enemyOnCooldown = true;
								
								enemyCooldownTimer.restart();
							}

						}

						if (player.playerSprite.getPosition().x <= potion7.potionSprite.getPosition().x + 10 && player.playerSprite.getPosition().x >= potion7.potionSprite.getPosition().x - 10)
						{
							if (player.playerSprite.getPosition().y <= potion7.potionSprite.getPosition().y + 8 && player.playerSprite.getPosition().y >= potion7.potionSprite.getPosition().y - 8)
							{
								player.score += potion1.score;

								potion7.potionSprite.setPosition(1050, 0);

								powerSound.play();

								inventory->insert(potion1.score);

								enemyOnCooldown = true;
						
								enemyCooldownTimer.restart();
							}

						}

						if (player.playerSprite.getPosition().x <= potion8.potionSprite.getPosition().x + 10 && player.playerSprite.getPosition().x >= potion8.potionSprite.getPosition().x - 10)
						{
							if (player.playerSprite.getPosition().y <= potion8.potionSprite.getPosition().y + 8 && player.playerSprite.getPosition().y >= potion8.potionSprite.getPosition().y - 8)
							{
								player.score += potion1.score;

								potion8.potionSprite.setPosition(1050, 0);
								powerSound.play();

								inventory->insert(potion1.score);

								enemyOnCooldown = true;
								
								enemyCooldownTimer.restart();
							}

						}

						if (player.playerSprite.getPosition().x <= potion9.potionSprite.getPosition().x + 10 && player.playerSprite.getPosition().x >= potion9.potionSprite.getPosition().x - 10)
						{
							if (player.playerSprite.getPosition().y <= potion9.potionSprite.getPosition().y + 8 && player.playerSprite.getPosition().y >= potion9.potionSprite.getPosition().y - 8)
							{
								player.score += potion1.score;

								potion9.potionSprite.setPosition(1050, 0);

								powerSound.play();

								inventory->insert(potion1.score);

								enemyOnCooldown = true;
								
								enemyCooldownTimer.restart();
							}

						}

						if (player.playerSprite.getPosition().x <= potion10.potionSprite.getPosition().x + 10 && player.playerSprite.getPosition().x >= potion10.potionSprite.getPosition().x - 10)
						{
							if (player.playerSprite.getPosition().y <= potion10.potionSprite.getPosition().y + 8 && player.playerSprite.getPosition().y >= potion10.potionSprite.getPosition().y - 8)
							{
								player.score += potion1.score;

								potion10.potionSprite.setPosition(1050, 0);

								powerSound.play();

								inventory->insert(potion1.score);

								enemyOnCooldown = true;
								
								enemyCooldownTimer.restart();
							}

						}


						//Key Check
						if (player.playerSprite.getPosition().x <= key1.keySprite.getPosition().x + 7.5 && player.playerSprite.getPosition().x >= key1.keySprite.getPosition().x - 7.5)
						{
							if (player.playerSprite.getPosition().y <= key1.keySprite.getPosition().y + 10 && player.playerSprite.getPosition().y >= key1.keySprite.getPosition().y - 10)
							{
								//  player.score += potion1.score;
								key1.count++;

								key1.keySprite.setPosition(1050, 0);

								powerSound.play();

								inventory->insert(key1.score);
							}

						}

						if (player.playerSprite.getPosition().x <= key2.keySprite.getPosition().x + 7.5 && player.playerSprite.getPosition().x >= key2.keySprite.getPosition().x - 7.5)
						{
							if (player.playerSprite.getPosition().y <= key2.keySprite.getPosition().y + 10 && player.playerSprite.getPosition().y >= key2.keySprite.getPosition().y - 10)
							{
								//  player.score += potion1.score;
								key1.count++;

								key2.keySprite.setPosition(1050, 0);

								powerSound.play();

								inventory->insert(key1.score);
							}

						}


						if (player.playerSprite.getPosition().x <= key3.keySprite.getPosition().x + 7.5 && player.playerSprite.getPosition().x >= key3.keySprite.getPosition().x - 7.5)
						{
							if (player.playerSprite.getPosition().y <= key3.keySprite.getPosition().y + 10 && player.playerSprite.getPosition().y >= key3.keySprite.getPosition().y - 10)
							{
								key1.count++;

								key3.keySprite.setPosition(1050, 0);

								powerSound.play();

								inventory->insert(key3.score);
							}

						}


						//ghost check

						if (player.playerSprite.getPosition().x <= ghost1.enemySprite.getPosition().x + 15 && player.playerSprite.getPosition().x >= ghost1.enemySprite.getPosition().x - 15)
						{
							if (player.playerSprite.getPosition().y <= ghost1.enemySprite.getPosition().y + 15 && player.playerSprite.getPosition().y >= ghost1.enemySprite.getPosition().y - 15)
							{
								
								if (!enemyOnCooldown)
								{
									player.score -= ghost1.score;

									enemySound.play();

									inventory->remove(ghost1.score);


									ghost1.x = ghost1x;
									ghost1.y = ghost1y;
									ghost1.enemySprite.setPosition(ghost1x, ghost1y);
								}
								

								

								enemyOnCooldown = true;

								enemyCooldownTimer.restart();


							}
						}

						if (player.playerSprite.getPosition().x <= ghost2.enemySprite.getPosition().x + 15 && player.playerSprite.getPosition().x >= ghost2.enemySprite.getPosition().x - 10)
						{
							if (player.playerSprite.getPosition().y <= ghost2.enemySprite.getPosition().y + 15 && player.playerSprite.getPosition().y >= ghost2.enemySprite.getPosition().y - 15)
							{
								

								if (!enemyOnCooldown)
								{
									player.score -= ghost1.score;

									enemySound.play();

									inventory->remove(ghost1.score);


									ghost2.x = ghost2x;
									ghost2.y = ghost2y;
									ghost2.enemySprite.setPosition(ghost2x, ghost2y);
								}

								

								enemyOnCooldown = true;

								enemyCooldownTimer.restart();
							}
						}


						if (player.playerSprite.getPosition().x <= ghost3.enemySprite.getPosition().x + 15 && player.playerSprite.getPosition().x >= ghost3.enemySprite.getPosition().x - 10)
						{
							if (player.playerSprite.getPosition().y <= ghost3.enemySprite.getPosition().y + 15 && player.playerSprite.getPosition().y >= ghost3.enemySprite.getPosition().y - 15)
							{
								if (!enemyOnCooldown)
								{
									player.score -= ghost1.score;

									enemySound.play();

									inventory->remove(ghost1.score);


									ghost3.x = ghost3x;
									ghost3.y = ghost3y;
									ghost3.enemySprite.setPosition(ghost3x, ghost3y);
								}

								

								enemyOnCooldown = true;

								enemyCooldownTimer.restart();
							}
						}

						//platforms check
						if (player.playerSprite.getPosition().x <= platform1.pSprite.getPosition().x + 10 && player.playerSprite.getPosition().x >= platform1.pSprite.getPosition().x - 10)
						{
							if (player.playerSprite.getPosition().y <= platform1.pSprite.getPosition().y + 10 && player.playerSprite.getPosition().y >= platform1.pSprite.getPosition().y - 10)
							{
								player.score += platform1.score;

								platform1.pSprite.setPosition(1050, 0);

								inventory->insert(platform1.score);

								powerSound.play();

								ghost2.x = ghost2x;
								ghost2.y = ghost2y;
								ghost2.enemySprite.setPosition(ghost2x, ghost2y);

								ghost1.x = ghost1x;
								ghost1.y = ghost1y;
								ghost1.enemySprite.setPosition(ghost1x, ghost1y);

								ghost3.x = ghost3x;
								ghost3.y = ghost3y;
								ghost3.enemySprite.setPosition(ghost3x, ghost3y);
							}

						}

						if (player.playerSprite.getPosition().x <= platform2.pSprite.getPosition().x + 10 && player.playerSprite.getPosition().x >= platform2.pSprite.getPosition().x - 10)
						{
							if (player.playerSprite.getPosition().y <= platform2.pSprite.getPosition().y + 10 && player.playerSprite.getPosition().y >= platform2.pSprite.getPosition().y - 10)
							{
								player.score += platform1.score;

								platform2.pSprite.setPosition(1050, 0);

								powerSound.play();

								inventory->insert(platform1.score);

								ghost2.x = ghost2x;
								ghost2.y = ghost2y;
								ghost2.enemySprite.setPosition(ghost2x, ghost2y);

								ghost1.x = ghost1x;
								ghost1.y = ghost1y;
								ghost1.enemySprite.setPosition(ghost1x, ghost1y);

								ghost3.x = ghost3x;
								ghost3.y = ghost3y;
								ghost3.enemySprite.setPosition(ghost3x, ghost3y);
							}

						}

						if (player.playerSprite.getPosition().x <= platform3.pSprite.getPosition().x + 10 && player.playerSprite.getPosition().x >= platform3.pSprite.getPosition().x - 10)
						{
							if (player.playerSprite.getPosition().y <= platform3.pSprite.getPosition().y + 10 && player.playerSprite.getPosition().y >= platform3.pSprite.getPosition().y - 10)
							{
								player.score += platform1.score;

								platform3.pSprite.setPosition(1050, 0);

								inventory->insert(platform1.score);

								powerSound.play();

								ghost2.x = ghost2x;
								ghost2.y = ghost2y;
								ghost2.enemySprite.setPosition(ghost2x, ghost2y);

								ghost1.x = ghost1x;
								ghost1.y = ghost1y;
								ghost1.enemySprite.setPosition(ghost1x, ghost1y);

								ghost3.x = ghost3x;
								ghost3.y = ghost3y;
								ghost3.enemySprite.setPosition(ghost3x, ghost3y);
							}

						}


						//enemy check
						if (player.playerSprite.getPosition().x <= enemy1.enemySprite.getPosition().x + 13 && player.playerSprite.getPosition().x >= enemy1.enemySprite.getPosition().x - 13)
						{
							if (player.playerSprite.getPosition().y <= enemy1.enemySprite.getPosition().y + 13 && player.playerSprite.getPosition().y >= enemy1.enemySprite.getPosition().y - 13)
							{
								player.score -= enemy1.score;

								inventory->remove(enemy1.score);

								enemySound.play();


								enemy1.spawn();
							}
						}

						if (player.playerSprite.getPosition().x <= enemy2.enemySprite.getPosition().x + 13 && player.playerSprite.getPosition().x >= enemy2.enemySprite.getPosition().x - 13)
						{
							if (player.playerSprite.getPosition().y <= enemy2.enemySprite.getPosition().y + 13 && player.playerSprite.getPosition().y >= enemy2.enemySprite.getPosition().y - 13)
							{
								player.score -= enemy1.score;

								inventory->remove(enemy1.score);

								enemySound.play();


								enemy2.spawn();
							}
						}

						if (player.playerSprite.getPosition().x <= enemy3.enemySprite.getPosition().x + 13 && player.playerSprite.getPosition().x >= enemy3.enemySprite.getPosition().x - 13)
						{
							if (player.playerSprite.getPosition().y <= enemy3.enemySprite.getPosition().y + 13 && player.playerSprite.getPosition().y >= enemy3.enemySprite.getPosition().y - 13)
							{
								player.score -= enemy1.score;

								inventory->remove(enemy1.score);

								enemySound.play();


								enemy3.spawn();
							}
						}

						



						//win check
						if (player.x >= 962 && player.y == 508)
						{
							/*player.y = 507;
							player.playerSprite.setPosition(player.x, player.y)*/;

							if (key1.count == 3)
							{
								hasWon = true;
								cout << "WINN" << endl;
								break;
							}
						}


						if (player.score < 0)
						{
							hasLost = true;
							inventory->emptyTree();
							break;
						}
						


						/*if (!isPaused)
						{*/
						window.clear(Color::Black);
						window.draw(bg);

						gameTitle(window);

						m->draw();
						window.draw(player.playerSprite);

						window.draw(ghost1.enemySprite);
						window.draw(ghost2.enemySprite);
						window.draw(ghost3.enemySprite);


						window.draw(enemy1.enemySprite);
						window.draw(enemy2.enemySprite);
						window.draw(enemy3.enemySprite);


						sword1.draw(window);
						sword2.draw(window);
						sword3.draw(window);
						sword4.draw(window);
						sword5.draw(window);

						potion1.draw(window);
						potion2.draw(window);
						potion3.draw(window);
						potion4.draw(window);
						potion5.draw(window);
						potion6.draw(window);
						potion7.draw(window);
						potion8.draw(window);
						potion9.draw(window);
						potion10.draw(window);

						inventory->display(window);

						key1.draw(window);
						key2.draw(window);
						key3.draw(window);

						platform1.draw(window);
						platform2.draw(window);
						platform3.draw(window);

						player.displayScore(window);
						KeyInstructions(window);


						window.display();
					}

					


				}

				

				if (hasLost == true)
				{
					cout << "CHECKKINGG" << endl;
					window.clear();
					Sprite bg;
					Texture bgT;

					bgT.loadFromFile("images/2.png");
					bg.setTexture(bgT);
					bg.setScale(1, 1);

					gameTitle(window);

					Font font;
					font.loadFromFile("LilitaOne-Regular.ttf");
					Text endText("Game over", font, 50);
					endText.setPosition(400, 300);
					endText.setFillColor(Color(188, 33, 33));
					window.draw(endText);
					
					
				
				}

				if (hasWon == true)
				{
					window.clear();
					Sprite bg;
					Texture bgT;

					bgT.loadFromFile("images/2.png");
					bg.setTexture(bgT);
					bg.setScale(1, 1);

					gameTitle(window);
					Font font;
					font.loadFromFile("LilitaOne-Regular.ttf");
					Text endText("You win", font, 50);
					endText.setPosition(400, 300);
					endText.setFillColor(Color::White);
					window.draw(endText);

				}

				Event event;
				while (window.pollEvent(event))
				{
					if (event.type == Event::Closed)
					{
						window.close();
					}
				}

				window.display();

		}

			
	}


	void KeyInstructions(RenderWindow& window)
	{
		string instructions = "Collect the 3 Keys and reach the Finish Point";

		Font font;
		font.loadFromFile("LilitaOne-Regular.ttf");
		Text scText(instructions, font, 32);
		scText.setPosition(180, 580);
		scText.setFillColor(Color(18, 134, 191));

		Texture tex;
		Sprite sp;

		tex.loadFromFile("images/key.png");
		sp.setTexture(tex);
		sp.setPosition(780, 583);
		sp.setScale(2.1, 2.1);
		window.draw(sp);


		window.draw(scText);
	}

	void gameTitle(RenderWindow& window)
	{
		Font font;
		font.loadFromFile("LilitaOne-Regular.ttf");
		Text startGameText("Enchanted Labyrinth Explorer", font, 45);
		startGameText.setPosition(210, 32);
		startGameText.setFillColor(Color(188, 33, 33));
		window.draw(startGameText);
	}

	Menu* MenuObj()
	{
		return M;
	}

	Maze* mazeObj()
	{
		return m;
	}

	~Game() 
	{
		delete M;
		delete m;
		delete inventory;
	}
};

