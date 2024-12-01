#include <stdio.h>
#include <stdlib.h>

int getNum(char* str, int a, int b) {
  char res[b-a];
  for (int i = 0; i<=(b-a) ; i++) {
    *(res+i)=*(str+a+i);
  }
  return atoi(res);
}

void sortArray(int* arr, int len) {
  for (int i = 0; i<len; i++) {
    for (int j = 0; j<len; j++) {
      if (*(arr+i)<*(arr+j)) {
        int temp = *(arr+i);
        *(arr+i) = *(arr+j);
        *(arr+j) = temp;
      }
    }
  }
}

int find(int* arr, int key) {
  int finds = 0;
  for (int i = 0; i<1000; i++) {
    if (key == *(arr+i)) {
      finds++;
    }
  }
  return finds;
}

int main(void){
  FILE *fptr;
  fptr = fopen("input1.txt", "r");
  char line[256];
  int arr1[1000], arr2[1000], arr3[1000], count = 0;
  while (fgets(line, 256, fptr)) {
    *(arr1+count) = getNum(line, 0, 4);
    *(arr2+count) = getNum(line, 8, 12);
    count++;
  }
  fclose(fptr);


  sortArray(arr1, 1000);
  sortArray(arr2, 1000);



  int sum = 0;

  /*for (int i = 0; i<1000; i++) {*/
  /*  if (arr1[i]>arr2[i]) {*/
  /*    sum+=arr1[i]-arr2[i];*/
  /*  } else {*/
  /*    sum+=arr2[i]-arr1[i];*/
  /*  }*/
  /*}*/

  for (int i = 0; i<1000; i++) {
    sum = sum + *(arr1+i)*find(arr2, *(arr1+i));
  }

  printf("%d\n", sum);

  return 0;
}
