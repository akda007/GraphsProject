#ifndef DATATYPES
#define DATATYPES

struct movies_node;

typedef struct movies {
    int id;
	char* title;

	//filmes vizinhos
	struct movies_node* neighbors;
} movies_t;

//nodes da linked list de filmes
typedef struct movies_node {
	//filme
	movies_t* node;

	//proximo elemento
	struct movies_node* next;
} movies_node_t;

typedef struct actors {
    int id;
	char* name;
	
	//linked list de filmes que os atores participaram
    movies_node_t* movies;
} actors_t;



#endif