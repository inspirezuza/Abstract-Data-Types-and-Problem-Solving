#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TEXTSIZE 21
typedef char *item_t;
typedef struct hash {
    item_t *table;
    int size;
    int hash_key;
} hash_t;

hash_t *init_hashtable(int size, int hash_key) {
    hash_t *hashtable = (hash_t *) malloc(sizeof(hash_t));
    hashtable->size = size;
    hashtable->hash_key = hash_key;
    hashtable->table = (item_t *) malloc(sizeof(item_t) * size);

    for (int i = 0; i < size; i++) {
        hashtable->table[i] = NULL;
    }

    return hashtable;
}

unsigned int hash(char *text, int hash_key, int size) {
    unsigned int f_n = text[0];
    int n = strlen(text);

    for (int i = 1; i < n; i++) {
        f_n = (hash_key * f_n) + text[i];
    }
    return f_n % size;
}

void insert(hash_t *hashtable, char *text) {
    unsigned int index = hash(text, hashtable->hash_key, hashtable->size);
    int i = 0;
    while (hashtable->table[(index + (i + i * i) / 2) % hashtable->size] !=
           NULL) {
        i++;
    }
    hashtable->table[(index + (i + i * i) / 2) % hashtable->size] =
        strdup(text);
}

int search(hash_t *hashtable, char *text) {
    unsigned int index = hash(text, hashtable->hash_key, hashtable->size);
    int i = 0;
    while (hashtable->table[(index + (i + i * i) / 2) % hashtable->size] !=
           NULL) {
        if (strcmp(
                hashtable->table[(index + (i + i * i) / 2) % hashtable->size],
                text) == 0) {
            return (index + (i + (i * i)) / 2) % hashtable->size;
        }
        i++;
    }
    return -1;
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