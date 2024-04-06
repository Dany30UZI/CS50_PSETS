#include <stdio.h>
#include <cs50.h>

void print_row(int length);

int main(void)
{
    int height = get_int("What is the height?");
    for(int i = 0; i < height; i++)
    {
        print_row(i+1);
    }
}

void print_row(int length, int spaces)
{
    for(int i = 0; i < length; i++)
    {
        printf("#");
    }
    printf("\n");
}
