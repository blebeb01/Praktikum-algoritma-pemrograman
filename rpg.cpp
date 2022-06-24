#include <iostream>
#include <conio.h>
#include <time.h>
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
  // Game dojo suit
  /*
     1 jalan biasa : _
     2 orang : !
     3 
     4 tembok : =
     5 kayu : -
     6 Batu : o
   */

//    int panjangPeta = 20; // x
//    int lebarPeta = 16; // y

//    int posisiKarakterY = 15;
//    int posisiKarakterX = 4;

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
	/*
     #define KEY_UP 72
     #define KEY_DOWN 80
     #define KEY_LEFT 75
     #define KEY_RIGHT 77
   */
  
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
}
