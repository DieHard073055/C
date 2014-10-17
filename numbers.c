#include <stdio.h>



int main(void)
{
  int i, r;
  
  for (i = 0; i < 20; i++)
  {
    r = GetRd(10, 56);
    printf ("Your number is %d\n", r);
  }
  
  return(0);
}
int GetRd(int min, int max)
{
  static int Init = 0;
  int rc;
  
  if (Init == 0)
  {
    srand(time(NULL));
    Init = 1;
  }
 rc = (rand() % (max - min + 1) + min);
 
  return (rc);
}

