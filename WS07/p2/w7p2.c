/*/////////////////////////////////////////////////////////////////////////
                          Workshop - #7 (P2)
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
#define MAXMOVE 15
#define MINMOVES 3


struct PlayerInfo {
    char character[2];
    int numLives;
    int tresureFound;
    int mv;
};

struct GameConfig {
    int treasure[MAXPATH];
    int path;
    int moves;
    char history[MAXPATH];
    int bombs[MAXPATH];
};

int main(void)
{
    struct PlayerInfo gamer;
    gamer.tresureFound = 0;
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
    printf("(Example: 1 0 0 1 1) NOTE: there are %d to set!\n", game.path);

    int i;

    for (i = 0; i < game.path; i += 5) {
        printf("   Positions [%2d-%2d]: ", i + 1, i + 5);
        scanf("%d %d %d %d %d", &game.bombs[i], &game.bombs[i + 1], &game.bombs[i + 2], &game.bombs[i + 3], &game.bombs[i + 4]);

    }
    printf("BOMB placement set\n");

    printf("\nTREASURE Placement\n");
    printf("------------------\n");
    printf("Enter the treasure placements in sets of 5 where a value\n");
    printf("of 1=TREASURE, and 0=NO TREASURE. Space-delimit your input.\n");
    printf("(Example: 1 0 0 1 1) NOTE: there are %d to set!\n", game.path);

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
    printf("   Path Length: %d", game.path);
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


    for (i = 0; i < game.path; i++) {
        game.history[i] = '-';
    }

    while (gamer.numLives >= 0 && game.moves >= 0) {


        for (i = 0; i < game.path; i++) {
            if (i == gamer.mv - 1) {
                printf("%3c", gamer.character[0]);
            }
            else {
                printf("%c", '\0');
            }
        }
       
        for (i = 0; i < game.path; i++) {
            if (i == 0) {
                printf("%3c", game.history[i]);
            }
            else {
                printf("%c", game.history[i]);
            }
        }
        printf("\n");

        for (i = 1; i <= game.path; i++) {
            if (i == 1) {
                printf("  |");
            }
            else if (i % 10 == 0) {
                printf("%d", i / 10);
            }
            else {
                printf("|");
            }
        }
        printf("\n");

        for (i = 1; i <= game.path; i++) {
            if (i == 1) {
                printf("%3d", i);
            }
            else if (i % 10 != 0) {
                printf("%d", i % 10);
            }
            else {
                printf("0");
            }
        }

        printf("\n+---------------------------------------------------+\n");
        printf("  Lives: %2d  | Treasures: %2d  |  Moves Remaining: %2d\n", gamer.numLives, gamer.tresureFound, game.moves);
        printf("+---------------------------------------------------+\n");





        if (gamer.numLives == 0) {

            gamer.numLives--;
        }
        else if (game.moves == 0) {

            game.moves--;
        }
        else {
            int moveFlag = 0;
            do {
                printf("Next Move [1-20]: ");
                scanf("%d", &gamer.mv);

                if (gamer.mv < 1 || gamer.mv >20) {
                    printf("  Out of Range!!!\n");
                }
                else {
                    moveFlag = 1;
                }

            } while (moveFlag == 0);

            if (game.bombs[gamer.mv - 1] == 1 && game.treasure[gamer.mv - 1] != 1) {
                gamer.numLives--;
                game.moves--;
                game.history[gamer.mv - 1] = '!';

                printf("\n===============> [!] !!! BOOOOOM !!! [!]\n\n");
            }
            else if (game.bombs[gamer.mv - 1] != 1 && game.treasure[gamer.mv - 1] == 1) {
                game.moves--;
                gamer.tresureFound++;
                game.history[gamer.mv - 1] = '$';

                printf("\n===============> [$] $$$ Found Treasure! $$$ [$]\n\n");
            }
            else if (game.bombs[gamer.mv - 1] == 1 && game.treasure[gamer.mv - 1] == 1) {
                gamer.numLives--;
                game.moves--;
                gamer.tresureFound++;
                game.history[gamer.mv - 1] = '&';

                printf("\n===============> [&] !!! BOOOOOM !!! [&]\n");
                printf("===============> [&] $$$ Life Insurance Payout!!! [&]\n\n");
            }
            else if (game.history[gamer.mv - 1] == '.') {

                printf("\n===============> Dope! You've been here before!\n\n");

            }
            else {

                game.moves--;
                game.history[gamer.mv - 1] = '.';
                printf("\n===============> [.] ...Nothing found here... [.]\n\n");
            }
            if (gamer.numLives == 0) { printf("No more LIVES remaining!\n\n"); };
            if (game.moves == 0) { printf("No more MOVES remaining!\n\n"); }

        }


    }
    printf("\n##################");
    printf("\n#   Game over!   #\n");
    printf("##################\n\n");

    printf("You should play again and try to beat your score!\n");


    return 0;

}