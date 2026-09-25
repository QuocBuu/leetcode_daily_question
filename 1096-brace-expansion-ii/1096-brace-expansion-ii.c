/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 10000
#define MAX_LEN 64

typedef struct {
    char **data;
    int size;
} StringList;

StringList createList(void)
{
    StringList list;
    list.data = malloc(MAX_WORDS * sizeof(char *));
    list.size = 0;

    return list;
}

void addString(StringList *list, char *str)
{
    list->data[list->size] = malloc(strlen(str) + 1);
    strcpy(list->data[list->size], str);
    list->size++;
}

void freeList(StringList *list)
{
    for (int i = 0; i < list->size; i++)
        free(list->data[i]);

    free(list->data);
}

void merge(StringList *current, StringList *words)
{
    if (current->size == 0) {
        for (int i = 0; i < words->size; i++)
            addString(current, words->data[i]);

        return;
    }

    StringList combined = createList();

    for (int i = 0; i < current->size; i++) {
        for (int j = 0; j < words->size; j++) {
            char temp[MAX_LEN];

            strcpy(temp, current->data[i]);
            strcat(temp, words->data[j]);

            addString(&combined, temp);
        }
    }

    freeList(current);
    *current = combined;
}

int compareString(const void *a, const void *b)
{
    return strcmp(*(char **)a, *(char **)b);
}

void sortAndUnique(StringList *list)
{
    if (list->size == 0)
        return;

    qsort(list->data, list->size, sizeof(char *), compareString);

    int write = 1;

    for (int read = 1; read < list->size; read++) {
        if (strcmp(list->data[read], list->data[write - 1]) != 0) {
            list->data[write++] = list->data[read];
        } else {
            free(list->data[read]);
        }
    }

    list->size = write;
}

StringList dfs(char *s, int start, int end)
{
    StringList result = createList();

    StringList groups[MAX_LEN];
    int groupCount = 1;

    groups[0] = createList();

    int depth = 0;
    int left = 0;

    for (int i = start; i <= end; i++) {
        if (s[i] == '{') {
            depth++;

            if (depth == 1)
                left = i + 1;
        }
        else if (s[i] == '}') {
            depth--;

            if (depth == 0) {
                StringList words = dfs(s, left, i - 1);

                merge(&groups[groupCount - 1], &words);
                freeList(&words);
            }
        }
        else if (s[i] == ',' && depth == 0) {
            groups[groupCount++] = createList();
        }
        else if (depth == 0) {
            char temp[2] = {s[i], '\0'};

            StringList word = createList();
            addString(&word, temp);

            merge(&groups[groupCount - 1], &word);
            freeList(&word);
        }
    }

    for (int i = 0; i < groupCount; i++) {
        for (int j = 0; j < groups[i].size; j++)
            addString(&result, groups[i].data[j]);

        freeList(&groups[i]);
    }

    sortAndUnique(&result);

    return result;
}

char **braceExpansionII(char *expression, int *returnSize)
{
    StringList result = dfs(expression, 0, strlen(expression) - 1);

    *returnSize = result.size;

    return result.data;
}