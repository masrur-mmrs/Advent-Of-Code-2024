#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROWS 130
#define MAX_COLS 130

void getStartingPosition(char map[MAX_ROWS][MAX_COLS+2], int *x, int *y) {
    for (int i = 0; i < MAX_ROWS; i++) {
        for (int j = 0; j < MAX_COLS; j++) {
            if (map[i][j] == '^') {
                *y = i;
                *x = j;
            }
        }
    }
}

void printMap(char map[MAX_ROWS][MAX_COLS+2]) {
  system("clear");
  for (int i = 0;i < MAX_ROWS; i++) {
    printf("%s\n", map[i]);
  }
}

void nextMove(char map[MAX_ROWS][MAX_COLS+2], char playerDir, int *x, int *y) {
    switch (playerDir) {
        case '^':
            if (*y > 0 && map[*y - 1][*x] == '#') {
                map[*y][*x] = '>';
            } else if (*y > 0) {
                map[*y - 1][*x] = '^';
                map[*y][*x] = 'X';
                (*y)--;
            }
            break;
        case '>':
            if (*x < MAX_COLS - 1 && map[*y][*x + 1] == '#') {
                map[*y][*x] = 'V';
            } else if (*x < MAX_COLS - 1) {
                map[*y][*x + 1] = '>';
                map[*y][*x] = 'X';
                (*x)++;
            }
            break;
        case 'V':
            if (*y < MAX_ROWS - 1 && map[*y + 1][*x] == '#') {
                map[*y][*x] = '<';
            } else if (*y < MAX_ROWS - 1) {
                map[*y + 1][*x] = 'V';
                map[*y][*x] = 'X';
                (*y)++;
            }
            break;
        case '<':
            if (*x > 0 && map[*y][*x - 1] == '#') {
                map[*y][*x] = '^';
            } else if (*x > 0) {
                map[*y][*x - 1] = '<';
                map[*y][*x] = 'X';
                (*x)--;
            }
            break;
        default:
            exit(0);
            break;
    }

}

void countX(char map[MAX_ROWS][MAX_COLS + 2]) {
  int x = 1;
  for (int i = 0; i < MAX_ROWS; i++) {
    for (int j = 0; j< MAX_COLS; j++) {
      if (map[i][j] == 'X') x++;
    }
  }
  printf("Distance travelled %d\n", x);
}

int main() {
    FILE *file = fopen("input6.txt", "r");

    char line[MAX_COLS+2], map[MAX_ROWS][MAX_COLS+2];
    int i = 0, x, y;

    while (fgets(line, sizeof(line), file) && i < MAX_ROWS) {
        strncpy(map[i], line, MAX_COLS + 1);
        map[i][MAX_COLS] = '\0'; 
        i++;
    }
    fclose(file);

    getStartingPosition(map, &x, &y);

    while (y < MAX_ROWS-1 && x < MAX_COLS-1 && y > 0 && x > 0) {
        nextMove(map, map[y][x], &x, &y);
        printMap(map);
    }

    countX(map);


    return 0;
}

