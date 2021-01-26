#include <stdio.h>
#include <stdlib.h>

int asalmi(int i, int n){
    if (n == 1){
        return 0;
    }
    
    if (n == 2){
        return 1;
    }
    
    if (n % i == 0){
        return 0;
    }
   
    if (i * i > n){
        return 1;
    }
    return asalmi(i + 1, n);
}

int main(){
    int x;
    scanf("%d", &x);
    if(asalmi(2, x) == 1){
        printf("%d asal sayýdýr\n", x);
    }
    if(asalmi(2, x) == 0){
        printf("%d asal sayý deðildir \n", x);
    }

return 0;
}
