#include "dtypes.h"
#include "actorsdata.h"
#include "moviesdata.h"
#include "string.h"

#include <stdio.h>

int main() {
    movies_array_t* movies = movies_array_create();

    movies_t* A = create_movie(1, "movie a");
    movies_t* B = create_movie(2, "movie b");
    movies_t* C = create_movie(3, "movie c");
    movies_t* D = create_movie(4, "movie d");

    movies_array_insert(movies, A);
    movies_array_insert(movies, B);
    movies_array_insert(movies, C);
    movies_array_insert(movies, D);

    insert_movie_neighbor(A, C);
    insert_movie_neighbor(B, A);
    insert_movie_neighbor(B, D);
    insert_movie_neighbor(D, B);
    insert_movie_neighbor(C, B);
    insert_movie_neighbor(C, A);
    insert_movie_neighbor(C, D);

    print_movies(movies);


    movies_array_free(&movies);

    return 0;
}