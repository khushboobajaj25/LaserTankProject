#include <stdlib.h>
#include <malloc.h>
#include <stdio.h>
#include <conio.h>
#include <unistd.h>
extern int player_row;
extern int player_col;
extern char playerpos;
void addDir(char **wall, int i, int j, char playerpos)
{
    if (playerpos == 'u')
    {
        wall[i][j] = '^';
    }
    else if (playerpos == 'd')
    {
        wall[i][j] = 'v';
    }
    else if (playerpos == 'r')
    {
        wall[i][j] = '>';
    }
    else if (playerpos == 'l')
    {
        wall[i][j] = '<';
    }
    else
    {
        wall[i][j] = 'X';
    }
}

void make_map(int row, int col, int player_row, int player_col, char playerpos, int enemy_row, int enemy_col, char enemy_pos, int laser_row, int laser_col)
{
    system("cls");

    char **wall = (char **)malloc(row * col * sizeof(char *)); // Allocate row pointers
    for (int i = 0; i < row; i++)
    {
        wall[i] = (char *)malloc(col * sizeof(char));
    }
    for (int i = 0; i < col; i++)
    {
        printf("*");
    }
    printf("\n");
    for (int i = 1; i < row - 1; i++)
    {
        printf("*");
        for (int j = 1; j < col - 1; j++)
        {
            wall[i][j] = ' ';

            if (i == player_row && j == player_col)
            {
                addDir(wall, i, j, playerpos);
                printf("%c", wall[i][j]);
            }
            else if (i == enemy_row && j == enemy_col)
            {
                addDir(wall, i, j, enemy_pos);
                printf("%c", wall[i][j]);
            }
            else if (i == laser_row && j == laser_col)
            {
                if (playerpos == 'r' || playerpos == 'l')
                    wall[i][j] = '-';
                else
                    wall[i][j] = '|';
                printf("\033[0;31m"); /* change font color into red color for the oncoming printf function */
                printf("%c", wall[i][j]);

                printf("\033[0m"); /* change font color back to default color (basically a reset button)*/
            }
            else
            {
                printf("%c", wall[i][j]);
            }
        }
        printf("*\n");
    }
    for (int i = 0; i < col; i++)
    {
        printf("*");
    }
    printf("\n");
}