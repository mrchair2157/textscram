//GPL 3.0
#include "main.h"

//this function takes equ and uses it as a lut to convert the text of the input file with it's contents in an alphabetic order.
void lookup(char *equ ,FILE *in, FILE *out,int *fd)
{
size_t x = 0;
char ch;
//main loop
    while(EOF != ( ch = fgetc(in))) 
    {
        //gets the block of data to be converted

            /* does the conversion, ie s and a are the zeroth element of there arry.
             * and if there is an A in some text it replaces it with a s.
             * there are check to only do this if it is a letter in the english alphabet.
             * the last one is a resort case to bring over what is there.
             */

            if(ch >= 'a' && ch <= 'z')
            {
                fputc(equ[ch - 'a'],out);
            }
            else if(ch >= 'A' && ch <= 'Z')
            {
                fputc(equ[ch - 'A'] - 32,out);
            }
            else
            {
                fputc(ch,out);
            }
        
       x++;
       write(fd[1],&x,sizeof(size_t)); 
    }

       close(fd[1]);

}


void decode(FILE *in,FILE *out,const char *equ,char *abc,int *fd)
{ 
    char ch;
    size_t x = 0;
    while((ch = fgetc(in)) != EOF)
    {
        //gets the block of data to be converted
            /* does the conversion, ie s and a are the zeroth element of there arry.
             * and if there is an A in some text it replaces it with a S.
             * there are check to only do this if it is a letter in the english alphabet.
             * the last one is a resort case to bring over what is there.
             */
            if(ch >= 'a' && ch <= 'z')
            {
                int i;
                for(i = 0; equ[i] != ch;i++)
               ; 
                 fputc(abc[i],out);
            }
            else if(ch >= 'A' && ch <= 'Z')
            {
                int i;
                for(i = 0;(equ[i] - 32) != ch;i++)
                ;
                fputc(abc[i] - 32,out);
            }
            else
            {
                fputc(ch,out);
            }
       x++;
       write(fd[1],&x,sizeof(size_t)); 
    }

       close(fd[1]);

}
//functions in this file are to get data about the file we will be working with and allocate memory for this program.


struct info getinfo(char *filename,bool *tf)
{
    //runs stat and puts the data into a struct called fi with two members called Filesz for filesz and block for the chunks I will be working with.
    struct info fi;
    struct stat sb;
    if(stat(filename,&sb) < 0)
    {
        printf("stat failed,did you include a input file?\n");
        *tf = true;
    }
    fi.FileSz = sb.st_size;
    fi.block = 200;
    if(sb.st_size >= fi.block)
    {
    for(;sb.st_size % fi.block != 0 ;fi.block++);
    }

    return fi;

}

int progress(struct info fi, int *fd)
{
    size_t data;
    bool notfinished = true;
    while(notfinished == true)
            {
                read(fd[0], &data, sizeof(size_t));
                printf("%zu bytes of %zu bytes is done.\r",data,fi.FileSz);
                if(fi.FileSz <= data)
                {
                    notfinished = false;
                }
            }
    
            close(fd[0]);
            return 0;
}
