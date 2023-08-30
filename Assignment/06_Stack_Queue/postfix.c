#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

typedef struct node
{
    float data;
    struct node *next;
} node_t;

void push(node_t**s, float f) {
    node_t *t = (node_t*)malloc(sizeof(node_t));
    t->data = f;
    t->next = *s;
    *s = t;
}

float pop(node_t**s){
    if(s==NULL){
        printf("wtf");
        return 0;
    }
    node_t *t = *s;
    float data = (*s)->data;
    *s = (*s)->next;
    free(t);
    return data;
}

int main(){
    int n;
    float result = 0;
    scanf("%d ",&n);
    node_t *stack = NULL;
    char c;
    for(int i=0;i<n;i++){
        scanf("%c",&c);
        if(c>='0' && c<='9'){
            push(&stack,(float)(c-'0'));
        }
        else{
            float a = pop(&stack);
            float b = pop(&stack);
            if(c == '+'){
                result = b + a; 
            }
            else if(c == '-'){
                result = b - a; 
            }
            else if(c == '*'){
                result = b * a; 
            }
            else if(c == '/'){
                result = b / a; 
            }
            push(&stack,result);
        }
    }
    
    printf("%.2f",result);
    return 0;
}