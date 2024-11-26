#include <stdio.h>
#include <math.h>
int num=0;
void div(int n, int r, int c){
  if(n==0) return;
  if(r/(int)pow(2, n-1)){
    num+=2*pow(4,n-1);
    r-=(int)pow(2, n-1);
  }
  if(c/(int)pow(2, n-1)){
    num+=pow(4,n-1);
    c-=(int)pow(2, n-1);
  }
  return div(--n, r, c);
}
int main(){
  int N, r, c; scanf("%d %d %d", &N, &r, &c);
  div(N, r, c);
  printf("%d", num);
  return 0;
}