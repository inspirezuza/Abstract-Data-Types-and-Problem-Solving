#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct node{
    int data;
    int drank;
    int number;
    struct node *next;
} node_t;

node_t *cut(node_t *prev, node_t *head){
    return head;
}

void show(node_t *head, int n){
    node_t *current = head;
    for(int i=0;i<n;i++){
        printf("%d/%d ",current->drank,current->data);
        current = current->next;
    }
    printf("\n");
}

int iskin(int i,int k){
    char buffer[sizeof(int)*8+1];
    sprintf(buffer,"%d",i);
    for(int i=0;i<strlen(buffer);i++){
        
        if(buffer[i]-'0'==k){
            // printf("buf %d %d ",buffer[i]-'0',k);
            return 1;
        }
    }
    return 0;
}

int main(){
    int n,k,drink;
    scanf("%d %d",&n,&k);
    
    node_t *head = (node_t*)malloc(sizeof(node_t));
    scanf("%d",&drink);
    head->data = drink;
    head->drank = 0;
    head->number = 1;
    head->next = NULL;
    
    if(n==1){
        printf("1");
        return 0;
    }

    node_t *current = head;
    node_t *temp;
    for(int i=1;i<n-1;i++){
        temp = (node_t*)malloc(sizeof(node_t));
        scanf("%d",&drink);
        current->next = temp;
        temp->data = drink;
        temp->drank = 0;
        temp->number = i+1;
        current = current->next;
    }
    temp = (node_t*)malloc(sizeof(node_t));
    scanf("%d",&drink);
    temp->data = drink;
    temp->drank = 0;
    temp->number = n;
    temp->next = head;
    current->next = temp;

    current = head;
    node_t *prev = temp;
    int i=0;
    while(prev->next!=prev){
        i++;
        
        if((i%k==0) || iskin(i,k)){
            current->drank++;
            if(current->drank > current->data){
                prev->next = current->next;
                n--;
                current = current->next;
                // show(current,n);
                continue;
            }
        }
        // show(current,n);
        prev = current;
        current = current->next;
    }
    printf("%d",current->number);
    return 0;
}