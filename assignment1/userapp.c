#include <stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdint.h>
#include<string.h>
#define adxl_x "/dev/x-axis"
#define adxl_y "/dev/y-axis"
#define adxl_z "/dev/z-axis"

int s;
int main()

{
  int fd,n;
  uint16_t val;
  printf("ENTER    1 for X-axis acceleration \n\t 2 for Y-axis acceleration \n\t 3 for Z-axis acceleration : \n");
  scanf("%d",&n);
 
  if(n==1)
  {
  fd=open(adxl_x, O_RDWR);
 
  if(fd  == -1)
  {
 
    printf("777 permission for file %s \n",adxl_x);
    exit(-1);
  }
 
  read(fd,&val,2);


  printf("X-Axis Acceleration is : %d\n",val);
  }
  if(n==2)
  {
  fd=open(adxl_y , O_RDWR);
 
  if(fd  == -1)
  {
 
    printf("777 permission for file %s \n",adxl_y);
    exit(-1);
  }
 
  read(fd,&val,2);
  printf("Y-Axis Acceleration is : %d\n",val);
  }
  if(n==3)
  {
  fd=open(adxl_z, O_RDWR);
 
  if(fd  == -1)
  {
 
    printf("777 permission for file %s ",adxl_z);
    exit(-1);
  }
 
  read(fd,&val,2);
  printf("Z-Axis Acceleration is : %d\n",val);
  }
  
  if((n!=1) &&(n !=2) &&(n !=3))
  printf("\nENTER VALID COMMAND\n");
 
  close(fd);
 
 
  return 0;
}

