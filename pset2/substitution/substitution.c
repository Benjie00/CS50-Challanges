#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>

//INSTRUCTIONS:

// save file
// Copy "./substition zyxwvutsrqpqnolkjihgfedcba" into terminal
// run
//enter an input


//declaring custom function
int encrypt_input(string input, string alphabet, string key);


//argc is number of CLA, argv[] is array of all the CLA provided


int main(int argc, string argv[1])

{
    string ALPHABET = "abcdefghijklmnopqrstuvwxyz";
    //getting key

    string key = argv[1];

    //reject lack of argument or too many arguments

    if (argc < 2)
    {
        printf("Error - no key\n");
        return 1;
    }
    else if (argc > 2)
    {
        printf("Error - too many arguments\n");
        return 1;
    }






    //validating key (case insensative, only letters to be converted, must contain 26 characters, each letter once)
    int n = strlen(key);


    //if key isnt 26 characters - return 1
    if (n != 26)
    {
        printf("Error - key must be 26 characters\n");
        return 1;
    }
    else
    {

    }

    //detect non-alphabetical key characters
    for (int p = 0; p < n; p++)
    {
        //check to see if string is just letters
        if (isalpha(key[p]))
        {

        }

        else
        {
            printf("Error - key must only contain letters\n");
            return 1;
        }

    }

    //detect duplicate characters in key

    //intital loop to pick a character
    for (int k = 0; k < n; k++)
    {
        //nested loop to cycle through other chracters and see if they are the same --> prints error
        for (int l = n; l > k; l--)
        {
            if (key[k] == key[l] || key[k] == key[l] - 32 || key[k] == key[l] + 32)
            {
                printf("Error - do not use same letter twice in key\n");
                return 1;
            }
            else
            {

            }
        }
    }


    //getting input from user

    string input = get_string("Plaintext: ");


    //printing output
    printf("ciphertext: ");

    //encrypting input loop

    char output = encrypt_input(input, ALPHABET, key);

}

//making custom function here

int encrypt_input(string input, string alphabet, string key)
{

    //LOOP to cycle through characters in input, map against key and print cipher.
    for (int i = 0, input_length = strlen(input); i < input_length; i++)
    {
        //LOWER CASE
       if (input[i] >= 'a' && input[i] <= 'z')
       {
            //loop to cycle through alpabet characters
            for (int j = 0, alpha_length = strlen(alphabet); j < alpha_length; j++)
            {
                //print key at j if input at i is same as alphabet at j
                if (input[i] == alphabet[j])
                {
                    printf("%c", tolower(key[j]));
                }
            }
       }
    //UPPER CASE
        else if (input[i] >= 'A' && input[i] <= 'Z')
        {
        //loop to cycle through alpabet characters
            for (int j2 = 0, alpha_length2 = strlen(alphabet); j2 < alpha_length2; j2++)
            {
        //print key at j if input at i is same as alphabet at j
                if (input[i] == alphabet[j2] - 32)
                {
                    printf("%c", toupper(key[j2]));
                }
            }
        }
        //special characters
        else
        {
            printf("%c", input[i]);
        }


    }
    printf("\n");
    return 0;
}
