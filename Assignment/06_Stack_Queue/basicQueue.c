#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
    int data;
    struct node *next;
} node_t;

typedef struct queue_t{
    node_t *front;
    node_t *rear;
} queue_t;

queue_t *enqueue(queue_t *q, int value){
    
    node_t *t = (node_t*)malloc(sizeof(node_t));
    t->data = value;
    
    if(q==NULL){
        q = (queue_t*)malloc(sizeof(queue_t));
        q->front = t;
        q->rear = t;
    }
    else{
        q->rear->next = t;
        q->rear = t;
    };
    return q;
}

queue_t *dequeue(queue_t *q){
    if(q==NULL){
        printf("Queue is empty.\n");
    }
    else if(q->front == q->rear){
        printf("%d\n",q->front->data);
        free(q->front);
        q=NULL; 
    }
    else{
        printf("%d\n",q->front->data);
        node_t *t = q->front;
        q->front = q->front->next;
        free(t);
    };
    return q;
}

void show(queue_t *q){
    if(q==NULL){
        printf("Queue is empty.\n");
    }
    else{
        node_t *t = q->front;
        while(t!=q->rear){
            printf("%d ",t->data);
            t = t->next;
        };
        printf("%d\n",q->rear->data);
    }
}

void empty(queue_t* q){
    if(q==NULL){
        printf("Queue is empty.\n");
    }else{
        printf("Queue is not empty.\n");
    }
}

void size(queue_t* q){
    int i = 0;
    if(q==NULL){
        printf("0\n");
    }
    else{
        node_t *t = q->front;
        while(t != q->rear){
            i++;
            t = t->next;
        }
        i++;
        printf("%d\n",i);
    }
    
}

int main(void)
{
    queue_t *q = NULL;
    int n, i, command, value;
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        scanf("%d", &command);
        switch (command)
        {
        case 1:
            scanf("%d", &value);
            q = enqueue(q, value);
            break;
        case 2:
            q = dequeue(q);
            break;
        case 3:
            show(q);
            break;
        case 4:
            empty(q);
            break;
        case 5:
            size(q);
            break;
        }
    }
    return 0;
}