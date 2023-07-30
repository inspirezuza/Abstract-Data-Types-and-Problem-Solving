#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
    int data;
    struct node *next;
} node_t;

node_t *append(node_t *head){
    int newdata;
    scanf("%d",&newdata);
    node_t *t = (node_t*)malloc(sizeof(node_t));

    t->data = newdata;
    t->next = NULL;
    if(head==NULL){
        return t;
    }
    else{
        node_t *current = head;
        while(current->next != NULL){
            current = current->next;
        }
        current->next = t;
    }
    return head;
};

void get(node_t *head){
    int n;
    scanf("%d",&n);
    node_t *current = head;
    for(int i=0;i<n;i++){
        current = current->next;
    }
    printf("%d\n",current->data);
}

void show(node_t *head){
    node_t *t = head;
    while(t != NULL) {
        printf("%d ",t->data);
        t = t->next;
    }
    printf("\n");
};

node_t *reverse(node_t *head){
    node_t *current = head;
    node_t *temp = (node_t*)malloc(sizeof(node_t));
    temp->data = current->data;
    temp->next = NULL;
    current = current->next;
    while(current != NULL){
        node_t *newtemp = (node_t*)malloc(sizeof(node_t));
        newtemp->next = temp;
        newtemp->data = current->data;
        temp = newtemp;  
        current = current->next;
    }

    return temp;
}

node_t *cut(node_t *head){
    int a,b;
    scanf("%d %d",&a,&b);
    node_t *current = head;

    for(int i=0;i<a;i++){
        current = current->next;
    }
    head=current;
    
    for(int i=0;i<b-a;i++){
        head = head->next;
    }
    head->next = NULL;
    return current;
}

int main(void)
{
    node_t *startNode;
    int n, i;
    char command;
    startNode = NULL;
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        scanf(" %c", &command);
        switch (command)
        {
        case 'A':
            startNode = append(startNode);
            break;
        case 'G':
            get(startNode);
            break;
        case 'S':
            show(startNode);
            break;
        case 'R':
            startNode = reverse(startNode);
            break;
        case 'C':
            startNode = cut(startNode);
            break;
        default:
            break;
        }
    }
    return 0;
}