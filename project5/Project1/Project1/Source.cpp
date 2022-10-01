#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

#define size 10

int stack[size];
int maze[size][size];
int bfs[size][size];
int queek[size];
int font = -1, rear = -1;

int top = -1;

void add(int num)
{
	rear++;
	queek[rear] = num;
}
int minus()
{
	font++;
	return queek[font];
}

void push(int data) {
	if (top >= size) {
		//printf("堆疊已滿,無法再加入\n");
	}
	else {
		top++;
		stack[top] = data;
	}

}
int pop() {
	int data;
	if (top==-1) {
		//printf("堆疊已空\n");
	}
	else {
		data = stack[top];
		top--;
		return data;
	}
}
void startmaze(int mazesize)
{
	int temp=0;

	for (int i = 0; i < mazesize; i++)
	{
		for (int j = 0; j < mazesize; j++)
		{
			scanf("%d", &temp);
			maze[i][j]=temp;
			bfs[i][j] = temp;
		}
	}
	maze[0][0] = 1;
	bfs[0][0] = 1;
}

int checkroad(int mazesize)
{
	int check = 0;

	for (int i = 0; i < mazesize; i++)
	{
		if (maze[stack[top]][i] == 3 && maze[i][i] == 0)
		{
			check = 1;
		}
	}
	return check;
}

void printmaze(int mazesize)
{
	for (int i = 0; i < mazesize; i++)
	{
		for (int j = 0; j < mazesize; j++)
		{
			printf("	%d", maze[i][j]);
		}
		printf("\n");
	}
}

void walk(int mazesize)
{
	for (int i = 0; i < mazesize; i++)
	{
		//printf("stack %d ,maze[stack[top]][i] %d,maze[i][i] %d \n", stack[top], maze[stack[top]][i], maze[i][i]);
		if (maze[stack[top]][i] == 3&&maze[i][i]==0)
		{
			//printf("ok");
			printf("%d ", i);
			push(i);
			maze[i][i] = 1;
			break;
		}
		else if (maze[stack[top]][i] == 3 && maze[i][i] == 1)
		{
			if (checkroad(mazesize)==0)
			{
				maze[stack[top]][stack[top]] = 2;
				pop();
			}
		}
		else if (maze[stack[top]][i] == 3 && maze[i][i] == 2)
		{
			if (checkroad(mazesize)==0)
			{
				maze[stack[top]][stack[top]] = 2;
				maze[stack[top]][i] == -1;
				pop();
			}
		}
	}
}

void bfswalk(int mazesize)
{
	for (int i = 0; i < mazesize; i++)
	{
		//printf("stack %d ,maze[stack[top]][i] %d,maze[i][i] %d \n", stack[top], maze[stack[top]][i], maze[i][i]);
		if (bfs[font+1][i]==3&&bfs[i][i]!=1)
		{
			printf("%d ",i);
			add(i);
			bfs[i][i] = 1;
		}
	}
	minus();
}


int main()
{
	//DFS

	int mazesize=0;
	printf("please enter mazesize");
	scanf("%d", &mazesize);
	startmaze(mazesize);
	push(0);
	printf("DFS: 0 ");
	int count = 0;
	while (maze[0][0] != 2&&count<10)
	{
		walk(mazesize);
		count++;
	}
	printf("\n");
	
	//BFS
	top = -1;
	
	printf("BFS: 0 ");
	while (font<mazesize)
	{
		bfswalk(mazesize);
	}
}
