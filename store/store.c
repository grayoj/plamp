#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_KEY_SIZE 256
#define MAX_VALUE_SIZE 4096
#define MAX_ENTRIES 1000

typedef struct {
    char key[MAX_KEY_SIZE];
    char value[MAX_VALUE_SIZE];
} Entry;

Entry database[MAX_ENTRIES];
int num_entries = 0;

void put(const char* key, const char* value) {
    if (num_entries == MAX_ENTRIES) {
        printf("Database is full. Cannot add more entries.\n");
        return;
    }

    Entry entry;
    strncpy(entry.key, key, MAX_KEY_SIZE);
    strncpy(entry.value, value, MAX_VALUE_SIZE);
    database[num_entries++] = entry;
    printf("Added entry with key '%s' and value '%s'\n", key, value);
}

const char* get(const char* key) {
    for (int i = 0; i < num_entries; i++) {
        if (strcmp(database[i].key, key) == 0) {
            return database[i].value;
        }
    }

    printf("Entry with key '%s' not found\n", key);
    return NULL;
}

