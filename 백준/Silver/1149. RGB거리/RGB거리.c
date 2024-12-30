#include <stdio.h>
#define min(x,y) (x<y?x:y)
int main(){
  int n; scanf("%d", &n);
  int color[n+1][3];
  for(int i=1; i<=n; i++)
    for(int j=0; j<3; j++)
      scanf("%d", &color[i][j]);
  //recurrence relation
  for(int i=2; i<=n; i++){
    color[i][0] += min(color[i-1][1], color[i-1][2]);
    color[i][1] += min(color[i-1][0], color[i-1][2]);
    color[i][2] += min(color[i-1][0], color[i-1][1]);
  }
  printf("%d", min(color[n][0], min(color[n][1], color[n][2])));
}