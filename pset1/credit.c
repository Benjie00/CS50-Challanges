#include <cs50.h>
#include <stdio.h>
#include <math.h>
//asks for user credit card, then reports (via printf) whether it is a valid American Express, MasterCard, or Visa card number, per the definitions of each’s format herein.

int main(void)
{
    // user enter card number (all card should be 13-16 digits)

    long card;
    int r, r2, count = 0, sum = 0, r3, r5, sum2 = 0, sum3 = 0;
    long n2, n3, n4, x;

    const long n = get_long("Enter your credit-card number:");

    // new varible to count digits (keep n const)
    n2 = n;

 // count length of n
        while (n2 != 0)
        {
            //removing last digit loop
            n2 = n2 / 10;
            count++;
        }

    if (count != 13 && count != 15 && count != 16)
    {
        printf("INVALID\n");
        return 0;
    }
    else
    {

    }

   // printf("%i digits\n", count);

    // new varible to complete algorithm
    n3 = n;


    //check sum of every other digit (starting with second last)


    //loop: count is the number of digits in the input, the loop will run until i=0, after every loop i -1
    for (int i = count; i != 1; i--)
    {

        //removing last digit 12345678
        n3 = n3 / 10;
        //isolating new last digit 8
        r = n3 % 10;
        //removing last digit 1234567
        n3 = n3/10;
        // mutipling r digit by 2 = 16
        r2 = r * 2;
        //breaking r2 into digits and adding them
        r3 = (r2)/10 + (r2 %10);
        //sum of r3
        sum = sum + r3;
    }





    //print sum
    // printf("the sum of digits that were mutiplied by 2 is: %i\n", sum);

  //check sum of every other digit (starting with last)
    n4 = n;

    for (int j = 0; j < count; j++)
    {
        r5 = n4 % 10;
        n4 = n4/100;
        sum2 = sum2 + r5;

    }
    // print sum2
    //printf("%i\n", sum2);

    //printing total of sum1 and sum2
    sum3 = sum + sum2;
   // printf("Final number is: %i\n", sum3);

    //printing if the card is valid or not
    if (sum3 % 10 == 0)
    {
        printf("VALID\n");
    }
    else
    {
        printf("INVALID\n");
        return 0;
    }




    // is the card visa, mc, or ae?

    //visa 13 or 16 digit
    //ae 15
    //mc 16
    //x is varible to determine first two digits of n
    x = n;

    if (count == 15)
    {
        x = x / pow(10,13);
        if (x == 35 || x == 37)
        {
             printf("AMEX\n");
        }
        else
        {
            printf("INVALID\n");
            return 0;
        }

    }
    else if (count == 13)
    {
        printf("VISA\n");
    }
    else if (count == 16)
    {
        //getting first 2 digits
        x = x / pow(10,14);

        if (x == 51 || x == 52 || x == 53 || x == 54 || x == 55)
        {
            printf("MASTERCARD\n");
        }
        else if (count == 16)
        {
            x = x /10;
            if (x == 4)
            {
                printf("VISA\n");
            }
        else
        {
            printf("INVALID\n");
            return 0;
        }
        }
    }

}