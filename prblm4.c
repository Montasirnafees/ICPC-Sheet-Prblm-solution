#include <stdio.h>

int main()
{
    char ch;

    printf("Enter a lowercase letter: ");
    scanf(" %c", &ch);

    if(ch>='a' && ch<='z')
    {
        printf("The upper-case equivalent is: %c\n", ch-32);
    }
    else
    {
        printf("Invalid Input\n");
    }

    return 0;
}
