#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

char grid[9] = {'0', '1', '2', '3', '4', '5', '6', '7', '8'};

int checkwin() {
  if (grid[0] == grid[1] && grid[1] == grid[2])
  return -1;

  else if (grid[3] == grid[4] && grid[4] == grid[5])
  return -1;

  else if (grid[6] == grid[7] && grid[7] == grid[8])
  return -1;

  else if (grid[0] == grid[3] && grid[3] == grid[6])
  return -1;

  else if (grid[1] == grid[4] && grid[4] == grid[7])
  return -1;

  else if (grid[2] == grid[5] && grid[5] == grid[8])
  return -1;

  else if (grid[0] == grid[4] && grid[4] == grid[8])
  return -1;

  else if (grid[2] == grid[4] && grid[4] == grid[6])
  return -1;

  else if (grid[0] != '0' && grid[1] != '1' && grid[2] != '2' &&
  grid[3] != '3' && grid[4] != '4' && grid[5] != '5' && grid[6]
  != '6' && grid[7] != '7' && grid[8] != '8')
  return 0;

  else
  return 1;
}

void draw() {
  printf("TIC TAC TOE\n");
  printf("     |     |     \n");
  printf("  %c  |  %c  |  %c \n", grid[0], grid[1], grid[2]);
  printf("_____|_____|_____\n");
  printf("     |     |     \n");
  printf("  %c  |  %c  |  %c \n", grid[3], grid[4], grid[5]);
  printf("_____|_____|_____\n");
  printf("     |     |     \n");
  printf("  %c  |  %c  |  %c \n", grid[6], grid[7], grid[8]);

  printf("     |     |     \n\n");
}

int main() {
  int player = 1;
  int status;
  int square;;
  char mark;
  do {
    draw();
    player = (player % 2) ? 1 : 2;

    printf("Player %d, enter a number:  ", player);

    char buffer[128];
    int ctg = open("ctg", O_RDONLY);
    read(ctg, buffer, sizeof(buffer));
    square = atoi(buffer);

    mark = (player == 1) ? 'X' : 'O';

    if (square == 0 && grid[0] == '0')
    grid[0] = mark;
    else if (square == 1 && grid[1] == '1')
    grid[1] = mark;
    else if (square == 2 && grid[2] == '2')
    grid[2] = mark;
    else if (square == 3 && grid[3] == '3')
    grid[3] = mark;
    else if (square == 4 && grid[4] == '4')
    grid[4] = mark;
    else if (square == 5 && grid[5] == '5')
    grid[5] = mark;
    else if (square == 6 && grid[6] == '6')
    grid[6] = mark;
    else if (square == 7 && grid[7] == '7')
    grid[7] = mark;
    else if (square == 8 && grid[8] == '8')
    grid[8] = mark;
    else {
      printf("Invalid move ");
      player--;
    }
    status = checkwin();

    player++;
  } while (status == 1);

  draw();

  if (status == -1)
  printf("Player %d win", --player);
  else
  printf("Game draw");
  return 0;
}
