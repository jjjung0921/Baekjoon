#include <stdio.h>
#include <math.h>
int prime(int n, int m){
  for(int i = 2; i<n; i++){
    if(n%i==0 && m%i==0){
      return 0;
    }
  }
  return 1;
}
int main(){
  int max, min; scanf("%d %d", &max, &min);
  int div = min/max, range = sqrt(div);
  do{
    if(div%range==0){
      if(prime(range, div/range)){
        printf("%d %d\n", max*range, max*div/range);
        return 0;
      }
    }
  }while(range--);
}