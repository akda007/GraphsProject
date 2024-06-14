#include "moviesdata.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


movies_array_t* movies_array_create() {
    movies_array_t* arr = malloc(sizeof(movies_array_t));

    arr->max_size = MSTART_SIZE;
    arr->length = 0;
    arr->data = calloc(arr->max_size, sizeof(movies_t*));

    return arr;
}

void movies_array_free(movies_array_t** array) {
    for (int i = 0; i < (*array)->length; i++) {
        free_movie(&((*array)->data[i]));

        //Change to linked list specific free
    }

    free((*array)->data);
    free(*array);
}

void movies_array_resize(movies_array_t* array) {
    int new_size = array->max_size * SIZE_MULTIPLIER;

    // array->data = realloc(array->data, sizeof(movies_t*) * new_size);
    movies_t** new_array = calloc(new_size, sizeof(movies_t*));
    
    for (int i = 0; i < array->max_size; i++) {
        if (array->data[i]) {
            new_array[i % new_size] = array->data[i];
        }
    }

    free(array->data);

    array->data = new_array;

    if (!array->data) {
        printf("Unable to resize actors list");
        exit(-1);
    }

    array->max_size = new_size;
}

void movies_array_insert(movies_array_t* array, movies_t* movie) {
    if (array->length > 0 && array->length / array->max_size  * 100.0 > RESIZE_MARGIN) {
        movies_array_resize(array);
    }

    int index = movie->id % array->max_size;

    while (array->data[index]) {
        index++;

        if (index >= array->max_size) {
            movies_array_resize(array);

            index = movie->id % array->max_size;
        }
    }

    array->data[index] = movie;
    array->length++;
}


movies_t* create_movie(int id, char* title) {
    movies_t* movie = malloc(sizeof(movies_t));

    movie->id = id;
    movie->neighbors = NULL;
    movie->title = malloc(strlen(title)+1);
    strcpy(movie->title, title); 

    return movie;
}

void free_movie_nodes(movies_node_t** neighbors) {
    movies_node_t* current = *neighbors;

    while (current) {
        movies_node_t* node = current->next;
        free(current);

        current = node;
    }

    free(neighbors);
}

void free_movie(movies_t** movie) {
    if (!(*movie)) return;

    free((*movie)->title);
    free_movie_nodes(&((*movie)->neighbors));
    free(*movie);
}

void print_movies(movies_array_t* movies){
    for (int i = 0; i < movies->max_size; i++) {
        if (!movies->data[i]) continue;

        movies_t* movie = movies->data[i];
        printf("Title: %s | id: %d\t", movie->title, movie->id);

        movies_node_t* current = movie->neighbors;
        while (current) {
            printf("%d, ", current->node->id);
            current = current->next;
        }

        printf("=========================\n");
    }

}


void insert_movie_neighbor(movies_t* movie, movies_t* neighbor) {
    movies_node_t* current = movie->neighbors;

    if (!current) {
        movies_node_t* new = malloc(sizeof(movies_node_t));
        new->node = neighbor;
        new->next = NULL;

        movie->neighbors = new;

        return;
    }

    while (current->next) {
        if (current->node == neighbor) return;

        current =  current->next;
    }

    movies_node_t *new = malloc(sizeof(movies_node_t));

    new->node = neighbor;
    new->next = NULL;

    current->next = new;
}

movies_t* array_find_movie(movies_array_t* array, int id) {
    int index = id % array->max_size;
    movies_t* movie = array->data[index];

    while (movie->id != id) {
        movie = array->data[++index];

        if (!movie) {
            return NULL;
        }
    }

    return movie;
}