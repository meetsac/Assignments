#include <getopt.h>
#include <stdio.h>
#include <stdlib.h>
/*Program to show the working of getopt_long function*/
const char* program_name;
void print_usage (FILE* stream, int exit_code)
{
        fprintf(stream,"Usage: %s options [ inputfile...]\n", program_name);
        fprintf(stream," -h --help    Display this usage info.\n"
        "-o --output  filename Write output to file\n"
        "-v --verbose Print verbose messages.");
        exit (exit_code);
}

int main (int argc, char* argv[])
{
        int next_option;
        const char* const short_options="ho:v";
        const struct option long_options[]={
                { "help", 0, NULL, 'h'},
                { "output", 1, NULL, 'o'},
                { "verbose", 0, NULL, 'v'},
                { NULL, 0, NULL, 0 }
        };
        const char* output_filename = NULL;
        int verbose = 0;
        program_name =argv[0];
        do {
                next_option = getopt_long (argc, argv, short_options,
                                           long_options, NULL);
                switch (next_option)
                {
                        case 'h':/*help*/
                                 print_usage (stdout, 0);
                        case 'o':/*output*/
                                 output_filename = optarg;
                                 printf("output is choosen\n");
                                 break;
                        case 'v':/*verbose*/
                                 verbose = 1;
                                 printf("verbose is choosen\n");
                                 break;
                        case '?':/*user specified invalid option.*/
                                 print_usage (stderr, 1);
                                 printf("Invalid option\n");
                        case -1:break;
                        default:abort ();
                }
        }
        while (next_option != -1);
        if(verbose) {
                int i;
                for(i = optind; i <argc; ++i)
                        printf( "arguments are :%s\n", argv[i]);
        }
        return 0;
}