#include<stdio.h>
#include<stdlib.h>


typedef struct Link
{
	int x;
	struct Link * next;
}link;

void add(link * head, int num)
{
	link* prev;
	link* next;
	link* newnode;
	newnode = (link*)malloc(sizeof(link));
	newnode -> x = num;
	newnode -> next = 0;
	next = head;
	while(newnode -> x > next->x)
	{
		if(next->next==0)
		{
			next ->next = newnode;
			return;
		}
		prev = next;
		next = next -> next;
	}
	prev -> next = newnode;
	newnode -> next = next;
}
	
int main()
{
	link *start, *newnode, *tail;
	tail = (link*)malloc(sizeof(link));
	start = tail;
	tail -> x = 0;
	for(int i=1;i<10;i++)
	{
		newnode = (link*)malloc(sizeof(link));
		newnode -> x = i*i;
		newnode -> next = 0; 
		tail -> next = newnode;
		tail = newnode;
	}
	tail = start;
	while(tail -> next != 0)
	{
		printf("%d ", tail -> x);
		tail = tail -> next;
	}
	
	printf("%d\n", tail -> x);
	tail = start;
	add(start, 90);
	
	while(tail -> next != NULL)
	{
		printf("%d ", tail -> x);
		tail = tail -> next;
	}
	printf("%d\n", tail -> x);
}


