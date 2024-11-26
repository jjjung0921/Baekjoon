#include <stdio.h>
#include <math.h>
int count(int length){
  int n = sqrt(length);
  int count;
  if(n*n == length){
    count = 2*n - 1;
    return count;
  } else if(length <=(n*(n+1))){
    count = 2*n;
    return count;
  } else{
    count = 2*n + 1;
    return count;
  }
}
int main(){
  int t; scanf("%d", &t);
  while(t--){
    int x, y; scanf("%d %d", &x, &y);
    int length = y - x;
    printf("%d\n", count(length));
  }
}