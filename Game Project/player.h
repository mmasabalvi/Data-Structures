#include <SFML/Graphics.hpp>
#include<string.h>
#include<string>
#include "powerups.h"
using namespace sf;
using namespace std;

class Player
{
private:
    Maze& maze; 
public:
    Texture playerTex;
    Sprite playerSprite;
    float speed = 1;
    int x, y;

    bool hasWon = 0;

    static int score;
   // static int lives;

    Font font;

    int speedLevel = 10;

    Player(string png_path, Maze& m) : maze(m)
    {
        playerTex.loadFromFile(png_path);
        playerSprite.setTexture(playerTex);
        x = 32; 
        y = 196;

        //x was 32
       /* x = 50;
        y = 100;*/

        playerSprite.setPosition(x, y);
        playerSprite.setScale(1, 1.1);
       // playerSprite.setRotation(180.f);
        playerSprite.setOrigin(playerSprite.getLocalBounds().width * 0.5f, playerSprite.getLocalBounds().height * 0.5f);
        
    }

    void move(string direction) 
    {
        if (hasWon)
        {
            return;
        }

        float delta_x = 0, delta_y = 0;

        float posX = playerSprite.getPosition().x;

        float posY = playerSprite.getPosition().y;

        FloatRect spriteBounds = playerSprite.getGlobalBounds();

        int spriteWidth = static_cast<int>(spriteBounds.width);
        int spriteHeight = static_cast<int>(spriteBounds.height);

     
        int padW = 2;
        int padH = 2;


        if ((posY <= 520 && posY >= 190) && posX == 30)
        {
            posX = 31;
            delta_y = 0;
        }

        if ((posY <= 520 && posY >= 190) && posX == 968)
        {
            posX = 967;
            delta_y = 0;
        }

        if ((posX <= 985 && posX >= 25) && posY == 205)
        {
            posY = 206;
            delta_x = 0;
        }

        if ((posX <= 985 && posX >= 25) && posY == 508)
        {
            posY = 507 ;
            delta_x = 0;
        }

        if (posX <= 10 && posX >= 25 && posY <= 196)
        {
            posY = 197;
            delta_x = 0;
        }
        

       
        if (direction == "l")
        {
            delta_x = -0.1;
        }
          
        else if (direction == "r")
        {
            delta_x = 0.1;
        }

        else if (direction == "u")
        {
            delta_y = -0.1;
        }

        else if (direction == "d")
        {
            delta_y = 0.1;
        }

        delta_x *= speedLevel * speed;
        delta_y *= speedLevel * speed;

        int newPosX = static_cast<int>(posX + delta_x);

        int newPosY = static_cast<int>(posY + delta_y);

        int leftX = (newPosX - 25 - (spriteWidth / 2 - padW)) / 15;

        int rightX = (newPosX - 25 + (spriteWidth / 2 - padW)) / 15;

        int topY = (newPosY - 200 - (spriteHeight / 2 - padH)) / 15;

        int bottomY = (newPosY - 200 + (spriteHeight / 2 - padH)) / 15;

        
        bool canMove = true;

        for (int x = leftX; x <= rightX; x++) 
        {
            for (int y = topY; y <= bottomY; y++) 
            {
                if (!maze.isFree(x, y))
                {
                    canMove = false;
                    break;
                }
            }

            if (!canMove)
            {
                break;
            }
        }

        if (canMove) 
        {
      
            playerSprite.setPosition(newPosX, newPosY);
            x = newPosX;
            y = newPosY;
        }

        /*cout << "Player x: " << x << endl;
        cout << "Player y: " << y << endl;*/


       /* Player x : 963
            Player y : 508*/
    }

    void displayScore(RenderWindow& window)
    {
        string scoreString = "Score: " + to_string(score);

        font.loadFromFile("LilitaOne-Regular.ttf");
        Text scText(scoreString, font, 32);
        scText.setPosition(840, 120);
        scText.setFillColor(Color(18, 134, 191));

        window.draw(scText);
    }

};

int Player::score = 0;