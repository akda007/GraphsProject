#ifndef MOVIESDATA
#define MOVIESDATA

#include "datatypes.h"

#define MSTART_SIZE 1000
#define MOVIES_SIZE_MULTIPLIER 2
#define RESIZE_MARGIN 80 //percentage

typedef struct movies_array {
    int max_size;
    int length;
    
    movies_t** data;
} movies_array_t;

movies_array_t* movies_array_create();
void movies_array_free(movies_array_t** array);
void movies_array_insert(movies_array_t* array, movies_t* movie);
void movies_array_resize(movies_array_t* array);
void movies_array_insert(movies_array_t* array, movies_t* movie);
movies_t* create_movie(const int id, const char* title);
void free_movie(movies_t** movie);
void free_movie_nodes(movies_node_t** neighbors);
void print_movies(movies_array_t* movies);
void insert_movie_neighbor(movies_t* movie, movies_t* neighbor) ;
movies_t* array_find_movie(movies_array_t* array, int id);

#endif