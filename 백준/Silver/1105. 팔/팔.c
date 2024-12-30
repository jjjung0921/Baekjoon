#include <stdio.h>
int main(){
    int l,r; scanf("%d %d", &l, &r);
    int div = 1000000000;
    int count = 0;
    
    while(div){
        int ld = l/div, rd=r/div;
        if(l!=r && ld!=rd) break;
        
        if(ld==8) count++;
        l -= ld*div; r -= rd*div;
        div/=10;
    }
    printf("%d", count);
}