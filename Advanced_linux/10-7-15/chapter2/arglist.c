#include<stdio.h>
/*Program to recieve number of command line arguments and display the recieved contents*/
int main(int argc, char* argv[])
{
        printf ("Program name:%s\n",argv[0]);
        printf ("Program arguments are %d arguments\n", argc-1);
        if (argc > 1){
                int count;
                printf("Arguments are:\n");
                for(count = 1; count < argc ; count++)
                printf (" %s\n", argv[i]);
        }
        return 0;
}