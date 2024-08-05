#include <SFML/Graphics.hpp>
using namespace std;
using namespace sf;


const char title[] = "Enchanted Labyrinth Explorer";

class Menu
{
private:

	Font font;
	RenderWindow window;
	Sprite menuSpr, playerSpr, enemySpr, ghostSpr, instrSpr, keySpr, platformSpr, potionSpr, swordSpr;
	Texture menuTex, playerTex, enemyTex, ghostTex, instrTex, keyTex, platformTex, potionTex, swordTex;

	bool hasGameStarted = false;

public:

	Menu()
	{
		font.loadFromFile("LilitaOne-Regular.ttf");
		menuTex.loadFromFile("images/menu.png");
		menuSpr.setTexture(menuTex);
		menuSpr.setScale(1, 1);

		playerTex.loadFromFile("images/playerb.png");
		playerSpr.setTexture(playerTex);
		playerSpr.setScale(2, 2);
		playerSpr.setPosition(100, 250);

		enemyTex.loadFromFile("images/enemy1.png");
		enemySpr.setTexture(enemyTex);
		enemySpr.setScale(2, 2);
		enemySpr.setPosition(100, 300);

		ghostTex.loadFromFile("images/g.png");
		ghostSpr.setTexture(ghostTex);
		ghostSpr.setScale(2, 2);
		ghostSpr.setPosition(100, 350);

		instrTex.loadFromFile("images/2.png");
		instrSpr.setTexture(instrTex);
		instrSpr.setScale(1, 1);

		keyTex.loadFromFile("images/key.png");
		keySpr.setTexture(keyTex);
		keySpr.setScale(2, 2);
		keySpr.setPosition(100, 400);

		platformTex.loadFromFile("images/platform.png");
		platformSpr.setTexture(platformTex);
		platformSpr.setScale(2, 2);
		platformSpr.setPosition(100, 450);

		potionTex.loadFromFile("images/potion1.png");
		potionSpr.setTexture(potionTex);
		potionSpr.setScale(2, 2);
		potionSpr.setPosition(100, 550);

		swordTex.loadFromFile("images/sword.png");
		swordSpr.setTexture(swordTex);
		swordSpr.setScale(2, 2);
		swordSpr.setPosition(100, 500);
	}

	void display()
	{
		RenderWindow window(VideoMode(1000, 600), title);
		Font font;
		font.loadFromFile("LilitaOne-Regular.ttf");

		Text gameName("Enchanted Labyrinth Explorer", font, 60);
		gameName.setPosition(120, 20);
		gameName.setFillColor(Color(255, 0, 0));
		gameName.setOutlineColor(Color(211, 225, 15));

		Text startGameText("New Game", font, 36);
		startGameText.setPosition(415, 165);
		startGameText.setFillColor(Color(225, 165, 0));

		Text instructionsText("Help", font, 36);
		instructionsText.setPosition(465, 325);
		instructionsText.setFillColor(Color(225, 165, 0));

		Text exitText("Exit", font, 36);
		exitText.setPosition(475, 490);
		exitText.setFillColor(Color(225, 165, 0));

		Text istText1("Navigate through the enchanting Labyrinth, overcome obstacles, and find ", font, 27);
		istText1.setPosition(100, 20);
		istText1.setFillColor(Color(225, 165, 0));

		Text istText2("the hidden treasures deep inside, guarded by magical creatures and", font, 27);
		istText2.setPosition(100, 60);
		istText2.setFillColor(Color(225, 165, 0));

		Text istText3("hidden traps, to achieve the highest score!", font, 27);
		istText3.setPosition(100, 100);
		istText3.setFillColor(Color(225, 165, 0));

		Text istText4("Controls: Use arrow keys to navigate your player through the maze", font, 27);
		istText4.setPosition(100, 180);
		istText4.setFillColor(Color(225, 165, 0));

		Text istText5("Player:    Use Arrow Keys to navigate the Player", font, 17);
		istText5.setPosition(150, 255);
		istText5.setFillColor(Color(225, 165, 0));

		Text istText6("Enemy:    Beware and stay out of the Enemy's Line of Sight", font, 17);
		istText6.setPosition(150, 305);
		istText6.setFillColor(Color(225, 165, 0));

		Text istText7("Ghost:    Stay sharp as the Ghosts will follow you wherever you go", font, 17);
		istText7.setPosition(150, 355);
		istText7.setFillColor(Color(225, 165, 0));

		Text istText8("Key:    Collect the 3 keys and reach the end point", font, 17);
		istText8.setPosition(150, 405);
		istText8.setFillColor(Color(225, 165, 0));

		Text istText9("Platform:    Collect the Platform to respawn the Ghosts to their Initial Position (+100 Pts)", font, 17);
		istText9.setPosition(150, 455);
		istText9.setFillColor(Color(225, 165, 0));

		Text istText10("Sword:    Your Ultimate Weapon (+50 Pts)", font, 17); 
		istText10.setPosition(150, 505);
		istText10.setFillColor(Color(225, 165, 0));

		Text istText11("Potion:    Collect the Potion to pause Ghosts and gain immunity (+50 Pts)", font, 17);
		istText11.setPosition(150, 555);
		istText11.setFillColor(Color(225, 165, 0));


		while (window.isOpen())
		{
			Event event;
			bool returnToMainMenu = false;

			while (window.pollEvent(event))
			{
				if (event.type == Event::Closed)
				{
					window.close();
				}

				if (Keyboard::isKeyPressed(Keyboard::Num1))
				{
					hasGameStarted = true;
				}

				if (Keyboard::isKeyPressed(Keyboard::Num2))
				{

					window.clear();

					window.draw(instrSpr);
					window.draw(istText1);
					window.draw(istText2);
					window.draw(istText3);
					window.draw(istText4);
					window.draw(playerSpr);
					window.draw(enemySpr);
					window.draw(platformSpr);
					window.draw(swordSpr);
					window.draw(keySpr);
					window.draw(potionSpr);
					window.draw(ghostSpr);
					window.draw(istText6);
					window.draw(istText5);
					window.draw(istText7);
					window.draw(istText8);
					window.draw(istText9);
					window.draw(istText10);
					window.draw(istText11);

					window.display();

					while (true)
					{
						sf::Event event;
						while (window.pollEvent(event))
						{
							if (event.type == sf::Event::Closed || Keyboard::isKeyPressed(Keyboard::Enter))
							{
								break;  // Return to main menu
							}
						}
						if (Keyboard::isKeyPressed(Keyboard::Enter))
						{
							break;
						}
					}
				}



				if (Keyboard::isKeyPressed(Keyboard::Num3))
				{
					hasGameStarted = false;
					window.close();
				}

				if (hasGameStarted == 1)
				{
					break;
				}
			}

			window.draw(menuSpr);
			window.draw(gameName);
			window.draw(startGameText);
			window.draw(instructionsText);
			window.draw(exitText);


			if (hasGameStarted == 1)
			{
				window.close();
			}

			window.display();
		}
	}

	bool checkGame()
	{
		return hasGameStarted;
	}
};