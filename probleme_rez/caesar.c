#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
    else
    {

        int INDICE[] = {0,  1,  2,  3,  4,  5,  6,  7,  8,  9,  10, 11, 12,
                        13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25};
        char c = ' ';
        int count = 0;
        string text = argv[1];
        int length = strlen(argv[1]);
        int number = atoi(argv[1]);
        int co = 0;

        for (int i = 0; i < length; i++)
        {
            if (isalpha(text[i]))
            {
                count++;
            }
        }
        if (count == 0)
        {
            string show = get_string("plain text: ");

            int length_show = strlen(show);

            for (int i = 0; i < length_show; i++)
            {
                if (isalpha(show[i]) && isupper(show[i]))
                {
                    co = INDICE[show[i] - 'A'];
                    c = 65 + ((co + number) % 26);
                    printf("%c", c);
                }
                else if (isalpha(show[i]) && islower(show[i]))
                {
                    co = INDICE[show[i] - 'a'];
                    c = 97 + ((co + number) % 26);
                    printf("%c", c);
                }
                else
                {
                    c = show[i];
                    printf("%c", c);
                }
            }
            printf("\n");
        }
        else
        {
            printf("Usage: ./caesar key\n");
            return 1;
        }
    }
}
