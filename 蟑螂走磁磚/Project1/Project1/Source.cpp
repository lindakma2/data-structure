#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;

//define firstarray at top
int firstx=10, firsty =10;
int firstarray[15][15], firstsize = 15;

//firstfuncion
void FirstArrayStart()
{
	for (int i = 0; i < firstsize; i++)
	{
		for (int j = 0; j < firstsize; j++)
		{
			firstarray[i][j] = 0;
		}
	}
	firstarray[firstx][firsty] = 1;
}

void FirstGenertateDirection(int nowx,int nowy,int size)
{
	int generate = rand() % 8;
	int xmove[8] = { -1,0,1,1,1,0,-1,-1 };
	int ymove[8] = { 1,1,1,0,-1,-1,-1,0 };
	
	if (nowx + xmove[generate] < 0 || nowx + xmove[generate] >= size)
	{
		return;
	}
	else if (nowy + ymove[generate] < 0 || nowy + ymove[generate] >= size)
	{
		return;
	}
	else
	{
		firstx = firstx + xmove[generate];
		firsty = firsty + ymove[generate];
		firstarray[firstx][firsty]++;
	}
}

bool Firstfull()
{
	bool full=true;
	for (int i = 0; i < firstsize; i++)
	{
		for (int j = 0; j < firstsize; j++)
		{
			if(firstarray[i][j] == 0)
			{
				full = false;
			}
		}
	}
	if (full)
	{
		return true;
	}
	else
	{
		return false;
	}
}
void FirstPrintMaze()
{
	for (int i = 0; i < firstsize; i++)
	{
		for (int j = 0; j < firstsize; j++)
		{
			if (firstarray[i][j] >= 10)
			{
				cout << firstarray[i][j] << " ";
			}
			else
			{
				cout << firstarray[i][j] << "  ";
			}
		}
		cout << endl;
	}
}

//define firstarray at top
int secondx = 10, secondy = 10;
int secondarray[39][19], secondxize = 39, secondysize = 19;

//second function
void SecondArrayStart()
{
	for (int i = 0; i < secondxize; i++)
	{
		for (int j = 0; j < secondysize; j++)
		{
			secondarray[i][j] = 0;
		}
	}
	secondarray[secondx][secondy] = 1;
}

void SecondGenertateDirection(int nowx, int nowy)
{
	int generate = rand() % 8;
	int xmove[8] = { -1,0,1,1,1,0,-1,-1 };
	int ymove[8] = { 1,1,1,0,-1,-1,-1,0 };

	if (nowx + xmove[generate] < 0 || nowx + xmove[generate] >= secondxize)
	{
		return;
	}
	else if (nowy + ymove[generate] < 0 || nowy + ymove[generate] >= secondysize)
	{
		return;
	}
	else
	{
		secondx = secondx + xmove[generate];
		secondy = secondy + ymove[generate];
		secondarray[secondx][secondy]++;
	}
}

bool Secondfull()
{
	bool full = true;
	for (int i = 0; i < secondxize; i++)
	{
		for (int j = 0; j < secondysize; j++)
		{
			if (secondarray[i][j] == 0)
			{
				full = false;
			}
		}
	}
	if (full)
	{
		return true;
	}
	else
	{
		return false;
	}
}
void SecondPrintMaze()
{
	for (int i = 0; i < secondxize; i++)
	{
		for (int j = 0; j < secondysize; j++)
		{
			if (secondarray[i][j] >= 10)
			{
				cout << secondarray[i][j] << " ";
			}
			else
			{
				cout << secondarray[i][j] << "  ";
			}
		}
		cout << endl;
	}
}
int main()
{
	srand(time(NULL));

	//first array
	cout << "first maze"<<endl;
	FirstArrayStart();
	int step=0;
	while (!Firstfull())
	{
		
		FirstGenertateDirection(firstx, firsty, firstsize);
		step++;
		if (step > 50000)
		{
			break;
		}
	}
	FirstPrintMaze();
	cout << "total step is:" << step<<endl;
	cout << "-------------------------------------------" << endl;

	//second array
	cout << "second maze" << endl;
	SecondArrayStart();
	step = 0;
	while (!Secondfull())
	{

		SecondGenertateDirection(secondx, secondy);
		step++;
		if (step > 50000)
		{
			break;
		}
	}
	SecondPrintMaze();
	cout << "total step is:" << step << endl;
	return 0;
}