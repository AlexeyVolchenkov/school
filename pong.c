//I WANT TO PLAY WITH YOU
//        YOUR FRIEND, AI
// размер поля 80 на 25 символов
// размер ракетки 3 символа, размер мяча 1

#include <stdio.h>

void cross_and_toe_display(int ball_x, int ball_y, int player1_y, int player2_y, int player1_x, int player2_x, int score1, int score2);
void move_ball(int *ball_x, int *ball_y, int *direct_x, int *direct_y, int *score1, int *score2, int *player1_y, int *player2_y, int *player1_x, int *player2_x);
int racket_player1_move_up(int player1_y);
int racket_player1_move_down(int player1_y);
int racket_player2_move_up(int player2_y);
int racket_player2_move_down(int player2_y);
int check_goal_player1(int ball_x, int score1);
int check_goal_player2(int ball_x, int score2);
int move_ball_x(int ball_x, int ball_y, int direct_y);
int move_ball_y(int ball_x, int ball_y, int direct_y);
int return_from_racket(int direct_x, int ball_x, int ball_y, int player1_x, int player1_y, int player2_x, int player2_y);
int ball_change_direct_y(int ball_y, int direct_y);

int main() {
    int ball_x = 40, ball_y = 12, direct_x = -1, direct_y = -1;
    int player1_x = 2, player1_y = 12;
    int player2_x = 78, player2_y = 12;
    int score1 = 0, score2 = 0;
    char move_racket;
    while (score1 <= 21 && score2 <= 21)
    {
        direct_x = return_from_racket(direct_x, ball_x, ball_y, player1_x, player1_y, player2_x, player2_y);
        direct_y = ball_change_direct_y(ball_y, direct_y);
        score1 = check_goal_player1(ball_x, score1);
        score2 = check_goal_player2(ball_x, score2);
        ball_y = move_ball_y(ball_x, ball_y, direct_y);
        ball_x = move_ball_x(ball_x, ball_y, direct_x);
        cross_and_toe_display(ball_x, ball_y, player1_y, player2_y, player1_x, player2_x, score1, score2);
        scanf("%c", &move_racket);
        if (move_racket == 'a') {
            player1_y = racket_player1_move_up(player1_y);
        } else if (move_racket == 'z') {
            player1_y = racket_player1_move_down(player1_y);
        } else if (move_racket == 'k') {
            player2_y = racket_player2_move_up(player2_y);
        } else if (move_racket == 'm') {
            player2_y = racket_player2_move_down(player2_y);
        } else if (move_racket == ' ') {

        }
    }
}

void cross_and_toe_display(int ball_x, int ball_y, int player1_y, int player2_y, int player1_x, int player2_x, int score1, int score2) {
    char cross = 'X';
    char toe = '0';
    char space = ' ';
    int x = 80, y = 26;
    for (int k = 0; k <= y - 1; k++) {
        for (int i = 0; i <= x; i++) {
            if (k == 1 || k == y - 1) {
                printf("—");
            } else if(k == 0 && i == 16){
                printf("player1: %d", score1);
            } else if(k == 0 && i == 45){
                printf("player2: %d", score2);
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

int move_ball_x(int ball_x, int ball_y, int direct_x){
    ball_x = ball_x + direct_x;
    if(ball_x >= 79){
        ball_x = 40;
    } else if (ball_x <= 0) {
        ball_x = 40;
    }
    return ball_x;
}

int move_ball_y(int ball_x, int ball_y, int direct_y){
    ball_y = ball_y + direct_y;
    if(ball_x >= 79){
        ball_y = 12;
    } else if (ball_x <= 0) {
        ball_y = 12;
    }
    return ball_y;
}

int check_goal_player1(int ball_x, int score1){
    if(ball_x >= 79) {
        score1 = score1 + 1;
    }
    return score1;
}

int check_goal_player2(int ball_x, int score2){
    if(ball_x <= 1) {
        score2 = score2 + 1;
    }
    return score2;
}


int return_from_racket(int direct_x, int ball_x, int ball_y, int player1_x, int player1_y, int player2_x, int player2_y){
    if(ball_x - 1 == player1_x && (player1_y - 1 <= ball_y && ball_y <= player1_y + 1)) {
        direct_x = direct_x * -1;
    }

    if(ball_x + 1 == player2_x && (ball_y == player2_y || ball_y == player2_y - 1 || ball_y == player2_y + 1)) {
        direct_x = direct_x * -1;
    }
    return direct_x;
}

int ball_change_direct_y(int ball_y, int direct_y){
    if(ball_y + 1 == 25) {
        direct_y = direct_y * -1;
    } else if (ball_y - 1 == 1) {
        direct_y = direct_y * -1;
    }
    return direct_y;
}

int racket_player1_move_up(int player1_y){
    if(player1_y >= 3){
        player1_y = player1_y - 1;
    }
    return player1_y;
}

int racket_player1_move_down(int player1_y){
    if(player1_y <= 21){
        player1_y = player1_y + 1;
    }
    return player1_y;
}

int racket_player2_move_up(int player2_y){
    if(player2_y >= 3){
        player2_y = player2_y - 1;
    }
    return player2_y;
}

int racket_player2_move_down(int player2_y){
    if(player2_y <= 21){
        player2_y = player2_y + 1;
    }
    return player2_y;
}
