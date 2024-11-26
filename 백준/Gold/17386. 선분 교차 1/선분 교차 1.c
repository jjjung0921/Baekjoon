#include <stdio.h>
long long int direction(long long int x1, long long int y1, long long int x2, long long int y2, long long int x3, long long int y3) {
  long long int check = (x2-x1) * (y3-y1) - (y2-y1) * (x3-x1);
  if (check < 0)
    return -1;
  else if (check > 0)
    return 1;
  else
    return 0;
}
int main() {
  long long int x1, y1, x2, y2, x3, y3, x4, y4, ABC, ABD, CDA, CDB;
  scanf("%lld %lld %lld %lld", &x1, &y1, &x2, &y2);
  scanf("%lld %lld %lld %lld", &x3, &y3, &x4, &y4);
  ABC = direction(x1, y1, x2, y2, x3, y3);
  ABD = direction(x1, y1, x2, y2, x4, y4);
  CDA = direction(x3, y3, x4, y4, x1, y1);
  CDB = direction(x3, y3, x4, y4, x2, y2);
  if (ABC * ABD <= 0 && CDA * CDB <= 0) {
    printf("1");
  } else {
    printf("0");
  }
}