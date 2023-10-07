#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TEXTSIZE 21

typedef struct item {
    char *text;
    struct item *next;
} item_t;

typedef struct hash {
    item_t **table;
    int size;
    int hash_key;
} hash_t;

unsigned int hash(const char *text, int hash_key, int table_size) {
    unsigned int f_n = 0;
    int n = strlen(text);

    for (int i = 0; i < n; i++) {
        f_n = (hash_key * f_n) + text[i];
    }

    return f_n % table_size;
}

hash_t *init_hashtable(int size, int hash_key) {
    hash_t *hashtable = (hash_t *) malloc(sizeof(hash_t));
    hashtable->size = size;
    hashtable->hash_key = hash_key;
    hashtable->table = (item_t **) malloc(sizeof(item_t *) * size);

    for (int i = 0; i < size; i++) {
        hashtable->table[i] = NULL;
    }

    return hashtable;
}

void insert(hash_t *hashtable, const char *text) {
    unsigned int index = hash(text, hashtable->hash_key, hashtable->size);
    item_t *new_item = (item_t *) malloc(sizeof(item_t));
    new_item->text = strdup(text);
    new_item->next = hashtable->table[index];
    hashtable->table[index] = new_item;
}

int search(hash_t *hashtable, const char *text) {
    unsigned int index = hash(text, hashtable->hash_key, hashtable->size);
    item_t *current = hashtable->table[index];

    while (current != NULL) {
        if (strcmp(current->text, text) == 0) {
            return index;   // Found
        }
        current = current->next;
    }

    return -1;   // Not found
}

int main(void) {
    hash_t *hashtable = NULL;
    char *text = NULL;
    int m, n, i, hash_key;
    int command;
    scanf("%d %d %d", &m, &n, &hash_key);
    hashtable = init_hashtable(m, hash_key);
    text = (char *) malloc(sizeof(char) * TEXTSIZE);

    for (i = 0; i < n; i++) {
        scanf("%d %s", &command, text);
        switch (command) {
        case 1:
            insert(hashtable, text);
            break;
        case 2:
            printf("%d\n", search(hashtable, text));
            break;
        }
    }

    return 0;
}
