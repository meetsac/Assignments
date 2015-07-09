# include <stdio.h>
# include <string.h>
# include <sys/types.h>
# include <attr/xattr.h>

int
main(int argc,char *argv[])
{
	char var1[100];
        size_t size=0;
        int val=atoi(argv[3]);
        if(argc==4){
		strcpy(var1,"trusted.");
		strcat(var1,argv[2]);
		size = setxattr(argv[1],var1,&val,sizeof(val),0);
		if(size == 0) {
			printf ("\nAttribute is Set\n");
			val =0;      
			size = getxattr(argv[1],var1,&val,sizeof(val));
			if(size > 0)
				printf ("Attribute value retrieved.\n\n%s = %d\n", var1 , val);
			else
				printf ("Error in Retrieval\n");
		} else
			printf ("Error in Setting Attribute\n\n");
        }
        else
                printf("pleas give the proper number of arguments");
}
