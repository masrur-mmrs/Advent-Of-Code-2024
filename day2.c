#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int isSafe(int *nums, int size) {
    int inc = 1, dec = 1;
    for (int i = 1; i < size; i++) {
        int dif = nums[i] - nums[i-1];
        if (dif < -3 || dif > 3 || dif == 0) { 
          return 0;
        }
        if (dif < 0) {
          inc = 0;
        }
        else if (dif > 0) {
          dec = 0;
        }
    }
    return (inc != dec);
}

int main() {
    FILE *file, *file1;
    file = fopen("input2.txt", "r");
    file1 = fopen("output.txt", "w");
    
    char line[256];
    int safe = 0;
    while (fgets(line, 256, file)) {
        int nums[256], count = 0;
        char *token = strtok(line, " ");
        while (token != NULL) {
            nums[count++] = atoi(token);
            token = strtok(NULL, " ");
        }
        
        if (isSafe(nums, count)) {
            safe++;
            continue;
        }
        
        int foundSafe = 0;
        for (int i = 0; i < count; i++) {
            int temp[256];
            int tempCount = 0;
            
            for (int j = 0; j < count; j++) {
                if (j != i) temp[tempCount++] = nums[j];
            }
            
            if (isSafe(temp, tempCount)) {
                foundSafe = 1;
                break;
            }
        }
        
        if (foundSafe) safe++;
    }
    
    printf("%d\n", safe);
    fclose(file);
    fclose(file1);
    return 0;
}
