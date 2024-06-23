#include "dotwriter.h"
#include <stdio.h>
#include <stdlib.h>

void write_file(const char* file, movies_array_t* data) {
    FILE* f = fopen(file, "w+");

    fprintf(f, "graph Neighbor_Movies { concentrate = true\n\t");


    for (int i = 0; i < data->max_size; i++) {
        if (!data->data[i]) continue;

        movies_t* movie = data->data[i];
        
        if (!movie->neighbors) continue;

        fprintf(f, "\"%s\" -- ", movie->title);

        movies_node_t* current = movie->neighbors;
        while (current) {
            fprintf(f, "\"%s\"", current->node->title);

            current = current->next;

            if (current) {
                fprintf(f, ", ");
            }
        }

        fprintf(f, ";\n\t");
    }

    fprintf(f, "\n}");
    fclose(f);
}