#include <stdio.h>

void pat1(int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            printf("%d ",1+i+n*j);
        }
        printf("\n");
    }
}

void pat2(int n){
    int arr[60] = {};
    arr[0] = 1;
    printf("%d ",arr[0]);
    for(int i=1;i<n;i++){
        if(i%2==1){
            arr[i] = arr[i-1] + n*2-1;
        }
        else{
            arr[i] = arr[i-1] + 1;
        }
        printf("%d ",arr[i]);
        
    }
    printf("\n");
    for(int i=1;i<n;i++){
        for(int j=0;j<n;j++){
            if(j%2==1){
                arr[j] -= 1;
            }
            else{
                arr[j] += 1;
            }
            printf("%d ",arr[j]);
        }
        printf("\n");
    }
}

void pat3(int n){
    int c = 1;
    int arr[60][60] = {};
    for(int i=0;i<n;i++){
        for(int j=0;j<i+1;j++){
            if(i%2==1){
                arr[n-i+j-1][j] = c;
                // printf("%d %d  ",n-i+j-1,j);    
            }
            else{
                arr[n-j-1][i-j] = c;
                // printf("%d %d  ",n-j-1,i-j); 
            }
            c++;    
        }
        // printf("\n");
    }

    for(int i=n-2;i>=0;i--){
        for(int j=1;j<i+2;j++){
            if(i%2==1){
                arr[j-1][n-i-2+j] = c;
                // printf("%d %d  ",j-1, n-i-2+j);    
            }
            else{
                arr[i-j+1][n-j] = c;
                // printf("%d %d  ",i,n-j); 
            }
            c++;    
        }
        // printf("\n");
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
}

void pat4(int n){
    int arr[60][60] = {};
    int c=2;
    int i=0,j=0;
    int loop=0;
    arr[0][0] = 1;
    while(c<=n*n){
        if(loop==0){
            // printf("%d %d\n",i,j);
            do{
                i++;
                arr[i][j] = c++;
            }while(i<n-1  && arr[i+1][j] == 0);
        }
        else if(loop==1){
            do{
                j++;
                arr[i][j] = c++;
            }while(j<n-1 && arr[i][j+1] == 0);
        }
        else if(loop==2){
            do{
                i--;
                arr[i][j] = c++;
            }while(i>0 && arr[i-1][j] == 0);
        }
        else if(loop==3){
            do{
                j--;
                arr[i][j] = c++;
            }while(j>0 && arr[i][j-1] == 0);
        }
        loop++;
        loop%=4;
    }
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            printf("%d ", arr[i][j]);
        }
    printf("\n");
    }
    
}

int main(){
    int n,p;
    scanf("%d %d",&n,&p);
    if(n==1){
        printf("1");
    }
    else if(p==1){
        pat1(n);
    }
    else if(p==2){
        pat2(n);
    }
    else if(p==3){
        pat3(n);
    }
    else if(p==4){
        pat4(n);
    }
    return 0;
}