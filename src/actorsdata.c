#include "actorsdata.h"

#include <stdio.h>
#include <stdlib.h>

actors_array_t* actors_array_create() {
    actors_array_t* arr = malloc(sizeof(actors_array_t));

    arr->max_size = START_SIZE;
    arr->length = 0;
    arr->data = malloc(sizeof(actors_t*) * arr->max_size);

    return arr;
}

void actors_array_free(actors_array_t** array) {
    for (int i = 0; i < (*array)->length; i++) {
        free((*array)->data[i]);

        //Change to linked list specific free
    }

    free((*array)->data);
    free(*array);
}

void actors_array_resize(actors_array_t* array) {
    int new_size = array->max_size * SIZE_MULTIPLIER;

    array->data = realloc(array->data, sizeof(actors_t*) * new_size);
    
    if (!array->data) {
        printf("Unable to resize actors list");
        exit(-1);
    }

    array->max_size = new_size;
}

void actors_array_insert(actors_array_t* array, actors_t* actor) {
    if (array->length > 0 && array->max_size / array->length * 100.0 > RESIZE_MARGIN) {
        actors_array_resize(array);
    }

    array->data[array->length++] = actor;
}