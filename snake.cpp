#include <iostream>
#include <conio.h>
using namespace std;

bool gameover;
const int width = 20;
const int height = 17;
int x, y, fruitX, fruitY, score;
int tailX[100], tailY[100]; //snake coordinates
int nTail;
enum eDirecton {STOP = 0, LEFT, RIGHT, UP, DOWN}; //Controls
eDirecton dir;

void Setup() {
    gameover = false;
    dir = STOP;
    x = width / 2;
    y = height / 2;
    fruitX = rand() % width; //Display food randomly
    fruitY = rand() % height; 
    score = 0;
}

void Draw() {
    system("cls");
    
    for(int i = 0; i< width + 2; i++)
    cout << "#";
    cout << endl;

    for(int i = 0; i < height; i++) {
        for(int j = 0; j < width; j++) {
            if(j == 0)
            cout << "#"; //Walls
            
            if(i == y && j == x)
            cout << "*"; //Snake

            else if(i == fruitY && j == fruitX)
            cout << "%"; //

            else {
                bool print = false;
            }
        }
    }

}