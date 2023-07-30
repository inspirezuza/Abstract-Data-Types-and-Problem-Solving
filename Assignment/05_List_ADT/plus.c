#include <stdio.h>
#include <string.h>

int main(){
    char a[9999] = {};
    char b[9999] = {};
    char t[9999] = {};
    scanf("%s",a);
    scanf("%s",b);
    if(strlen(a) < strlen(b)){
        strcpy(t,a);
        strcpy(a,b);
        strcpy(b,t);
    }
    int i = 0;
    int x,y;
    int p =0;
    while(i<strlen(a)){
        if((int)(strlen(a)-1-i) < 0){
            x = 0;
        }
        else{
            x = (int)a[strlen(a)-1-i] - '0'; 
        }

        if((int)(strlen(b)-1-i) < 0){
            y = 0;
        }
        else{
            y = (int)b[strlen(b)-1-i] - '0'; 
        }
        if(p){
            x++;
            p=0;
        }
        if(x+y>=10){
            p=1;
        }
        t[strlen(a)-1-i] = (x+y)%10 + '0';
        i++;
    }

    if(p){
        printf("1");
    }
    for(int i=0;i<strlen(a);i++){
        printf("%c",t[i]);
    }
    return 0;
}
