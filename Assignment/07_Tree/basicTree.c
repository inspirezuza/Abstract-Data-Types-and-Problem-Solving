#include <stdio.h>
#include <stdlib.h>
// You can define your own (one or more)
// structures here. However, we eventually
// need the data type "tree_t".
// For example:
// typedef struct node {
// ...
// } node_t;
// typedef node_t tree_t;
// Write your code here
// ...

typedef struct tree
{
    int value;
    struct tree *first_child;
    struct tree *next_sibling;
} tree_t;

typedef struct node
{
    tree_t *value;
    struct node *next;
} node_t;

typedef node_t stack_t;

typedef struct queue
{
    node_t *front;
    node_t *rear;
} queue_t;

void showstack(stack_t *s);

// stack
void push(stack_t **s, tree_t *value)
{
    node_t *newnode = (node_t *)malloc(sizeof(node_t));
    newnode->value = value;
    newnode->next = *s;
    *s = newnode;
}
tree_t *pop(stack_t **s)
{
    if (*s == NULL)
    {
        printf("stack is empty");
        return NULL;
    }
    node_t *t = *s;
    tree_t *tree = t->value;
    *s = (*s)->next;
    free(t);
    return tree;
}

void showstack(stack_t *s)
{
    stack_t *t = s;
    while (t != NULL)
    {
        printf("%d -> ", t->value->value);
        t = t->next;
    }
}
// queue
void enqueue(queue_t **q, tree_t *value)
{
    node_t *newnode = (node_t *)malloc(sizeof(node_t));
    newnode->value = value;
    newnode->next = NULL;
    if ((*q)->front == NULL)
    {
        (*q)->rear = (*q)->front = newnode;
    }
    else
    {
        (*q)->rear->next = newnode;
        (*q)->rear = newnode;
    }
}
tree_t *dequeue(queue_t **q)
{
    tree_t *value;
    if ((*q)->front == NULL)
    {
        printf("Queue is empty");
    }
    else
    {
        node_t *t = (*q)->front;
        value = t->value;
        (*q)->front = (*q)->front->next;
        if ((*q)->front == NULL)
        {
            (*q)->rear = NULL;
        }
        free(t);
    }
    return value;
}

void showqueue(queue_t *q)
{
    node_t *t = q->front;
    while (t != NULL)
    {
        printf("%d -> ", t->value->value);
        t = t->next;
    }
    printf("\n");
}

// searchpos
tree_t *searchpos(tree_t *t, int parent)
{
    if (t == NULL)
    {
        return NULL;
    }
    if (t->value == parent)
    {
        return t;
    }
    tree_t *pos = searchpos(t->first_child, parent);
    if (pos != NULL)
    {
        return pos;
    }
    else
    {
        return searchpos(t->next_sibling, parent);
    }
}

// 1
tree_t *attach(tree_t *t, int parent, int child)
{
    tree_t *newt = (tree_t *)malloc(sizeof(tree_t));
    newt->value = child;
    newt->first_child = NULL;
    newt->next_sibling = NULL;
    if (t == NULL)
    {
        return newt;
    }

    tree_t *pos = searchpos(t, parent);
    if (pos->first_child == NULL)
    {
        pos->first_child = newt;
    }
    else
    {
        pos = pos->first_child;
        while (pos->next_sibling != NULL)
        {
            pos = pos->next_sibling;
        }
        pos->next_sibling = newt;
    }
    return t;
}

void destroy(tree_t **t)
{
    if ((*t) == NULL)
    {
        return;
    }
    destroy(&((*t)->first_child));
    destroy(&((*t)->next_sibling));
    free(*t);
}

tree_t *searchbefore(tree_t *t, int node_data)
{
    if (t == NULL)
    {
        return NULL;
    }
    if (t->first_child != NULL)
    {
        if (t->first_child->value == node_data)
        {
            return t;
        }
    }
    if (t->next_sibling != NULL)
    {
        if (t->next_sibling->value == node_data)
        {
            return t;
        }
    }
    tree_t *pos = searchbefore(t->first_child, node_data);
    if (pos != NULL)
    {
        return pos;
    }
    else
    {
        return searchbefore(t->next_sibling, node_data);
    }
}

void print_tree(tree_t *t);

// 2
tree_t *detach(tree_t *t, int node_data)
{
    if (t == NULL)
    {
        return NULL;
    }
    if (t->value == node_data)
    {
        return t;
    }
    tree_t *parent = searchbefore(t, node_data);
    if (parent->first_child != NULL)
    {
        if (parent->first_child->value == node_data)
        {
            tree_t *temp = parent->first_child->next_sibling;
            destroy(&(parent->first_child->first_child));
            free(parent->first_child);
            parent->first_child = temp;
        }
    }
    if (parent->next_sibling != NULL)
    {
        if (parent->next_sibling->value == node_data)
        {
            if (parent->next_sibling->next_sibling != NULL)
            {
                tree_t *temp = parent->next_sibling->next_sibling;
                destroy(&(parent->next_sibling->first_child));
                free(parent->next_sibling);
                parent->next_sibling = temp;
            }
            else
            {
                destroy(&(parent->next_sibling));
                parent->next_sibling = NULL;
            }
        }
    }

    return t;
}

// 3
int search(tree_t *t, int node_data)
{
    if (t == NULL)
    {
        return 0;
    }
    if (t->value == node_data)
    {
        return 1;
    }
    return search(t->first_child, node_data) || search(t->next_sibling, node_data);
}

// 4
int degree(tree_t *t, int node_data)
{
    int degree = 0;
    tree_t *pos = searchpos(t, node_data);
    if (pos->first_child != NULL)
    {
        pos = pos->first_child;
        while (pos != NULL)
        {
            pos = pos->next_sibling;
            degree++;
        }
    }
    return degree;
}

// 5
int is_root(tree_t *t, int node_data)
{
    if (t->value == node_data)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

// 6
int is_leaf(tree_t *t, int node_data)
{
    tree_t *pos = searchpos(t, node_data);
    if (pos->first_child == NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

// 7
void siblings(tree_t *t, int node_data)
{
    if (t == NULL || t->value == node_data)
    {
        printf("\n");
        return;
    }
    queue_t *q = (queue_t *)malloc(sizeof(queue_t));
    q->front = NULL;
    q->rear = NULL;
    enqueue(&q, t);
    int check = 0;
    tree_t *temp;
    tree_t *parent;
    while (q->front != NULL)
    {
        parent = dequeue(&q);
        if (parent->first_child == NULL)
        {
            continue;
        }
        else
        {
            temp = parent->first_child;
            while (temp != NULL)
            {
                if (temp->value == node_data)
                {

                    check = 1;
                    break;
                }
                enqueue(&q, temp);
                temp = temp->next_sibling;
            }
        }
        if (check == 1)
        {
            break;
        }
    }
    while (q->front != NULL)
    {
        dequeue(&q);
    }

    temp = parent->first_child;
    while (temp != NULL)
    {
        if (temp->value == node_data)
        {
            temp = temp->next_sibling;
            continue;
        }
        printf("%d ", temp->value);
        temp = temp->next_sibling;
    }
    printf("\n");
}

// 8
int depth_helper(tree_t *t, int node_data, int current_depth)
{
    if (t == NULL)
    {
        return 0;
    }
    if (t->value == node_data)
    {
        return current_depth;
    }
    int result = depth_helper(t->first_child, node_data, current_depth + 1);
    if (result)
    {
        return result;
    }
    return depth_helper(t->next_sibling, node_data, current_depth);
}

int depth(tree_t *t, int node_data)
{
    if (t == NULL)
    {
        return -1;
    }
    return depth_helper(t, node_data, 0);
}

// 9
tree_t *print_path_helper(tree_t *t, stack_t **s, int end)
{
    if (t == NULL)
    {
        return NULL;
    }
    else if (t->value == end)
    {
        push(&(*s), t);
        return t;
    }
    tree_t *pos = print_path_helper(t->first_child, s, end);
    if (pos != NULL)
    {
        push(&(*s), t);
        return t;
    }
    else
    {
        return print_path_helper(t->next_sibling, s, end);
    }
}

void print_path(tree_t *t, int start, int end)
{
    tree_t *pos = searchpos(t, start);
    stack_t *s = NULL;
    print_path_helper(pos, &s, end);
    while (s != NULL)
    {
        tree_t *temp = pop(&s);
        printf("%d ", temp->value);
    }
    printf("\n");
}

// 10
int path_length(tree_t *t, int start, int end)
{
    tree_t *pos = searchpos(t, start);
    return depth(pos, end) + 1;
}

// 11
int ancestor(tree_t *t, int node_data)
{
    print_path(t, t->value, node_data);
}

void bfs(tree_t *t);

// 12
int descendant(tree_t *t, int node_data)
{
    tree_t *pos = searchpos(t, node_data);
    bfs(pos);
    printf("\n");
}

// 13
void bfs(tree_t *t)
{
    queue_t *q = (queue_t *)malloc(sizeof(queue_t));
    q->front = NULL;
    q->rear = NULL;
    enqueue(&q, t);
    while (q->front != NULL)
    {
        printf("%d ", q->front->value->value);
        tree_t *temp = dequeue(&q);
        if (temp->first_child != NULL)
        {
            tree_t *child = temp->first_child;
            while (child != NULL)
            {
                enqueue(&q, child);
                child = child->next_sibling;
            }
        }
    }
}

// 14
void dfs(tree_t *t)
{

    if (t == NULL)
    {
        return;
    }
    printf("%d ", t->value);
    dfs(t->first_child);
    dfs(t->next_sibling);
}

// 15
void print_tree_helper(tree_t *t, int depth)
{
    if (t == NULL)
    {
        return;
    }
    for (int i = 0; i < depth; i++)
    {
        printf("    ");
    }
    printf("%d\n", t->value);
    print_tree_helper(t->first_child, depth + 1);
    print_tree_helper(t->next_sibling, depth);
}

void print_tree(tree_t *t)
{
    print_tree_helper(t, 0);
}

int main(void)
{
    tree_t *t = NULL;
    int n, i, command;
    int parent, child, node, start, end;

    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        scanf("%d", &command);
        switch (command)
        {
        case 1:
            scanf("%d %d", &parent, &child);
            t = attach(t, parent, child);
            break;
        case 2:
            scanf("%d", &node);
            t = detach(t, node);
            break;
        case 3:
            scanf("%d", &node);
            printf("%d\n", search(t, node));
            break;
        case 4:
            scanf("%d", &node);
            printf("%d\n", degree(t, node));
            break;
        case 5:
            scanf("%d", &node);
            printf("%d\n", is_root(t, node));
            break;
        case 6:
            scanf("%d", &node);
            printf("%d\n", is_leaf(t, node));
            break;
        case 7:
            scanf("%d", &node);
            siblings(t, node);
            break;
        case 8:
            scanf("%d", &node);
            printf("%d\n", depth(t, node));
            break;
        case 9:
            scanf("%d %d", &start, &end);
            print_path(t, start, end);
            break;
        case 10:
            scanf("%d %d", &start, &end);
            printf("%d\n",
                   path_length(t, start, end));
            break;
        case 11:
            scanf("%d", &node);
            ancestor(t, node);
            break;
        case 12:
            scanf("%d", &node);
            descendant(t, node);
            break;
        case 13:
            bfs(t);
            break;
        case 14:
            dfs(t);
            break;
        case 15:
            print_tree(t);
            break;
        }
    }
    return 0;
}