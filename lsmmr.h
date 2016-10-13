//lsmmr.h
// header for last memory
#include <sys/types.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stddef.h>
#include <string.h>
#include <time.h>
#include <dirent.h>

int initgraph();

int ovwrt_buf(string pathsrc,int verb);
FILE *fsrc;
int sizebuff;
string a;
int i;
int namo;

int scr_mv(string psr, string pds);
FILE *src , *dst;

int clone_f(char path1,char argv[2]);
FILE *src , *dst;

void unlock(char path,char r);
FILE *file;
DIR *dfile;
struct dirent *enmfile;

int essential_f(char w);

void helpme();

int main(char argc, char argv[]);