#include <stdio.h>
int main(){
  int n, m; scanf("%d %d", &n, &m);
  int arr[n], max = 0;
  for(int i=0; i<n; i++) {scanf("%d", &arr[i]); max = max < arr[i] ? arr[i] : max;}
  int min = 0;
  while(min < max){
    int mid = (min+max)/2, small = arr[0], big = arr[0], cnt = 0;
    for(int i=0; i<n; i++){
      small = small < arr[i] ? small : arr[i];
      big = big > arr[i] ? big : arr[i];
      if(big - small > mid) {
        small = arr[i]; big = arr[i]; cnt++;
      }
    }
    cnt++;
    if(cnt > m) min = mid + 1;
    else max = mid;
  }
  printf("%d", min);
}