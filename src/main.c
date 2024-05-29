#include "dtypes.h"
#include "actorsdata.h"
#include "string.h"

#include <stdio.h>

int main() {
    actors_array_t* array = actors_array_create();

    actors_t a1, a2;
    a1.id = 1;
    a2.id = 2;

    a1.primaryName = malloc(10);
    a2.primaryName = malloc(10);
    strcpy(a1.primaryName, "Pedro");
    strcpy(a2.primaryName, "Joao");

    actors_array_insert(array, &a1);
    actors_array_insert(array, &a2);

    for (int i = 0; i < array->length; i++) {
        printf("%s\n", array->data[i]->primaryName);
    }

    actors_array_free(&array);
    return 0;
}