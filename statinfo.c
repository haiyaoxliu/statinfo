#include <stdio.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <time.h>
#include <math.h>
#include <string.h>

int ginfo(char* path) {

  //init
  struct stat info;
  char size[256];
  int mode;

  //error
  if(stat(path,&info) < 0) {
     return 1;
  }
  //formatting
  //size
  static const char *abbr[] = { "B", "KB", "MB", "GB" };
  size_t d = 0;
  long s = info.st_size;

  while (s >= 1024 && d < (sizeof abbr / sizeof *abbr)) {
    d++;   
    s /= 1024;
  }
  sprintf(size, "%ld %s",s,abbr[d]);

  //mode
  mode = 0000666 & info.st_mode;

  printf("\n\tpath:\t\t%s\n\tfile size:\t%s\n\tmode:\t\t%o\n\tlast access:\t%s\n",path,size,mode,ctime(&(info.st_atime)));
  return 0;
}

int main() {

  char path[] = "./t.txt";
  ginfo(path); //? printf("%s",info) : printf("\nERROR file at:\n\t%s\nnot found\n",path);

}
