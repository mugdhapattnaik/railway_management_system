/* 
Railway reservation using linked lists and queues-
If reservation is full, put them in waiting list(queue) and give them a waiting list number.
A passenger may cancel their ticket if they want to; in this case, the passenger's ticket(in waiting list) is booked automatically.
Display all the contents of reserved passengers.

*/

#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#define size 10


typedef struct NODE
{
	int reg_no;
	int age;
	char name[20];
	struct NODE *next;
} node;

node* deq();
void create();
int reserve(node*);
int cancel(int);
void enq(node*);
void display();


node *start;
node *front;
node *rear;
int count=0;
int reg_num=0;

void create( )
{
	node *new=malloc(sizeof(node));
	new->reg_no=1;
	printf("Name: ");
	scanf("%s", new->name);
	printf("Age : ");
	scanf("%d", &new->age);
	start=new;
	new->next=NULL;
	reg_num++;	
}

int reserve(node *start)
{
	
	if(start==NULL)
	{
   		create(start);
		return 1;
	}
	else 
	{	
        node *temp, *new_node;
        temp=start;
        while(temp->next!=NULL)
            temp=temp->next;
        
        new_node=malloc(sizeof(node));        
        printf("Name: ");
        scanf("%s", new_node->name);
        printf("Age : ");
        scanf("%d", &new_node->age);
        new_node->next=NULL;

        if(reg_num<=size)
        {
            reg_num++;
            new_node->reg_no=reg_num;
            temp->next=new_node;
            
            return 1;
        }
        else
        {
            enq(new_node);
            return 0;
        }
    }
}

// NEHAAAAAAAAAAA
//CHECK IF THIS CANCEL THING IS WORKING DURING EXECUTION

int cancel(int reg)
{
	node *ptr, *preptr=NULL, *new;
	ptr=start;
	if(start==NULL)
	return -1;
	if(ptr->next==NULL && ptr->reg_no==reg)
		{
		start=NULL;
		reg_num--;
		free(ptr);
		return 1;
		
		}
		
	else{	
	while(ptr->reg_no!=reg && ptr->next!=NULL)
		{
			preptr=ptr;
			ptr=ptr->next;
		}
		if(ptr==NULL && ptr->reg_no!=reg)
			return -1;
		else
			preptr->next=ptr->next;
		free(ptr);
		new=deq();
		while(preptr->next!=NULL)
			preptr=preptr->next;
		preptr->next=new;
		reg_num--;
		return 1;
	
	}
}

void enq(node *new_node)
{
	if(rear==NULL)
	{
		rear=new_node;
		rear->next=NULL;
		front=rear;
	}
	else
	{
		node *temp=new_node;
		rear->next=temp;
		temp->next=NULL;
		rear=temp;
	}
	count++;
}

node* deq()
{
	node *front1;
	front1=front;
	if(front==NULL)
		return NULL;
	else
	{
	    count-- ;
		if(front->next!=NULL)
		{
			front=front->next;
			front1->next=NULL;
			return front1;
		}
		else
		{
			front=NULL;
			rear=NULL;
			
			return front1;
		}
	}
}

void display()
{
	node *temp=start;
	while(temp!=NULL)
	{
		printf("\nRegistration Number: %d\n", temp->reg_no);
		printf("Name : %s\n\n", temp->name);
		temp=temp->next;
    }    
}


int main()
{
	int choice, status=0,canc=0, reg=0;
	start=rear=front=NULL;	
	printf("\n\t\t\t-x-x-x-RAILWAY RESERVATION-x-x-x-\t\t\t\t\n");
	int ch =0;
    printf("Are you a passenger or an employee?\n");
    printf("If you are an employee, enter 1.\n If you are a passenger, enter 2.\n");
    int q;
    scanf("%d",&q);
    if(q==1)
    {
        //NEHAAAAAAAAAAAAA 
        //IMPLEMENT THE TRAIN DATABASE USING LINKED LIST
        FILE *tptr = fopen("trains.txt","w+");
        FILE *ptr = fopen("data.txt","w+");
        //empmenu(tptr,ptr);
    }
    else if(q==2)
    {       
        while(ch!=4)
        {
            printf("\n\nDo you want to - \n 1. Reserve a ticket? \n 2. Cancel Booking \n 3. Display passenger details \n 4. exit\n\n");
            scanf("%d", &choice); 
            switch(choice)
            {	
                case 1: status=reserve(start);
                        if(status==0)
                            printf("\nBooking Full!\nYou are added to the waiting list. Waiting list number %d", count);
                        else
                            printf(" \nBooking Successful. Reg no:%d\n\n", reg_num);    
                        break;
                    
                case 2: printf(" \n Enter the Registration number to be cancelled\n");
                        scanf(" %d", &reg);
                        if(reg>reg_num)
                            printf("Invalid");
                        else
                        {
                            canc=cancel(reg);
                            if(canc==-1)
                                printf("\nRegistration number invalid\n");
                            else
                                printf("\nRegistration cancelled successfully\n");
                        }
                        break;
                        
                case 3: display();
                        break;
                case 4: exit(0);   
                        break;
                default: printf("\nWrong choice!\n");
            }
        }
    }
}

