#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#include "dataparser.h"
#include "actorsdata.h"
#include "moviesdata.h"

long parse_id(char* id_str) {
    const char* sanitized_str  = id_str+2;

    return strtol(sanitized_str,NULL, 10);
}

void parse_actors_file(const char* file_path, actors_array_t* data_array) {
    if (!data_array) {
        printf("Actors array is null!");
        exit(-1);
    }
    
    FILE* file = fopen(file_path, "r");

    const int buff_size = 255;
    char buff[buff_size];
    char name[255];
    char id[255];

    while (fgets(buff, buff_size, file)) {
        //Skip if it does not starts with tt
        if (buff[0] != 'n' || !isdigit(buff[2])) {
            printf("Skipping line\n");
            continue;
        }

        sscanf(buff, "%[^\t]\t%[^\t]\t", id, name);

        actors_t* actor = create_actor(parse_id(id), name);

        if (actor == NULL) {
            printf("Failed to create actor\n");
            continue;
        }

        actors_array_insert(data_array, actor);
    }
    
}