#include <stdio.h>
#include <math.h>

int max(int a, int b){
    if(a > b) return a;
    return b;
}

int min(int a, int b){
    if(a < b) return a;
    return b;
}

int estate(int m,int n){
    if(m == 1){
        return n;
    }
    if(n == 1){
        return m;
    }
    for(int i=16;i>=1;i--){
        if(m>=pow(2,i) && n>=pow(2,i)){
            return 1 + estate(min(m,n)-pow(2,i),max(m,n)) + estate(pow(2,i),max(m,n)-pow(2,i));
        }
    }
    return 0;
}

int main(){
    int m,n;
    scanf("%d %d",&m,&n);
    printf("%d",estate(m,n));
    return 0;
}
//O(log(max(m,n)))