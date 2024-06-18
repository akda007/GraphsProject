#include "actorsdata.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

actors_array_t* actors_array_create() {
    actors_array_t* arr = malloc(sizeof(actors_array_t));

    arr->max_size = ASTART_SIZE;
    arr->length = 0;
    // arr->data = malloc(sizeof(actors_t*) * arr->max_size);
    arr->data = calloc(arr->max_size, sizeof(actors_t*));

    return arr;
}

void actors_array_free(actors_array_t** array) {
    for (int i = 0; i < (*array)->length; i++) {


        free((*array)->data[i]);        
    }

    free((*array)->data);
    free(*array);
}

void free_nodes(movies_node_t* node) {
    movies_node_t* current = node;
    movies_node_t* previous = NULL;

    while (current) {
        previous = current;
        current = current->next;

        free(previous);
    }

}

void free_actor(actors_t* actor) {
    free(actor->name);
    free_nodes(actor->movies);

    free(actor);
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
    if (array->length > 0 && array->length / array->max_size  * 100.0 > RESIZE_MARGIN) {
        actors_array_resize(array);
    }

    array->data[array->length++] = actor;
}

actors_t* create_actor(long id, char* name) {
    actors_t* actor = malloc(sizeof(actors_t));

    actor->id = id;
    actor->movies = NULL;
    actor->name = malloc(strlen(name)+1);
    strcpy(actor->name, name);    

    return actor;
}

void actor_insert_movie(actors_t *actor, movies_t *movie) {
    movies_node_t *node = malloc(sizeof(movies_node_t));

    node->next = NULL;
    node->node = movie;

    if (!(actor->movies)) {
        actor->movies = node;
        return;
    }

    movies_node_t* current = actor->movies;

    while(current->next) {
        current = current->next;
    }

    current->next = node;
}

void print_actor(actors_t* actor) {

    printf("(%d): %s  ->  ", actor->id, actor->name);
    
    movies_node_t* movie = actor->movies;

    while (movie) {
        printf("%s, ", movie->node->title);
        movie = movie->next;
    }

    putchar('\n');
}