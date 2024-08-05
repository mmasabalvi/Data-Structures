#include "game.h"

int main()
{
    Game Obj;

    Music music;
    music.openFromFile("sounds/background.wav");
    music.play();
    music.setLoop(true);

    Obj.MenuObj()->display();
    Obj.startGame();

    return 0;
}