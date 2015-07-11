#include<stdio.h>
/*Program to display the environment variables*/
extern char** environ;
int main ()
{
        char** var;
        for (var = environ; *var != NULL; ++var)
                printf("%s\n", *var);
                return 0;
}