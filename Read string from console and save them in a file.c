/*// read strings from the console and save them in a file*/

#include <stdio.h>

int main(void)
{
    FILE *fp;
    char s[100];

    fp = fopen("datafile.txt", "w"); /*/ error check this!*/

    while(fgets(s, sizeof(s), stdin) != NULL) { /*/ read a string*/
        fputs(s, fp);  /*/ write it to the file we opened*/
    }

    fclose(fp);

    return 0;
}

