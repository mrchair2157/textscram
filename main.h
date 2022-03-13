//GPL 3.0
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdbool.h>
#include <time.h>
#include <signal.h>
//struct
struct info
{
    size_t FileSz;
    int block;
};
//secondary
void lookup(char *equ,FILE *in, FILE *out,int *fd);
void decode(FILE *in,FILE *out,const char *equ,char *abc, int *fd);
//files
struct info getinfo(char *filename,bool *tf);
int progress(struct info fi,int *fd);


