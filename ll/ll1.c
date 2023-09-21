#include<stdio.h>
#include<stdlib.h>
struct Node{
	int data;
	struct Node* next;
};
typedef struct Node node;

/*void create(node* prev)
{
	node new_node;
	new_node.data=8;
	new_node.next=NULL;
	prev->next=&new_node;
}*/
node* traverse(node *head,int display);
void add(node ** head_address);
node* create();
node* create()
{
	node *new_node=(node *)malloc(sizeof(node));
	printf("enter the data:");
	scanf("%d",&(new_node->data));
	//new_node.data;
	new_node->next=NULL;
	return new_node;
}
void main()
{
	node * head=NULL;
	add(&head);
	add(&head);
	add(&head);
	traverse(head,1);
}
void add(node ** head_address)
{
	node *last=traverse(*head_address,0);
	if(last==NULL)
	{
		*head_address=create();
	}
	else
	{
		last->next=create();
	}
}
node* traverse(node *head,int display)
{
	if(head==NULL)
	{
		return NULL;
	}
	else
	{
		while(head->next!=NULL)
		{
			if(display==1)
			{
				printf("%d \n",head->data);
			}
			
			head=head->next;
		}
		if (display==1)
		{
			printf("%d \n",head->data);
		}
		return head;
	}
	/*
	node *current=&first;
	//printf("%d",current.data);
	while(current->next!=NULL)
	{
		printf("%d",current.data);
		current=current->next;
	}
	printf("%d",current->data);
	*/
}
