
int filewriting(struct data *d, int size, char filename[])
{
  FILE *fileptr;
  fileptr = fopen(filename,"a");
  if(fileptr != NULL)
  {
     fwrite(d,size,1,fileptr);
     if(fwrite != 0)
       fclose(fileptr);
       return 1;
  }
  fclose(fileptr);
  return 0;
}

int loginfile(char email[], char pass[], struct data *d,int size, char filename[])
{
    FILE *fileptr;
    fileptr = fopen (filename, "r");
    if (fileptr == NULL)
    {
        return 0;
    }
    while(fread(d, size, 1, fileptr))
    {
      if( ( strcmp(d->Email,email) == 0) && strcmp(d->PassWord,pass) == 0 )
      {
        SetColor(12);
        printf("\nWelcome %s %s\n",d->Fname,d->Lname);
        SetColor(7);
        return 1;
      }
    }
    fclose (fileptr);
    return 0;
}
