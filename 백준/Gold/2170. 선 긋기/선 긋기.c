#include <stdio.h>
#include <stdlib.h>
int compare(const void* a, const void* b) {
    int* rowA = *(int**)a;
    int* rowB = *(int**)b;
    return rowA[0] - rowB[0];
}
int main(){
  int n, line[2]; scanf("%d", &n);
  int** arr = (int **)malloc(sizeof(line)*n);
  for (int i = 0; i < n; i++) arr[i] = (int *)malloc(sizeof(int) * 2);
  for(int i=0; i<n; i++)
    for(int j=0; j<2; j++)
      scanf("%d", &arr[i][j]);
  qsort(arr, n, sizeof(int*), compare);
  int start, end, sum=0;
  for(int i=0; i<n; i++){
    if(i==0){start = arr[i][0]; end = arr[i][1];}
    if(arr[i][0] > end){sum+=end-start; start = arr[i][0]; end = arr[i][1];}
    else{end = end > arr[i][1] ? end : arr[i][1];}
  }
  sum+=end-start;
  printf("%d", sum);
}