#include <stdio.h>

void N(int n){
    for(int i=0; i<n+1; i++){
        for(int j=n-i;j>0;j--){
            printf(" ");
        }
        for(int j=1+(i*2);j>0;j--){
            printf("#");
        }
        printf("\n");
    }

    for(int i=0;i<n+1;i++){
        printf(" ");
        for(int j=0; j<(n*2-1); j++){
            printf("#");
        }
        printf("\n");
    }
}

void S(int n){
    for(int i=0;i<n+1;i++){
        printf(" ");
        for(int j=0; j<(n*2-1); j++){
            printf("#");
        }
        printf("\n");
    }
    
    for(int i=0; i<n+1; i++){
        for(int j= 0;j<i;j++){
            printf(" ");
        }
        for(int j=0;j<1+((n-i)*2);j++){
            printf("#");
        }
        printf("\n");
    }
}

void E(int n){
    for(int i=0;i<n+1;i++){
        printf(" ");
    }
    printf("#\n");

    for(int i=0;i<n-1;i++){
        for(int j=0;j<n+i+3;j++){
            printf("#");
        }
        printf("\n");
    }
    
    //mid
    for(int i=0;i<n*2+2;i++){
        printf("#");
    }
    printf("\n");
    
    for(int i=n-2;i>=0;i--){
        for(int j=0;j<n+i+3;j++){
            printf("#");
        }
        printf("\n");
    }

    for(int i=0;i<n+1;i++){
        printf(" ");
    }
    printf("#");
}

void W(int n){
    for(int i=0;i<n;i++){
        printf(" ");
    }
    printf("#\n");


    for(int i=0;i<n-1;i++){
        for(int k=0;k<n-i-1;k++){
            printf(" ");
        }
        for(int j=0;j<n+i+3;j++){
            printf("#");
        }
        printf("\n");
    }
    
    //mid
    for(int i=0;i<n*2+2;i++){
        printf("#");
    }
    printf("\n");
    
    for(int i=n-2;i>=0;i--){
        for(int k=0;k<n-i-1;k++){
            printf(" ");
        }
        for(int j=0;j<n+i+3;j++){
            printf("#");
        }
        printf("\n");
    }

    for(int i=0;i<n;i++){
        printf(" ");
    }
    printf("#\n");
}

int main(){
    char direction;
    int n;
    scanf("%c %d",&direction,&n);
    if(direction == 'N'){
        N(n);   
    }
    if(direction == 'S'){
        S(n);   
    }
    if(direction == 'E'){
        E(n);   
    }
    if(direction == 'W'){
        W(n);   
    }
    return 0;
}