#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#include "dataparser.h"
#include "actorsdata.h"
#include "moviesdata.h"

long parse_id(char* id_str) {
    const char* sanitized_str  = id_str+2;

    return strtol(sanitized_str, NULL, 10);
}

void parse_movies_file(const char* file_path, movies_array_t* movies_array) {
    if (!movies_array) {
        printf("Array is null");
        exit(-1);
    }

    FILE* file = fopen(file_path, "r");

    const int buff_size = 255;
    char buff[buff_size], title[buff_size], id[buff_size], type[30];

    while (fgets(buff, buff_size, file)) {
        if (buff[0] != 't' || !isdigit(buff[2])) {
            // printf("Skipping line");
            continue;
        }

        sscanf(buff, "%[^\t]\t%[^\t]\t%[^\t]\t", id, type, title);

        if (strcmp(type, "movie") != 0) {
            // printf("Not a movie... Skipping!\n");
            continue;
        }

        movies_t* movie = create_movie(parse_id(id), title);

        movies_array_insert(movies_array, movie);
    }
}

void update_actor_movies(movies_array_t* movies, actors_t* actor, char* titles) {
    char* c = titles;

    long id;
    movies_t* movie;
    while (*c != '\0') {
        if (*c == ',') {
            *c = '\0';

            id = strtol(titles+2, NULL, 10);

            movie = array_find_movie(movies, id);
            
            if (movie)
                actor_insert_movie(actor, movie);

            titles = c+1;
        }

        c++;
    }

    id = strtol(titles+2, NULL, 10);

    movie = array_find_movie(movies, id);    

    if (movie)
        actor_insert_movie(actor, movie);
}

void update_neighbors(actors_t* actor) {
    movies_node_t* node = actor->movies;

    if (!node) return;

    while (node) {
        for (movies_node_t* n = actor->movies; n->next; n = n->next) {
            if (n == node) continue;

            insert_movie_neighbor(node->node, n->node);
        }

        node = node->next;
    }
    
}

void parse_actors_file(const char* file_path, actors_array_t* data_array, movies_array_t* movies) {
    if (!data_array) {
        printf("Actors array is null!");
        exit(-1);
    }
    
    FILE* file = fopen(file_path, "r");

    const int buff_size = 255;
    char buff[buff_size], name[buff_size], id[buff_size], titles[buff_size];

    while (fgets(buff, buff_size, file)) {
        //Skip if it does not starts with tt
        if (buff[0] != 'n' || !isdigit(buff[2])) {
            // printf("Skipping line\n");
            continue;
        }

        sscanf(buff, "%[^\t]\t%[^\t]\t%*[^\t]\t%*[^\t]\t%*[^\t]\t%[^\n]\n", id, name, titles);

        actors_t* actor = create_actor(parse_id(id), name);

        if (actor == NULL) {
            printf("Failed to create actor\n");
            continue;
        }


        update_actor_movies(movies, actor, titles);
        update_neighbors(actor);

        actors_array_insert(data_array, actor);
    }
    
}