#include <stdio.h>

int main()
{
    char ch;

    printf("Enter a character (case insensitive): ");
    scanf(" %c", &ch);

    if (ch=='a'||ch=='e'||ch=='i'||ch=='o'||ch=='u'||
        ch=='A'||ch=='E'||ch=='I'||ch=='O'||ch=='U')
    {
        printf("You have pressed a Vowel\n");
    }
    else if((ch>='A'&&ch<='Z')||(ch>='a'&&ch<='z'))
    {
        printf("You have pressed a Consonant\n");
    }
    else
    {
        printf("You have pressed an Unidentified Alphabet.\n");
    }

    return 0;
}
