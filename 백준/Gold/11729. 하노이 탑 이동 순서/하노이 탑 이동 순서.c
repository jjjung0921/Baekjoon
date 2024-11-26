#include <stdio.h>
#include <math.h>
void Hanoi(int n, int start, int middle, int end){
  if(n==1){
    printf("%d %d\n", start, end);
    return ;
  }
  Hanoi(n-1, start, end, middle);
  Hanoi(1, start, middle, end);
  Hanoi(n-1, middle, start, end);
}
int main(){
  int n; scanf("%d", &n);
  printf("%d\n", (int)pow(2,n)-1);
  Hanoi(n,1,2,3);
  return 0;
}