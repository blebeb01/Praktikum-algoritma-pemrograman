#include <iostream>
#include <conio.h>
#include <time.h>
#include <cstdlib>
#include <ctime>
#include <windows.h>

using namespace std;

#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_LEFT 75
#define KEY_RIGHT 77

void
setcolor (unsigned short color)
{
  HANDLE hCon = GetStdHandle (STD_OUTPUT_HANDLE);

  SetConsoleTextAttribute (hCon, color);

}

void mhurt (int atk, int magi, int mdef);

struct posisi
	{	
    	int panjangPeta;
    	int lebarPeta;
    	int koordinatY;
    	int koordinatX;
    	int koordinat;
  	};

int main ()
{
// Map & Movement
	posisi myPosisi;

	myPosisi.panjangPeta = 40;
	myPosisi.lebarPeta = 24;
	myPosisi.koordinatY = 8;
	myPosisi.koordinatX = 0;


	cout << "Karakter ada di y:" << myPosisi.
	koordinatX << ", x:" << myPosisi.koordinatY << "\n";

	int peta[myPosisi.lebarPeta][myPosisi.panjangPeta] = {
    {4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4},
    {4, 2, 1, 1, 1, 1, 5, 6, 5, 2, 1, 1, 1, 1, 1, 1, 1, 1, 2, 4},
    {4, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 4},
    {4, 1, 1, 1, 1, 1, 5, 1, 5, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 4},
    {4, 1, 1, 1, 1, 1, 5, 1, 5, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 4},
    {4, 1, 1, 1, 1, 1, 5, 1, 5, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 4},
    {4, 5, 5, 5, 5, 5, 5, 1, 5, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 4},
    {1, 1, 1, 1, 1, 1, 1, 1, 5, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 4},
    {1, 1, 1, 1, 1, 1, 1, 1, 5, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 4},
    {4, 5, 5, 5, 5, 5, 5, 1, 5, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 4},
    {4, 1, 1, 1, 1, 1, 5, 1, 5, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 4},
    {4, 1, 1, 1, 1, 1, 5, 1, 5, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 4},
    {4, 1, 1, 1, 1, 1, 5, 1, 5, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 4},
    {4, 1, 1, 1, 1, 1, 5, 1, 5, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 4},
    {4, 2, 1, 1, 1, 1, 1, 1, 1, 2, 1, 1, 1, 1, 1, 1, 1, 1, 2, 4},
    {4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4},
	};


	int arrowKey;
  
	int game = 1;
	while (game <= 1)
    {
      // Input Keyboard
      main :
	  cout << "Masukan arrow key ";
      arrowKey = (getch ());
      cout << "Arrow key yang dimasukan " << myPosisi.koordinat << "\n";

      // Aturan menggerakkan karakter ke atas
      if (arrowKey == KEY_UP
	  && peta[myPosisi.koordinatY - 1][myPosisi.koordinatX] < 4)
	{
	  myPosisi.koordinatY -= 1;
	  myPosisi.koordinatY < 0 ? myPosisi.koordinatY =
	    0 : myPosisi.koordinatY;
	}
      else if (arrowKey == KEY_DOWN
	       && peta[myPosisi.koordinatY + 1][myPosisi.koordinatX] < 4)
	{
	  myPosisi.koordinatY += 1;
	  myPosisi.koordinatY > 15 ? myPosisi.koordinatY =
	    15 : myPosisi.koordinatY;
	}
      else if (arrowKey == KEY_LEFT
	       && peta[myPosisi.koordinatY][myPosisi.koordinatX - 1] < 4)
	{
	  myPosisi.koordinatX -= 1;
	  myPosisi.koordinatX < 0 ? myPosisi.koordinatX =
	    0 : myPosisi.koordinatX;
	}
      else if (arrowKey == KEY_RIGHT
	       && peta[myPosisi.koordinatY][myPosisi.koordinatX + 1] < 4)
	{
	  myPosisi.koordinatX += 1;
	  myPosisi.koordinatX > 19 ? myPosisi.koordinatX =
	    19 : myPosisi.koordinatX;
	}
      else
	{

// nothing to do
	};

      myPosisi.koordinat = peta[myPosisi.koordinatY][myPosisi.koordinatX];
      system ("cls");
      for (int i = 0; i < myPosisi.lebarPeta; i++)
	{
	  for (int j = 0; j < myPosisi.panjangPeta; j++)
	    {
	      if (myPosisi.koordinatX == j && myPosisi.koordinatY == i
		  && myPosisi.koordinat < 4)
		{
		  setcolor (13);
		  cout << "$";
		  setcolor (7);
		}
	      else if (peta[i][j] == 1)
		{
		  setcolor (11);
		  cout << "_";
		  setcolor (7);
		}
	      else if (peta[i][j] == 2)
		{
		  setcolor (4);
		  cout << "!";
		  setcolor (7);
		}
	      else if (peta[i][j] == 4)
		{
		  setcolor (2);
		  cout << "=";
		  setcolor (7);
		}
	      else if (peta[i][j] == 5)
		{
		  setcolor (1);
		  cout << "-";
		  setcolor (7);
		}
	      else if (peta[i][j] == 6)
		{
		  setcolor (8);
		  cout << "o";
		  setcolor (7);
		}
	    }
	  cout << "\n";

	};
	};
	
// Gameplay
	int choice;
	int mhp, hp, i, init, atk, def, matk, mdef, hurt, mhurt, agi, magi;
	atk = 10;
	def = 15;
	agi = 5;
	matk = 10;
	mdef = 15;
	magi = 5;
	
	srand((unsigned)time(0));
	init = rand()%2 + 1;
	mhp = rand()%50 + 60;
	hp = rand()%20 + 80;
	
	if (init == 1) {
		cout<<"You start.\n==========\n";
		while (hp > 0 || mhp > 0) {
			cout<<"What do you want to do?\n1 - Fierce Attack\n2 - Lithe Attack\n3 - Defensive moves\n";
			do {cin >> choice;}
			while (choice > 3 || choice < 1);
			
			switch (choice) {
				case 1:
					atk = rand()%20 + 10;
					def = rand()%10 + 10;
					agi = rand()%5;
					break;
				case 2:
					atk = rand()%5 + 10;
					def = rand()%10 + 10;
					agi = rand()%15;
					break;
				case 3:
					atk = rand()%10 + 10;
					def = rand()%20 + 10;
					agi = rand()%5;
					break;
			}
			choice = rand()%3;
			switch (choice) {
				case 1:
					atk = rand()%20 + 10;
					def = rand()%10 + 10;
					agi = rand()%5;
					break;
				case 2:
					atk = rand()%5 + 10;
					def = rand()%10 + 10;
					agi = rand()%15;
					break;
				case 3:
					atk = rand()%10 + 10;
					def = rand()%20 + 10;
					agi = rand()%5;
					break;
			}
			
// Battle
   			mhurt = (atk - magi) - (mdef / atk);
			if (mhurt < 0) {
				mhurt = 0;
			}
			mhp = mhp - mhurt;
			cout << "You did " << mhurt << " damage to the monster!\n";
			cin.get();
			
// Event (monster)
			if (mhp < 1) {
				cout << "You killed the beast!! You won with " << hp << " hp left.\n";
				cin.get();
				return 0;
			}
			cout << "The monster now have " << mhp << " hp left.\n";
			hurt = (matk - agi) - (def / matk);
			if (hurt < 0) {
				hurt = 0;
			}
			hp = hp -hurt;
			cout << "The monster hit you for " << hurt << " damage.\n";
			
// Event (human)
			if (hp < 1) {
				cout << "You died. The beast still has " << mhp << " hp left.\n";
				cin.get();
				return 0;
			}
			cout << "You now have " << hp << " hp left.\n\n";
			}
			}
			
// If the moster starts first
			else {
				cout << "Monster start.\n==============\n";
				while (hp > 0 || mhp >0) {
					choice = rand()%3;
					switch (choice) {
						case 1:
							matk = rand()%20 + 10;
							mdef = rand()%10 + 10;
							magi = rand()%5;
							break;
						case 2:
        					matk = rand()%5 + 10;
							mdef = rand()%10 + 10;
							magi = rand()%15;
        					break;
    					case 3:
        					matk = rand()%10 + 10;
							mdef = rand()%20 + 10;
							magi = rand()%5;
							break;
					}
					
// Monster attacks (first turn)
					hurt = (matk - agi) - (def / matk);
					if (hurt < 0) {
						hurt = 0;
					}
					hp = hp - hurt;
					cout << "The monster hit you for " << hurt << " damage.\n";
					
// Human damaged
					if (hp < 1) {
						cout << "You died. The beast still has " << mhp << " hp left.\n";
						cin.get();
						return 0;
					}
					
					cout << "You now have " << hp << " hp left.\n\n";
					cout << "What do you want to do?\n1 - Fierce Attack\n2 - Lithe Attack\n3 - Defensive moves\n";
					do {cin >> choice;}
					while (choice > 3 || choice < 1);
					switch (choice) {
						case 1:
							matk = rand()%20 + 10;
							mdef = rand()%10 + 10;
							magi = rand()%5;
							break;
						case 2:
        					matk = rand()%5 + 10;
							mdef = rand()%10 + 10;
							magi = rand()%15;
        					break;
    					case 3:
        					matk = rand()%10 + 10;
							mdef = rand()%20 + 10;
							magi = rand()%5;
							break;
					}
					 
// Human damages monster
					mhurt = (atk - magi) - (mdef / atk);
					if (mhurt < 0) {
						mhurt = 0;
					}
					mhp = mhp - mhurt;
					cout << "You did " << mhurt << " damage to the monster!\n";
					cin.get();
					return 0;
				}
				cout << "The monster now have " << mhp << " hp left.\n";
			}
		
	
	
}
