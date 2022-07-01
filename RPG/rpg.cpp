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
#define ESC 27

void setcolor (unsigned short color) {
  HANDLE hCon = GetStdHandle (STD_OUTPUT_HANDLE);
  SetConsoleTextAttribute (hCon, color);
}

// Map   
	const int mapLength = 20;
	const int mapWidth = 16;
	int mapY = 8;
	int mapX = 0;
	int keyBind;
	
	int map[mapWidth][mapLength] = {
    {4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4},
    {4, 1, 5, 1, 1, 1, 2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 4},
    {4, 1, 5, 1, 1, 1, 1, 1, 2, 1, 1, 1, 1, 1, 1, 1, 1, 2, 1, 4},
    {4, 1, 5, 1, 5, 5, 5, 5, 5, 5, 5, 1, 1, 5, 5, 5, 1, 1, 1, 4},
    {4, 1, 5, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 5, 1, 5, 1, 1, 1, 4},
    {4, 1, 5, 5, 5, 5, 5, 1, 1, 2, 1, 1, 1, 5, 1, 5, 1, 1, 1, 4},
    {4, 5, 5, 5, 1, 1, 5, 1, 1, 1, 1, 1, 2, 5, 1, 5, 1, 5, 5, 4},
    {1, 1, 1, 5, 1, 1, 5, 1, 1, 6, 6, 1, 1, 5, 1, 5, 1, 5, 1, 4},
    {1, 1, 1, 5, 1, 1, 5, 1, 1, 6, 6, 1, 1, 5, 1, 5, 1, 5, 1, 4},
    {4, 1, 1, 5, 5, 5, 5, 1, 1, 1, 1, 1, 1, 5, 1, 5, 1, 5, 1, 4},
    {4, 1, 1, 5, 1, 1, 1, 1, 2, 1, 1, 2, 1, 5, 1, 5, 1, 5, 5, 4},
    {4, 1, 1, 5, 1, 1, 1, 1, 1, 1, 1, 1, 1, 5, 1, 5, 1, 1, 1, 4},
    {4, 1, 1, 1, 1, 1, 5, 5, 5, 1, 1, 1, 1, 5, 5, 5, 1, 1, 1, 4},
    {4, 1, 2, 1, 1, 1, 5, 1, 5, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 4},
    {4, 1, 1, 5, 5, 5, 5, 1, 5, 5, 5, 5, 1, 1, 1, 1, 2, 1, 1, 4},
    {4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4},
	};
	
// Stat
	struct player {
			int atk;
			int def;
			int agi;
		};
	struct monster {
			int matk;
			int mdef;
			int magi;
		};
	  	
// Movement
		void playermove (int key) {
			if (keyBind == KEY_UP
		  	&& map[mapY - 1][mapX] < 4)
			{
			  mapY -= 1;
			  mapY < 0 ? mapY = 0 : mapY;
			}
	  	    else if (keyBind == KEY_DOWN
			       && map[mapY + 1][mapX] < 4)
			{
			  mapY += 1;
			  mapY > 15 ? mapY =
			    15 : mapY;
			}
	    	  else if (keyBind == KEY_LEFT
			       && map[mapY][mapX - 1] < 4)
			{
			  mapX -= 1;
			  mapX < 0 ? mapX =
			    0 : mapX;
			}
		      else if (keyBind == KEY_RIGHT
			       && map[mapY][mapX + 1] < 4)
			{
			  mapX += 1;
			  mapX > 19 ? mapX =
			    19 : mapX;
			};
		}
		
// Map render
		void maprender() {
			int pos = map[mapY][mapX];
			for (int i = 0; i < mapWidth; i++) {
		  		for (int j = 0; j < mapLength; j++) {
			    	if (mapX == j && mapY == i && pos < 4)
					{
						setcolor (13);
					  	cout << "T";
					  	setcolor (7);
					}
		   			else if (map[i][j] == 1)
					{
					  	setcolor (11);
					  	cout << " ";
					  	setcolor (7);
					}
			 	     else if (map[i][j] == 2)
					{
						setcolor (4);
						cout << "!";
						setcolor (7);
					}
				      else if (map[i][j] == 4)
					{
						setcolor (2);
						cout << "X";
						setcolor (7);
					}
		 		     else if (map[i][j] == 5)
					{
						setcolor (1);
						cout << "O";
						setcolor (7);
					}
		 		     else if (map[i][j] == 6)
					{
						setcolor (8);
						cout << "U";
						setcolor (7);
					}
		    }
		  cout << "\n";
			};
		};
	
int main ()	{
	  // Game dojo suit
	  /*
	     1 jalan biasa : _
	     2 orang : !
	     3 
	     4 tembok : =
	     5 kayu : -
	     6 Batu : o
	   */
	
// Main menu
		char menu;
		int retry;
		menu: 
		setcolor (14);
		cout << "==============================\n";
		cout << "          SIMPLE RPG          \n";
		cout << "==============================\n";
		cout << "\n1. Play\n2. Quit\n";
		setcolor (7);
		menu = getch();
		if (menu == '1') {
		system ("cls");
		cout << "\n\n\n\n          Defeat all enemies.";
		cout << "\n\n\n\n      press any key to continue...";
		getch();
		system ("cls");
		
// Movement
		int game = 1;
		while (game <= 1)
	    {
	      // Keyboard Input
	      main :
	      playermove (keyBind);
	      
	      maprender();
	      
	      cout << "\n\nUse arrow keys to move\n\n";
	      cout << "Press Esc to quit\n";
	      
		keyBind = getch();
		
		system ("cls");
			
// Gameplay	
		if (map[mapY][mapX] == 2) {
	int choice;
  int i, init, hurt, mhurt, hp, mhp;
  player stat;
  stat.atk = 10;
  stat.def = 15;
  stat.agi = 5;
  
  monster mstat;
  mstat.matk = 10;
  mstat.mdef = 15;
  mstat.magi = 5;
  
  game:
  srand((unsigned)time(0));
  init = rand()%2+1;
  mhp = rand()%50 + 60;
  hp = rand()%20 + 80;
  
  if (init == 1) {
// Player starts first
  cout<<"You start.\n==========\n";
  while (hp > 0 || mhp > 0) {
    cout<<"What do you want to do?\n1 - Fierce Attack\n2 - Lithe Attack\n3 - Defensive moves\n";
     do{cin>>choice;}while(choice>3 || choice<1);
    switch (choice) {
      case 1:
        stat.atk = rand()%20+10;
		stat.def = rand()%10+10;
		stat.agi = rand()%5;
		break;
      case 2:
		stat.atk = rand()%5+10;
		stat.def = rand()%10+10;
		stat.agi = rand()%15;
        break;
      case 3:
        stat.atk = rand()%10+10;
		stat.def = rand()%20+10;
		stat.agi = rand()%5;
		break;
	}
    choice = rand()%3;
    switch (choice) {
      case 1:
        mstat.matk = rand()%20+10;
		mstat.mdef = rand()%10+10;
		mstat.magi = rand()%5;
		break;
      case 2:
        mstat.matk = rand()%5+10;
		mstat.mdef = rand()%10+10;
		mstat.magi = rand()%15;
        break;
      case 3:
        mstat.matk = rand()%10+10;
		mstat.mdef = rand()%20+10;
		mstat.magi = rand()%5;
		break;
	}

// Battle
    mhurt = (stat.atk - mstat.magi) - (mstat.mdef/stat.atk);
    if (mhurt < 0) {
      mhurt = 0;
    }
    mhp = mhp - mhurt;
    cout<<"You did "<<mhurt<<" damage to the monster!\n";
    cin.get();
    
// Monster died (player started first)
    if (mhp < 1) {
    	map[mapY][mapX] = 1;
    	system ("cls");
      cout<<"You killed the monster!! You won with "<<hp<<" hp left.\n";
      getch();
      system ("cls");
      goto main;
      }
      
    cout<<"The monster now have "<<mhp<<" hp left.\n";
    hurt = (mstat.matk - stat.agi) - (stat.def/mstat.matk);
    if (hurt < 0) {
      hurt = 0;
    }
    hp = hp - hurt;
    cout<<"The monster hit you for "<<hurt<<" damage.\n";
    
// Player died (player started first)
    if (hp < 1) {
      cout<<"You died. The monster still has "<<mhp<<" hp left.\n";
      system ("cls");
      setcolor (20);
      cout << "\n\n\n\n          GAME OVER          \n";
      setcolor (7);
      getch();
      cout << "Retry?\n";
      cout << "1. Yes         2. No\n";
      cin >> retry;
      if (retry == 1) {
      	system ("cls");
      	goto game;
	  }
	  else if (retry == 2) {
	  	system ("cls");
      	goto menu;
	  }
      system ("cls");
      goto game;
      }
	cout<<"You now have "<<hp<<" hp left.\n\n";
     }
     }

// Monster starts first
  else {
  cout<<"Monster start.\n==============\n";
    while (hp > 0 || mhp > 0) {
    choice = rand()%3;
    switch (choice) {
      case 1:
        mstat.matk = rand()%20+10;
		mstat.mdef = rand()%10+10;
		mstat.magi = rand()%5;
		break;
      case 2:
        mstat.matk = rand()%5+10;
		mstat.mdef = rand()%10+10;
		mstat.magi = rand()%15;
        break;
      case 3:
        mstat.matk = rand()%10+10;
		mstat.mdef = rand()%20+10;
		mstat.magi = rand()%5;
		break;
	}
// Monster attack
    hurt = (mstat.matk - stat.agi) - (stat.def/mstat.matk);
    if (hurt < 0) {
      hurt = 0;
    }
    hp = hp - hurt;
    cout<<"The monster hit you for "<<hurt<<" damage.\n";
// Player died (monster started first)
    if (hp < 1) {
      cout<<"You died. The monster still has "<<mhp<<" hp left.\n";
      system ("cls");
      setcolor (20);
      cout << "\n\n\n\n          GAME OVER          \n";
      setcolor (7);
      getch();
      cout << "Retry?\n";
      cout << "1. Yes         2. No\n";
      cin >> retry;
      if (retry == 1) {
      	system ("cls");
      	goto game;
	  }
	  else if (retry == 2) {
	  	system ("cls");
      	goto menu;
	  }
      
      }
      
 	cout<<"You now have "<<hp<<" hp left.\n\n";
    cout<<"What do you want to do?\n1 - Fierce Attack\n2 - Lithe Attack\n3 - Defensive moves\n";
     do{cin>>choice;}while(choice>3 || choice<1);
    switch (choice) {
      case 1:
        stat.atk = rand()%20+10;
		stat.def = rand()%10+10;
		stat.agi = rand()%5;
		break;
      case 2:
        stat.atk = rand()%5+10;
		stat.def = rand()%10+10;
		stat.agi = rand()%15;
        break;
      case 3:
        stat.atk = rand()%10+10;
		stat.def = rand()%20+10;
		stat.agi = rand()%5;
		break;
        }


// Monster died (monster started first)
    mhurt = (stat.atk - mstat.magi) - (mstat.mdef/stat.atk);
    if (mhurt < 0) {
      mhurt = 0;
    }
    mhp = mhp - mhurt;
    cout<<"You did "<<mhurt<<" damage to the monster!\n";
    cin.get();

    if (mhp < 1) {
    	map[mapY][mapX] = 1;
    	system ("cls");
      cout<<"You killed the monster!! You won with "<<hp<<" hp left.\n";
      getch();
		system ("cls");
      goto main;
      }
    cout<<"The monster now have "<<mhp<<" hp left.\n";
  } 
  } 
}

// Quit game
	if (keyBind == ESC) {
		system ("cls");
		char quit;
		cout << "Do you want to quit the game?\n\n";
		cout << "1. Yes          2. No\n";
		quit = getch();
		
		if (quit == '1') {
			system ("cls");
			exit (0);
		}
		else if (quit == 2) {
			system ("cls");
		}
	}
}
	}
	else if (menu == '2') {
		system ("cls");
		exit (0);
	}
}
