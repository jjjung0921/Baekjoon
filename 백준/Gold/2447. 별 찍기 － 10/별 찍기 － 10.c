#include <stdio.h>
#include <string.h>
char star[6600][6600];
void init(int n){
  for(int i=0; i<n; i++){
    memset(star[i], '*', n);
  }
  return;
}
void set(int n, int row, int column, int end){
  if(n==1) return;
  int gap = n/3;
  while(row < end){
    while(column < end){
      for(int i=0; i<gap; i++){
        memset(star[row+i]+column, ' ', gap);
      }
      column += n;
    }
    row += n;
    column = gap;
  }
  set(n/3, gap/3, gap/3, end);
}
int main(){
  int n; scanf("%d", &n);
  init(n);
  set(n, n/3, n/3, n);
  for(int i=0; i<n; i++){
    memset(star[i]+n, 0, 1);
    printf("%s\n", star[i]);
  }
}