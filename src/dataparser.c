#include <stdio.h>
#include <stdlib.h>

#include "dataparser.h"
#include "actorsdata.h"
#include "moviesdata.h"

void parse_actors_file(const char* file_path, actors_array_t* data_array) {
    FILE* file = fopen(file_path, "r");

    const int buff_size = 255;
    char buff[buff_size];
    char name[255];
    char id[255];

    while (fgets(buff, buff_size, file)) {
        //Skip if it does not starts with tt
        if (buff[0] != 'n') {
            printf("Skipping line\n");
            continue;
        }

        sscanf(buff, "%[^\t]\t%[^\t]\t", id, name);
        printf("%s %s\n", id, name);
    }
    
}