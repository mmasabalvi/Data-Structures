
#include <SFML/Graphics.hpp>
#include<string>
#include"player.h"
using namespace sf;
using namespace std;

class Enemy
{

public:
    
    Texture enemyTex;
    Sprite enemySprite;
    float speed = 0.11;
    float x, y;
    int score = 25;
   

    Enemy(string path, int x, int y)
    {
        enemyTex.loadFromFile(path);
        enemySprite.setTexture(enemyTex);

        this->x = x;
        this->y = y;

        enemySprite.setPosition(x, y);
        enemySprite.setScale(1.2, 1.2);
        //	enemySprite.setRotation(90.f);
        enemySprite.setOrigin(enemySprite.getLocalBounds().width * 0.5f, enemySprite.getLocalBounds().height * 0.5f);
    }

    void moveTowardsPlayer(const Player& player, const Maze& maze)
    {
        // Correct the position if it's on the boundary to avoid crossing it
        checkforBoundary();

        int targetX = player.x;
        int targetY = player.y;

        //cout << "TargetX: " << targetX << endl;
        //cout << "TargetY: " << targetY << endl;

        float xPos = 0, yPos = 0;

       
        if (x < targetX) 
        {
            xPos = speed;// *time;  // Move right
            //  cout << "CHECKINGGGG1" << endl;
        }

        if (x > targetX) 
        {
            xPos = -speed;//*time; // Move left
            //  cout << "CHECKINGGGG2" << endl;
        }

        if (y < targetY)
        {
            yPos = speed;//*time;  // Move down
            // cout << "CHECKINGGGG1" << endl;
        }

        if (y > targetY) 
        {
            yPos = -speed;//*time; // Move up
            //   cout << "CHECKINGGGG2" << endl;
        }

        float newX = x + xPos;
        float newY = y + yPos;

        x = newX;
        y = newY;
        enemySprite.setPosition(x, y);

    }

    void checkforBoundary()
    {
        
        if ((y <= 520 && y >= 190) && x == 25)
        {
            x = 26;  
        }

        if ((y <= 520 && y >= 190) && x == 975) 
        {
            x = 974; 
        }
        if ((x <= 985 && x >= 25) && y == 200) {
            y = 201;
        }
        if ((x <= 975 && x >= 25) && y == 505)
        {
            y = 504; 
        }
    }
};

class Enemy2
{
public:
  
    Texture enemyTex;
    Sprite enemySprite;
    float speed = 0.25;
    float x, y;
    int score = 50;
    Maze maze;

    Enemy2(string path)
    {
        enemyTex.loadFromFile(path);
        enemySprite.setTexture(enemyTex);

        this->x = x;
        this->y = y;

        enemySprite.setPosition(x, y);
        enemySprite.setScale(1.2, 1.2);
        //	enemySprite.setRotation(90.f);
        enemySprite.setOrigin(enemySprite.getLocalBounds().width * 0.5f, enemySprite.getLocalBounds().height * 0.5f);
    }

    Enemy2(string path, Maze& maze)
    {
        enemyTex.loadFromFile(path);
        enemySprite.setTexture(enemyTex);
        enemySprite.setScale(1, 1);
        enemySprite.setOrigin(enemySprite.getLocalBounds().width * 0.5f, enemySprite.getLocalBounds().height * 0.5f);

        this->maze = maze;
       
    }

    void spawn()
    {
        bool placed = false;

        int paddingWidth = 2;
        int paddingHeight = 2;

        while (!placed)
        {
            // Generate a random position within the maze with padding
            x = 35 + rand() % (965 - 35 + 1);
            y = 210 + rand() % (495 - 210 + 1);

            // Calculate padding boundaries
            int leftX = (x - (enemySprite.getLocalBounds().width / 2 - paddingWidth) - 25) / 15;
            int rightX = (x + (enemySprite.getLocalBounds().width / 2 - paddingWidth) - 25) / 15;
            int topY = (y - (enemySprite.getLocalBounds().height / 2 - paddingHeight) - 200) / 15;
            int bottomY = (y + (enemySprite.getLocalBounds().height / 2 - paddingHeight) - 200) / 15;


            bool isValidPosition = true;

            for (int i = leftX; i <= rightX; ++i)
            {
                for (int j = topY; j <= bottomY; ++j)
                {
                    if (!maze.isFree(i, j))
                    {
                        isValidPosition = false;
                        break;
                    }
                }

                if (!isValidPosition)
                    break;
            }

            if (isValidPosition)
            {
                // Free space found, place the powerup here
                placed = true;
                enemySprite.setPosition(x, y);
            }
        }
    }

    void moveTowardsPlayer(const Player& player, const Maze& maze)
    {
        checkforBoundary();

        int targetX = player.x;
        int targetY = player.y;

        //cout << "TargetX: " << targetX << endl;
        //cout << "TargetY: " << targetY << endl;

        float xPos = 0, yPos = 0;

        if (x < targetX)
        {
            xPos = speed;// *time;  // Move right
            //  cout << "CHECKINGGGG1" << endl;
        }

        if (x > targetX)
        {
            xPos = -speed;//*time; // Move left
            //  cout << "CHECKINGGGG2" << endl;
        }

        if (y < targetY) 
        {
            yPos = speed;//*time;  // Move down
            // cout << "CHECKINGGGG1" << endl;
        }

        if (y > targetY)
        {
            yPos = -speed;//*time; // Move up
            //   cout << "CHECKINGGGG2" << endl;
        }

        float newX = x + xPos;
        float newY = y + yPos;
      
        int gridX = static_cast<int>((newX - 25) / 15); 
        int gridY = static_cast<int>((newY - 200) / 15);

        if (maze.isFree(static_cast<int>(gridX), static_cast<int>(gridY)))
        {
            x = newX;
            y = newY;
            enemySprite.setPosition(x, y);

        }

    }

  
    void checkforBoundary()
    {
       
        if ((y <= 520 && y >= 190) && x == 25) 
        {
            x = 26; 
        }

        if ((y <= 520 && y >= 190) && x == 975)
        {
            x = 974; 
        }

        if ((x <= 985 && x >= 25) && y == 200) 
        {
            y = 201;
        }

        if ((x <= 975 && x >= 25) && y == 505) 
        {
            y = 504; 
        }
    }

};
