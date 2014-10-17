
/*
 * This code is written in C, but it could just as easily be done in C++.
 * The rand() and srand() functions are available in both languages.
 */
 
#include <stdio.h>  
#include <stdlib.h>  
#include <time.h>  

int main(void)
{
  int i, r;
  
  for (i = 0; i < 20; i++)
  {
    r = GetRand(10, 12);
    printf ("Your number is %d\n", r);
  }
  
  return(0);
}

int GetRand(int min, int max)
{
  static int Init = 0;
  int rc;
  
  if (Init == 0)
  {
    /*
     *  As Init is static, it will remember it's value between
     *  function calls.  We only want srand() run once, so this
     *  is a simple way to ensure that happens.
     */
    srand(time(NULL));
    Init = 1;
  }

  /*
   * Formula:  
   *    rand() % N   <- To get a number between 0 - N-1
   *    Then add the result to min, giving you 
   *    a random number between min - max.
   */  
  rc = (rand() % (max - min + 1) + min);
 
  return (rc);
}

