#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int n;
    do
    {
         n = get_int("Height:");
    }
    while(n>1 && n>8);
        //row
    for(int i=0; i<n; i++)
    {
        //column
        for (int j=0;j<n-i; j++)
        {
            printf(" ");
        }
        for (int k=0; k<=(2*i-1);k++)
        {
                if(k==i+1){
                printf(" ");
                            printf("#");
            }
        }


        //next row
        printf("\n");
    }
}