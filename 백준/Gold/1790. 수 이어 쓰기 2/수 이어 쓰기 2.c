#include <math.h>
#include <stdio.h>
int length(int N) {
  int res = 0, mul = 1, val = N, len = 1;
  do {
    if (val / 10 == 0)
      res += (N - mul + 1) * len;
    else {
      res += mul * 9 * len;
      mul *= 10;
      len += 1;
    }
    val /= 10;
  } while (val > 0);
  return res;
}
int split(int num, int loc) {
  int len = 0;
  int number = num;
  while (num > 0) {
    num /= 10;
    len++;
  }
  int result = number / (int)pow(10, len-loc) % 10;
  return result;
}
int main() {
  int N, k;
  scanf("%d %d", &N, &k);
  if (k > length(N)) { //불가능한 케이스
    printf("-1");
    return 0;
  } else {
    if (k < 10) // k가 10보다 작으면 무조건 k
      printf("%d", k);
    else { // k가 10보다 클 때
      int num = 0;
      while (length(num) < k)
        num++;
      int result = split(num, k - length(num-1));
      printf("%d", result);
      return 0;
    }
  }
}