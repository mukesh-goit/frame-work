#include<stdio.h>
#include<stdlib.h>
#define size 10
struct item
{
	int ele;
};
struct queue{
	struct item it[size];
	int front ;
	int rear;
	int full;
};
void insert(struct queue *q,int data)
{
	if(q->rear==size-1)
	q->rear=0;
	else 
	(q->rear)++;
	if(q->front==q->rear&&q->full==1)
	printf("queue overflow\n");
	else
	q->it[q->rear].ele=data;
	q->full=1;
}
int delete(struct queue *q)
{
	if(q->front==q->rear&&q->full==0)
	{
	printf("queue underflow\n");
	return;
}
	if(q->front==size-1)
	q->front=0;
	else
	q->front++;
	q->full=0;
return (q->it[q->front].ele);
	
}
void display(struct queue q)
{     int i;
	if(q.front==q.rear&&q.full==0)
	printf("empty queue\n");
	printf("the elements of queue are\n");
	do{if(q.front==size-1)
	    q.front=0;
	    else
	    q.front++;
		printf("%d",q.it[q.front]);
	}while(q.front!=q.rear);
	
}
int main()
{
	int d,choice;int data;
	struct queue q;
	q.front=size-1;
	q.rear=size-1;
	for(;;)
	{
	printf("enter 1 to insert ,2 to delete,3 to display,4 to quit\n");
	scanf("%d",&choice);
	switch(choice)
	{
		case 1:printf("enter the data to be inserted\n");
		scanf("%d",&data);
		insert(&q,data);
		break;
		case 2:d=delete(&q);
		printf("deleted elemnt is %d\n",d);
		break;
		case 3:display(q);
		break;
		case 4:printf("quitting \n");
		return;
		default:printf("no such option");
		
	}
}
return 0;
}

