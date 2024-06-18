#ifndef DATATYPES
#define DATATYPES

struct movies_node;

typedef struct movies {
    int id;
	char* title;

	struct movies_node* neighbors;
} movies_t;

typedef struct movies_node {
	movies_t* node;

	struct movies_node* next;
} movies_node_t;

typedef struct actors {
    int id;
	char* name;
	
    movies_node_t* movies;
} actors_t;



#endif