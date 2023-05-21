#include <stddef.h>
#include "store.h"
#include <stdio.h>

int main()
{
    put("name", "Gerald");
    put("age", "18");

    const char *name = get("name");
    if (name != NULL)
    {
        printf("Name: %s\n", name);
    }

    const char *job = get("job");
    if (job != NULL)
    {
        printf("Job: %s\n", job);
    }

    return 0;
}
