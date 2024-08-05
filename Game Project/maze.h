
#include <SFML/Graphics.hpp>
#include <iostream>
#include <stack>
#include <cstdlib>
#include <ctime>

using namespace std;

class Maze
{
private:
    int startX = 25; int startY = 200;

    int cellSize = 15;


public:
    int width, height;
    int** mazeGrid;

    bool** visited;                     

    RenderWindow* window;

    Maze(){}

    Maze(int w, int h, RenderWindow* win)
    {
        width = w;
        height = h;
        window = win;

        mazeGrid = new int* [height];                                       //grid to store 0s and 1s for valid points
        visited = new bool* [height];                                   //visited to see if cell has been visited before

        window->setVerticalSyncEnabled(true);                          //to synchronize the frame rate of rendering with the refresh rate of the monitor

        for (int i = 0; i < height; i++)
        {
            mazeGrid[i] = new int[width];                                   //allocate memory
            visited[i] = new bool[width];

            for (int j = 0; j < width; j++)
            {
                mazeGrid[i][j] = 1;                                         //set complete maze with walls                   

                visited[i][j] = false;                                  //initialize all cells as not visited
            }
        }

        mazeGrid[0][0] = 0;                                                //for start position
        mazeGrid[height - 1][width - 1] = 0;                               //for end position
                                                                       //both will be empty so that player can enter and exit
        generateMaze();

        //finalizeWalls();
    }

    void generateMaze()
    {
        srand(time(NULL));

        stack<pair<int, int>> stack;                                   //declares stack of type pair object

        int x = 0;
        int y = 0;

        mazeGrid[y][x] = 0;                                                //start at the top-left corner of the maze
        visited[y][x] = true;                                         //mark start cell as visited

        stack.push({ y, x });                                        //current pair points pushed to stack
     
        while (!stack.empty())
        {
            auto current = stack.top();                                //current has current x and y points
            stack.pop();

            pair<int, int> neighbors[4];                               //declare neighbours array of pair type

            int count = findNeighbors(current.first, current.second, neighbors);       //gets count of valid neighbors and sets neighbors' points in array

            if (count > 0)
            {
                stack.push(current);                                   //put the current cell back on the stack

                int randIndex = rand() % count;                         //random index generated between zero to count

                auto chosen = neighbors[randIndex];                    //chosen has the random x and y positions now

                removeWall(current.first, current.second, chosen.first, chosen.second);     //specific wall between current point and neighboring point removed

                mazeGrid[chosen.first][chosen.second] = 0;                                      //on grid, neighboring point set as path

                visited[chosen.first][chosen.second] = true;                                //mark neoghboring point as visited

                stack.push(chosen);                                                         //push neighboring point, it is out current point now

            }

           
        }
        //makePathToExit();
    }

    int findNeighbors(int y, int x, pair<int, int> neighbors[4])
    {
        int count = 0;                                                                      //no.of valid neighboring cells

                                                                                            // Directions: up, down, left, right
        const int yDir[4] = { -2, 2, 0, 0 };
        const int xDir[4] = { 0, 0, -2, 2 };

        for (int i = 0; i < 4; i++)
        {
            int yPos = y + yDir[i];                                                             //finds neighboring positions in terms of x and y
            int xPos = x + xDir[i];

            if (yPos >= 0 && yPos < height && xPos >= 0 && xPos < width && !visited[yPos][xPos])       //checks if neighboring positions are in range and have not been visited before
            {
                neighbors[count++] = { yPos, xPos };                                            //count increased, and added to neighboring cells
            }
        }

        return count;
    }

    void removeWall(int y1, int x1, int y2, int x2)
    {
        int midY = (y1 + y2) / 2;
        int midX = (x1 + x2) / 2;

        mazeGrid[midY][midX] = 0; //remove wall
    }


    
    void draw()
    {
        RectangleShape cell(Vector2f(cellSize, cellSize));

        for (int i = 0; i < height; ++i) 
        {
            for (int j = 0; j < width; ++j) 
            {
                cell.setPosition(startX + j * cellSize, startY + i * cellSize);

                cell.setFillColor(mazeGrid[i][j] == 1 ? Color(188, 33, 33) : Color(153, 204, 255));

                window->draw(cell);
            }
        }
       
        makeBoundaries();
    }


    void makeBoundaries()
    {
        RectangleShape boundary(Vector2f(15, 335));
        boundary.setFillColor(Color(188, 33, 33));
        boundary.setPosition(10, 185);         
        window->draw(boundary);

        RectangleShape boundary1(Vector2f(15, 15));
        boundary1.setFillColor(Color(153, 204, 255));
        boundary1.setPosition(25, 185);
        window->draw(boundary1);

        RectangleShape boundary2(Vector2f(945, 15));
        boundary2.setFillColor(Color(188, 33, 33));
        boundary2.setPosition(40, 185);
        window->draw(boundary2);

        RectangleShape boundary3(Vector2f(15, 340));
        boundary3.setFillColor(Color(188, 33, 33));
        boundary3.setPosition(970, 190);
        window->draw(boundary3);

        RectangleShape boundary4(Vector2f(15, 15));
        boundary4.setFillColor(Color(153, 204, 255));
        boundary4.setPosition(955, 515);
        window->draw(boundary4);


        RectangleShape boundary5(Vector2f(945, 15));
        boundary5.setFillColor(Color(188, 33, 33));
        boundary5.setPosition(10, 515);
        window->draw(boundary5);
    }

    void makePathToExit()
    {
        int y = height - 2, x = width - 1;
        while (y >= 0)
        {
            mazeGrid[y][x] = 0;
            y--;
        }
    }

    bool isFree(int x, int y) const
    {
         return mazeGrid[y][x] == 0;
    }

    ~Maze()
    {
        for (int i = 0; i < height; i++) 
        {
            delete[] mazeGrid[i];
            delete[] visited[i]; 
        }

        delete[] mazeGrid;
        delete[] visited; 
    }
};


