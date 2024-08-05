#include <SFML/Graphics.hpp>
#include <cstdlib>
#include <ctime>
#include "maze.h";
using namespace std;
using namespace sf;

class Sword
{
public:
	int score = 50;
	Texture swordTex;
	Sprite swordSprite;
	float x, y;


	Sword()
	{
		swordTex.loadFromFile("images/sword.png");
		swordSprite.setTexture(swordTex);
		swordSprite.setOrigin(swordSprite.getLocalBounds().width * 0.5f, swordSprite.getLocalBounds().height * 0.5f);

		swordSprite.setScale(1.3, 1.1);

		x = 38;
		y = 211;
		swordSprite.setPosition(x, y);


	}


	Sword(const Maze& maze)
	{
		swordTex.loadFromFile("images/sword.png");
		swordSprite.setTexture(swordTex);
		swordSprite.setOrigin(swordSprite.getLocalBounds().width * 0.5f, swordSprite.getLocalBounds().height * 0.5f);

		swordSprite.setScale(1.3, 1.1);
		//srand(time(NULL));

		bool kept = false;

		while (!kept) 
		{
			
			x = 35 + rand() % (965 - 35 + 1);
			y = 210 + rand() % (495 - 210 + 1);

			//cout << x << " " << y << " ";

			int padW = 2;
			int padH = 2;

			int leftX = (x - 25 - (swordSprite.getLocalBounds().width / 2 - padW)) / 15;

			int rightX = (x - 25 + (swordSprite.getLocalBounds().width / 2 - padW)) / 15;
			int topY = (y - 200 - (swordSprite.getLocalBounds().height / 2 - padH)) / 15;
			int bottomY = (y - 200 + (swordSprite.getLocalBounds().height / 2 - padH)) / 15;

			bool validPos = true;

			for (int i = leftX; i <= rightX; ++i)
			{
				for (int j = topY; j <= bottomY; ++j)
				{
					if (!maze.isFree(i, j))
					{
						validPos = false;
						break;
					}
				}

				if (!validPos)
				{
					break;
				}
					
			}

			if (validPos)
			{
				kept = true;
				swordSprite.setPosition(x, y);
			}
		}
	}

	void draw(RenderWindow& window)
	{
		window.draw(swordSprite);
	}
};

class Potion
{
public:

	int score = 25;
	Texture potionTex;
	Sprite potionSprite;
	float x, y;

	Potion(string path)
	{
		potionTex.loadFromFile(path);
		potionSprite.setTexture(potionTex);
		potionSprite.setOrigin(potionSprite.getLocalBounds().width * 0.5f, potionSprite.getLocalBounds().height * 0.5f);

		potionSprite.setScale(1.3, 1.3);

		x = 30;
		y = 210;
		potionSprite.setPosition(x, y);
	}

	Potion(const Maze& maze, string path)
	{
		potionTex.loadFromFile(path);
		potionSprite.setTexture(potionTex);
		potionSprite.setOrigin(potionSprite.getLocalBounds().width * 0.5f, potionSprite.getLocalBounds().height * 0.5f);

		potionSprite.setScale(1.3, 1.3);
		//srand(time(NULL));

		FloatRect spriteBounds = potionSprite.getGlobalBounds();
		int spriteWidth = static_cast<int>(spriteBounds.width);
		int spriteHeight = static_cast<int>(spriteBounds.height);

		bool kept = false;
		while (!kept)
		{
		
			x = 35 + rand() % (965 - 35 + 1);
			y = 210 + rand() % (495 - 210 + 1);

			//cout << x << " " << y << " ";


			int padW = 2;
			int padH = 2;

			int leftX = (x - 25 - (potionSprite.getLocalBounds().width / 2 - padW)) / 15;
			int rightX = (x - 25 + (potionSprite.getLocalBounds().width / 2 - padW)) / 15;
			int topY = (y - 200 - (potionSprite.getLocalBounds().height / 2 - padH)) / 15;
			int bottomY = (y - 200 + (potionSprite.getLocalBounds().height / 2 - padH)) / 15;

			bool validPos = true;
			for (int i = leftX; i <= rightX; ++i)
			{
				for (int j = topY; j <= bottomY; ++j)
				{
					if (!maze.isFree(i, j))
					{
						validPos = false;
						break;
					}
				}
				if (!validPos)
				{
					break;
				}
			}

			if (validPos)
			{
				kept = true;
				potionSprite.setPosition(x, y);
			}
		}
	}


	void draw(RenderWindow& window)
	{
		window.draw(potionSprite);
	}
};

class Key
{
public:
	static int count;
	Texture keyTex;
	Sprite keySprite;
	float x, y;
	int score = 0;

	Key(Maze &maze)
	{
		keyTex.loadFromFile("images/key.png");
		keySprite.setTexture(keyTex);
		keySprite.setOrigin(keySprite.getLocalBounds().width * 0.5f, keySprite.getLocalBounds().height * 0.5f);

		keySprite.setScale(1.2, 1.2);
		//srand(time(NULL));

		bool kept = false;

		while (!kept)
		{
			
			x = 35 + rand() % (965 - 35 + 1);
			y = 210 + rand() % (495 - 210 + 1);

			//	//cout << x << " " << y << " ";


			int padW = 2;
			int padH = 2;

			int leftX = (x - 25 - (keySprite.getLocalBounds().width / 2 - padW)) / 15;
			int rightX = (x - 25 + (keySprite.getLocalBounds().width / 2 - padW)) / 15;
			int topY = (y - 200 - (keySprite.getLocalBounds().height / 2 - padH)) / 15;
			int bottomY = (y - 200 + (keySprite.getLocalBounds().height / 2 - padH)) / 15;

			bool validPos = true;

			for (int i = leftX; i <= rightX; ++i)
			{
				for (int j = topY; j <= bottomY; ++j)
				{
					if (!maze.isFree(i, j))
					{
						validPos = false;
						break;
					}
				}
				if (!validPos)
				{
					break;
				}
			}

			if (validPos)
			{
				
				kept = true;
				keySprite.setPosition(x, y);
			}
		}
	}



	

	void draw(RenderWindow& window)
	{
		window.draw(keySprite);
	}

};

int Key::count = 0;

class Platform
{
public:
	int score = 100;
	Texture pTex;
	Sprite pSprite;
	float x, y;

	Platform(const Maze& maze)
	{
		pTex.loadFromFile("images/platform.png");
		pSprite.setTexture(pTex);
		pSprite.setOrigin(pSprite.getLocalBounds().width * 0.5f, pSprite.getLocalBounds().height * 0.5f);

		pSprite.setScale(1.3, 1.3);
		//srand(time(NULL));

		bool kept = false;
		while (!kept)
		{
			// Generate random coordinates within the specified ranges
			x = 35 + rand() % (965 - 35 + 1);
			y = 210 + rand() % (495 - 210 + 1);

			//cout << x << " " << y << " ";

			// Check if the generated position is free in the maze
			//if (maze.isFree((x - 25)/15, (y - 200)/15))
			//{
			//	kept = true; // Free space found, place the sword here
			//	swordSprite.setPosition(x, y);
			//}

			int padW = 2;
			int padH = 2;
			int leftX = (x - 25 - (pSprite.getLocalBounds().width / 2 - padW)) / 15;
			int rightX = (x - 25 + (pSprite.getLocalBounds().width / 2 - padW)) / 15;
			int topY = (y - 200 - (pSprite.getLocalBounds().height / 2 - padH)) / 15;
			int bottomY = (y - 200 + (pSprite.getLocalBounds().height / 2 - padH)) / 15;

			bool validPos = true;
			for (int i = leftX; i <= rightX; ++i)
			{
				for (int j = topY; j <= bottomY; ++j)
				{
					if (!maze.isFree(i, j))
					{
						validPos = false;
						break;
					}
				}
				if (!validPos)
					break;
			}

			if (validPos)
			{
				// Free space found, place the powerup here
				kept = true;
				pSprite.setPosition(x, y);
			}
		}


	}


	void draw(RenderWindow& window)
	{
		window.draw(pSprite);
	}

};