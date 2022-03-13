//GPL 3.0
#include "main.h"
#define END(VAL) \
        fclose(encoding); \
        fclose(in); \
        fclose(out); \
        return VAL; 

int main(int argc, char **argv)
{
    //if argc is < 5 that means that the program can't get in data or output it due to the fact that it doesn't know where.
    if(argc < 5)
    {
        printf("usage: mode, input file, output file, encoding file.\n");
        return -1;
    }
    //opens the files and gets the text key. (witch is what equ stands for)

    struct stat sb;
    if(0 > stat(argv[4], &sb))
    {
        printf("stat failed, did you include a encoding file?\n %zu",sb.st_size);
        return -1;
    }

    if(0 > stat(argv[2], &sb))
    {
        printf("stat failed,did you include a input file?\n %zu",sb.st_size);
        return -1;
    }
    
    //pipe init
    bool *tf = false;
    struct info fi = getinfo(argv[2],tf); 
    if(tf == (bool*)true)
    {
        return -1;

    }

    //sets up files
    FILE *in = fopen(argv[2],"r");
    FILE *out = fopen(argv[3],"w+");
    FILE *encoding = fopen(argv[4],"r");
    char equ[27];
    //gets the translation key
    fread(equ,1,26,encoding); 
    if(strlen(equ) < 26)
    {
        printf("did not receive a proper length key from %s\n",argv[4]);
        END(-1);
    }
    char abc[27] = "abcdefghijklmnopqrstuvwxyz";
    equ[26] = 0;

    //sees if the user would like to continue with the current options
    char yn;
    do
    {
        printf("you have chosen %s.\n" \
                "key = %s.\n" \
                "abc = %s.\n" \
                "continue? y or n: ",argv[2], equ,abc);
        yn = getchar();
    if(yn == 'n')
    {
        printf("Exiting...\n");
        END(0);
    }
    } 
    while(yn != 'y');
    printf("you have chosen to continue...\n");


    //change the a,b,c,d letters out for the equ values, better explanation in secondary.c. 
    int fd[2],pid;
    pipe(fd);
    if((pid = fork()) > 0)
    {
        progress(fi,fd); 
        printf("\n");
        return 0;
    }
    if(strcmp(argv[1],"encode") == 0)
    {
        printf("encoding\n");
        lookup(equ,in,out,fd);
    }
    if(strcmp(argv[1],"decode") == 0)
    {
        printf("decoding\n");
        decode(in,out,equ,abc,fd);
    }
//frees pointers.
    wait(NULL);
    END(0);
}
