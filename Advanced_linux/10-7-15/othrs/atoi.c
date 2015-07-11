#include <stdio.h>
#include <stdlib.h>
/*Program to check working of atoi function*/
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