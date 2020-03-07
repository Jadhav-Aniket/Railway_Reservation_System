# include<stdio.h>
# include<stdlib.h>
# include "Registration.h"
void main()
{
  int choice;
  printf("Welcome To Railway Reservation System !!!\n");
  printf("1.Registration\n2.Exit\nEnter Choice: ");
  scanf("%d",&choice);
  switch (choice) {
    case 1:
       printf("Registration in Progress....\n");
       registration();
    case 2:
       exit(0);
  }
  return ;
}
