#include "actorsdata.h"
#include "moviesdata.h"
#include "string.h"
#include "dotwriter.h"
#include "dataparser.h"
#include <stdio.h>


int main() {
    // movies_array_t* movies = movies_array_create();

    // movies_t* A = create_movie(1, "movie a");
    // movies_t* B = create_movie(2, "movie b");
    // movies_t* C = create_movie(3, "movie c");
    // movies_t* D = create_movie(4, "movie d");

    // movies_array_insert(movies, A);
    // movies_array_insert(movies, B);
    // movies_array_insert(movies, C);
    // movies_array_insert(movies, D);

    // insert_movie_neighbor(A, C);
    // insert_movie_neighbor(B, A);
    // insert_movie_neighbor(B, D);
    // insert_movie_neighbor(D, B);
    // insert_movie_neighbor(C, B);
    // insert_movie_neighbor(C, A);
    // insert_movie_neighbor(C, D);

    // puts("Movies");
    // puts("========================");
    // print_movies(movies);


    actors_array_t* aarray = actors_array_create();
    movies_array_t* marray = movies_array_create();

    printf("Parsing file\n");

    parse_movies_file("title.basics.tsv", marray);
    parse_actors_file("name.basics.tsv", aarray, marray);
    // actors_t* a = create_actor(1, "Andrey");
    // actors_t* b = create_actor(2, "Pedro");
    // actors_t* c = create_actor(3, "Joao");
    // actors_t* d = create_actor(4, "Murylo");
    // actors_array_insert(array, a);
    // actors_array_insert(array, b);
    // actors_array_insert(array, c);
    // actors_array_insert(array, d);

    // puts("Movies");
    // puts("========================");
    // print_movies(marray);
  
    // puts("Actors");
    // puts("========================");
    

    // for (int i = 0; i < aarray->length; i++) {
    //     print_actor(aarray->data[i]);
    // }

    // printf("Parsed: %d\n", aarray->length);

    write_file("graph.dot", marray);

    actors_array_free(&aarray);
    movies_array_free(&marray);
    return 0;
}
