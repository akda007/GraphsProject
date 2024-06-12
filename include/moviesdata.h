#ifndef MOVIESDATA
#define MOVIESDATA

#include "dtypes.h"

#define MSTART_SIZE 10
#define SIZE_MULTIPLIER 5
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
movies_t* create_movie(int id, char* title);
void free_movie(movies_t** movie);
void print_movies(movies_array_t* movies);
void insert_movie_neighbor(movies_t* movie, movies_t* neighbor) ;

#endif