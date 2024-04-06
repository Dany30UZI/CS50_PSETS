#include <cs50.h>
#include <stdio.h>

void print_row(int dot, int hash);

int main(void)
{
    int height = get_int("What is the height?");

    while(height <= 0)
    {
        height = get_int("What is the height?");
    }

    for(int i = height; i > 0; i--)
        {
             print_row(i-1, height-(i-1));
         }
}

void print_row(int dot, int hash)
{
    for(int i = 0; i < dot; i++)
    {
        printf(" ");
    }
    for(int j = 0; j < hash; j++)
    {
        printf("#");
    }
    printf("\n");
}
