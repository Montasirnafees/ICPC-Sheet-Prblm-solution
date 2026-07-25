#include <stdio.h>

int main()
{
    int guess=37;

    while (1)
    {
        scanf("%d", &guess);

        if (guess > 37)
        {
            printf("Too High\n");
        }
        else if (guess < 37)
        {
            printf("Too Low\n");
        }
        else
        {
            printf("Correct\n");
            break;
        }
    }

    return 0;
}
