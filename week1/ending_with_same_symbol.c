#include<stdio.h>
#include <stdlib.h>
int main()
{
    char ip[20],curr;
    int i=0,st=0;
    printf("\nEnter input string: ");
    scanf("%s",&ip);
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
                printf("Invalid token");
                exit(0);
            }
            break;


            case 1:
            if(curr=='a')
                st=4;
            else if(curr=='b')
                st=2;
            else
            {
                printf("Invalid token");
                exit(0);
            }
            break;


            case 2:
            if(curr=='a')
                st=1;
            else if(curr=='b')
                st=3;
            else
            {
                printf("Invalid token");
                exit(0);
            }
            break;


            case 3:
            if(curr=='a')
                st=1;
            else if(curr=='b')
                st=3;
            else
            {
                printf("Invalid token");
                exit(0);
            }
            break;

            case 4:
            if(curr=='a')
                st=4;
            else if(curr=='b')
                st=2;
            else
            {
                printf("Invalid token");
                exit(0);
            }
            break;
        }
    }
    if(st==4 || st==3)
        printf("String accepted!");
    else
        printf("String not accepted");
    return 0;
}
