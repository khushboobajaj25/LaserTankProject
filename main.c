#include <stdio.h>
#include "map.c"
#include "performAction.c"
#include <stdio.h>
int player_row;
int player_col;
char playerpos;
int main()
{

    sleep(1);
    system("cls");
    int row, col, enemy_row, enemy_col,plyr_row,plyr_col;
    char enemy_pos,plyr_pos;
    printf("Enter mapRow: ");
    scanf("%d", &row);
    printf("Enter mapColounm: ");
    scanf("%d", &col);
    printf("Enter playerRow: ");
    scanf("%d", &plyr_row);
    printf("Enter playerColounm: ");
    scanf("%d", &plyr_col);
    scanf("%c");
    printf("Enter playerPosition: ");
    scanf("%c", &plyr_pos);
    
    printf("Enter enemyRow: ");
    scanf("%d", &enemy_row);
    printf("Enter enemyColounm: ");
    scanf("%d", &enemy_col);
    scanf("%c");
    printf("Enter enemyPosition: ");
    scanf("%c", &enemy_pos);
    scanf("%c");
    player_row = plyr_row;
    player_col = plyr_col;
    playerpos = plyr_pos;

    while (1)
    {
        char action;
        make_map(row, col, player_row, player_col, playerpos, enemy_row, enemy_col, enemy_pos, -1, -1);
        printf("w to go/face up\n");
        printf("s to go/face down\n");
        printf("a to go/face left\n");
        printf("d to go/face right\n");
        printf("f to shoot laser\n");
        printf("action:");
        scanf("%c", &action);
        scanf("%c");
        //system("cls");

        int isGameOver = perform_action(row, col, enemy_row, enemy_col, enemy_pos, action);
        if (isGameOver)
        {
            break;
        }
    }
    return 0;
}