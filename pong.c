//I WANT TO PLAY WITH YOU
//        YOUR FRIEND, AI
// размер поля 80 на 25 символов
// размер ракетки 3 символа, размер мяча 1

#include <stdio.h>

void cross_and_toe_display(int ball_x, int ball_y, int player1_y, int player2_y, int player1_x, int player2_x);
void move_ball(int *ball_x, int *ball_y, int *direct_x, int *direct_y, int *score1, int *score2, int *player1_y, int *player2_y, int *player1_x, int *player2_x);
void racket_player1_move_up(int *player1_y);
void racket_player1_move_down(int *player1_y);
void racket_player2_move_up(int *player2_y);
void racket_player2_move_down(int *player2_y);

int main() {
    int ball_x = 40, ball_y = 12, direct_x = -1, direct_y = -1;
    int player1_x = 2, player1_y = 12;
    int player2_x = 78, player2_y = 12;
    int score1 = 0, score2 = 0;
    char move_racket;
    while (score1 <= 21 && score2 <= 21)
    {
        move_ball(&ball_x, &ball_y, &direct_x, &direct_y, &score1, &score2, &player1_y, &player2_y, &player1_x, &player2_x);
        cross_and_toe_display(ball_x, ball_y, player1_y, player2_y, player1_x, player2_x);
        scanf("%c", &move_racket);
        if (move_racket == 'a') {
            racket_player1_move_up(&player1_y);
        } else if (move_racket == 'z') {
            racket_player1_move_down(&player1_y);
        } else if (move_racket == 'k') {
            racket_player2_move_up(&player2_y);
        } else if (move_racket == 'm') {
            racket_player2_move_down(&player2_y);
        } else if (move_racket == ' ') {

        }
    }
}

void cross_and_toe_display(int ball_x, int ball_y, int player1_y, int player2_y, int player1_x, int player2_x) {
    char cross = 'X';
    char toe = '0';
    char space = ' ';
    int x = 80, y = 25;
    for (int k = 0; k <= y - 1; k++) {
        for (int i = 0; i <= x; i++) {
            if (k == 0 || k == y - 1) {
                printf("—");
            } else if (k == ball_y && i == ball_x) {
                printf("@");
            } else if ((k >= player1_y - 1 && k <= player1_y + 1) && i == player1_x) {
                printf("|");
            } else if ((k >= player2_y - 1 && k <= player2_y + 1) && i == player2_x) {
                printf("|");
            } else if (i == 0 && k != 0 && k != y - 1){
                printf("|");
            } else if (i == x && k != 0 && k != y - 1){
                printf("|");
            }
            else {
                printf("%c", space);
            }
        }
        printf("\n");
    }
}

void move_ball(int *ball_x, int *ball_y, int *direct_x, int *direct_y, int *score1, int *score2, int *player1_y, int *player2_y, int *player1_x, int *player2_x){
    if(*ball_y + 1 == 24) {
        *direct_y = -1;
    } else if (*ball_y - 1 == 0) {
        *direct_y = 1;
    }

    if(*ball_x - 1 == *player1_x && (*player1_y - 1 <= *ball_y && *ball_y <= *player1_y + 1)) {
        *direct_x = *direct_x * -1;
    }

    if(*ball_x + 1 == *player2_x && (*ball_y == *player2_y || *ball_y == *player2_y - 1 || *ball_y == *player2_y + 1)) {
        *direct_x = *direct_x * -1;
    }
    if(*ball_x == 79) {
        *score1 = *score1 + 1;
        *ball_x = 40;
        *ball_y = 12;
    } else if (*ball_x == 1) {
        *score2 = *score2 + 1;
        *ball_x = 40;
        *ball_y = 12;
    }
    

    *ball_x = *ball_x + 1 * *direct_x;
    *ball_y = *ball_y + 1 * *direct_y;
}

void racket_player1_move_up(int *player1_y){
    if(*player1_y >= 3){
        *player1_y = *player1_y - 1;
    }
}

void racket_player1_move_down(int *player1_y){
    if(*player1_y <= 21){
        *player1_y = *player1_y + 1;
    }
}

void racket_player2_move_up(int *player2_y){
    if(*player2_y >= 3){
        *player2_y = *player2_y - 1;
    }
}

void racket_player2_move_down(int *player2_y){
    if(*player2_y <= 21){
        *player2_y = *player2_y + 1;
    }
}
