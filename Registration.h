
struct data
{
   char Fname[20];
   char Lname[20];
   char Email[30];
   char DOB[15];
   char City[15];
   char PassWord[20];
}d;

extern int filewriting(struct data *d,int size, char filename[]);
extern int loginfile(char email[], char pass[], struct data *d,int size, char filename[]);

void registration(int mode) // mode = 1(Admin) mode = 2(User)
{
   int retval; // Return Value
   char pass1[20],pass2[20];
   header();
   SetColor(6);
   printf("Registration is in Progress.....\n\n");
   SetColor(7);
   printf("Enter First Name: ");
   scanf("%s",&d.Fname);
   printf("Enter Last Name: ");
   scanf("%s",&d.Lname);
   printf("Enter Email: ");
   scanf("%s",&d.Email);
   printf("Enter Date of Birth (DD/MM/YYYY): ");
   scanf("%s",&d.DOB);
   printf("Enter City: ");
   scanf("%s",&d.City);
   printf("Enter PassWord: ");
   scanf("%s",&pass1);
   printf("ReEnter PassWord: ");
   scanf("%s",&pass2);

   if(strcmp(pass1,pass2)!=0)
   {
     printf("\nPasswords are Different. Please try again!!\n Press any key to continue...");
     getch();
     registration(mode);
   }
   else
   {
     strcpy(d.PassWord,pass1);
     if(mode == 1)
       retval = filewriting( &d, sizeof(struct data), "DataFiles/AdminRegistrationData.dat");
     else
       retval = filewriting( &d, sizeof(struct data), "DataFiles/UserRegistrationData.dat");
   }

   if(retval == 1)
   {
     SetColor(4);
     printf("\nRegistration Successful !!!\nPress any key to continue.");
     SetColor(7);
   }
   else
   {
     SetColor(4);
     printf("\nSome Error Occured. Try again !!!\nPress any key to continue.");
     SetColor(7);
   }
   getch();
}

int login(int mode)
{
  int state;
  char email[30],pass[20];
  header();
  printf("Email: ");
  scanf("%s",&email);
  printf("Password: ");
  scanf("%s",&pass);

  if(mode == 3) // mode = 3(Admin)   mode =4(User)
    state = loginfile(email, pass, &d, sizeof(struct data), "DataFiles/AdminRegistrationData.dat");
  else
    state = loginfile(email, pass, &d, sizeof(struct data), "DataFiles/UserRegistrationData.dat");

  if(state == 0)
    {
      SetColor(10);
      printf("\nLogin Failed !!!! Please try again.\nPress any key to continue.");
      SetColor(7);
      getch();
      return 0;
    }
  else
    {
      SetColor(10);
      printf("\nLogin Successful!!!\nPress any key to continue.");
      SetColor(7);
      getch();
      return 1;
    }
  return 0;
}
