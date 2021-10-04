#include <stdio.h>
// hehe boy
void draw(int leftPen, int rightPen, int ballX, int ballY, int playerOneScore, int playerTwoScore);

void ballMove(int leftPen, int rightPen, int ballX, int ballY, int playerOneScore, int playerTwoScore);

void step();

void clear();

int main() {
    step();
    return 0;
}

void draw(int leftPen, int rightPen, int ballX, int ballY, int playerOneScore, int playerTwoScore) {
    char space = ' ';
    char TDBorders = '-';
    char LRCBorders = '|';
    char ball = '*';
    char penLeft = ']';
    char penRight = '[';
    for (int y = 0; y <= 24; y++) {
        for (int x = 0; x <= 79; x++) {
            if (y == 0 || y == 24) {
                printf("%c", TDBorders);
            } else if (x == 0 || x == 79 || x == 39) {
                if (x == ballX && y == ballY) {
                    printf("%c", ball);
                } else {
                    printf("%c", LRCBorders);
                }
            } else if (x == 76 && (y == rightPen || y == rightPen-1 || y == rightPen+1)) {
                printf("%c", penRight);
            } else if (x == 3 && (y == leftPen || y == leftPen-1 || y == leftPen+1)) {
                printf("%c", penLeft);
            } else if (x == ballX && y == ballY) {
                printf("%c", ball);
            } else {
                printf("%c", space);
            }
        }
        printf("\n");
    }
    printf("%39d:%d\n", playerOneScore, playerTwoScore);
}

void step() {
    int playerOneScore = 0;
    int playerTwoScore = 0;
    int leftPen = 13;
    int rightPen = 13;
    int ballX = 5, ballY = leftPen;
    int ballDirX = 1;
    int ballDirY = 1;
    draw(leftPen, rightPen, ballX, ballY, playerOneScore, playerTwoScore);
    char key, c;
    while (playerOneScore != 21 && playerTwoScore != 21) {
        if ((scanf("%c%c", &key, &c) == 2) && (c == '\n') && ((key == ' ') || (key == 'z') ||
        (key == 'Z') || (key == 'a') || (key == 'A') || (key == 'm') ||
        (key == 'M') || (key == 'k') || (key == 'K'))) {
            if (ballY >= 23 || ballY <= 1) {
                ballDirY *= -1;
            }

            if (ballX+1 ==76 && ballY == rightPen) {
                ballDirX *= -1;
                ballDirY *= 0;
            }

            if (ballX+1 ==76 && ballY == rightPen+1) {
                ballDirX *= - 1;
                ballDirY = 1;
            }

            if (ballX+1 ==76 && ballY == rightPen-1) {
                ballDirX *= - 1;
                ballDirY = -1;
            }

            if (ballX-1 ==3 && ballY == leftPen) {
                ballDirX *= - 1;
                ballDirY *= 0;
            }

            if (ballX-1 ==3 && ballY == leftPen+1) {
                ballDirX *= - 1;
                ballDirY = 1;
            }

            if (ballX-1 ==3 && ballY == leftPen-1) {
                ballDirX *= - 1;
                ballDirY = -1;
            }

            if (ballX == 76) {
                    playerOneScore +=1;
                    ballX = 75;
                    ballY = rightPen - ballDirY;
                    ballDirX *= -1;
            }
            if (ballX == 3) {
                    playerTwoScore +=1;
                    ballX = 4;
                    ballY = leftPen - ballDirY;
                    ballDirX *= -1;
                }

            ballX += ballDirX;
            ballY += ballDirY;
                if ((key == 'z') || (key == 'Z')) {
                if (leftPen + 2 == 24) {
                } else {
                    leftPen += 1;
                }
                clear();
                draw(leftPen, rightPen, ballX, ballY, playerOneScore, playerTwoScore);
            } else if ((key == 'a') || (key == 'A')) {
                if (leftPen - 2 == 0) {
                } else {
                    leftPen -= 1;
                }
                clear();
                draw(leftPen, rightPen, ballX, ballY, playerOneScore, playerTwoScore);
            } else if ((key == 'm') || (key == 'M')) {
                if (rightPen + 2 == 24) {
                } else {
                    rightPen += 1;
                }
                clear();
                draw(leftPen, rightPen, ballX, ballY, playerOneScore, playerTwoScore);
            } else if ((key == 'k') || (key == 'K')) {
                if (rightPen - 2 == 0) {
                } else {
                    rightPen -= 1;
                }
                clear();
                draw(leftPen, rightPen, ballX, ballY, playerOneScore, playerTwoScore);
            } else if (key == ' ') {
                clear();
                draw(leftPen, rightPen, ballX, ballY, playerOneScore, playerTwoScore);
                }
        } else if (scanf("%c%c", &key, &c) == EOF) {
            break;
            } else {
            clear();
            draw(leftPen, rightPen, ballX, ballY, playerOneScore, playerTwoScore);
            fflush(NULL);
        }
    }
    if (playerOneScore == 21) {
        printf("My congratulations, player One!");
    }
    if (playerTwoScore == 21) {
        printf("My congratulations, player Two!");
    }
}

void clear() {
    printf("\33c\e[3J");
}
