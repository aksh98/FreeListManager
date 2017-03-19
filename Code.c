#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node
{
	long long int address;
	int size;
	struct node* next; 
};

typedef struct node Node;
Node* start = NULL;
Node* currNode;

void mallocc(int size)
{
	Node* newnode = (Node*)malloc(sizeof(Node));
	newnode->next = NULL;
	newnode->size = size;
	newnode->address = (long long int)newnode;

	if(start==NULL)
	{
		start = newnode;
		currNode = newnode;
	}
	else { 
		currNode->next = newnode;}
	currNode = newnode;

}

void freee(int num)
{
	if(start == NULL){
		printf("Null start\n");
		return;
	}
	
	Node* temp = start;
	if(num == 1)
	{
		start = temp->next;
		free(temp);
		return;
	}
	int i;
	for (i = 1;(i < num-1) && (temp!=NULL); ++i){
		temp = temp->next; }

	if (temp == NULL || temp->next == NULL)
	{
		printf("No value here\n");
		return;
	}
	Node* next = temp->next->next;
	free(temp->next);
	temp->next = next;
}

void display()
{
	Node* newnode;
	printf("The linked list:\n");
	newnode = start;
	if(newnode == NULL){
		printf("Empty List\n");
		return;
	}
	int count = 0;
	printf("Index | Size |    Address\n");
	printf("==============================\n");
	while(newnode!=NULL)
	{
		count++;
		printf("%5d | %4d | %lld\n",count,newnode->size,newnode->address );
		newnode = newnode->next;
	}
	printf("==============================\n");
	return;
}

int main()
{
	printf("You can choose any one:\n");
	printf("1. Malloc\n2. Free\n3. Print\n4. Exit\n");
	while(1){
		char str[20];
		scanf("%s",str);
		int num;
		if(strcmp("malloc",str)==0 || strcmp("Malloc",str)==0)
		{
			scanf("%d",&num);
			mallocc(num);
		}
		else if(strcmp("Free",str)==0 || strcmp("free",str)==0)
		{
			scanf("%d",&num);
			freee(num);
		}
		else if(strcmp("Print",str)==0 || strcmp("print",str)==0)
		{
			display();
		}
		else if(strcmp("exit",str)==0 || strcmp("Exit",str)==0)
		{
			return 0;
		}
		else{
			printf("Invalid input! Enter again\n");
		}
	}
	return 0;
}