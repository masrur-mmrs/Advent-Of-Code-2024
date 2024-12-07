
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main() {
    FILE *file, *outFile;
    file = fopen("input3.txt", "r");
    outFile = fopen("output3.txt", "w");

    char line[4096];
    int flag = 1;
    unsigned long long int sum = 0;

    while (fgets(line, sizeof(line), file)) {
        int count = 0;

        while (line[count] != '\0') {
              
              if (strncmp(&line[count], "do()", 4) == 0) {
                flag = 1;
              } else if (strncmp(&line[count], "don't()", 7) == 0) {
                flag = 0;
              }

              if (strncmp(&line[count], "mul(", 4) == 0) {
              count += 4;                 
              int a = 0, b = 0;
              int valid = 1;

              while (isspace(line[count])) count++; 
              if (isdigit(line[count])) {
                  while (isdigit(line[count])) {
                      a = a * 10 + (line[count] - '0');
                      count++;
                  }
              } else {
                  valid = 0;  
              }

              if (line[count] != ',' || !valid) {
                  valid = 0;
              } else {
                  count++;  
              }

              while (isspace(line[count])) count++;  
              if (isdigit(line[count])) {
                  while (isdigit(line[count])) {
                      b = b * 10 + (line[count] - '0');
                      count++;
                  }
              } else {
                  valid = 0;  
              }

              while (isspace(line[count])) count++;  
              if (line[count] != ')' || !valid) {
                  valid = 0;
              }
    
            if (valid && flag) {  
                  fprintf(outFile, "%d X %d\n", a, b);
                  sum += (a * b);
              }
          }
          count++;
        }
    }

    printf("%llu\n", sum);

    fclose(file);
    fclose(outFile);
    return 0;
}

