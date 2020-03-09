# include<conio.h>
# include<string.h>
# include<stdlib.h>
# include<dir.h>
# include<windows.h>
# include<stdio.h>
# include "Design.h"
# include "Registration.h"
# include "FileOperation.h"

void AdminMenu();
void UserMenu();

void home()
{
  int choice;
  //printf("Welcome To Railway Reservation System !!!\n");
  header();
  printf("1.Admin Registration\n2.User Registration\n3.Admin Login\n4.User Login\n5.Exit\nEnter Choice: ");
  scanf("%d",&choice);
  switch (choice) {
    case 1:
       registration(choice);
       break;
    case 2:
       registration(choice);
       break;
    case 3:
       if(login(choice)==1)
          AdminMenu();
       break;
    case 4:
       if(login(choice)==1)
          UserMenu();
       break;
    case 5:
       footer();
       exit(0);
  }
  home();
}

void AdminMenu()
{
  return;
}

void UserMenu()
{
  return;
}

void main()
{
  home();
}
