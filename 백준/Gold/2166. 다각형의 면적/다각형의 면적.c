#include <stdio.h>
#include <math.h>
double triarea(long long int x1, long long int y1, long long int x2, long long int y2, long long int x3, long long int y3){ //신발끈 공식
  double area = (x1*y2 + x2*y3 + x3*y1 - y1*x2 - y2*x3 - y3*x1);
  area/=2;
  return area;
}
int main(){
  int N; scanf("%d", &N);
  long long int x1, y1; scanf("%lld %lld", &x1, &y1); N=N-1; //한 점은 고정
  long long int x2, y2; scanf("%lld %lld", &x2, &y2); N=N-1; 
  long long int before_x = x2, before_y = y2;
  double area = 0;
  while(N--){
    long long int x, y; scanf("%lld %lld", &x, &y);
    double tri = triarea(x1, y1, before_x, before_y, x, y);
    area += tri;
    before_x = x, before_y = y;
  }
  area = fabs(area);
  printf("%.1lf", area);
}