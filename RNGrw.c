#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

int genRandInt(){
  int ret;
  int fd = open("/dev/random", O_RDONLY);
  int x = read(fd, &ret, 4);
  close(fd);
  return ret;
}


int main(){

  printf("Generating random numbers: \n");
  int numsToWrite[10];
  int i;
  for (i = 0; i < 10; i++) {
    int newRandInt = genRandInt();
    printf("random %d: %u\n", i, newRandInt);
    numsToWrite[i] = newRandInt;
  }
  
  
  char fileName[] = "kappa";
  printf("\nWriting to %s...\n", "kappa");
  int fd = open(fileName, O_CREAT | O_WRONLY, 0644);
  int no = write( fd, numsToWrite, 10*sizeof(int) );
  printf("\n -1 or 40?!?!?!: %d\n", no);
  close(fd);

  
  printf("\nReading from %s...\n", "kappa");
  //stuff here
  int reading = open(fileName, O_RDONLY);
  int numsToRead[10];
  
  int yes = read( reading, numsToRead, 10*sizeof(int));
  printf("\n -1 or 40?!?!?!: %d\n", yes);
  printf("\nPrinting out from %s... \n","kappa");
  for( i = 0; i < 10; i++){
    printf( "random %d: %u\n", i, numsToRead[i]);
  }
  close(reading);
  return 0;
}  
