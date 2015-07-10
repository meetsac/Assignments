# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/types.h>
# include <errno.h>
# include <attr/xattr.h>

/* Program to check the proper working of setxattr and getxattr */
int
main(int argc,char *argv[])
{
        char *attr_name;
        size_t size = 0;
        int val,i,ret = -1;
        FILE *fp;
        if(argc==4){
                fp=fopen(argv[1],"r");
                 
                if(fp==NULL){
                        printf("%s",strerror(errno));
                        goto out;
                }
                
                for(i=0;i<strlen(argv[3]);i++) {
                        if(argv[3][i]<'0' || argv[3][i]>'9') {
                                printf("pass the proper arguments\n\n");
                                goto out;
                        }
                }
                
                val = atoi(argv[3]);
                attr_name = (char *) calloc ((strlen(argv[3]) + 9),(sizeof (char)));
                if (!attr_name) {
                        printf("NOt enough memory \n");
                        goto out;
                }
                strcpy(attr_name,"trusted.");
                strcat(attr_name,argv[2]);
                /*new attribute is added
                * INPUT :
                *      char *argv[1]       :       filename
                *      char *attr_name     :       attribute name
                *      void *val           :       pointer to attribute value
                *      size_t sizeof(val)  :       size of value
                *      int flag            :       flag value
                * OUTPUT :
                *      size_t              :       success/failure indicator
                */
                size = setxattr(argv[1],attr_name,&val,sizeof(val),0);
                if(size == 0) {
                        printf ("\nAttribute is added here\n");
                        val =0;
                        /*existing attribute value
                        *INPUT :
                        *      char *argv[1]      :       filename
                        *      char *attr_name    :       attribute name
                        *      void *val          :       pointer to 
                        *                                 attribute value
                        *      size_t sizeof(val) :       size of value
                        * OUTPUT :
                        *      size_t             :       success/failure
                        *                                 indicator
                        */
                        size = getxattr(argv[1],attr_name,&val,sizeof(val));
                        if(size > 0)
                                printf ("Attribute value retrieved.\n\n%s = %d\n", attr_name , val);
                        else {
                                printf ("Error while accessing the existing attribute value\n");
                                goto out;
                        }
                } else {
                        printf ("Error While Setting the new Attribute\n\n");
                        goto out;
                }
                ret = 0;
        }
        else
                printf("Please give the proper number of arguments");
        
out:
        if (!attr_name)
                free(attr_name);
        if (ret != -1)
                return 0;
        else
                return -1;
}
