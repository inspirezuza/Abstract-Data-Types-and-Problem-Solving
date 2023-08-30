#include <stdio.h>
#include <stdlib.h>

typedef struct stack{
    char *arr;
    int topstack;
}stack_t;

void push(stack_t *s, int c){
    s->arr[++s->topstack] = c;
}

void pop(stack_t *s){
    s->topstack--;
}

int find(char c, char *arr){
    
    for(int i=0;i<3;i++){
        if(c == arr[i]){
            return i+1;
        }
    }
    return 0;
}

int main(){
    int n;
    scanf("%d",&n);
    char paren[n+1];
    scanf("%s",paren);

    stack_t *s = (stack_t*)malloc(sizeof(stack_t));
    
    s->arr = (char*)malloc(sizeof(char) * n);
    s->topstack = -1;
    
    char open_paren[3] = {'[','{','('};
    char close_paren[3] = {']','}',')'};
    
    for(int i=0;i<n;i++){
        if(find(paren[i],open_paren)){
            push(s, paren[i]);
        }
        else{
            if(s->topstack == -1){
                printf("0");
                return 0;
            }
            if(find(s->arr[s->topstack],open_paren) == find(paren[i],close_paren)){
                pop(s);
            }else{
                printf("0");
                return 0; 
            }
        }
    }
    if(s->topstack==-1){
        printf("1");
    }
    else{
        printf("0");
    }
    return 0;
}