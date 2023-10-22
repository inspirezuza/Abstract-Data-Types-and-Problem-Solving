#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORD_LENGTH 50

void sortString(char str[]) {
    int length = strlen(str);
    for (int i = 0; i < length - 1; i++) {
        for (int j = i + 1; j < length; j++) {
            if (str[i] > str[j]) {
                char temp = str[i];
                str[i] = str[j];
                str[j] = temp;
            }
        }
    }
}

int main() {
    int m, n;
    scanf("%d %d", &m, &n);

    char **anagrams = (char **) malloc(m * sizeof(char *));
    char **sorted_words = (char **) malloc(m * sizeof(char *));

    for (int i = 0; i < m; i++) {
        anagrams[i] = (char *) malloc(MAX_WORD_LENGTH * sizeof(char));
        sorted_words[i] = (char *) malloc(MAX_WORD_LENGTH * sizeof(char));
        scanf("%s", anagrams[i]);
        strcpy(sorted_words[i], anagrams[i]);
        sortString(sorted_words[i]);
    }

    for (int i = 0; i < n; i++) {
        char word[MAX_WORD_LENGTH];
        scanf("%s", word);
        char sorted_word[MAX_WORD_LENGTH];
        strcpy(sorted_word, word);
        sortString(sorted_word);

        for (int j = 0; j < m; j++) {
            if (strcmp(sorted_word, sorted_words[j]) == 0)
                printf("%s ", anagrams[j]);
        }
        printf("\n");
    }
    return 0;
}
