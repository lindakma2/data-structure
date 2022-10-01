#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

class bst
{
public:
	int data;
	bst* llink;
	bst* rlink;
};

typedef bst node2;

void insert(bst* head,int number)
{
	bst* current=head;
	bst* node1 = new bst;
	node1->data = number;
	node1->llink = NULL;
	node1->rlink = NULL;
	while (!(current->rlink == NULL && current->llink == NULL))
	{
		if (number > current->data)
		{
			if (current->rlink==NULL)
			{
				break;
			}
			current = current->rlink;
		}
		else if (number < current->data)
		{
			if (current->llink == NULL)
			{
				break;
			}
			current = current->llink;
		}
		
	}
	if (number > current->data)
	{
		current->rlink = node1;
	}
	else if (number < current->data)
	{
		current->llink = node1;
	}
}

void inorder(bst* ptr)
{
	if (ptr)
	{
		inorder(ptr->llink);
		printf("%d ", ptr->data);
		inorder(ptr->rlink);
	}
}

bool check(int enter[],int count,int number)
{
	for (int i = 0; i < count; i++)
	{
		if (enter[i] == number)
		{
			return false;
		}
	}
	return true;
}

bst* minValueNode(bst* node)
{
	bst* current = node;

	while (current && current->llink != NULL)
		current = current->llink;

	return current;
}

bst* deleteNode(bst* root, int key)
{
	if (root == NULL)
		return root;

	if (key < root->data)
		root->llink = deleteNode(root->llink, key);

	else if (key > root->data)
		root->rlink = deleteNode(root->rlink, key);

	
	else {
		
		if (root->llink == NULL) {
			struct bst* temp = root->rlink;
			free(root);
			return temp;
		}
		else if (root->rlink == NULL) {
			struct bst* temp = root->llink;
			free(root);
			return temp;
		}

		
		struct bst* temp = minValueNode(root->rlink);

		
		root->data = temp->data;

		root->rlink = deleteNode(root->rlink, temp->data);
	}
	return root;
}

void found(int enter[], int count,int number)
{
	int rank=0;
	int check = 0;
	int temp = 0;

	

	for (int i = 0; i < count-1; i++)
	{
		for (int j = 0; j < count - 1 - i; j++)
		{
			if (enter[j] > enter[j + 1])
			{
				temp = enter[j];
				enter[j] = enter[j + 1];
				enter[j + 1] = temp;
			}
		}
	}

	for (int i = 0; i < count; i++)
	{
		if (enter[i] != number&&enter[i]!=-1)
		{
			rank++;
		}
		else if (enter[i] == number)
		{
			rank++;
			check = 1;
			printf("rank %d: ", rank);
		}
	}
	if (!check)
	{
		printf("no found");
	}
}

int main()
{
	int temp=0,count=0,enter[100];
	FILE* fin;
	bst* head=new bst;
	head->llink = NULL;
	head->rlink = NULL;
	fin = fopen("data.txt", "rt");
	fscanf(fin, "%d", &temp);
	while (temp != -1)
	{
		enter[count] = temp;
		if (temp != -1&&count==0)
		{
			head->data = temp;
		}
		else
		{
			//printf("%d", temp);
			insert(head, temp);
		}
		fscanf(fin, "%d", &temp);
		count++;
		
	}
	inorder(head);
	
	int method = 0,enternum=0;
	printf("please enter the method \n");
	printf("1.insert \n");
	printf("2.delete \n");
	printf("3.find \n");
	printf("4.quit \n");
	scanf("%d", &method);
	while (method != 4)
	{

		if (method == 1)
		{
			printf("please enter number");
			scanf("%d", &enternum);
			if (check(enter, count, enternum))
			{
				enter[count] = enternum;
				insert(head, enternum);
				inorder(head);
			}
			else
			{
				printf("already exist");
			}
		}
		else if (method == 2)
		{
			printf("please enter number");
			scanf("%d", &enternum);
			if (!check(enter, count, enternum))
			{
				for (int i = 0; i < count; i++)
				{
					if (enter[i] == enternum)
					{
						enter[i] = -1;
					}
				}
				deleteNode(head, enternum);
				inorder(head);
			}
			else
			{
				printf("don't exist");
			}
		}
		else if (method == 3)
		{
			printf("please enter number");
			scanf("%d", &enternum);
			found(enter, count, enternum);
		}
		else
		{
			break;
		}
		printf("please enter method");
		scanf("%d", &method);
	}

	return 0;
}