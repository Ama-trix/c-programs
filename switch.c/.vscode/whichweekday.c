#include<stdio.h>
#include<conio.h>
int main()
{
  int day;
  printf("enter the day of the number");
  switch(day){
  case 1 :
  printf("the day is sunday");
  
  case 2 :
  printf("the day is monday");
  break;
  case 3 :
  printf("the day is tuesday");
  break;
  case 4 :
  printf("the day is wednesday");
  break;
  case 5 :
  printf("the day is thursday");
  break;
  case 6 :
  printf("the day is friday");
  break;
  case 7 :
  printf("the day is saturday");
  break;
  default :
  printf("your day number is not valid");
  break; 
  }
}