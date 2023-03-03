#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int generatenumber(int num)
{
    srand(time(NULL));
    return rand() % num;
}
int greater(char c1, char c2)
{
    if (c1 == c2)
    {
        return -1;
    }

    else if ((c1 == 'r') && (c2 == 's'))
    {
        return 1;
    }
    else if ((c1 == 'p') && (c2 == 's'))
    {
        return 0;
    }
    else if ((c1 == 's') && (c2 == 'p'))
    {
        return 1;
    }
    else if ((c1 == 'r') && (c2 == 'p'))
    {
        return 1;
    }
    else if ((c1 == 'p') && (c2 == 'r'))
    {
        return 0;
    }

    else
    {
        return 0;
    }
}
int main()
{
    int num;
    int playerscore = 0, compscore = 0;
    char playerchar, compchar;
    char dict[] = {'r', 's', 'p'};
    printf("Let's play the game\n");
    printf("There are three lavels and the winner at each lavel will be awarded 1 point\n");
    for (int i = 1; i < 4; i++)
    {
        printf("Player 1's turn\n");
        printf("Press 1 for Rock, 2 for Scissors and 3 for Paper\n");
        scanf("%d", &num);
        playerchar = dict[num - 1];
        printf("you choose %c\n", playerchar);
        printf("computer's turn\n");
        printf("Press 1 for Rock, 2 for Scissors and 3 for Paper\n");
        num = generatenumber(3) + 1;
        compchar = dict[num - 1];
        printf("CPU choose %c\n", compchar);
        if (greater(playerchar, compchar) == 1)
        {
            playerscore += 1;
            printf("player got it\n\n");
        }
        else if (greater(playerchar, compchar) == -1)
        {
            compscore += 1;
            playerscore += 1;
            printf("it's draw\n\n");
        }
        else
        {
            compscore += 1;
            printf("computer got it\n\n");
        }
    }
    if (playerscore > compscore)
    {
        printf("player is the winner");
    }
    else if (playerscore == compscore)
    {
        printf("draw");
    }

    else
    {
        printf("compueter is the winner");
    }

    return 0;
}
