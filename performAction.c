#include <stdlib.h>
#include <malloc.h>
#include <conio.h>
#include <stdio.h>
#include <unistd.h>
extern int player_row;
extern int player_col;
extern char playerpos;
int laser(int enemy_row, int enemy_col, char enemy_pos, int row, int col, int player_row, int player_col, char playerpos)
{
    if (playerpos == 'r')
    {
        for (int i = player_col + 1; i < col - 2; i++)
        {
            if (enemy_row == player_row && i == enemy_col)
            {
                make_map(row, col, player_row, player_col, playerpos, enemy_row, enemy_col, 'X', -1, -1);

                return 1;
            }
            else
            {
                make_map(row, col, player_row, player_col, playerpos, enemy_row, enemy_col, enemy_pos, player_row, i);
            }
            sleep(1);
        }
    }
    else if (playerpos == 'l')
    {
        for (int i = player_col - 1; i >= 1; i--)
        {
            if (enemy_row == player_row && i == enemy_col)
            {
                make_map(row, col, player_row, player_col, playerpos, enemy_row, enemy_col, 'X', -1, -1);

                return 1;
            }
            else
            {
                make_map(row, col, player_row, player_col, playerpos, enemy_row, enemy_col, enemy_pos, player_row, i);
            }
            sleep(1);
        }
    }
    else if (playerpos == 'u')
    {
        for (int i = player_row - 1; i >= 1; i--)
        {
            if (enemy_col == player_col && i == enemy_row)
            {
                make_map(row, col, player_row, player_col, playerpos, enemy_row, enemy_col, 'X', -1, -1);

                return 1;
            }
            else
            {
                make_map(row, col, player_row, player_col, playerpos, enemy_row, enemy_col, enemy_pos, i, player_col);
            }
            sleep(1);
        }
    }
    else if (playerpos == 'd')
    {
        for (int i = player_row + 1; i < row - 1; i++)
        {
            if (enemy_col == player_col && i == enemy_row)
            {
                make_map(row, col, player_row, player_col, playerpos, enemy_row, enemy_col, 'X', -1, -1);

                return 1;
            }
            else
            {
                make_map(row, col, player_row, player_col, playerpos, enemy_row, enemy_col, enemy_pos, i, player_col);
            }
            sleep(1);
        }
    }
    return 0;
}
int canEnemykill(int row, int col, int enemy_row, int enemy_col, char enemy_pos)
{
    if (player_row == enemy_row)
    {
        if (enemy_pos == 'l')
        {
            if (player_col < enemy_col)
            {

                return laser(player_row, player_col, playerpos, row, col, enemy_row, enemy_col, enemy_pos);
            }
            else
            {
                return 0;
            }
        }
        else if (enemy_pos == 'r')
        {
            if (player_col > enemy_col)
            {
                return laser(player_row, player_col, playerpos, row, col, enemy_row, enemy_col, enemy_pos);
            }
            else
            {
                return 0;
            }
        }
    }
    else if (player_col == enemy_col)
    {
        if (enemy_pos == 'u')
        {
            if (player_row < enemy_row)
            {
                return laser(player_row, player_col, playerpos, row, col, enemy_row, enemy_col, enemy_pos);
            }
            else
            {
                return 0;
            }
        }
        else if (enemy_pos == 'd')
        {
            if (player_row > enemy_row)
            {
                return laser(player_row, player_col, playerpos, row, col, enemy_row, enemy_col, enemy_pos);
            }
            else
            {
                return 0;
            }
        }
    }
    return 0;
}

int perform_action(int row, int col, int enemy_row, int enemy_col, char enemy_pos, char action)
{
    int isGameOver;
    if (action == 'w')
    {
        if (playerpos == 'u')
        {
            if (player_row != 1)
            {
                player_row--;
                make_map(row, col, player_row, player_col, playerpos, enemy_row, enemy_col, enemy_pos, -1, -1);
                isGameOver = canEnemykill(row, col, enemy_row, enemy_col, enemy_pos);
                if (isGameOver)
                {
                    printf("You Lose");
                }
            }
        }
        else
        {
            playerpos = 'u';
            make_map(row, col, player_row, player_col, playerpos, enemy_row, enemy_col, enemy_pos, -1, -1);
        }
    }
    else if (action == 's')
    {
        if (playerpos == 'd')
        {
            if (player_row != row - 2)
            {
                player_row++;
                make_map(row, col, player_row, player_col, playerpos, enemy_row, enemy_col, enemy_pos, -1, -1);
                isGameOver = canEnemykill(row, col, enemy_row, enemy_col, enemy_pos);
                if (isGameOver)
                {
                    printf("You Lose");
                }
            }
        }
        else
        {
            playerpos = 'd';
            make_map(row, col, player_row, player_col, playerpos, enemy_row, enemy_col, enemy_pos, -1, -1);
        }
    }
    else if (action == 'a')
    {
        if (playerpos == 'l')
        {
            if (player_col != 1)
            {
                player_col--;
                make_map(row, col, player_row, player_col, playerpos, enemy_row, enemy_col, enemy_pos, -1, -1);
                isGameOver = canEnemykill(row, col, enemy_row, enemy_col, enemy_pos);
                if (isGameOver)
                {
                    printf("You Lose");
                }
            }
        }
        else
        {
            playerpos = 'l';
            make_map(row, col, player_row, player_col, playerpos, enemy_row, enemy_col, enemy_pos, -1, -1);
        }
    }
    else if (action == 'd')
    {
        if (playerpos == 'r')
        {
            if (player_col != col - 2)
            {
                player_col++;
                make_map(row, col, player_row, player_col, playerpos, enemy_row, enemy_col, enemy_pos, -1, -1);
                isGameOver = canEnemykill(row, col, enemy_row, enemy_col, enemy_pos);
                if (isGameOver)
                {
                    printf("You Lose");
                }
            }
        }
        else
        {
            playerpos = 'r';
            make_map(row, col, player_row, player_col, playerpos, enemy_row, enemy_col, enemy_pos, -1, -1);
        }
    }
    else if (action == 'f')
    {
        isGameOver = laser(enemy_row, enemy_col, enemy_pos, row, col, player_row, player_col, playerpos);
        if (isGameOver)
        {
            printf("You Win");
        }
        return isGameOver;
    }
    return isGameOver;
}
