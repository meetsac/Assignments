#include<stdio.h>
int main(int argc, char* argv[])
{
        printf ("Program name:%s\n",argv[0]);
        printf ("Program arguments are %d arguments\n", argc-1);
        if (argc > 1){
                int i;
                printf("Arguments are:\n");
                for(i = 1; i < argc ; i++)
                printf (" %s\n", argv[i]);
        }
        return 0;
}