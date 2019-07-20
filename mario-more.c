#include <cs50.h>
#include <stdio.h>

const char POUND = '#';
const char BLANK = ' ';

void build_pyramid(char c, int i);

int main(void)
{
    int n;
    do
    {
        n = get_int("Height: ");
    } while (n < 1 || n > 8);
    
    for (int i = 1; i <= n; i++)
    {
        build_pyramid(BLANK, n - i);
        build_pyramid(POUND, i);
        printf("  ");
        build_pyramid(POUND, i);
        printf("\n");
    }
}

void build_pyramid(char c, int i)
{
    for (int j = 0; j < i; j++)
    {
        printf("%c", c);
    }
}
