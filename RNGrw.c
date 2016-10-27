#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>

unsigned int genRandInt(){
  unsigned int ret;
  int fd = open("/dev/random", O_RDONLY, 0666);
  read(fd, &ret, 4);
  close(fd);
  return ret;
}


int main(){
  umask(000);

  printf("Generating random numbers: \n");
  int numsToWrite[10];
  int i;
  for (i = 0; i < 10; i++) {
    unsigned int newRandInt = genRandInt();
    printf("random %d: %u\n", i, newRandInt);
    numsToWrite[i] = genRandInt();
  }
  
  
  char fileName[] = "kappa.txt";
  printf("\nWriting to %s...\n", fileName);
  int fd = open(fileName, O_CREAT | O_WRONLY, 0666);
  write( fd, numsToWrite, 10*sizeof(int) );
  close(fd);

  
  printf("\nReading from %s...\n", fileName);
  //stuff here
  int reading = open(fileName, O_RDONLY, 0666);
  int numsToRead[10];
  read( reading, numsToRead, 10*sizeof(int));

  printf("\nPrinting out from %s... \n",fileName);
  for( i = 0; i < 10; i++){
    printf( "random %d: %u\n", i, numsToRead[i]);
  }
  close(reading);
  return 0;
}  
