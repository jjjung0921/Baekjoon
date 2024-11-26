#include <math.h>
#include <stdio.h>
double calculate_c(double x, double y, double d) { //c를 구하는 함수
  double h1 = sqrt(pow(x,2)-pow(d,2));
  double h2 = sqrt(pow(y,2)-pow(d,2));
  return (h1*h2)/(h1+h2);
}

int main() {
  double x, y, c; scanf("%lf %lf %lf", &x, &y, &c); 
  double min=0, max=x>y?y:x, mid; //w의 값은 0보다 크고 min(x,y)보다 작을 수밖에 없다
  while(min<=max){ //이진탐색
    mid=(min+max)/2; 
    double cal = calculate_c(x, y, mid);
    if(cal-c<0.000001 && cal-c>-0.000001){
      break;
    } else if(cal>c){
      min = mid;
    } else{
      max = mid;
    }
  }
  printf("%.3lf", mid);
}