#include <stdio.h>
int direction(int x1, int y1, int x2, int y2, int x3, int y3){
  return x1*y2 + x2*y3 + x3*y1 - (x2*y1 + x3*y2 +x1*y3);
}
int main() {
  int x1, y1, x2, y2, x3, y3;
  scanf("%d %d\n%d %d\n%d %d", &x1, &y1, &x2, &y2, &x3, &y3);
  int direct = direction(x1, y1, x2, y2, x3, y3);
  if(direct>0) printf("1");
  else if(direct<0) printf("-1");
  else printf("0");
}