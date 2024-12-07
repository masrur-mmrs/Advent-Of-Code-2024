#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  
  FILE *file;
  
  file = fopen("input4.txt", "r");

  char line[256], puzzle[140][256], buff1[5], buff2[5];
  int i = 0, j = 0, count = 0;

  while (fgets(line, 256, file)) {
    j = 0;
    while (line[j] != '\n') {
      puzzle[i][j] = line[j];
      j++;
    }
    i++;
  }

  for (i = 0; i<138; i++) {
    for (j = 0; j<138; j++) {
      sprintf(buff1, "%c%c%c", puzzle[i][j], puzzle[i+1][j+1], puzzle[i+2][j+2]);
      sprintf(buff2, "%c%c%c", puzzle[i][j+2], puzzle[i+1][j+1], puzzle[i+2][j]);
      if (
        ((strcmp(buff1, "MAS")==0) || (strcmp(buff1, "SAM")==0)) 
       &&
        ((strcmp(buff2, "MAS")==0) || (strcmp(buff2, "SAM")==0))
         ) 
      {
        count++;
      }

      /*if ((strncmp(&puzzle[i][j], "XMAS", 4)==0) || (strncmp(&puzzle[i][j], "SAMX", 4)==0)) count++;*/
      /*if (i<137) {*/
      /*  sprintf(buff, "%c%c%c%c", puzzle[i][j], puzzle[i+1][j], puzzle[i+2][j], puzzle[i+3][j]);*/
      /*  if ((strcmp(buff, "XMAS")==0) || (strcmp(buff, "SAMX")==0)) count++;*/
      /*}*/
      /*if (j<137 && i<137) {*/
      /*  sprintf(buff, "%c%c%c%c", puzzle[i][j], puzzle[i+1][j+1], puzzle[i+2][j+2], puzzle[i+3][j+3]);*/
      /*  if ((strcmp(buff, "XMAS")==0) || (strcmp(buff, "SAMX")==0)) count++;*/
      /*}*/
      /*if (j>2 && i<137) {*/
      /*  sprintf(buff, "%c%c%c%c", puzzle[i][j], puzzle[i+1][j-1], puzzle[i+2][j-2], puzzle[i+3][j-3]);*/
      /*  if ((strcmp(buff, "XMAS")==0) || (strcmp(buff, "SAMX")==0)) count++;*/
      /*}*/
    }
  }

  printf("%d\n", count);

  fclose(file);
  
  return 0;
}
