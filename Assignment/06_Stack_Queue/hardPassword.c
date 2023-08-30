#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node
{
    char data;
    struct node *next;
} node_t;

void push(node_t **s,char c){
    node_t *t = (node_t*)malloc(sizeof(node_t));
    t->data = c;
    t->next = *s;
    *s = t;
}

char pop(node_t **s){
    if(*s == NULL){
        return 0;
    }
    node_t *t = *s;
    int c = (*s)->data;
    *s = (*s)->next; 
    free(t);
    return c;
}

int main(){
    int havex = 0;
    int result = 1;
    char pw;
    node_t *stack = NULL;
    while((pw = getchar()) != '\n'){
        if(!havex){
            if(pw == 'x'){
                havex = 1;
            }else{
                push(&stack, pw);
            }
        }else{
            if(pw == 'y'){
            break;
            }
            else if(pw == pop(&stack)){
                continue;
            }
            else{
                result =0;
                break;
            }
        
        }
    }
    if(stack!=NULL){
        result = 0;
    }
    printf("%d",result);
}