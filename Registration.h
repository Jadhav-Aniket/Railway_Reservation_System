# include<string.h>
struct data
{
   char Fname[20];
   char Lname[20];
   char Email[30];
   char DOB[15];
   char City[15];
   char PassWord[20];
}d;

void filewritting();

void registration()
{
   char pass1[20],pass2[20];

   printf("*****Registration*****\n");

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
     printf("Passwords are Different. Please try again!!\n");
     registration();
   }
   else
   {
     strcpy(d.PassWord,pass1);
     filewritting();
   }
}

void filewritting()
{
  FILE *fileptr;
  fileptr = fopen("RegistrationData.dat","w");
  if(fileptr != NULL)
  {
     fwrite(&d,sizeof(struct data),1,fileptr);
     if(fwrite != 0)
       printf("Registration Successful !!!\n");
     else
       printf("Some Error Occured. Try again !!\n");
  }
  fclose(fileptr);
}
