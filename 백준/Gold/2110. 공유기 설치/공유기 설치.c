#include <stdio.h>
#include <stdlib.h>
int compare(const void *a, const void *b){ //정렬
  return ( *(int*)a - *(int*)b );
}
int main(){
  int n, c; scanf("%d %d", &n, &c);
  int arr[n], result;
  for(int i=0; i<n; i++) scanf("%d", &arr[i]); //각 좌표
  qsort(arr, n, sizeof(int), compare); //정렬
  int length = arr[n-1] - arr[0]; //최대 거리
  
  int max = length+1, min = 0;
  while(max > min){
    int mid = (max + min) / 2, cnt = 1, current = arr[0];
    for(int i=1; i<n; i++){
      if(arr[i] >= current + mid){ //mid보다 멀면 설치
        current = arr[i]; //현재 위치 조정
        cnt++; //공유기 설치
      }
    }
    if(cnt < c) {max = mid;} //적게 설치되면 간격 줄이기
    else {min = mid+1; result = mid;} //많이 설치되면 간격 높이기
  }
  printf("%d", result);
}