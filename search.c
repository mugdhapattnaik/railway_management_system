#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#define SIZE 10000;

void menu();
void empmenu();
void startagain();

struct tm {
   int tm_min;         /* minutes, range 0 to 59           */
   int tm_hour;        /* hours, range 0 to 23             */
   int tm_mday;        /* day of the month, range 1 to 31  */
   int tm_mon;         /* month, range 0 to 11             */
};

typedef struct Trains{
    char tno[10];
    char source[100];
    char dest[100];
    struct tm *date;
}train;

FILE *tptr = fopen("C:\Users\nehas\Documents\GitHub\railway_management_system\trains.txt","r");


int main()
{
    printf("Are you a passenger or an employee?\n");
    printf("If you are an employee, enter 1.\n If you are a passenger, enter 2.");
    int q;
    scanf("%d",&q);
    if(q==1)
    {
        empmenu();
    }
    else if(q==2)
    {
        menu();
    }
}


void menu()
{
    int x;
    char n[100];
    char s[100];
    char d[100];
    int p;
    printf("\n1.Display all scheduled trains\n");
    printf("2.Search train by source/starting place\n" );
    printf("3.Search train by destination\n");
    printf("4.Search by train number\n");
    printf("5.Search by date\n");
    printf("6.Book train\n");

    printf("Enter your choice :\n");
    scanf("%d", &x);
    switch(x)
    {
        case 1: printf("SCHEDULED TRAINS\n");
                break;

        case 2: printf("source lol\n");
                break;

        case 3: printf("destination lol\n");
                break;

        case 4: printf("train number lol\n");
                break;

        case 5: printf("date lol\n");
                break;
               
        case 6 :printf("Enter number of passengers : ");
                scanf("%d",&p);
                for(int i=0;i<p;i++)
                {
                    printf("Enter passenger%d name :  ",(i+1));
                    scanf("%s",&n);
                }
                printf("Enter source/starting place :  ");
                scanf("%s",&s);
                printf("Enter destination :  ");
                scanf("%s",&d);
                break;


    }
    startagain();


}

void startagain()
{
    printf("Do you want to start over?(1 for yes and 2 for no)\n");
    int b;
    scanf("%d",&b);
    if(b==1)
    {
        menu();
    }
    else if(b==2)
    {
        printf("Alright, thank you.");
    }
}

void empmenu()
{
    
}
