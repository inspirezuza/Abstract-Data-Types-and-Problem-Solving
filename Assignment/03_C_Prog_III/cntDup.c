#include <stdio.h>

int main(){
    int n;
    int cnt[10050] = {};
    int max = -1;
    scanf("%d",&n);
    int t;
    for(int i=0;i<n;i++){
        scanf("%d",&t);
        cnt[t] += 1;
        if(cnt[t]>max){
            max = cnt[t];
        }
    }
    for(int i=0; i<10050; i++){
        if(cnt[i] == max){
            printf("%d ",i);
        }
    }
    return 0;
}