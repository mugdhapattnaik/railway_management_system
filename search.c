#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#define SIZE 1000

void menu();
void empmenu(FILE *);
void startagain();


typedef struct Trains{
    char tno[10];
    char source[100];
    char dest[100];
    char date[100];
}train;

train t[100];


int main()
{
    FILE *tptr;
    tptr = fopen("trains.txt", "a");
    printf("Are you a passenger or an employee?\n");
    printf("If you are an employee, enter 1.\n  If you are a passenger, enter 2. \n To view the entire train schedule, enter 3. ");
    int q;
    scanf("%d",&q);
    if(q==1)
    {
        empmenu(tptr);
        freopen("trains.txt","r",tptr);
        readFile(tptr);
        fclose(tptr);
    }
    else if(q==2)
    {
        menu();
    }
    else if(q==3)
    {
        
    }


}


void menu()
{
    int x;
    char n[100];
    char s[100];
    char d[100];
    int p;
    printf("1.Search train by source/starting place\n" );
    printf("2.Search train by destination\n");
    printf("3.Search by train number\n");
    printf("4.Search by date\n");

    printf("Enter your choice :\n");
    scanf("%d", &x);
    switch(x)
    {

        case 1: printf("source lol\n");
                break;

        case 2: printf("destination lol\n");
                break;

        case 3: printf("train number lol\n");
                break;

        case 4: printf("date lol\n");
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

void readFile(FILE * fPtr)
{
    char ch;

    do 
    {
        ch = fgetc(fPtr);

        putchar(ch);

    } while (ch != EOF);
}

void empmenu(FILE *a)
{
    printf("Do you want to add train data?\n");
    printf("To add train data, enter 1. \n To view data, enter 2.\n");
    int w;
    scanf("%d",&w);
    if(w==1)
    {
        printf("Enter the number of trains whose details you want to add :\n ");
        int n;
        scanf("%d",&n);
        for(int j=0;j<n;j++)
        {
            printf("Enter train number: \n");
            scanf("%s",&t[j].tno);
            fgets(t[j].tno, SIZE, stdin);
            fputs(t[j].tno,a);
            freopen("trains.txt","r",a);
            printf("Enter Source: \n");
            scanf("%s",&t[j].source);
            fgets(t[j].source, SIZE, stdin);
            fputs(t[j].source,a);
            freopen("trains.txt","r",a);
            printf("Enter destination: \n");
            scanf("%s",&t[j].dest);
            fgets(t[j].dest, SIZE, stdin);
            fputs(t[j].dest,a);
            freopen("trains.txt","r",a);
            printf("Enter departure date: \n");
            scanf("%s",&t[j].date);
            fgets(t[j].date, SIZE, stdin);
            fputs(t[j].date,a);
            freopen("trains.txt","r",a);

            printf("\nSuccessfully appended data to file. \n");

        }

    }
    else if(w==2)
    {
       menu();
       startagain();
    }
}

void tdisplay(train a)
{
    printf("Train number : %s  ",a.tno);
    printf("Source/starting point : %s  ",a.source);
    printf("Destination : %s  ",a.dest);
    printf("Date and Time : %s  ",a.date);

}