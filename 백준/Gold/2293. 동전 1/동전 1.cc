#include <iostream>
using namespace std;
int main(){
    int n, k; scanf("%d %d", &n, &k);
    int* price = new int[n];
    for(int i=0; i<n; i++)
        scanf("%d", &price[i]);
    int dp[k+1] = {0}; //각 값을 만드는 경우의 수
    dp[0] = 1;
   for(int i=0; i<n; i++)
        for(int j=price[i]; j<=k; j++)
            dp[j] += dp[j-price[i]];
    printf("%d", dp[k]);
    delete[] price;
}