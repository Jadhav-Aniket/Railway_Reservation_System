
void SetColor(int ForgC)
{
  WORD wColor;
  HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
  CONSOLE_SCREEN_BUFFER_INFO csbi;
  //We use csbi for the wAttributes word.
  if(GetConsoleScreenBufferInfo(hStdOut, &csbi))
    {
      //Mask out all but the background attribute, and add in the forgournd color
      wColor = (csbi.wAttributes & 0xF0) + (ForgC & 0x0F);
      SetConsoleTextAttribute(hStdOut, wColor);
    }
  return;
}

void header()
{
  system("@cls||clear");
  printf("\n\n\n***************************************************\n\n");
  SetColor(3);
  printf("\tWelcome To Railway Reservation System");
  SetColor(7);
  printf("\n\n***************************************************\n\n");
  return ;
}

void footer()
{
  printf("\n\n***************************************************\n\n");
  SetColor(3);
  printf("\tThank you. Please visit agian.");
  SetColor(7);
  printf("\n\n***************************************************\n");
  return ;
}
