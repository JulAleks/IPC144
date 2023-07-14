/*/////////////////////////////////////////////////////////////////////////
                          Workshop - #7 (P1)
Full Name : Julia Alekseev
Student ID#: 051292134
Email: jalekseev@myseneca.ca
Section : G

Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
/////////////////////////////////////////////////////////////////////////*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define MAXPATH 70
#define MINPATH 10
#define PATHMULT 5
#define MAXLIVES 10
#define MINLIVES 1
#define MAXMOVE 26
#define MINMOVES 3


struct PlayerInfo {
    char character[2];
    int numLives;
};

struct GameConfig {
    int treasure[MAXPATH];
    int path;
    int moves;
    int history;
    int bombs[MAXPATH];
};

int main(void)
{
    struct PlayerInfo gamer;
    struct GameConfig game;

    printf("================================\n");
    printf("         Treasure Hunt!\n");
    printf("================================\n\n");


    printf("PLAYER Configuration\n");
    printf("--------------------\n");

    printf("Enter a single character to represent the player: ");
    scanf("%[^\n]%*c", gamer.character);

    int playFlag = 0;

    do {
        printf("Set the number of lives: ");
        scanf("%d", &gamer.numLives);

        int maxLives = MAXPATH * 0.75;
        if (gamer.numLives < MINLIVES || gamer.numLives > MAXLIVES || gamer.numLives > maxLives) {
            printf("     Must be between %d and %d!\n", MINLIVES, MAXLIVES);
        }
        else {
            playFlag = 1;
        }
    } while (playFlag == 0);
    printf("Player configuration set-up is complete\n\n");

    printf("GAME Configuration\n");
    printf("------------------\n");
    game.history = 0;
  
    int gameFlag = 0;
    do {
    printf("Set the path length (a multiple of %d between %d-%d): ", PATHMULT, MINPATH, MAXPATH);
    scanf("%d%*c", &game.path);

    if (game.path < MINPATH || game.path > MAXPATH || game.path % PATHMULT != 0) {
        printf("     Must be a multiple of %d and between %d-%d!!!\n", PATHMULT, MINPATH, MAXPATH);
    }
    else {
        gameFlag = 1;
    }
    } while (gameFlag == 0);

    int limitFlag = 0;

    do {
        printf("Set the limit for number of moves allowed: ");
        scanf("%d", &game.moves);

        if (game.moves < MINMOVES || game.moves > MAXMOVE) {
            printf("    Value must be between %d and %d\n", MINMOVES, MAXMOVE);
        }
        else {
            limitFlag = 1;
        }

    } while (limitFlag == 0);

    printf("\nBOMB Placement\n");
    printf("--------------\n");
    printf("Enter the bomb positions in sets of 5 where a value\n");
    printf("of 1=BOMB, and 0=NO BOMB. Space-delimit your input.\n");
    printf("(Example: 1 0 0 1 1) NOTE: there are 35 to set!\n");

    int i;
  
    for (i = 0; i < game.path; i += 5) {
        printf("   Positions [%2d-%2d]: ", i + 1, i + 5);
        scanf("%d %d %d %d %d", &game.bombs[i], &game.bombs[i+1], &game.bombs[i + 2], &game.bombs[i+3], &game.bombs[i+4]);
        
    }
    printf("BOMB placement set\n");

    printf("\nTREASURE Placement\n");
    printf("------------------\n");
    printf("Enter the treasure placements in sets of 5 where a value\n");
    printf("of 1=TREASURE, and 0=NO TREASURE. Space-delimit your input.\n");
    printf("(Example: 1 0 0 1 1) NOTE: there are 35 to set!\n");
    
    for (i = 0; i < game.path; i += 5) {
        printf("   Positions [%2d-%2d]: ", i + 1, i + 5);
        scanf("%d %d %d %d %d", &game.treasure[i], &game.treasure[i + 1], &game.treasure[i + 2], &game.treasure[i + 3], &game.treasure[i + 4]);

    }
    printf("TREASURE placement set\n");

    printf("\nGAME configuration set-up is complete...\n\n");
    printf("------------------------------------\n");
    printf("TREASURE HUNT Configuration Settings\n");
    printf("------------------------------------\n");
    printf("Player:\n");
    printf("   Symbol     : %c\n", gamer.character[0]);
    printf("   Lives      : %d\n", gamer.numLives);
    printf("   Treasure   : [ready for gameplay]\n");
    printf("   History    : [ready for gameplay]\n\n");
    printf("Game:\n");
    printf("   Path Length: %d",  game.path);
    printf("\n   Bombs      : ");
    for (i = 0; i < game.path; i++) {
        printf("%d", game.bombs[i]);
    }
    printf("\n   Treasure   : ");
    for (i = 0; i < game.path; i++) {
        printf("%d", game.treasure[i]);
    }

    printf("\n\n====================================");
    printf("\n~ Get ready to play TREASURE HUNT! ~");
    printf("\n====================================\n");
    return 0;
}