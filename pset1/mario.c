#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int h;

    do
    {
        h = get_int("enter a height between 1 and 8:");
    }
    while (h<1 || h>8);

    //row
    for (int i = 0; i < h; i++)
    {
         // inserting spaces on left
        for (int k = h-1; k > i; k--)
        {

          //print spaces before
            printf(" ");
        }

    //column left hand side
        for (int j = 0; j <= i; j++)
        {
            printf("#");
        }
      //middle gap
        printf("  ");

      //printing right hand side columns
        for (int x = 0; x <=i; x++)
        {
            printf("#");
        }

        //new row
        printf("\n");
    }
}




