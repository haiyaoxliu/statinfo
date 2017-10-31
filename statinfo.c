#include <stdio.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <time.h>

int pinfo(char* path) {
  //int s, m;
  //long t;
  struct stat info;
  if(stat(path,&info) < 0) {
    return 1;
  }
  char size[256];
  
  sprintf(size,"%lld",info.st_size);
  printf("Information:\n\tpath:\t%s\n\tfile size:\t%s\n\tmode:\t%d\n\tlast access:\t%s\n",path,size,info.st_mode,ctime(&(info.st_atime)));
  return 0;
}

int main() {
  pinfo("./t.txt");
}
