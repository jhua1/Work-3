#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>

unsigned int RNG(){
  unsigned int ret;
  read( open("/dev/random", O_RDONLY, 0666), &ret, 4);
  return ret;
}

void main(){
  umask(000);
  //int ind = open("numbers.txt", O_CREAT, 0666);
  printf("Here is spaghetti: %d\n", RNG());
}  