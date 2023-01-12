#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

int count_letters(string text);
int count_words(string text);
int count_sentences(string text);

int main(void)
{
    //getting input
    string text = get_string("Text: ");

    //avg letters/100w --> because both varibables are ints, at least one needs to be casted as a float.
    float L = count_letters(text) / (float) count_words(text) * 100;
    //avg sentences/100w
    float S = count_sentences(text) / (float) count_words(text) * 100;
  //equation for index
    int index = round(0.0588 * L - 0.296 * S - 15.8);

    //printing output

    //if > grade 16
    if (index > 16)
    {
        printf("Grade 16+\n");
    }
    //before grade 1
    else if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else
    {
    printf("Grade %i\n", index);
    }
    return 0;
}

//function to count letters
int count_letters(string text)
{

    int letters = 0;

    for (int i = 0, n = strlen(text); i <= n; i++)
    {
        if (isalpha(text[i]))
        {
            letters ++;
        }
    }
   // printf("letters = %i\n", sum);
    return letters;
}
//funnction to count words
int count_words(string text)

{
    //sum = 1 to account for the last word not having a space after.
    int words = 1;
    for (int i = 0, n = strlen(text); i <= n; i++)
    {
        if(isspace(text[i]))
        {
            words ++;
        }
    }
  // printf("Words = %i\n", sum + 1);

    return words;
}

//function to count sententences
int count_sentences(string text)
{
    int sentences = 0;
    for (int i = 0, n = strlen(text); i <= n; i++)
    {
        if (text[i] == '.' || text[i] == '?' || text[i] == '!')
        {
            sentences ++;
        }
    }
  //   printf("Sentences = %i\n", sum);
    return sentences;
}
