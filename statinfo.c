#include <stdio.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <time.h>
#include <math.h>
#include <string.h>

int efile(char* path) {
  int fd;
  //open(fd, ,);

  return 0;
}

int ginfo(char* path) {

  //error
  struct stat info;
  if(stat(path,&info) < 0) {
     return 1;
  }

  //decl & init
  char *abbr[] = { "B", "kB", "MB", "GB", "TB" }; //static const
  char *mode[] = { "r", "w", "x", "-" };
  char *time = ctime(&(info.st_atime));

  size_t unit = 0;          //size unit tracker
  long len = info.st_size;  //raw size data
  int pos = 0;              //mode pos. tracker
  int nmode = info.st_mode; //raw mode data

  char size[8];             //format: ABCD { ,K,M,G}B\0, 8 chars minimum
  char mode[10];            //rwxr--r--, 10 chars minimum

  //size formatting
  while (len >= 1024 && unit < (sizeof abbr / sizeof *abbr)) {
    unit++;
    len /= 1024;
  }
  sprintf(size, "%ld %s",len,abbr[unit]);

  //mode formatting
  nmode &= 0000666;
  

  printf("\n\tpath:\t\t%s",path);
  printf("\n\tfile size:\t%s",size);
  printf("\n\tmode:\t\t%b",mode);
  printf("\n\tlast access:\t%s\n",time);
  return 0;
}

int main() {

  efile("t.txt");
  char path[] = "./t.txt";
  ginfo(path); //? printf("%s",info) : printf("\nERROR file at:\n\t%s\nnot found\n",path);

}
