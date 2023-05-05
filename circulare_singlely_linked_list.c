#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node *next;
};
typedef struct node NODE;
NODE *head=NULL;
void insert_at_head(NODE*nn){
	if(head==NULL){
		head=nn;
		head->next=head;
	}
	else
	{   NODE *temp=head;
		nn->next=head;
		while(temp->next!=head)
		temp=temp->next;
		temp->next=nn;
		head=nn;
	}
}
void insert_at_end(NODE *nn)
{
	if(head==NULL)
	{
	head=nn;
	head->next=head;
    }
	else
	{
		NODE *temp=head;
		while(temp->next!=head)
		temp=temp->next;
		temp->next=nn;
		nn->next=head;
	}
}
void delete_at_head()
{
	if(head==NULL)
	{
		printf("No nodes\n");
	}
	else if(head->next==head){
		printf("deleted element is %d\n",head->data);
		head=NULL;
	}
	else{
		NODE *temp=head;
		while(temp->next!=head)
		{
			temp=temp->next;
		}
		temp->next=head->next;
		printf("deleted element is %d\n",head->data);
		head=head->next;
	}
}
void delete_at_end()
{
	if(head==NULL)
	printf("No nodes\n");
	else if(head->next==head)
	{
		printf("delete node is %d \n",head->data);
		head=NULL;
	}
	else{
	NODE *temp=head;
	while(temp->next->next!=head)
	temp=temp->next;
	printf("deleted element is %d\n",temp->next->data);
    temp->next=head;
	}
}
void insert_at_pos(NODE *nn,int pos)
{
	if(pos==1)
	insert_at_head(nn);
	else
	{
		NODE *temp=head;
		int c=1;
		while(c<pos-1)
		{
			c++;
			temp=temp->next;
		}
		nn->next=temp->next;
		temp->next=nn;
	}
}
void delete_at_pos(int pos)
{   
    
    if(head==NULL)
    printf("No nodes to delete\n");
    else if(pos==1)
	delete_at_head();
	else{
		NODE *temp=head;
		int c=1;
		while(c<pos-1)
		{
			c++;
			temp=temp->next;
		}
		printf("deleted node is %d \n",temp->next->data);
		temp->next=temp->next->next;
	}
}
void display(){
	if(head==NULL)
	{
	printf("No nodes\n");
	return;
    }
	NODE *temp=head;
	do{
		printf("%d ",temp->data);
		temp=temp->next;
	}while(temp!=head);
	printf("\n");
}
int main()
{    int choice;
	while(1)
	{
		printf("enter\n1.insert at head\n2.insert at end\n3.delete at head\n4.delete at end \n5.insert at pos\n6.delete at pos\n7.display and anything else to exist");
		scanf("%d",&choice);
		if(choice==1)
		{
			int val;
			printf("enter value to be inserted:");
			scanf("%d",&val);
			NODE*nn=(NODE*)malloc(sizeof(NODE));
			nn->data=val;
			nn->next=NULL;
			insert_at_head(nn);
		}
		else if(choice==2)
		{
		int val;
		printf("enter value to be inserted:");
			scanf("%d",&val);
			NODE*nn=(NODE*)malloc(sizeof(NODE));
			nn->data=val;
			nn->next=NULL;
			insert_at_end(nn);
		}
		else if(choice==3)
		{
			delete_at_head();
		}
		else if(choice==4)
		{
			delete_at_end();
		}
		else if(choice==5)
		{
		NODE *nn=(NODE*)malloc(sizeof(NODE));
		int val;
		printf("enter a value to insert");
		scanf("%d",&val);
		nn->data=val;
		nn->next=NULL;
		int pos;
		printf("enter position to insert the node");
		scanf("%d",&pos);
		insert_at_pos(nn,pos);	
		}
		else if(choice==6)
		{
		int pos;
		printf("enter position to delete node at that position");
		scanf("%d",&pos);	
		delete_at_pos(pos);	
		}
		else if(choice==7)
		{
			display();
		}
		else
		{
			printf("your exist");
			break;
		}
	}
}
