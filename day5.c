#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define RULES_SIZE 1176

int countComas (char *str) {
  int count = 0, i = 0;
  while (str[i] != '\n') {
    if (str[i] == ',') count++;
    i++;
  }
  return count;
}

void fillArray (int *arr, char *str) {
  char *tok = strtok(str, ",");
  int i = 0;
  while (tok!=NULL) {
    *(arr + i) = atoi(tok);
    tok = strtok(NULL, ",");
    i++;
  }
}

int isSafe (int rules[RULES_SIZE][2], int key, int n) {
  for (int i = 0; i<RULES_SIZE; i++) {
    if (rules[i][0] == n) if (rules[i][1] == key) return 0;
  }
  return 1;
}

int main(){
  
  FILE *file;
  file = fopen("input5.txt", "r");
  char line[256], *tok;

  int rules[RULES_SIZE][2], i = 0, j = 0, sum = 0;
  

  while (i < RULES_SIZE) {
    fgets(line, 256, file);
    tok = strtok(line, "|");
    j = 0;
    while (tok!=NULL) {
      rules[i][j] = atoi(tok);
      tok = strtok(NULL, "|");
      j++;
    }
    i++;
  }

  fgets(line, 256, file);

  while (fgets(line, 256, file)) {
    int len = countComas(line) + 1;
    int arr[len];
    int flag = 1, flag2 = 0;

    fillArray(arr, line);

    for(i = 0; i<len; i++) {
      for (j = i + 1; j<len; j++) {
        flag = isSafe(rules, arr[i], arr[j]);
        if (flag == 0) {
          flag2 = 1;
          int temp = arr[i];
          arr[i] = arr[j];
          arr[j] = temp;
        }
      }
    }
    
    if (flag2) sum+=arr[len/2];

  }

  printf("%d\n", sum);

  fclose(file);


  return 0;
}
