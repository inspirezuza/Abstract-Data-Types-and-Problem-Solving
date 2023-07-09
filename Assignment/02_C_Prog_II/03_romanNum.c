#include <stdio.h>

void roman(int val){
    int num[] = {1000,100,10,1};
    char roman[] = {'M', 'D', 'C', 'L', 'X', 'V', 'I'};
    int t;
    for(int i=0;i<4;i++){
        t = val/num[i];
        val-=t*num[i];
        if (t==0) continue;
        else if (t<=3){
            for(int j=0;j<t;j++){
                printf("%c",roman[i*2]);
            }
        }
        else if(t==4){
            printf("%c%c",roman[i*2],roman[i*2-1]);
        }
        else if (t<=8){
            printf("%c",roman[i*2-1]);
            t-=5;
            for(int j=0;j<t;j++){
                printf("%c",roman[i*2]);
            }
        }
        else if (t==9){
            printf("%c%c",roman[i*2],roman[i*2-2]);
        }
    }
    printf("\n");
}

int main(){
    int n;
    scanf("%d",&n);
    
    int val;
    for(int i=0; i<n; i++){
        scanf("%d", &val);
        roman(val);
    }
    return 0;
}