#include<stdio.h>
#include <stdlib.h>
int main()
{
    int st=0,i=0;
    char curr,ip[20];
    printf("Enter ip string \t :");
    scanf("%s",ip);
    while((curr=ip[i++])!='\0')
    {
        switch(st)
        {
            case 0: 
            if(curr=='a')
                st=1;
            else if(curr=='b')
                st=2;
            else
            {
                printf("Invalid symbol");
                exit(0);
            }
            break;


            case 1: 
            if(curr=='a')
                st=0;
            else if(curr=='b')
                st=3;
            else
            {
                printf("Invalid symbol");
                exit(0);
            }
            break;


            case 2: 
            if(curr=='a')
                st=3;
            else if(curr=='b')
                st=0;
            else
            {
                printf("Invalid symbol");
                exit(0);
            }
            break;


            case 3: 
            if(curr=='a')
                st=2;
            else if(curr=='b')
                st=1;
            else
            {
                printf("Invalid symbol");
                exit(0);
            }
            break;
        }
    }
    if(st==0)
        printf("String accepted");
    else
        printf("String not accepted");
    return 0;
}
