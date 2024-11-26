#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main(){
  int x[3], y[3], z[3]; for(int i=0; i<3; i++) scanf("%d %d %d", &x[i], &y[i], &z[i]);
  int bay = y[1] - y[0], cay = y[2] - y[0], baz = z[1] - z[0], caz = z[2] - z[0], bax = x[1] - x[0], cax = x[2] - x[0];
  double area = sqrt(pow(bay * caz - baz * cay, 2) + pow(bax * caz - baz * cax, 2) + pow(bax * cay - bay * cax, 2));
  double ab = sqrt(pow(x[0]-x[1], 2) + pow(y[0]-y[1], 2) + pow(z[0]-z[1],2));
  double ac = sqrt(pow(x[0]-x[2], 2) + pow(y[0]-y[2], 2) + pow(z[0]-z[2],2));
  double bc = sqrt(pow(x[1]-x[2], 2) + pow(y[1]-y[2], 2) + pow(z[1]-z[2],2));
  double min = area / ab;
  if(area==0){
    min = ac > bc ? bc : ac;
    if(ab > ac && ab > bc) min = 0;
  }
  else{
    if(pow(ac,2) > pow(ab,2) + pow(bc,2) || pow(bc,2) > pow(ab,2) + pow(ac,2)) min = bc>ac?ac:bc;
  }
  printf("%.10lf",min);
}