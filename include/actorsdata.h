#ifndef ACTORSDATA
#define ACTORSDATA

#include "datatypes.h"

#define ASTART_SIZE 10
#define SIZE_MULTIPLIER 2
#define RESIZE_MARGIN 80 //percentage

typedef struct actors_array {
    int max_size;
    int length;
    
    actors_t** data;
} actors_array_t;

actors_array_t* actors_array_create();
void actors_array_free(actors_array_t** array);
void actors_array_insert(actors_array_t* array, actors_t* actor);
void actors_array_resize(actors_array_t* array);
void actor_insert_movie(actors_t* actor, movies_t* movie);
actors_t* create_actor(long id, char* name);
void print_actor(actors_t* actor);

#endif