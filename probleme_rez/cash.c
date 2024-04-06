#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int count = 0;
    int money = get_int("Input money");

    while(money < 0)
    {
        money = get_int("Input money");
    }

    while(money > 0)
    {
        if(money - 25 >= 0)
        {
            money = money - 25;
            count ++;
        }else if(money - 10 >= 0)
        {
            money = money - 10;
            count ++;
        }else if(money - 5 >= 0)
        {
            money = money - 5;
            count ++;
        }else if(money - 1 >= 0)
        {
            money = money - 1;
            count ++;
        }
    }
    printf("%i\n", count);
}
