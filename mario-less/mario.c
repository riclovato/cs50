#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int n;
    do
    {

        n = get_int("height:");

    }
    while (n < 1 || n > 8);
//row
    for (int i = 1; i <= n; i++)
    {

//spaces
        for (int k = 0; k < n - i; k++)
        {

            printf(" ");
        }
        for (int j = 0; j < i; j++)
        {
            printf("#");
        }

        printf("\n");
    }
}