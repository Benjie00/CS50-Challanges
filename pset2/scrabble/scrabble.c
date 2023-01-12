#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Points assigned to each letter of the alphabet
int POINTS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

//declaring function
int compute_score(string word, int array[]);

int main(void)
{
    // Get input words from both players
    string word1 = get_string("Player 1: ");
    string word2 = get_string("Player 2: ");

    // Score both words
    int score1 = compute_score(word1, POINTS);
    int score2 = compute_score(word2, POINTS);


    // TODO: Print the winner
    //player 1 wins
    if (score1 > score2)
    {
        printf("Player 1 wins!\n");
    }
    //player 2 wins
    else if (score2 > score1)
    {
        printf("Player 2 wins!\n");
    }
    //if tie
    else
    {
        printf("Tie\n");
    }
}

int compute_score(string word, int array[])
{
    // TODO: Compute and return score for string
    int sum = 0;
    int index = 0;

    //counting total number of characters in word
    for (int i = 0, n = strlen(word); i < n; i++)
    {
        //condion for if UPPER case
        if (word[i] >= 'A' && word[i] <= 'Z')
        {
            //obtaining a score for each letter of word (converting aski index position to POINTS index position (for CAPS))
            index = word[i] - 65;
            //sum of score
            sum += array[index];
        }

        //condition to include lowercase letters
        else if (word[i] >= 'a' && word[i] <= 'z')
        {
            //converting aski to position in POINTS array
            index = word[i] - 97;
            sum += array[index];
        }
        //condition for if not a letter - do nothing
        else
        {

        }

    }
    //returning the score (sum)
    return sum;
}

