#include <stdio.h>
#include <stdlib.h>
void main()
{
    char buffer[20];
    int num;
    printf("Please enter a number\n");
    scanf("%s",buffer);
    num = atoi(buffer);
    if(num == '\0')
    {
        printf("Error Message!");
    }
    else
    {
        printf("\n\nThe number entered is %d", num);
    }

}