#include <stdio.h>
#include <cs50.h>

bool valid_triangle(int a, int b, int c);

int main(void)
{
    valid_triangle(1,2,3);


}

bool valid_triangle(int a, int b, int c)
{
    if(a <= 0 || b <= 0 || c <= 0)
    {
        return false;
    }
    if(a + b < c || a + c < b || b + c < a)
    {
        return false;
    }
    return true;
}
