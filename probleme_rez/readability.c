#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

int main(void)
{
    int countl = 0;
    int countb = 0;
    int count_sem = 0;
    int cuvinte = 0;
    float index;

    string text = get_string("Text: ");
    int length = strlen(text);

    for (int i = 0; i < length; i++)
    {
        if (isalpha(text[i]))
        {
            countl++;
        }
        else if (isblank(text[i]))
        {
            countb++;
        }
        else if (text[i] == '!' || text[i] == '?' || text[i] == '.')
        {
            count_sem++;
        }
    }

    cuvinte = countb + 1;

    index = 0.0588 * (100.0 * countl / cuvinte) - 0.296 * (100.0 * count_sem / cuvinte) - 15.8;

    int x = (int) round(index);

    if (x < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (x >= 16)
    {
        printf("Grade 16+\n");
    }
    else
        printf("Grade %i\n", x);
}
